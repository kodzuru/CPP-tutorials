#include "Account.h"


namespace Programm
{
	Account::Account()
	{
		Name = "";
		ID = "№0";
		Balance = 0;
	}
	Account::Account(char* id, char* name, ui b)
	{
		Name = name;
		ID = id;
		if (b < Max) {
			Balance = b;
		}
		else {
			Balance = 0;
		}
	}
	Account::~Account()
	{
	}
	void Account::setID(char* id) 
	{
		ID = id;
	}
	char* Account::getID()
	{
		return ID;
	}
	void Account::setName(char* name)
	{
		Name = name;
	}
	char* Account::getName()
	{
		return Name;
	}
	void Account::setBalance(ui b)
	{
		if (b < Max) {
			Balance = b;
		}
		else {
			Balance = 0;
		}
		
	}
	ui Account::getBalance()
	{
		return Balance;
	}

	bool Account::addBalance(ui add)
	{
		if (Balance + add < Max) {
			Balance += add;
			return true;
		}
		else {
			Balance = Balance;
			return false;
		}
		
		
	}
	bool Account::takeMoney(ui take)
	{
		if (take <= Balance) {
			Balance -= take;
			return true;
		}
		else {
			return false;
		}
	}

	Account Account::MAX(Account & a)
	{
		if (Balance < a.getBalance()) {
			return a;
		}
		else {
			return *this;
		}
	}
}