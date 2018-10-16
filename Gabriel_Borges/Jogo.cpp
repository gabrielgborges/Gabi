#include "Jogo.h"

Jogo::Jogo()
{
	v = 0;
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	//CARREGA MAPA
	mapa.carregar("assets/tilemaps/mapa.json");
	//CARREGA PERSONAGENS(SPRITES)
	gRecursos.carregarSpriteSheet("Guerreiro", "assets/spritesheets/Knight.png", 4, 4);
	Guerreiro = new guerreiro();
	Guerreiro->setSpriteSheet("Guerreiro");

	gRecursos.carregarSpriteSheet("Mago", "assets/spritesheets/Mage.png", 4, 4);
	Mago = new mago();
	Mago->setSpriteSheet("Mago");

	gRecursos.carregarSpriteSheet("Ladrao", "assets/spritesheets/Thief.png", 4, 4);
	Ladrao = new ladrao();
	Ladrao->setSpriteSheet("Ladrao");
	//SETA O 1o personagem
	Personagem_atual = Guerreiro;
	Personagem_atual->spr.desenhar(dirx, diry);
	
	//CARREGA HABILIDADES(SPRITES)
	gRecursos.carregarSpriteSheet("Machado2", "assets/spritesheets/Machado2.png", 1, 1);
	Guerreiroh = new guerreiroh;
	Guerreiroh->sprG.setSpriteSheet("Machado2");
	Guerreiroh->sprG.desenhar(dirx, diry);

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
	mapa.descarregar();
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		mapa.desenhar();

		Personagem_atual->atualizar();
		
		//MOVIMENTAÇAO - HABILIDADE LADRAO
		if (Personagem_atual == Ladrao) {

			if (gTeclado.segurando[TECLA_ESPACO]) {
				if (gTeclado.segurando[TECLA_D]) {

			

					dirx += 3;
				}
				if (gTeclado.segurando[TECLA_A]) {

			

					dirx -= 3;
				}
				if (gTeclado.segurando[TECLA_W]) {

			
					diry -= 3;

				}
				if (gTeclado.segurando[TECLA_S]) {

					
					diry += 3;

				}

				else {
					
				}

			}
			//SEM HABILIDADE
			else {
				if (gTeclado.segurando[TECLA_D]) {

					Personagem_atual->spr.desenhar(dirx , diry );

					dirx += 1;
				}
				if (gTeclado.segurando[TECLA_A]) {

					Personagem_atual->spr.desenhar(dirx, diry );

					dirx -= 1;
				}
				if (gTeclado.segurando[TECLA_W]) {

					Personagem_atual->spr.desenhar(dirx, diry);
					diry -= 1;

				}
				if (gTeclado.segurando[TECLA_S]) {

					Personagem_atual->spr.desenhar(dirx, diry);
					diry += 1;

				}

				else {
					Personagem_atual->spr.desenhar(dirx, diry);
				}
			}
		}

		//HABILIDADE MAGO
		else if (Personagem_atual == Mago) {
			if (gTeclado.segurando[TECLA_ESPACO]) 
				{
					if (gTeclado.segurando[TECLA_D]) {

						Personagem_atual->spr.desenhar(dirx + 70, diry);
						Personagem_atual->spr.desenhar(dirx - 70, diry);
						Personagem_atual->spr.desenhar(dirx, diry +70);
						Personagem_atual->spr.desenhar(dirx, diry - 70);
						Personagem_atual->spr.desenhar(dirx , diry);

						dirx += 1;
					}
					if (gTeclado.segurando[TECLA_A]) {
						Personagem_atual->spr.desenhar(dirx + 70, diry);
						Personagem_atual->spr.desenhar(dirx - 70, diry);
						Personagem_atual->spr.desenhar(dirx, diry + 70);
						Personagem_atual->spr.desenhar(dirx, diry - 70);
						Personagem_atual->spr.desenhar(dirx, diry);

						dirx -= 1;
					}
					if (gTeclado.segurando[TECLA_W]) {

						Personagem_atual->spr.desenhar(dirx , diry);
						Personagem_atual->spr.desenhar(dirx + 70, diry);
						Personagem_atual->spr.desenhar(dirx - 70, diry);
						Personagem_atual->spr.desenhar(dirx, diry + 70);
						Personagem_atual->spr.desenhar(dirx, diry - 70);
						diry -= 1;

					}
					if (gTeclado.segurando[TECLA_S]) {
						Personagem_atual->spr.desenhar(dirx + 70, diry);
						Personagem_atual->spr.desenhar(dirx - 70, diry);
						Personagem_atual->spr.desenhar(dirx, diry + 70);
						Personagem_atual->spr.desenhar(dirx, diry - 70);
						Personagem_atual->spr.desenhar(dirx , diry);
						diry += 1;

					}

					else {
						Personagem_atual->spr.desenhar(dirx + 70, diry);
						Personagem_atual->spr.desenhar(dirx - 70, diry);
						Personagem_atual->spr.desenhar(dirx, diry + 70);
						Personagem_atual->spr.desenhar(dirx, diry - 70);
						Personagem_atual->spr.desenhar(dirx, diry);
					}
				}
			//SEM HABILIDADE
			else {
				if (gTeclado.segurando[TECLA_D]) {

					Personagem_atual->spr.desenhar(dirx, diry);

					dirx += 1;
				}
				if (gTeclado.segurando[TECLA_A]) {

					Personagem_atual->spr.desenhar(dirx, diry);

					dirx -= 1;
				}
				if (gTeclado.segurando[TECLA_W]) {

					Personagem_atual->spr.desenhar(dirx, diry);
					diry -= 1;

				}
				if (gTeclado.segurando[TECLA_S]) {

					Personagem_atual->spr.desenhar(dirx, diry);
					diry += 1;

				}

				else {
					Personagem_atual->spr.desenhar(dirx, diry);
				}
			}
			
		}
		//GUERREIRO
		else
		{		//LANÇAR HABILIDADES - guerreiro
			Guerreiroh->sprG.desenhar(dirmx, dirmy);
			if (gTeclado.segurando[TECLA_ESPACO]) {
				if (dir == 1) //direita
				{
					dirmx+= 2;
				}
				else if (dir == 2) //esquerda
				{
					dirmx-= 2;
				}
				else if (dir == 3) //cima
				{	
					dirmy-= 2;
				}
				else if (dir == 4) //baixo
				{
					dirmy+= 2;
				}

			}
			
				if (gTeclado.segurando[TECLA_D]) {

					Personagem_atual->spr.desenhar(dirx, diry);

					dirx += 1;
				}
				if (gTeclado.segurando[TECLA_A]) {

					Personagem_atual->spr.desenhar(dirx, diry);

					dirx -= 1;
				}
				if (gTeclado.segurando[TECLA_W]) {

					Personagem_atual->spr.desenhar(dirx, diry);
					diry -= 1;

				}
				if (gTeclado.segurando[TECLA_S]) {

					Personagem_atual->spr.desenhar(dirx, diry);
					diry += 1;

				}

				else {
					Personagem_atual->spr.desenhar(dirx, diry);
				}
			
		}
		//MUDAR PERSONAGEM

		if (gTeclado.pressionou[TECLA_1]) {
			Personagem_atual = Guerreiro;

		}
		if (gTeclado.pressionou[TECLA_2]) {
			Personagem_atual = Mago;
		}
		if (gTeclado.pressionou[TECLA_3]) {
			Personagem_atual = Ladrao;
		}
		

		
	
		
	
		uniTerminarFrame();
	}
}