// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDataStruct.h"
#include "ItemBase.generated.h"

/**
 * 
 */
UCLASS()
class TREASUREGAME_API UItemBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "ItemData", meta = (UIMin = 1, UIMax = 40))
	int32 Quantity;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FName ID;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemTextData TextData;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemAssetData AssetData;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemNumericData NumericData;

	UItemBase();

	UItemBase* CreateItemCopy();

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemStackWeight() const
	{
		// inline function because it is a small function, which can optimize the code
		return Quantity * NumericData.Weight; 
	};

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemSingleWeight() const
	{
		return NumericData.Weight;
	};

	UFUNCTION(Category = "Item")
	FORCEINLINE bool IsFullItemStack() const
	{
		return Quantity ==  NumericData.MaxStackSize;
	};

	UFUNCTION(Category = "Item")
	void SetQuantity(const int32 NewQuantity);

	UFUNCTION(Category = "Item")
	virtual void Use(ATreasureGameCharacter* Character);

protected:
	bool operator==(const FName& OtherID) const
	{
		return ID == OtherID;
	}
};
