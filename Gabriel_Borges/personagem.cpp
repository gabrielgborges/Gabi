#include "personagem.h"



personagem::personagem()
{
	velo = 3.0f;
	dir.set(0, 0);
	
}


personagem::~personagem()
{
}

int personagem::ganhar_grana(int x)
{
	return grana + x;
}

void personagem::atualizar()
{
	//Vetor2D pos = getPosCentro();
	//if (gTeclado.segurando[TECLA_D]) {
	//	dir.set(1, 0);
	//	pos += dir*velo*gTempo.getDeltaTempo();
	//	setPosCentro(pos);
	//}
	//if (gTeclado.segurando[TECLA_A]) {
	//	dir.set(-1, 0);
	//	pos += dir*velo*gTempo.getDeltaTempo();
	//	setPosCentro(pos);
	//}
	//if (gTeclado.segurando[TECLA_W]) {
	//	dir.set(0, -1);
	//	pos += dir*velo*gTempo.getDeltaTempo();
	//	setPosCentro(pos);
	//}
	//if (gTeclado.segurando[TECLA_S]) {
	//	dir.set(0, 1);
	//	pos += dir*velo*gTempo.getDeltaTempo();
	//	setPosCentro(pos);

	//}


	

	

}

void personagem::setSpriteSheet(string spritesheet)
{
	spr.setSpriteSheet(spritesheet);
	setSprite(&spr);
}
