#pragma once

#include "Engine/DataTable.h"

#include "LuaValue.h"

#include "LuaFunctionDataTable.generated.h"

USTRUCT(BlueprintType)
struct LUAMACHINE_API FNameELuaTypePair
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELuaValueType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELuaSubCategoryObjectType SubCategoryObjectType;

};

USTRUCT(BlueprintType)
struct LUAMACHINE_API FLuaFunctionArgumentsRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNameELuaTypePair> Args;

};


