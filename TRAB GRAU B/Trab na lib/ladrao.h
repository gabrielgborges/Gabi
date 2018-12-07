#pragma once
#include "Tiro.h"
class ladrao
{
public:
	ladrao();
	~ladrao();
	

	void inicializar(string nome, string caminho, int xis, int yi);
	void atualizar();
	void desenhar();

	void matarTiro();
	Sprite getSpriteTiro();
	int getXTiro();
	int getYTiro();

	Sprite getSprite();
	int getX();
	int getY();
	void setX(int novoX);
	void setY(int novoY);
	int getDirecao();
	int getVida();
	void perderVida();

private:
	Texto texto;
	Sprite sprite;
	int x, y, direcao, pontuacao, vida;
	Tiro tiro;

};



