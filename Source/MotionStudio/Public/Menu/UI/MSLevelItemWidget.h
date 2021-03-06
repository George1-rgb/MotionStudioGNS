// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MSCoreTypes.h"
#include "MSLevelItemWidget.generated.h"

class UButton;
class UTextBlock;
class UImage;
UCLASS()
class MOTIONSTUDIO_API UMSLevelItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FOnLevelSelectedSignature OnLevelSelected;

	void SetLevelData(const FLevelData& Data);
	FLevelData GetLevelData() const { return LevelData; }

	void SetSelected(bool IsSelected);
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* LevelSelectButton;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* LevelNameTextBlock;

	UPROPERTY(meta = (BindWidget))
		UImage* LevelImage = nullptr;

	UPROPERTY(meta = (BindWidget))
		UImage* OpacityImage;

	UPROPERTY(meta = (BindWidget))
		UImage* FrameImage;


	virtual void NativeOnInitialized() override;
private:
	FLevelData LevelData;

	bool IsItemSelected = false;

	UFUNCTION()
	void OnLevelItemClicked();

	UFUNCTION()
	void OnLevelItemSelected();

	UFUNCTION()
	void OnLevelItemUnSelected();
};
