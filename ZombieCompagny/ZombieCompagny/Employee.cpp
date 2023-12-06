#include "Employee.h"

void Employee::ResetEmployeeStats() {
	zombificationState = ZombificationState::SANE;
	roundCounter = 0;
	incubationTime = 0;
}

bool Employee::CheckIsInIncubation() {
	switch (zombificationState)
	{
	case Employee::SANE:
		return false;
	case Employee::INCUBATING:
		return true;
	case Employee::ZOMBIFIED:
		return false;
	}
}
bool Employee::CheckIsZombified() {
	switch (zombificationState)
	{
	case Employee::SANE:
		return false;
	case Employee::INCUBATING:
		return false;
	case Employee::ZOMBIFIED:
		return true;
	}
}

void Employee::HandleInfection() {
	if (roundCounter == incubationTime) Employee::SetNewZombieficationState();
	if (Employee::CheckIsInIncubation() || Employee::CheckIsZombified()) {
		roundCounter += 1;
	}
}

void Employee::SetNewZombieficationState() {
	switch(zombificationState) {
	case Employee::SANE:
		zombificationState = Employee::ZombificationState::INCUBATING;
		incubationTime = 2 + rand() % (5 - 2);
		break;
	case Employee::INCUBATING:
		zombificationState = Employee::ZombificationState::ZOMBIFIED;
		break;
	case Employee::ZOMBIFIED:
		zombificationState = Employee::ZombificationState::ZOMBIFIED;
		break;
	}
}