// crash_stub.cpp - the browser reports traps itself; no crash.log on the web build.
#include "platform/platform.h"

void crashlog_install(void) {}
void crashlog_mark(const char*) {}
