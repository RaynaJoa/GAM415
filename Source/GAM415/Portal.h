// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/BoxComponent.h"
#include "Portal.generated.h"

class GAM415Character;


UCLASS()
class GAM415_API APortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Spawn portals
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;

	//Screen Capture feature
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneCaptureComponent2D* sceneCapture;

	//Rendering 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextureRenderTarget2D* renderTarget;

	//To spawn box component
	UPROPERTY(EditAnywhere)
		UBoxComponent* boxComp;
	
	//Edit portals anywhere
	UPROPERTY(EditAnywhere)
		APortal* OtherPortal;

	//Material interface for portal
	UPROPERTY(EditAnywhere)
		UMaterialInterface* mat;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void SetBool(AGAM415Character* playerChar);

	UFUNCTION()
		void UpdatePortals();




};
