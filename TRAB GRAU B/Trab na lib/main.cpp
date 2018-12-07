#include "Jogo.h"
#include <array>
#include "Menu.h"
void main() {
	int opcao;
	std::array<Menu, 10>g_menus; //array stl
	//Menu g_menus[10];

	//Declaraçao de pilha usando a stack da STL
	std::stack<Menu*> s_pilha_menus;

	//inicializar Menu Main
	g_menus[0].m_opcoes[0] = "Novo Jogo";
	g_menus[0].m_opcoes_indice[0] = 0;
	g_menus[0].m_opcoes[1] = "Carregar Jogo";
	g_menus[0].m_opcoes_indice[1] = 0;
	g_menus[0].m_opcoes[2] = "Salvar Jogo";
	g_menus[0].m_opcoes_indice[2] = 0;
	g_menus[0].m_opcoes[3] = "Opcoes";
	g_menus[0].m_opcoes_indice[3] = 0;
	g_menus[0].m_opcoes[4] = "Sair";
	g_menus[0].m_opcoes_indice[4] = 0;
	g_menus[1].m_opcoes[0] = "Som";
	g_menus[1].m_opcoes_indice[0] = 2;
	g_menus[1].m_opcoes[1] = "Grafico";
	g_menus[1].m_opcoes_indice[1] = 3;
	g_menus[2].m_opcoes[0] = "Volume musica";
	g_menus[2].m_opcoes_indice[0] = 5;
	g_menus[2].m_opcoes[1] = "Volume jogo";
	g_menus[2].m_opcoes_indice[1] = 6;
	g_menus[3].m_opcoes[0] = "Resolucao";
	g_menus[3].m_opcoes_indice[0] = 7;
	//inicializa pilha
	s_pilha_menus.push(&g_menus[0]);

	//acessa menu
	s_pilha_menus.top()->desenhaMenu();
	while (true) // loop do jogo
	{
		//Seleção de Opções
		std::cout << std::endl;
		std::cout <<opcao<< std::endl;
		std::cin >> opcao;
		if (opcao == 0) {
			if (s_pilha_menus.top()!= &g_menus[0])
				s_pilha_menus.pop();
		}
		system("CLS");

		// seleciona menu selecionado
		s_pilha_menus.push(&g_menus[opcao]);
		s_pilha_menus.top()->desenhaMenu();
		if (opcao == -1)//sai do jogo
			break;
	}
}

int main(int argc, char* argv[])
{

	Jogo jogo;
	jogo.inicializar();
	jogo.executar();
	jogo.finalizar();

	return 0;
}