#pragma once
#include "libUnicornio.h"
#include "guerreiro.h"
#include "ladrao.h"
#include "mago.h"
#include "guerreiroh.h"

class Jogo:public personagem
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();
	

private:
	personagem * Personagem_atual;
	guerreiro *Guerreiro;
	guerreiroh *Guerreiroh;
	ladrao *Ladrao;
	mago *Mago;
	TileMap mapa;
	int dirx = 200, diry = 100,dir = 0, dirmx=dirx,dirmy=diry;
	int x = 0, y = 0;
	Sprite sprG;
	int v,h;
};

