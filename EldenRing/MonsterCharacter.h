// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterCharacter.generated.h"

UCLASS()
class ELDENRING_API AMonsterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonsterCharacter();

	//UPROPERTY(VisibleInstanceOnly, Category = Animation)
		//class UAIAnimInstance* AIAnim;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackPower;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRange;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float AttackRadius;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float SkillPower;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float SkillRange;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		float SkillRadius;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Speed, Meta = (AllowPrivateAccess = true))
		float MonsterSpeed;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool bCanAttack;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = HP, Meta = (AllowPrivateAccess = true))
		float fAIHp;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = HP, Meta = (AllowPrivateAccess = true))
		float fMaxHp;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
		int nMonsterType;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
		bool bAlive;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
		bool bUIPrint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FString strMonsterType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FString strMonsterItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* DeathSound;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* AttackMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* IntroMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* SkillMontage;

	UPROPERTY(VisibleInstanceOnly, Category = Animation)
		class UMonsterInstance* MonsterAnim;

	UPROPERTY()
		class UParticleSystem* AttackParticle;

	UPROPERTY()
		class UParticleSystem* IntroParticle;

	UPROPERTY()
		class UParticleSystem* SkillParticle;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* ParticleMuzzleLocation;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* IntroParticleMuzzleLocation;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* ProjectileMuzzle;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AMonsterProjectile> ProjectileClass;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AMonsterItem> MonsterItemClass;

	//UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		//USceneComponent* AttackParticleLocation;

	//UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = HP, Meta = (AllowPrivateAccess = true))
		//class UWidgetComponent* AIWidget;

	//UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = HP, Meta = (AllowPrivateAccess = true))
		//class UStaticMeshComponent* HPStatic;

	//UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = HP, Meta = (AllowPrivateAccess = true))
		//class UAIHPBar_UW* MonsterHpBar;

	//UPROPERTY(EditDefaultsOnly, Category = HP)
	//	TSubclassOf<class UUserWidget> MONSTER_HPClass;

	//UPROPERTY(EditDefaultsOnly, Category = HP)
		//TSubclassOf<class UAIHPBar_UW> MONSTER_HPTClass;

	// damage particle
	UPROPERTY()
		class UParticleSystem* DamageParticle;

	UPROPERTY()
		class UGameplayStatics* GameStatic;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PostInitializeComponents() override;

	float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamasgeCauser) override;

	void Attack();
	void Skill();
	void AttackEnd();
	void SkillEnd();
	void AttackCheck();
	void SkillCheck();
	//void AttackCheck();
	//void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	//void AttackByPlayer(float DamageAmount);
	void MoveMonster();
	//void FindPlayer();
	void StopMonster();
	void StopAIController();
	void InitializeAI(FString MonsterType);
	void AttackParticleStart(FVector StartParticle);
	void IntroParticleStart();
	void SkillParticleStart();
	void SkillParticleEnd();
	void DropItem();
	void MonsterDestory();
};
