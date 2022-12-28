
# Intro

## Using in UE-5

- Needs to be compiled with Visual Studio toolchain x64 (for Windows)
- Needs to be a Release build
- Install will place the compiled libraries in the right folder

Then simply copy the `AntPlusPlugin` to your project's plugin folder.

## Unused commands I want to keep

```bash
cmake -S . -G "Visual Studio 16 2019" -B vstudio -A Win64
```

```bash
msbuild vstudio/ant_test.sln
```