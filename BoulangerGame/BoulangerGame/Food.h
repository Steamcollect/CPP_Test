#pragma once
#include "GlobalHeader.h"

class Food
{
public:
	string name = "";
	float price = 0;

	string ingredientRequire[];

	void SetFood(string nam, float price, string ingredientRequire[]);
};