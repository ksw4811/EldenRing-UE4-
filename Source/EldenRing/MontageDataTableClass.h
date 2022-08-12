// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "MontageDataTableClass.generated.h"

USTRUCT(BlueprintType)
struct FMontageDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// 몽타주
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* MyMontage;

	// 애니메이션
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class UAnimInstance> MyAnimation;
};

UCLASS()
class ELDENRING_API AMontageDataTableClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMontageDataTableClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
