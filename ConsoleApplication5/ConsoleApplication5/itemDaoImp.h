#pragma once
#include <iostream>
#include "Item.h"
class itemDaoImp
{

public:
	itemDaoImp();
	~itemDaoImp();


	virtual void inserirItem(std::ostream & os, Item item_atual) = 0;
	virtual void inserirItemEm(std::ostream & os, int indice) = 0;
	virtual void carregaItens(std::istream & is) = 0;


};

