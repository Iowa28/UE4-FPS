// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UdemyProject3/UdemyProject3GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUdemyProject3GameMode() {}
// Cross Module References
	UDEMYPROJECT3_API UClass* Z_Construct_UClass_AUdemyProject3GameMode_NoRegister();
	UDEMYPROJECT3_API UClass* Z_Construct_UClass_AUdemyProject3GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_UdemyProject3();
// End Cross Module References
	void AUdemyProject3GameMode::StaticRegisterNativesAUdemyProject3GameMode()
	{
	}
	UClass* Z_Construct_UClass_AUdemyProject3GameMode_NoRegister()
	{
		return AUdemyProject3GameMode::StaticClass();
	}
	struct Z_Construct_UClass_AUdemyProject3GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUdemyProject3GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UdemyProject3,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUdemyProject3GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "UdemyProject3GameMode.h" },
		{ "ModuleRelativePath", "UdemyProject3GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUdemyProject3GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUdemyProject3GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AUdemyProject3GameMode_Statics::ClassParams = {
		&AUdemyProject3GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AUdemyProject3GameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AUdemyProject3GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AUdemyProject3GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AUdemyProject3GameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AUdemyProject3GameMode, 1385224775);
	template<> UDEMYPROJECT3_API UClass* StaticClass<AUdemyProject3GameMode>()
	{
		return AUdemyProject3GameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUdemyProject3GameMode(Z_Construct_UClass_AUdemyProject3GameMode, &AUdemyProject3GameMode::StaticClass, TEXT("/Script/UdemyProject3"), TEXT("AUdemyProject3GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUdemyProject3GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
