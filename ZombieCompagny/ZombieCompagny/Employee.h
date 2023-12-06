#pragma once
#include <iostream>

using namespace std;

class Employee
{
public:
	enum ZombificationState {
		SANE,
		INCUBATING,
		ZOMBIFIED
	};

	int employeeIndex;
	int incubationTime;
	int roundCounter = 0;
	ZombificationState zombificationState;

	void ResetEmployeeStats();

	bool CheckIsInIncubation();
	bool CheckIsZombified();
	void HandleInfection();
	void SetNewZombieficationState();
};