#include "Inventory.h"

void Inventory::AddIngredient(int ingredientId) {
	ingredientCount[ingredientId]++;
}
void Inventory::AddFood(int foodId) {
	foodCount[foodId]++;
}

void Inventory::RemoveIngredient(int ingredientId) {
	ingredientCount[ingredientId]--;
}
void Inventory::RemoveFood(int foodId) {
	foodCount[foodId]--;
}

void Inventory::SaidIngredientInInventory(EntitiesCatalog entitiesCatalog) {
	system("cls");

	cout << "You actually have :" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << ingredientCount[i] << " " << entitiesCatalog.ReturnIngredientName(i) << endl;
	}
	
	cout << "\n\rAnd..." << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << foodCount[i] << " " << entitiesCatalog.ReturnIngredientName(i) << endl;
	}
}