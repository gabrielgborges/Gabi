#pragma once
#include "libUnicornio.h"
class Tiro
{
public:
	Tiro();
	~Tiro();
	int getX();
	int getY();
	bool getVivo();
	Sprite getSprite();

	void inicializar();
	void atualizar();
	void desenhar();
	void morrer();
	void disparar(float x, float y, int direcao);

private:
	float x, y, velocidade;
	Sprite sprite;
	bool vivo;
	int direcao;
};

