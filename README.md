# Click Target Game
Click a target that moves to a new location every few seconds to increase your score

## Dependencies
This project uses 
- [SDL2](https://wiki.libsdl.org/SDL2/FrontPage)
- [SDL2_ttf](https://wiki.libsdl.org/SDL2_ttf/FrontPage)


### Setup Instructions
1. Download SDL2 and SDL2_ttf development libraries.
2. Place the `include` and `lib` folders for both libraries in a known location.
3. Update your project settings in Visual Studio:
   - **VC++ Directories**:
     - **Include Directories**: `path/to/SDL2/include`; `path/to/SDL2_ttf/include`
     - **Library Directories**: `path/to/SDL2/lib/64`; `path/to/SDL2_ttf/lib/64`
   - **Linker > Input**: Add `SDL2.lib`; `SDL2main.lib`; `SDL2_ttf.lib`
