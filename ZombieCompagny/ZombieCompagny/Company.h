#pragma once
#include "Employee.h"
#include <vector>

using namespace std;

class Company
{
public:
	vector<Employee> employeeInCompagny;

	Company();

	void InfectEmployee(int employeeId);
	bool CheckIsEmployeeZombified(int employeeId);
	int CountEmployeeZombified();
	void IncubateEmployee();
	void ZombifiedEmployee();
};