#pragma once
#include <iostream>
typedef unsigned int ui;
class Account
{
private:
	char* ID;
	char* Name;
	ui Balance;
	ui Max = 999999; // ???? константа?
public:
	Account();
	Account(char*, char*, ui);
	~Account();

	void setID(char*);
	char* getID();
	void setName(char*);
	char* getName();
	void setBalance(ui);
	ui getBalance();

	virtual bool addBalance(ui);
	virtual bool takeMoney(ui);

	Account MAX(Account &);
	friend std::ostream& operator<<(std::ostream&, const Account&);
};
//public открытое наследование
class ExtraAccount : public Account
{
private:
	const int Over;
	double debt;
public:
	// при создании конструктора всегда вызывается конструктор базового класса
	// будет вызываться конструктор по умолчанию Account()
	ExtraAccount();
	ExtraAccount(char*, char*, ui);

	virtual bool takeMoney(ui);
	virtual bool addBalance(ui);

	friend std::ostream& operator<<(std::ostream&, ExtraAccount&);
};

