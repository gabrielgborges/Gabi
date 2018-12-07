#include "pch.h"
#include "Inventario.h"
using namespace std;

Inventario::Inventario()
{

}

Inventario::~Inventario()
{

}

void Inventario::usaItem(int index)
{
	if (inventarioIndex[index] == "1")
		cout << "usou " << index << endl;
	removeItem(index);
}

void Inventario::addItem(int index)
{
	int i = index;
	if (inventarioIndex[i] == "0")
		inventarioIndex[i] = "1";
}

void Inventario::removeItem(int index)
{
	int i = index;
	if (inventarioIndex[i] == "1")
		inventarioIndex[i] = "0";
}

void Inventario::esvazia()
{
	for (int i = 0; i < 5; i++)
		inventarioIndex[i] = "0";
}

void Inventario::leInventario(string usu)
{
	usuarioAux = usu;
	usuarioNome.append(usu);
	usuarioNome.append(".txt");

	inventarioFileIn.open(usuarioNome);
	for (int i = 0; i < 5; i++)
		inventarioFileIn >> inventarioIndex[i];
	inventarioFileIn.close();
}

void Inventario::salvaInventario()
{
	inventarioFileOut.open(usuarioNome, ios::trunc);
	for (int i = 0; i < 5; i++)
		inventarioFileOut << inventarioIndex[i] << endl;
	inventarioFileOut.close();
}






