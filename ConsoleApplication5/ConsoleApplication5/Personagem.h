#pragma once
#include "Item.h";
#include "itemDao.h"
class Personagem : public itemDao
{
public:
	Personagem();
	~Personagem();

	Item inventario[10];
	Item item_atual;
	



};
