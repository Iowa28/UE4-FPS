// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UdemyProject3 : ModuleRules
{
	public UdemyProject3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "AIModule", "GameplayTasks", "NavigationSystem" });
	}
}
