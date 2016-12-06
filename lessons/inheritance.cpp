#include "inheritance.h"
//Account
Account::Account():Name(""), ID("№0"),Balance(0)
{	
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

std::ostream& operator<<(std::ostream& os, const Account& a) {
	os << "Номер счёта: " << a.ID << std::endl;
	os << "Имя владельца счёта: " << a.Name << std::endl;
	os << "Баланс на счету: " << a.Balance << std::endl;
	return os;
}

//ExtraAccount
// после : вызывается до инициализации конструктора ExtraAccount
// после : задаются параметры по умолчанию debt(можно задать явно в конструкторе)
// Oveer - константа.Должна быть инициализирована до использования. Обязательно задаётся после :
ExtraAccount::ExtraAccount():Over(20000), debt(0), Account()
{
}
//вызывается конструктор с такими параметрами. Эти параметры передаются в конструктор родительского класса
// и добавляются параметры дочернего класса(ExtraAccount)
//аргументы переданные в конструктор ExtraAccount будут переданы в конструктор Account
ExtraAccount::ExtraAccount(char* id, char* name, ui b): Account(id, name, b), Over(20000), debt(0)
{

}
std::ostream& operator<<(std::ostream& os, ExtraAccount& a)
{
	os << "Номер счёта: " << a.getID() << std::endl;
	os << "Имя владельца счёта: " << a.getName() << std::endl;
	os << "Баланс на счету: " << a.getBalance() << std::endl;
	os << "Долг: " << a.debt << std::endl;
	os << "Предел возможного съёма: " << a.Over << std::endl;
	return os;
}

bool ExtraAccount::takeMoney(ui sum)
{
	if (debt > 0.0) {
		return false;
	}
	//this(производный класс), а у него есть методы базового класса
	//ещё можно Account::getBalance() т.к. в производном классе в конструкторе создаётся объект класса Account
	if (sum < Account::getBalance()) {
		Account::takeMoney(sum);// или Account::takeMoney()
		return true;
	}
	if (sum - Account::getBalance() <= Over) {
		
		debt = sum - Account::getBalance() + (sum - Account::getBalance())*0.15;
		Account::setBalance(0);
		return true;
	}
	return false;
}

bool ExtraAccount::addBalance(ui sum)
{
	if (debt == 0) {
		Account::addBalance(sum);
		return true;
	}
	else {
		if (sum <= debt) {
			debt -= sum;
			return true;
		}
		else {			
			Account::setBalance(sum - debt);
			debt = 0;
			return true;
		}
	}
	return false;
}