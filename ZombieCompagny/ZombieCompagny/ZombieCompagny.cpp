#include <iostream>
#include "Company.h"
#include "Employee.h"

using namespace std;

Company compagny = *new Company();
int moneyGain = 0;
string playerInput;

void LaunchDice() {
	int dice1;
	int dice2;
	int numberFound;
	cout << "'B' to launch dice..." << endl;
	cin >> playerInput;
	if (playerInput == "b" || playerInput == "B") {
		dice1 = 1 + rand() % (6 - 1);
		cout << "Dice 1 : " << dice1 << endl;
		dice2 = 1 + rand() % (6 - 1);
		cout << "Dice 2 : " << dice2 << endl;

		numberFound = dice1 + dice2;

		if (numberFound == 12) {
			cout << "You've stumbled upon " << numberFound << ", so 4 san employees was zombified" << endl;
			for (int i = 0; i < 4; i++)
			{
				compagny.ZombifiedEmployee();
			}
		}
		else if (numberFound <= 11 && numberFound >= 7) {
			cout << "You've stumbled upon " << numberFound << ", so 2 san employees was infected" << endl;
			for (int i = 0; i < 2; i++)
			{
				compagny.IncubateEmployee();
			}
		}
		else if (numberFound <= 6 && numberFound >= 3) {
			cout << "You've stumbled upon " << numberFound << ", so 1 san employee was infected" << endl;
			compagny.IncubateEmployee();
		}
	}
	else {
		cout << "You write the wrong letter... please retry." << endl;
		LaunchDice();
	}
}

int main()
{
	srand(time(0));

	for (int i = 1; i < 29; i++)
	{
		if(i == 0)compagny.InfectEmployee(0);

		for (int i = 0; i < 100; i++)
		{
			if (compagny.employeeInCompagny[i].CheckIsInIncubation() || compagny.employeeInCompagny[i].CheckIsZombified()) {
				compagny.employeeInCompagny[i].HandleInfection();

				if (compagny.employeeInCompagny[i].CheckIsInIncubation()) moneyGain += 45000 / 228;
			}
			else {
				int tmp = rand() % 101;
				if(tmp <= compagny.CountEmployeeZombified())compagny.employeeInCompagny[i].SetNewZombieficationState();

				moneyGain += 26000 / 228;
			}
		}

		LaunchDice();
		cout << "Day " << i << " : " << compagny.CountEmployeeZombified() << "% infected" << endl;
	}

	cout << "You lost " << moneyGain << "$ during this month" << endl;
}