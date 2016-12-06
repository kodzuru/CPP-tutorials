#pragma once

//инкапсуляция - закрытие параметров.
namespace Programm 
{
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
		Account(char* id = "№ 0", char* name = "", ui balance = 0); //с аргументами по умолчанию(указывются только в прототипе)
		~Account();

		void setID(char*);
		char* getID();
		void setName(char*);
		char* getName();
		void setBalance(ui);
		ui getBalance();

		bool addBalance(ui);
		bool takeMoney(ui);

		Account MAX(Account &);


	};
}


