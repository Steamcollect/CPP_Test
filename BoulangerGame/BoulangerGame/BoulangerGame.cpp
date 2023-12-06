#include "EntitiesCatalog.h"
#include "Inventory.h"
#include "Game.h"
#include "GlobalHeader.h"

int main()
{
	Game game = *new Game();
	game.entitiesCatalog.SetCatalog();
	game.SetShop();
	
	game.SaidShopIngredient();
}