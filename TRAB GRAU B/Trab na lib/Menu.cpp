#include "Menu.h"



Menu::Menu()
{

}


Menu::~Menu()
{
}

void Menu::desenhaMenu()
{
	for (int i = 0; i < 5; i++) {
		if (m_opcoes[i] != "") {
			std::cout << i << " - " << m_opcoes[i] << std::endl;
		}
	}
}
