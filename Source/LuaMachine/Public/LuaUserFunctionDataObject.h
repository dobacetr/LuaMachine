// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"

#include "LuaUserDataObject.h"

#include "LuaUserFunctionDataObject.generated.h"

/**
 * 
 */
UCLASS()
class LUAMACHINE_API ULuaUserFunctionDataObject : public ULuaUserDataObject
{
	GENERATED_BODY()
public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* FunctionTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* VariableTable;
};
