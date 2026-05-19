// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAM415Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

UCLASS(config=Game)
class AGAM415Projectile : public AActor
{
	GENERATED_BODY()

private:
	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	//Creating ball mesh to be used for coding
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ballMesh;

	//Creating the material for the ball mesh to be used
	UPROPERTY(EditAnywhere)
		UMaterial* baseMat;

	//To call random color before direct hit
	UPROPERTY()
		FLinearColor randColor;

	//Creating projectile material 
	UPROPERTY(EditAnywhere)
		UMaterialInterface* projMat;

	//Creating material dynamic for projectile
	UPROPERTY()
		UMaterialInstanceDynamic* dmiMat;

	//Creating partacles affect after shooting
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* colorP;


public:
	AGAM415Projectile();

	//Implemented begin play function
protected:
	virtual void BeginPlay();

public:
	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

