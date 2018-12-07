#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Login.h"
using namespace std;

class Inventario
{
public:
	Inventario();
	~Inventario();

	void usaItem(int index);
	void addItem(int index);
	void removeItem(int index);
	void esvazia();
	void leInventario(string usu);
	void salvaInventario();

private:
	map<string, string> inventario;
	string inventarioIndex[5] = { "0", "0", "0", "0", "0" };
	ifstream inventarioFileIn;
	ofstream inventarioFileOut;
	Login usuario;
	string usuarioNome;
	string usuarioAux;

};

