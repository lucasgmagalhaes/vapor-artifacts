# vapor-artifacts

Build and hosting of the artifacts (wasm + freely licensed assets) of the games listed in the [Vapor](https://github.com/lucasgmagalhaes/vapor) catalog.

- Each game has a workflow in `.github/workflows/build-<slug>.yml` that builds from a **pinned** source commit, verifies the hash of the assets, and publishes a Release (`<slug>-<n>`).
- The catalog (`games/<slug>/game.json` in the `vapor` repository) points to the Release URL and stores the `sha256` and `size`. The app checks both before installing.
- Only games with `assets_policy` `open` (code and assets under a free license) are built here, or the code of `bring-your-own` games, never proprietary assets.
- **Removal:** takedown requests are handled in the `vapor` repository (see `takedown/TAKEDOWN.md`); here it is enough to delete the game's Release (and workflow).
