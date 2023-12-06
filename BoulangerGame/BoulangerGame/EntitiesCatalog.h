#pragma once
#include "Ingredient.h"
#include "Food.h"
#include "GlobalHeader.h"

class EntitiesCatalog
{
public:
	void SetCatalog();
	float ReturnIngredientPrice(int ID);
	string ReturnIngredientName(int ID);
	Ingredient ReturnIngredient(int ID);

	string ReturnFoodName(int ID);
};