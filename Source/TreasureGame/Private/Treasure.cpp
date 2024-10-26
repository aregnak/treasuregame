// Fill out your copyright notice in the Description page of Project Settings.


#include "Treasure.h"

#include "Kismet/GameplayStatics.h"
#include "TreasureGame/TreasureGameCharacter.h"

ATreasure::ATreasure()
{
	TreasureValue = 100;

}

void ATreasure::Interact()
{
	Super::Interact();

	ATreasureGameCharacter* Player = Cast<ATreasureGameCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (Player)
	{
		Player->AddScore(TreasureValue);
	}

	Destroy(); // destroy the treasure after collected

}


