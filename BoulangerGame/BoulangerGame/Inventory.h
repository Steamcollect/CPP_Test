#pragma once
#include "Ingredient.h"
#include "Food.h"
#include "EntitiesCatalog.h"
#include "GlobalHeader.h";

class Inventory
{
public:
	int moneyCount = 0;

	int ingredientCount[5] = { 0,0,0,0,0 };

	int foodCount[3] = { 0,0,0 };

	void AddIngredient(int ingredientId);
	void AddFood(int foodId);
	void RemoveIngredient(int ingredientId);
	void RemoveFood(int foodId);
	void SaidIngredientInInventory(EntitiesCatalog entitiesCatalog);
};