
# Intro

- [x] Works with Unreal 5.1 on Windows
- [ ] Adapt CMake for MAc/ Linux targets
- [ ] Test on macOS
- [ ] Test on Linux

In the current state this library only works on Windows, and can connect to a power meter of a user-defined device ID (see ANT+ documentation).

The project was used in CLion IDE.

For commercial purposes please contact me :-)

## Using in UE-5

Important points for UE compatibility:

- Needs to be compiled for Windows with the MS BuildTools toolset using architecture x64
- Needs to be a Release build (if not, UE will complain at link time)

## Steps for using the plugin

- Run the CMake initiate command
- Run the CMake build command
- Run the CMake install command 

The CMake install step will place the compiled libraries in the `AntPlusPlugin` folder. 
So you should have two .lib files in AntPlusPlugin/Source/ThirdParty/AntPlusPluginLibrary/x64

- Copy the entire `AntPlusPlugin` folder to your UE project `Plugins` folder

Two functions are now available for your blueprints:

![](blueprint.png)

First, set your power meter sensor device ID (16 bits unsigned).

In your code you can then call the second block to read the last received power from the sensor.

## Useful commands

Initiate CMake build

```bash
cmake -DCMAKE_BUILD_TYPE=Release -S . -G Ninja -B cmake-build-release -G "Visual Studio 16 2019" -A x64
```

Build

```bash
cmake --build cmake-build-release --target ant_test_DLL -j 12
```

Install libraries in tree

```bash
cmake --build cmake-build-release --target install -j 12
```