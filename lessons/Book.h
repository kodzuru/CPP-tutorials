#pragma once
#include <string>



typedef unsigned int ui;
class Book
{
private:
	std::string Name;
	std::string Author;
	ui PopularIndex;
public:
	Book();
	Book(std::string, std::string, ui);
	~Book();
	void setName(std::string);
	std::string getName();
	void setAuthor(std::string);
	std::string getAuthor();
	void setPopularIndex(ui);
	ui getPopularIndex();
	Book whatPopular(Book& book);
	void Print(std::ostream& os);
};

