#pragma once
#include "libUnicornio.h"
class personagem: public ObjetoTileMap
{
public:
	personagem();
	virtual ~personagem();
	int grana;
	int ganhar_grana(int x);
	void atualizar();
	void setSpriteSheet(string spritesheet);//setar sprite
	Sprite spr;
	float velo;
	Vetor2D dir;

};

