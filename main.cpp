#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

class Document
{
public:
	virtual void show() = 0;

};

class TextDocument : public Document
{
public:
	void show()
	{
		std::cout << "This is text document" << std::endl;
	}
};

class PictureDocument : public Document
{
public:
	void show()
	{
		std::cout << "This is picture" << std::endl;
	}
};

class Creator
{
public:
	virtual Document* create() = 0;
};

class TextDocumentCreator : public Creator
{
public:
	Document* create() override
	{
		return new TextDocument();
	}
};

class PictureDocumentCreator : public Creator
{
public:
	Document* create() override
	{
		return new PictureDocument();
	}
};



int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	srand(time(NULL));

	Creator *creator = new TextDocumentCreator();
	Document* myDocument = creator->create();
	creator = new PictureDocumentCreator();
	Document* myDocument2 = creator->create();

	myDocument->show();
	myDocument2->show();
	return 0;
}
