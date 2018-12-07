#include "Jogo.h"
Jogo::Jogo()
{
	
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);
	
	//CARREGA MAPA
	/*mapa.carregar("assets/tilemaps/mapa.json");*/
	//CARREGA PERSONAGENS(SPRITES)

	m1.inicializar("m1", "assets/spritesheets/thief.png");
	l1.inicializar("l1", "assets/spritesheets/thief.png", 100, 200);
	l2.inicializar("l1", "assets/spritesheets/thief.png", 100, 100);
	l3.inicializar("l1", "assets/spritesheets/thief.png", 100, 300);

	gRecursos.carregarFonte("fonte1", "fonte_padrao.ttf", 20);
	texto.setFonte("fonte1");
	gRecursos.carregarFonte("fonte12", "fonte_padrao.ttf", 40);
	texto1.setFonte("fonte12");
	
	//CARREGA HABILIDADES(SPRITES)
	gRecursos.carregarSpriteSheet("Bola de Fogo", "assets/spritesheets/tiro.png", 1, 1);
	
	/*Mago->lancarMagiaSprite("Bola de Fogo");*/
    /*ObjetoTileMap * objPos = mapa.getCamadaDeObjetos("Objetos")->getObjeto("Pos1");
	Personagem_atual->setPosCentro(objPos->getPosCentro());
	mapa.getCamadaDeObjetos("Objetos")->adicionarObjeto(Personagem_atual);*/

	
	//	O resto da inicialização vem aqui!
	//	...
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...
	/*mapa.descarregar();*/
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{


	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		if (m1.getVida() > 0)
		{
			m1.atualizar();
			m1.desenhar();
		}
		else{}
		
		if (l1.getVida() > 0)
		{
			l1.desenhar();
			l1.atualizar();
		}
		else {}

		if (l2.getVida() > 0)
		{
			l2.desenhar();
			l2.atualizar();
		}
		else {}
		
		if (l3.getVida() > 0)
		{
			l3.desenhar();
			l3.atualizar();
		}
		else {}

		if (l3.getVida()<= 0 && l2.getVida() <= 0 && l1.getVida() <= 0)
		{
			texto1.setString("BOAAA!");
			texto1.desenhar(400, 200);
		}

		texto.setString("Pontuacao: ");
		
		texto.desenhar(100, 50);
		
		m1.mostrarPontuacao();
			if (uniTestarColisaoSpriteComSprite(m1.getSpriteTiro(), m1.getXTiro(), m1.getYTiro(), 1,l1.getSprite(), l1.getX(), l1.getY(), 1))
			{
				l1.perderVida();
				m1.setPontuacao(10);
				m1.matarTiro();
			
			}

			if (uniTestarColisao(m1.getSpriteTiro(), m1.getXTiro(), m1.getYTiro(), 1, l2.getSprite(), l2.getX(), l2.getY(), 1))
			{
				l2.perderVida();
				m1.setPontuacao(10);
				m1.matarTiro();
		
			}

			if (uniTestarColisao(m1.getSpriteTiro(), m1.getXTiro(), m1.getYTiro(), 1, l3.getSprite(), l3.getX(), l3.getY(), 1))
			{
				l3.perderVida();
				m1.setPontuacao(10);
				m1.matarTiro();
				
			}

			if (uniTestarColisao(l1.getSpriteTiro(), l1.getXTiro(), l1.getYTiro(), 1, m1.getSprite(), m1.getX(), m1.getY(), 1))
			{
				l1.matarTiro();				
				m1.perderVida(10);
				m1.setPontuacao(-10);
			}

			if (uniTestarColisao(l2.getSpriteTiro(), l2.getXTiro(), l2.getYTiro(), 1, m1.getSprite(), m1.getX(), m1.getY(), 1))
			{
				l2.matarTiro();
				m1.perderVida(10);
				m1.setPontuacao(-10);
			}

			if (uniTestarColisao(l3.getSpriteTiro(), l3.getXTiro(), l3.getYTiro(), 1, m1.getSprite(), m1.getX(), m1.getY(), 1))
			{
				l3.matarTiro();
				m1.perderVida(10);
				m1.setPontuacao(-10);
			}

		uniTerminarFrame();
	}
}

