# Visual Novel Engine

Engine to make 2D pixel-art visual novels. Requires OpenGL 3.0 minimum.

### BUILD

Tested on Windows10 MSVC.

- Make a build folder at the root: `mkdir build && cd build`.
- Run cmake inside the build folder: `cmake ..`.
- Run `make` if on a Linux machine, otherwise on Windows, `msbuild VNEngine.sln`.

### Updates
- 2022-01-31
  - Start of project, OpenGL window.

### TODO
- Pixel drawing system
- 2D text integration
- Music/sound engine integration
- PNG/JPEG loading support