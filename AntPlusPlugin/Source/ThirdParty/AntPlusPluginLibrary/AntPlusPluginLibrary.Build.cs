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
			PublicPreBuildLibraries.Add(Path.Combine(ModuleDirectory, "x64", "ant_lib.lib"));
			PublicPreBuildLibraries.Add(Path.Combine(ModuleDirectory, "x64", "ant_test_DLL.lib"));
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
			PublicPreBuildLibraries.Add(Path.Combine(ModuleDirectory, "Mac", "ant_lib.a"));
			PublicPreBuildLibraries.Add(Path.Combine(ModuleDirectory, "Mac", "ant_test_DLL.a"));
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
		{
			PublicPreBuildLibraries.Add(Path.Combine(ModuleDirectory, "Linux_x86_64", "ant_lib.a"));
			PublicPreBuildLibraries.Add(Path.Combine(ModuleDirectory, "Linux_x86_64", "ant_test_DLL.a"));
		}
	}
}
