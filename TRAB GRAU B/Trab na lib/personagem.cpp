//#include "personagem.h"
//
//
//
//personagem::personagem()
//{
//	velo = 3.0f;
//	dirx = 100;
//	diry = 200;
//	
//}
//
//
//personagem::~personagem()
//{
//}
//
//
//
//void personagem::desenhar()
//{
//	spr.desenhar(dirx, diry);
//}
//
//void personagem::atualizar()
//{
//
//	if (gTeclado.segurando[TECLA_D]) {
//		dirx += 1.5f;
//		
//	}
//	if (gTeclado.segurando[TECLA_A]) {
//		dirx -= 1.5f;
//	}
//	if (gTeclado.segurando[TECLA_W]) {
//
//		diry -= 1.5f;
//
//	}
//	if (gTeclado.segurando[TECLA_S]) {
//		diry += 1.5f;
//	}
//
//	desenhar();
//
//	
//
//}
//
//void personagem::setSpriteSheet(string spritesheet)
//{
//	spr.setSpriteSheet(spritesheet);
//	setSprite(&spr);
//}
