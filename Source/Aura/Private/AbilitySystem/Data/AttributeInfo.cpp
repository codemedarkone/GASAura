// CopyRight Red Project


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound /*= false*/) const
{
	for (const FAuraAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cant find info for attributeTag: [%s] on AttributeInfo [%s]."), *AttributeTag.ToString(), *GetNameSafe(this)); 
	}

	return FAuraAttributeInfo();
}
