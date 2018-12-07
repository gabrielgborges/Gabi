#include "mago.h"


mago::mago()
{
	
	pontuacao = 0;
	vida = 100;
}

mago::~mago()
{
}

void mago::inicializar(string nome, string caminho)
{
	if (!gRecursos.carregouSpriteSheet(nome))
	{
		gRecursos.carregarSpriteSheet(nome, caminho, 4, 4); // carrega a sprite do personagem (nro de animacoes, nro de frames da maior animacao)
	}
	sprite.setSpriteSheet(nome); // posiciona o personagem na tela
	x = 400;
	y = 300;

	tiro.inicializar();
}

void mago::atualizar()
{
	bool andou = false;


	////se a sprite estiver virada pra esquerda

	////esquerda
	//sprite.setInverterX(false);
	////direita
	//sprite.setInverterX(true);

	if (gTeclado.segurando[TECLA_ESQ])
	{
		andou = true;	// altera o status de andou
		direcao = 2;	// direção para onde o personagem vai se mover
		
		if (pontuacao < 100) 
		{
			x--;			// x-- faz com que a posição se altere no eixo
		}
		else
		{
			x -= 2;
		}
		sprite.setAnimacao(2);		// pega a 3a linha da sprite de personagem
		sprite.avancarAnimacao();	// faz a animacao do personagem
	}
	if (gTeclado.segurando[TECLA_DIR])//direita
	{
		andou = true;
		direcao = 1;
		if (pontuacao < 100)
		{
			x++;			// x-- faz com que a posição se altere no eixo
		}
		else
		{
			x += 2;
		}
		sprite.setAnimacao(1);
		sprite.avancarAnimacao();
	}
	if (gTeclado.segurando[TECLA_CIMA])//cima
	{
		andou = true;
		direcao = 3;
		if (pontuacao < 100)
		{
			y--;			// x-- faz com que a posição se altere no eixo
		}
		else
		{
			y -= 2;
		}
		sprite.setAnimacao(3);
		sprite.avancarAnimacao();
	}
	if (gTeclado.segurando[TECLA_BAIXO])//baixo
	{
		andou = true;
		direcao = 0;
		if (pontuacao < 100)
		{
			y++;			// x-- faz com que a posição se altere no eixo
		}
		else
		{
			y += 2;
		}
		sprite.setAnimacao(0);
		sprite.avancarAnimacao();
	}

	//atirar
	if (gTeclado.pressionou[TECLA_ESPACO] && tiro.getVivo() == false)
	{
		tiro.disparar(x, y, direcao);
	}

	if (!andou)
	{
		if (direcao == 2) // esquerda
			sprite.setFrame(0);

		else
			sprite.setFrame(1);
	}

	tiro.atualizar();
}

void mago::desenhar()
{
	sprite.desenhar(x, y);
	tiro.desenhar();
}

void mago::matarTiro()
{
	tiro.morrer();
}

Sprite mago::getSpriteTiro()
{
	return tiro.getSprite();
}

int mago::getXTiro()
{
	return tiro.getX();
}

int mago::getYTiro()
{
	return tiro.getY();
}

Sprite mago::getSprite()
{
	return sprite;
}

int mago::getX()
{
	return x;
}

int mago::getY()
{
	return y;
}

void mago::setX(int novoX)
{
	x = novoX;
}

void mago::setY(int novoY)
{
	y = novoY;
}

int mago::getDirecao()
{
	return direcao;
}

int mago::getPontuacao()
{
	return pontuacao;
}


void mago::setPontuacao(int p)
{
	pontuacao += p;
	
}

void mago::mostrarPontuacao( )
{

	arquivo.open("Ranking.txt", ifstream::in | ofstream::out | fstream::app);
	arquivo >> top1;
	if (top1 < pontuacao) 
	{
		arquivo.close();
		arquivo.open("Ranking.txt", ofstream::out);
		arquivo << pontuacao;
		arquivo.close();
	}
	else 
	{
		arquivo.close();
	}
	
}

void mago::perderVida(int dano)
{
	vida -= dano;
}

int mago::getVida()
{
	return vida;
}


