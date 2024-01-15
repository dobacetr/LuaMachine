// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetDriver.h"
#include "NetworkObject.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, meta = (ShowWorldContextPin, ShortTooltip = "UObject that replicates the derived BPClass properties."))
class LUAMACHINE_API UNetworkObject : public UObject
{
	GENERATED_BODY()
public:
	UNetworkObject()
	{
		AActor* owner = GetOwningActor();
		if(owner)
			if(owner->IsUsingRegisteredSubObjectList())
				owner->AddReplicatedSubObject(this);
	}

	/** Returns properties that are replicated for the lifetime of the actor channel */
	virtual void GetLifetimeReplicatedProps(TArray< class FLifetimeProperty >& OutLifetimeProps) const override
	{
		Super::GetLifetimeReplicatedProps(OutLifetimeProps);

		UBlueprintGeneratedClass* BPClass = Cast<UBlueprintGeneratedClass>(GetClass());
		if (BPClass != NULL)
		{
			BPClass->GetLifetimeBlueprintReplicationList(OutLifetimeProps);
		}
	}

	virtual bool IsSupportedForNetworking() const override
	{
		return true;
	}

	//// Allows the Object to get a valid UWorld from it's outer.
	//virtual UWorld* GetWorld() const override
	//{
	//	if (const UObject* MyOuter = GetOuter())
	//	{
	//		return MyOuter->GetWorld();
	//	}
	//	return nullptr;
	//}

	UFUNCTION(BlueprintPure, Category = "NetworkObject")
	AActor* GetOwningActor() const
	{
		return GetTypedOuter<AActor>();
	}

	virtual int32 GetFunctionCallspace(UFunction* Function, FFrame* Stack) override
	{
		check(GetOuter() != nullptr);
		return GetOuter()->GetFunctionCallspace(Function, Stack);
	}

	// Call "Remote" (aka, RPC) functions through the actors NetDriver
	virtual bool CallRemoteFunction(UFunction* Function, void* Params, struct FOutParmRec* OutParms, FFrame* Stack) override
	{
		check(!HasAnyFlags(RF_ClassDefaultObject));
		AActor* Owner = GetOwningActor();
		UNetDriver* NetDriver = Owner->GetNetDriver();
		if (NetDriver)
		{
			NetDriver->ProcessRemoteFunction(Owner, Function, Params, OutParms, Stack, this);
			return true;
		}
		return false;
	}
};
