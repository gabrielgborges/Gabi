#include "ladrao.h"


ladrao::ladrao()
{
	vida = 100;
}

ladrao::~ladrao()
{
}

void ladrao::inicializar(string nome, string caminho, int xis, int yi)
{
	if (!gRecursos.carregouSpriteSheet(nome))
	{
		gRecursos.carregarSpriteSheet(nome, caminho, 4, 4); // carrega a sprite do personagem (nro de animacoes, nro de frames da maior animacao)
	}
	sprite.setSpriteSheet(nome); // posiciona o personagem na tela
	x = xis;
	y = yi;


	tiro.inicializar();
}

void ladrao::atualizar()
{


	direcao = 1;

	//atirar
	if ( tiro.getVivo() == false)
	{
		tiro.disparar(x, y, direcao);
	}


	tiro.atualizar();
}

void ladrao::desenhar()
{
	sprite.desenhar(x, y);
	tiro.desenhar();
}

void ladrao::matarTiro()
{
	tiro.morrer();
}

Sprite ladrao::getSpriteTiro()
{
	return tiro.getSprite();
}

int ladrao::getXTiro()
{
	return tiro.getX();
}

int ladrao::getYTiro()
{
	return tiro.getY();
}

Sprite ladrao::getSprite()
{
	return sprite;
}

int ladrao::getX()
{
	return x;
}

int ladrao::getY()
{
	return y;
}

void ladrao::setX(int novoX)
{
	x = novoX;
}

void ladrao::setY(int novoY)
{
	y = novoY;
}

int ladrao::getDirecao()
{
	return direcao;
}

int ladrao::getVida()
{
	return vida;
}

void ladrao::perderVida()
{
	vida = vida - 33;
}
