# mkxp-z (Forma Rojo)

Bad experimentation bed for things I'm too much of a coward to push to the original, ignore this.

Refer to the [the original](https://github.com/mkxp-z/mkxp-z/) for everything.

## Experiments
### Done
- Changed `mkxp.json` to `config.json` for no reason in particular
- Setting `gameFolder` actually semi-works in a way that makes sense
- Console attaches to a host process if said host process is a console emulator

### To do
- Set `Graphics.play_movie`'s skip parameter to accept symbols for input actions, maybe? To change what button causes it to skip?
- A way to retrieve the monitors and running resolution of the player's PC? (Either `System.monitors[i]` or `Graphics.desktop_resolution` or something like that)
- Split detected controllers into an array for multiplayer experience
- Slap in a `rgssInput` config value that changes whether mkxp handles input itself, for madmen who want to disable the C-side input handling and replace it with some poorly-built poorly-optimized ruby-side one (Read as: Me)
- Fix console attachment to work with piping to files
- Ruby Version Selection in the Makefile
  - Figure out how to patch ruby directly instead of using a fork
- Ruby Version Selection as an Action
