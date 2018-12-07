#pragma once
#include "mago.h"
#include "ladrao.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	mago m1;
	ladrao l1, l2, l3;
	Texto texto, texto1;

};

