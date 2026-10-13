# Resident Evil 1 (PC decomp) for WebAssembly: work in progress

Status: **engine builds and starts in the browser; no game data, so it cannot be played yet.**
Built by the `build-re1-wasm` workflow; nothing is published as a Release unless a run is started
manually with `publish=true`.

Base: [`ecruells/resident-evil-pc-decomp`](https://github.com/ecruells/resident-evil-pc-decomp)
at commit `15004914527567a2b9cecf34997abe8c252bcbf9` (GPL-3.0). The game data
(assets) is never included: the player supplies it (`bring-your-own`).

## Legal

The decomp is a reconstruction of Capcom's 1997 binary. Its GPL license does not
grant any rights Capcom holds. Get legal advice **before** publishing a build or
the patches in this directory, and before making this branch public.

## What is in this directory

- `overlay/`: new files copied over the upstream tree (`wasm/CMakeLists.txt`, the web platform
  layer `src/platform/web/`: no-op video and crash stubs, a `ucontext.h` shim over Emscripten
  fibers, a GLES3 `glcorearb.h` shim) and a test page.
- `patches/`: small patches applied with `git apply` (GLES3 shaders and loader, web main loop,
  one MSVC-ism fix).

## Results (Emscripten 3.1.74)

- All shared translation units compile; the link succeeds (about 2 MB of wasm).
- In the browser the engine creates a WebGL2 context, opens audio, starts the task scheduler
  on fibers and runs the main loop. It then reports the missing game data
  (`could not load bank`, `Invalid magic`), which is expected.
- `-sEMULATE_FUNCTION_POINTER_CASTS=1` is required: the game calls vtable entries through
  pointers of another signature (harmless on x86, a trap in wasm). Without it the first scene
  teardown fails with `function signature mismatch`.

## Still to do

1. Mount the player's game files (see `byo_files` in Vapor) into the wasm filesystem, lazily:
   the data set is large.
2. FMV: replace the stub with a Cinepak decoder (27 videos, 242 MB).
3. Play-test every flow with real data; performance of ASYNCIFY and the emulated casts.
4. Save files: the game writes under `SAVE/`; map it to Vapor's save bridge.
