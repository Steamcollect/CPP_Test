#include "EntitiesCatalog.h"

Ingredient* flour = new Ingredient();
Ingredient* cheese = new Ingredient();
Ingredient* olives = new Ingredient();
Ingredient* eggs = new Ingredient();
Ingredient* bakingPowder = new Ingredient();

Food* bread = new Food();
Food* cheeseCake = new Food();
Food* olivesCake = new Food();

vector <Ingredient> ingredientExistant;
vector <Food> foodExistant;

void EntitiesCatalog::SetCatalog() {
	flour->SetIngrdient("Flour", .3);
	ingredientExistant.push_back(*flour);
	cheese->SetIngrdient("Cheese", .2);
	ingredientExistant.push_back(*cheese);
	olives->SetIngrdient("Olives", .1);
	ingredientExistant.push_back(*olives);
	eggs->SetIngrdient("Eggs", .3);
	ingredientExistant.push_back(*eggs);
	bakingPowder->SetIngrdient("Baking_Powder", .15);
	ingredientExistant.push_back(*bakingPowder);

	bread->SetFood("Bread", 1.5, new string[2]{ "Flour", "Baking_Powder" });
	foodExistant.push_back(*bread);
	cheeseCake->SetFood("Cheese_cake", 3.5, new string[3]{ "Flour", "Cheese", "Eggs"});
	foodExistant.push_back(*cheeseCake);
	olivesCake->SetFood("Olive_cake", 5, new string[5]{ "Flour", "Cheese", "Olive", "Eggs", "Baking_Powder"});
	foodExistant.push_back(*olivesCake);
}

float EntitiesCatalog::ReturnIngredientPrice(int ID) {
	return ingredientExistant[ID].price;
}

string EntitiesCatalog::ReturnIngredientName(int ID) {
	return ingredientExistant[ID].name;
}
string EntitiesCatalog::ReturnFoodName(int ID) {
	return foodExistant[ID].name;
}

Ingredient EntitiesCatalog::ReturnIngredient(int ID) {
	return ingredientExistant[ID];
}