#include "String.h"



String::String():str(NULL), length(0)//конструктор по умолчанию
{

}
String::String(char *s)//явный конструктор
{
	number_elem++;
	std::cout << number_elem << std::endl;
	length = strlen(s);
	str = new char[length + 1];
	for (ui i(0); i < length; i++) {
		str[i] = s[i];
	}
	str[length] = '\0';
}
String::String(const String& s)//конструктор копирования
{
	length = strlen(s.str);
	str = new char[length + 1];
	for (ui i(0); i < length; i++) {
		str[i] = s.str[i];
	}
	str[length] = '\0';
}
String::~String()
{
	number_elem--;
	std::cout << number_elem << std::endl;
	delete[] str;
}
std::ostream& operator<<(std::ostream& os, const String& s) {
	if (s.str == NULL) {
		os << "NULL" << std::endl;
		return os;
	}
	else {
		os << s.str << std::endl;
		return os;
	}
}
String& String::operator=(const String& s) // перегурузка оператора присваивания
{
	delete[] str; //удаление адреса 0x1
	length = strlen(s.str);
	str = new char[length + 1];
	for (ui i(0); i < length; i++) {
		str[i] = s.str[i];
	}
	str[length] = '\0';
	return *this;
}
String::operator char *()// оператор явного преобразования типов
{
	char* str = new char[this->length + 1];
	for (ui i(0); i < length; i++) {
		str[i] = this->str[i];
	}
	str[this->length] = '\0';
	return str;
}