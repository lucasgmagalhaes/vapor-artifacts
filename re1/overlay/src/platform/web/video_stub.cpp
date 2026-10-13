// video_stub.cpp - no FMV on the web build yet. plat_video_init() == FALSE tells
// VideoPlayback to skip every movie (see platform.h).
#include "platform/platform.h"

void plat_video_set_overlay_callback(PlatVideoOverlayCallback) {}
BOOL plat_video_init(void) { return FALSE; }
BOOL plat_video_open_and_play(const char*, int) { return FALSE; }
void plat_video_play_from(int) {}
void plat_video_stop(void) {}
void plat_video_close(void) {}
BOOL plat_video_is_active(void) { return FALSE; }
BOOL plat_video_take_end_event(void) { return FALSE; }
void plat_video_tick(void) {}
void plat_video_set_window_mode(BOOL) {}
