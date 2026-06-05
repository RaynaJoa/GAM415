// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PerlinProcTerrian.generated.h"

class UProceduralMeshComponent;
class UMaterialInterface;

UCLASS()
class GAM415_API APerlinProcTerrian : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerlinProcTerrian();

	//Set up X size for terrian 
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
		int XSize = 0;

	//Set up Y size for terrian 
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
		int YSize = 0;

	//Set up Z size for terrian
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = 0))
		float ZMultiplier = 1.0f;

	//Set up noise scale for terrian
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
		float NoiseScale = 1.0f;

	// Scale for terrian 
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0.000001))
		float Scale = 0;

	//UVScale for terrian
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0.000001))
		float UVScale = 0;

	//Radius for terrian
	UPROPERTY(EditAnywhere)
		float radius;

	//Depth for terrian
	UPROPERTY(EditAnywhere)
		FVector Depth;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Material being added to our class
	UPROPERTY(EditAnywhere)
		UMaterialInterface* Mat;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Alter mesh for terrian
	UFUNCTION()
		void AlterMesh(FVector impactPoint);

private:
	UProceduralMeshComponent* ProcMesh;
	TArray<FVector> Vertices;
	TArray<int> Triangles;
	TArray<FVector2D> UV0;
	TArray<FVector> Normals;
	TArray<FColor> UpVertexColors;

	int sectionID = 0;

	void CreateVertices();
	void CreateTriangles();

};
