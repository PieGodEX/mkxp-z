# mkxp-z (Forma Rojo)

Bad experimentation bed for things I'm too much of a coward to push to the original, ignore this.

Refer to the [the original](https://github.com/mkxp-z/mkxp-z/) for everything.

## Experiments
### Done
- Changed `mkxp.json` to `config.json` for no reason in particular
- Added `Filesystem.exist?(path)` to verify the existence of paths or files in the path cache
- Added `Bitmap.mask(color)` to efficienty remove a color from a bitmap
- Added `Font.solid` and `Font.solid=true/false` to set a font's solid setting without needing to edit the configuration file
- Added `Font.path` and `Font.path=` to brute force a font to load from a file without needing to know the font's family name
- Added `Graphics.window_width` and `Graphics.window_height` to retrieve the current size of the program window itself
  - (can probably be used for dynamic resolution nonsense)
- Added `bindControllerInput` option to the config (defaults as `true`), when set to false it disables all the default controller bindings, to make it easier to set your own override ruby-side


### Was done before but I need to do again
- Setting `gameFolder` actually semi-works in a way that makes sense
- Console attaches to a host process if said host process is a console emulator

### To do
- Set `Graphics.play_movie`'s skip parameter to accept symbols for input actions, maybe? To change what button causes it to skip?
- A way to retrieve the monitors and running resolution of the player's PC? (Either `System.monitors[i]` or `Graphics.desktop_resolution` or something like that)
- Split detected controllers into an array for multiplayer experience
- Fix console attachment to work with piping to files
- Externally loaded shaders
- Add Rect#to_a
- Figure out why Audio.bgm_pos eventually gets more and more desynced when used with MIDI
- Externally loaded plugins, any way for Ruby C extensions to be able to access mkxp-z internals
