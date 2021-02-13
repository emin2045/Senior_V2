// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Senior_V2 : ModuleRules
{
	public Senior_V2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
