
# Intro

- [x] Works with Unreal 5.1 on Windows
- [ ] Test on macOS
- [ ] Test on Linux

## Using in UE-5

- Needs to be compiled for Windows with the MS BuildTools toolset using architecture x64
- Needs to be a Release build
- Install will place the compiled libraries in the right folder

The UE5 exposed functions are defined in the ue5_lib.cpp/.h files.

Then simply copy the `AntPlusPlugin` folder to your project's plugin folder.

## Useful commands

Initiate

```bash
cmake -DCMAKE_BUILD_TYPE=Release -S . -G Ninja -B cmake-build-release
```

Build

```bash
cmake --build cmake-build-release --target ant_test_DLL -j 12
```

Install libraries in tree

```bash
cmake --build cmake-build-release --target install -j 12
```