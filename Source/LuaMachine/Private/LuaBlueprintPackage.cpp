// Copyright 2018-2023 - Roberto De Ioris


#include "LuaBlueprintPackage.h"

TSubclassOf<ULuaState> ULuaBlueprintPackage::GetLuaState() const
{
	ULuaState* LuaState = Cast<ULuaState>(GetOuter());
	if (LuaState)
	{
		return LuaState->GetClass();
	}
	return nullptr;
}

UWorld* ULuaBlueprintPackage::GetWorld() const
{
	ULuaState* LuaState = Cast<ULuaState>(GetOuter());
	if (LuaState)
	{
		return LuaState->GetWorld();
	}
	return nullptr;
}

void ULuaBlueprintPackage::Init()
{

}