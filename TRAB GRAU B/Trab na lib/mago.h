#pragma once
#include "Tiro.h"
#include <fstream>
class mago
{
public:
	mago();
	~mago();
	int pontuacao;
	
	fstream arquivo;
	void inicializar(string nome, string caminho);
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
	int getPontuacao();
	void setPontuacao(int p);
	void mostrarPontuacao( );
	void perderVida(int dano);
	int getVida();

private:
	Tiro tiro;
	Sprite sprite;
	int x, y, direcao, top1, vida;
};



