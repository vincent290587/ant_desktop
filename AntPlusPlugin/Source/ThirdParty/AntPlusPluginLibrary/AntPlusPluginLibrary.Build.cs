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
			// Add the library
			PublicPreBuildLibraries.Add(Path.Combine(ModuleDirectory, "x64", "libant_test_DLL.a"));
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
