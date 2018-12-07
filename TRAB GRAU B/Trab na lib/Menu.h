#pragma once
#include <iostream>
#include <string>
class Menu
{
public:
	Menu();
	~Menu();
	std::string m_opcoes[5];
	int m_opcoes_indice[5];
	void desenhaMenu();
};

