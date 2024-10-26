// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Treasure.generated.h"

UCLASS()
class TREASUREGAME_API ATreasure : public AInteractable
{
	GENERATED_BODY()

public:
	ATreasure();

	virtual void Interact() override;

private:
	UPROPERTY(EditAnywhere, Category = "Interact");
	int32 TreasureValue;
	
};
