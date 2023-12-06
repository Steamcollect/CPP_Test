#include "Company.h"

Company::Company() {
	for (int i = 0; i < 100; i++)
	{
		employeeInCompagny.push_back(*new Employee());
		employeeInCompagny[i].ResetEmployeeStats();
	}
}
void Company::InfectEmployee(int employeeId) {
	employeeInCompagny[employeeId].SetNewZombieficationState();
}
bool Company::CheckIsEmployeeZombified(int employeeId) {
	return employeeInCompagny[employeeId].CheckIsZombified();
}
int Company::CountEmployeeZombified() {
	int employeeZombifiedCount = 0;

	for (int i = 0; i < 100; i++)
	{
		if (employeeInCompagny[i].CheckIsZombified()) employeeZombifiedCount += 1;
	}
	return employeeZombifiedCount;
}

void Company::IncubateEmployee() {
	for (int i = 0; i < 100; i++)
	{
		if (!employeeInCompagny[i].CheckIsInIncubation() && !employeeInCompagny[i].CheckIsZombified()) {
			employeeInCompagny[i].SetNewZombieficationState();
			break;
		}
	}
}
void Company::ZombifiedEmployee() {
	for (int i = 0; i < 100; i++)
	{
		if (!employeeInCompagny[i].CheckIsInIncubation() && !employeeInCompagny[i].CheckIsZombified()) {
			employeeInCompagny[i].SetNewZombieficationState();
			employeeInCompagny[i].SetNewZombieficationState();
			break;
		}
	}
}