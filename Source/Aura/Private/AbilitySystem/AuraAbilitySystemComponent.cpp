// Copyright wyzn12


#include "AbilitySystem/AuraAbilitySystemComponent.h"

#include "AuraGameplayTags.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	if (IsValid(this))
	{
		OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
		const auto GameplayTags = FAuraGameplayTags::Get();
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Cyan,
			FString::Printf(TEXT("Tag: %s"), *GameplayTags.Attribute_Secondary_Armor.ToString()));
	}
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	EffectAssetTags.Broadcast(TagContainer);
}
