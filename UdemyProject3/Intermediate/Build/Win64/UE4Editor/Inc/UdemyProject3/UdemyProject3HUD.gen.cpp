// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UdemyProject3/UdemyProject3HUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUdemyProject3HUD() {}
// Cross Module References
	UDEMYPROJECT3_API UClass* Z_Construct_UClass_AUdemyProject3HUD_NoRegister();
	UDEMYPROJECT3_API UClass* Z_Construct_UClass_AUdemyProject3HUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_UdemyProject3();
// End Cross Module References
	void AUdemyProject3HUD::StaticRegisterNativesAUdemyProject3HUD()
	{
	}
	UClass* Z_Construct_UClass_AUdemyProject3HUD_NoRegister()
	{
		return AUdemyProject3HUD::StaticClass();
	}
	struct Z_Construct_UClass_AUdemyProject3HUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUdemyProject3HUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_UdemyProject3,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUdemyProject3HUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "UdemyProject3HUD.h" },
		{ "ModuleRelativePath", "UdemyProject3HUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUdemyProject3HUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUdemyProject3HUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AUdemyProject3HUD_Statics::ClassParams = {
		&AUdemyProject3HUD::StaticClass,
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
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AUdemyProject3HUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AUdemyProject3HUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AUdemyProject3HUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AUdemyProject3HUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AUdemyProject3HUD, 3344478699);
	template<> UDEMYPROJECT3_API UClass* StaticClass<AUdemyProject3HUD>()
	{
		return AUdemyProject3HUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUdemyProject3HUD(Z_Construct_UClass_AUdemyProject3HUD, &AUdemyProject3HUD::StaticClass, TEXT("/Script/UdemyProject3"), TEXT("AUdemyProject3HUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUdemyProject3HUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
