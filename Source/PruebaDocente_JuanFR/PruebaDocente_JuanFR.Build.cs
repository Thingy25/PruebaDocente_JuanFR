// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PruebaDocente_JuanFR : ModuleRules
{
	public PruebaDocente_JuanFR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "NavigationSystem", "UMG" });
	}
}
