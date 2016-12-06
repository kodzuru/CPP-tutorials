#include "Book.h"

using namespace std;

Book::Book()
{
	Name = "Имя книги не задано";
	Author = "Имя автора не задано";
	PopularIndex = 0;
}
Book::Book(string name, string a, ui pi)
{
	Name = name;
	Author = a;
	PopularIndex = pi;
}

Book::~Book()
{
}
void Book::setName(string name)
{
	Name = name;
}
string Book::getName()
{
	return Name;
}
void Book::setAuthor(string a)
{
	Author = a;
}
string Book::getAuthor()
{
	return Author;
}
void Book::setPopularIndex(ui pi)
{
	PopularIndex = pi;
}
ui Book::getPopularIndex()
{
	return PopularIndex;
}
Book Book::whatPopular(Book& book) 
{
	if (book.getPopularIndex() > PopularIndex) {
		return book;
	}
	else {
		return *this;
	}
}
void Book::Print(ostream& os)
{
	os << "Автор: " << Author << endl;
	os << "Название книги: " << Name << endl;
	os << "Индекс популярности: " << PopularIndex << endl;
	os << "-------------------------------" << endl;
}