#pragma once
#include "EntitiesCatalog.h"
#include "Inventory.h"
#include "GlobalHeader.h"

class Game
{
public:
	enum Phase
	{
		InShop,
		InKitchen,
		InYourMarket
	};

	EntitiesCatalog entitiesCatalog;
	Inventory inventory;

	int ingredientsInShopCount[5] = { 0,0,0,0,0 };

	float moneyCount = 10;

	Phase currentPhase = Phase::InShop;

	string playerInput;

	bool ContinueTheAction();

	void SetShop();
	
	void BuyInShop();
	void BuyIngredient(int ingredientId);
	void SaidShopIngredient();

	void GoToTheKitchen();
};

