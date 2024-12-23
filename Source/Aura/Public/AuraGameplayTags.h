// Copyright wyzn12

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/** FAuraGameplayTags
 * 
 *  Singleton containing native Gameplay Tags 
 */

struct FAuraGameplayTags
{
public:
	static const FAuraGameplayTags& Get() { return Instance; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attribute_Secondary_Armor;
	
protected:

private:
	static FAuraGameplayTags Instance;
};
