// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef UDEMYPROJECT3_UdemyProject3Projectile_generated_h
#error "UdemyProject3Projectile.generated.h already included, missing '#pragma once' in UdemyProject3Projectile.h"
#endif
#define UDEMYPROJECT3_UdemyProject3Projectile_generated_h

#define UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_SPARSE_DATA
#define UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAUdemyProject3Projectile(); \
	friend struct Z_Construct_UClass_AUdemyProject3Projectile_Statics; \
public: \
	DECLARE_CLASS(AUdemyProject3Projectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UdemyProject3"), NO_API) \
	DECLARE_SERIALIZER(AUdemyProject3Projectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAUdemyProject3Projectile(); \
	friend struct Z_Construct_UClass_AUdemyProject3Projectile_Statics; \
public: \
	DECLARE_CLASS(AUdemyProject3Projectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UdemyProject3"), NO_API) \
	DECLARE_SERIALIZER(AUdemyProject3Projectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AUdemyProject3Projectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AUdemyProject3Projectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AUdemyProject3Projectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AUdemyProject3Projectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AUdemyProject3Projectile(AUdemyProject3Projectile&&); \
	NO_API AUdemyProject3Projectile(const AUdemyProject3Projectile&); \
public:


#define UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AUdemyProject3Projectile(AUdemyProject3Projectile&&); \
	NO_API AUdemyProject3Projectile(const AUdemyProject3Projectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AUdemyProject3Projectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AUdemyProject3Projectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AUdemyProject3Projectile)


#define UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AUdemyProject3Projectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AUdemyProject3Projectile, ProjectileMovement); }


#define UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_12_PROLOG
#define UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_PRIVATE_PROPERTY_OFFSET \
	UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_SPARSE_DATA \
	UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_RPC_WRAPPERS \
	UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_INCLASS \
	UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_PRIVATE_PROPERTY_OFFSET \
	UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_SPARSE_DATA \
	UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_INCLASS_NO_PURE_DECLS \
	UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UDEMYPROJECT3_API UClass* StaticClass<class AUdemyProject3Projectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UdemyProject3_Source_UdemyProject3_UdemyProject3Projectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
