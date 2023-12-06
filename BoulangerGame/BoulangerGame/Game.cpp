#include "Game.h"
#include "Inventory.h"

void Game::SetShop() {
	for (int i = 0; i < 5; i++)
	{
		ingredientsInShopCount[i] = rand() % 5 + 5;
	}
}

void Game::BuyInShop() {
	cin >> playerInput;
	if (playerInput == "1") {
		cout << "How many " << entitiesCatalog.ReturnIngredientName(0) << " would you want to buy ?" << endl;
		BuyIngredient(0);
	}
	else if (playerInput == "2") {
		cout << "How many " << entitiesCatalog.ReturnIngredientName(1) << " would you want to buy ?" << endl;
		BuyIngredient(1);
	}
	else if (playerInput == "3") {
		cout << "How many " << entitiesCatalog.ReturnIngredientName(2) << " would you want to buy ?" << endl;
		BuyIngredient(2);
	}
	else if (playerInput == "4") {
		cout << "How many " << entitiesCatalog.ReturnIngredientName(3) << " would you want to buy ?" << endl;
		BuyIngredient(3);
	}
	else if (playerInput == "5") {
		cout << "How many " << entitiesCatalog.ReturnIngredientName(4) << " would you want to buy ?" << endl;
		BuyIngredient(4);
	}
	else {
		cout << "You whrite an unexistant number in this context..." << endl;
		BuyInShop();
	}
}
void Game::BuyIngredient(int ingredientId) {
	cin >> playerInput;
	int playerInputInt = stof(playerInput);

	int currentIngredientCount = ingredientsInShopCount[ingredientId];
	float ingredientPrice = entitiesCatalog.ReturnIngredientPrice(ingredientId);

	if (playerInputInt < 1) {
		cout << "You can not buy less than 1 " << entitiesCatalog.ReturnIngredientName(ingredientId) << "..." << endl;
		BuyIngredient(ingredientId);
	}
	else if (playerInputInt > currentIngredientCount) {
		cout << "There is not this amount of " << entitiesCatalog.ReturnIngredientName(ingredientId) << " today... \n\rSelect an other amount..." << endl;
		BuyIngredient(ingredientId);
	}
	else if (playerInputInt * entitiesCatalog.ReturnIngredientPrice(ingredientId) > moneyCount) {
		cout << "You dont have enough money" << endl;
		BuyIngredient(ingredientId);
	}
	else {
		Ingredient ingredientBuy = entitiesCatalog.ReturnIngredient(ingredientId);

		for (int i = 0; i < playerInputInt; i++)
		{
			inventory.AddIngredient(ingredientId);
		}

		cout << "You have bought " << playerInputInt << " " << entitiesCatalog.ReturnIngredientName(ingredientId) << endl;

		ingredientsInShopCount[ingredientId] -= playerInputInt;
		moneyCount -= playerInputInt * entitiesCatalog.ReturnIngredientPrice(ingredientId);
	}

	if (ContinueTheAction()) {
		SaidShopIngredient();
	}
	else {
		currentPhase = Phase::InShop;
		GoToTheKitchen();
	}
}
void Game::SaidShopIngredient() {
	system("cls");

	cout << "In the shop today, there is..." << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << " : " << entitiesCatalog.ReturnIngredientName(i) << " for " << entitiesCatalog.ReturnIngredientPrice(i) << " dollar, x" << ingredientsInShopCount[i] << endl;
	}

	cout << "\n\rSelect wich ingredient you want to buy" << endl;
	cout << "You have " << moneyCount << " dollar" << endl;

	BuyInShop();
}

void Game::GoToTheKitchen() {
	currentPhase = Phase::InKitchen;

	inventory.SaidIngredientInInventory(entitiesCatalog);
} 
bool Game::ContinueTheAction() {
	switch (currentPhase)
	{
	case InShop:
		cout << "\n\rWould you continue to buy some ingredient ?" << endl;
		break;
	case InKitchen:
		cout << "Would you continue to cooke ?" << endl;
		break;
	case InYourMarket:
		cout << "Would you close your bakery ?" << endl;
		break;
	}

	cout << "1 : Yes" << endl;
	cout << "2 : No" << endl;

	cin >> playerInput;

	if (playerInput == "1") return true;
	else if (playerInput == "2") return false;
	else {
		cout << "You whrite an unexistant number in this context..." << endl;
		ContinueTheAction();
	}
}