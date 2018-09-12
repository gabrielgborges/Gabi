#pragma once
#include "itemDaoImp.h"

class itemDao : public itemDaoImp
{
public:
	itemDao();
	~itemDao();


	virtual void inserirItem(std::ostream & os) override;
	virtual void inserirItemEm(std::ostream & os, int indice) override;
	virtual void carregaItens(std::istream & is) override;
};

