# Resident Evil 1 (PC decomp) for WebAssembly: work in progress

Status: **local spike, not published, no build workflow yet.**

Base: [`ecruells/resident-evil-pc-decomp`](https://github.com/ecruells/resident-evil-pc-decomp)
at commit `15004914527567a2b9cecf34997abe8c252bcbf9` (GPL-3.0). The game data
(assets) is never included: the player supplies it (`bring-your-own`).

## Legal

The decomp is a reconstruction of Capcom's 1997 binary. Its GPL license does not
grant any rights Capcom holds. Get legal advice **before** publishing a build or
the patches in this directory, and before making this branch public.

## Spike results (Emscripten 3.1.74, local)

- All 88 shared translation units (`src/game`, `src/system`, `src/marni`,
  `src/video`, `src/Globals.cpp`) compile to wasm. One patch was needed
  (`patches/0001-mainloop-use-uint8_t.patch`: `unsigned __int8` is not valid C++
  outside MSVC).
- Linux platform files `platform.cpp`, `input.cpp`, `audio.cpp`, `config.cpp`,
  `stubs.cpp` compile unchanged with `-sUSE_SDL=2`.
- Remaining platform work:
  1. `MarniGLFuncs.*`: replace the desktop-GL loader with `<GLES3/gl3.h>` and use
     `#version 300 es` shaders (`MarniDX_GL.cpp`, 780 lines).
  2. `crash.cpp` (needs `execinfo.h`): stub.
  3. `video.cpp` (ffmpeg): stub first, then a small Cinepak decoder for the 27 FMVs.
  4. `TaskScheduler.cpp` already has a `ucontext` path; wasm needs a thin
     `makecontext/swapcontext` shim over `emscripten_fiber_*` (requires ASYNCIFY).
  5. `main.cpp`: Emscripten main loop, asset tree loading on demand.
  6. Audit indirect calls through `__cdecl`/`__stdcall` vtable casts: wasm traps on
     signature mismatch.

## Not done

Nothing links or runs yet, and nothing has been played: no game data is available
in the development environment.
