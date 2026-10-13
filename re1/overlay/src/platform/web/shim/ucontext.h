// ucontext shim for Emscripten, built on emscripten_fiber_*. Only the subset the task
// scheduler uses: getcontext / makecontext (no args) / swapcontext, uc_stack, uc_link.
// Requires -sASYNCIFY.
#pragma once
#include <emscripten/fiber.h>
#include <stdlib.h>
#include <string.h>

#define RE1_FIBER_ASYNCIFY_STACK (128 * 1024)

typedef struct re1_ucontext {
    emscripten_fiber_t fiber;
    struct { void* ss_sp; size_t ss_size; } uc_stack;
    struct re1_ucontext* uc_link;
    void (*entry)(void);
    char* asyncify_stack;
    int initialised;
} ucontext_t;

static inline int getcontext(ucontext_t* c) { memset(c, 0, sizeof *c); return 0; }

static inline void re1_fiber_trampoline(void* arg)
{
    ucontext_t* c = (ucontext_t*)arg;
    c->entry();
    // Tasks never return in the original; if one does, hand control back for good.
    emscripten_fiber_swap(&c->fiber, &c->uc_link->fiber);
}

static inline void makecontext(ucontext_t* c, void (*fn)(void), int argc)
{
    (void)argc;
    c->entry = fn;
    if (c->asyncify_stack == NULL) c->asyncify_stack = (char*)malloc(RE1_FIBER_ASYNCIFY_STACK);
    emscripten_fiber_init(&c->fiber, re1_fiber_trampoline, c, c->uc_stack.ss_sp,
                          c->uc_stack.ss_size, c->asyncify_stack, RE1_FIBER_ASYNCIFY_STACK);
    c->initialised = 1;
}

static inline int swapcontext(ucontext_t* from, const ucontext_t* to)
{
    if (!from->initialised) {
        // The thread's own context (the scheduler): adopt the running stack.
        if (from->asyncify_stack == NULL) from->asyncify_stack = (char*)malloc(RE1_FIBER_ASYNCIFY_STACK);
        emscripten_fiber_init_from_current_context(&from->fiber, from->asyncify_stack, RE1_FIBER_ASYNCIFY_STACK);
        from->initialised = 1;
    }
    emscripten_fiber_swap(&from->fiber, (emscripten_fiber_t*)&to->fiber);
    return 0;
}
