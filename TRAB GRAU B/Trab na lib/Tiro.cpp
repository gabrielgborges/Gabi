#include "Tiro.h"



Tiro::Tiro()
{
}


Tiro::~Tiro()
{
}

int Tiro::getX()
{
	return x;
}

int Tiro::getY()
{
	return y;
}

bool Tiro::getVivo()
{
	return vivo;
}

Sprite Tiro::getSprite()
{
	return sprite;
}

void Tiro::inicializar()
{//carregar o sprite do tiro
	if (!gRecursos.carregouSpriteSheet("tiro"))
	{
		gRecursos.carregarSpriteSheet("tiro", "assets/spritesheets/fireballmini.png");
	}
	sprite.setSpriteSheet("tiro");
	velocidade = 1;
	vivo = false;
}




void Tiro::atualizar()
{
	if (vivo)
	{
		if (direcao == 1) //direita
		{
			x += velocidade + 2;
		}
		else if (direcao == 3) //cima
		{
			y -= velocidade + 2;
		}
		else if (direcao == 0) //baixo
		{
			y += velocidade + 2;
		}
		else //esquerda
		{
			x -= velocidade + 2;
		}

		if (x < sprite.getLargura() || x > gJanela.getLargura() + sprite.getLargura() || y < sprite.getLargura() || y > gJanela.getAltura() + sprite.getAltura())
		{
			vivo = false;
			//morrer();
		}
	}
}

void Tiro::desenhar()
{
	if (vivo)
	{
		sprite.desenhar(x, y);
	}
}

void Tiro::morrer()
{
	vivo = false;//destruir o tiro
}

void Tiro::disparar(float x, float y, int direcao)
{
	this->x = x;
	this->y = y;
	this->direcao = direcao;
	vivo = true;

}
