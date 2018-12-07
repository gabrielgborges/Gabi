#include <iostream>
#include "Inventario.h"
#include "Login.h"
#include <string>

using namespace std;

int main()
{
	Login menu;
	menu.menu();

	if (menu.TESTE() == 1) {
		Inventario inventario;
		inventario.leInventario(menu.getUsuario());
		inventario.usaItem(3);
		inventario.usaItem(4);
		inventario.salvaInventario();
	}

	system("pause");
}