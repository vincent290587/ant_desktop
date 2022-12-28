// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class AntPlusPluginLibrary : ModuleRules
{
	public AntPlusPluginLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			//PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "x64", "libant_test_DLL.dll.a"));

			// Delay-load the DLL, so we can load it from the right place first
			//PublicDelayLoadDLLs.Add("libant_test_DLL.dll");

			// Ensure that the DLL is staged along with the executable
			//RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "x64", "libant_test_DLL.dll"));

			PublicPreBuildLibraries.Add(Path.Combine(ModuleDirectory, "x64", "ant_lib.lib"));
			PublicPreBuildLibraries.Add(Path.Combine(ModuleDirectory, "x64", "ant_test_DLL.lib"));
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            //PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "libExampleLibrary.dylib"));
            //RuntimeDependencies.Add("$(PluginDir)/Source/ThirdParty/AntPlusPluginLibrary/Mac/Release/libExampleLibrary.dylib");
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
		{
			//string ExampleSoPath = Path.Combine("$(PluginDir)", "Binaries", "ThirdParty", "AntPlusPluginLibrary", "Linux", "x86_64-unknown-linux-gnu", "libExampleLibrary.so");
			//PublicAdditionalLibraries.Add(ExampleSoPath);
			//PublicDelayLoadDLLs.Add(ExampleSoPath);
			//RuntimeDependencies.Add(ExampleSoPath);
		}
	}
}
