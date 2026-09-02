// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjectBigLaser : ModuleRules
{
	public ProjectBigLaser(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ProjectBigLaser",
			"ProjectBigLaser/Variant_Horror",
			"ProjectBigLaser/Variant_Horror/UI",
			"ProjectBigLaser/Variant_Shooter",
			"ProjectBigLaser/Variant_Shooter/AI",
			"ProjectBigLaser/Variant_Shooter/UI",
			"ProjectBigLaser/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
