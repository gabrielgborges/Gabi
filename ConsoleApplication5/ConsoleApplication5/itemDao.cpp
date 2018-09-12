#include "stdafx.h"
#include "itemDao.h"


itemDao::itemDao()
{
}


itemDao::~itemDao()
{
}


void itemDao::inserirItem(std::ostream & os, Item item_atual)
{

	os.write(reinterpret_cast<char*>(&item_atual), sizeof(Item));
}

void itemDao::inserirItemEm(std::ostream & os, int indice)
{
	std::streampos pos(indice * sizeof(Item));
	os.seekp(pos);
	std::cout << "O item será escrito na posição: " << os.tellp() << std::endl;
	os.write(reinterpret_cast<char*>(&item_atual), sizeof(Item));
}


void itemDao::carregaItens(std::istream & is)
{
	int indice = 0;
	while (!is.eof()) {

		is.read(reinterpret_cast<char *>(&inventario[indice]), sizeof(Item));
		if (is.gcount() == 0) break;
		std::cout << "Id: " << inventario[indice].id << "Peso: " << inventario[indice].peso << "Tipo: " << inventario[indice].tipo << std::endl;
		indice++;

	}
