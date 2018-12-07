#include "pch.h"
#include <iostream>
#include "Login.h"

Login::Login()
{

}

Login::~Login()
{

}

string Login::getUsuario()
{
	return usuario;
}

void Login::setUsuario()
{
	cout << "Crie um usuario" << endl;
	cout << "Usuario: ";
	cin >> usuario;
	cout << "Senha: ";
	cin >> senha;

	loginArqOut.open("usuarios.txt", fstream::app);
	loginArqOut << usuario << endl;
	loginArqOut << senha << endl;
	loginArqOut.close();
}

void Login::login()
{
	system("CLS");

	cout << "Entre seu usuario" << endl;
	cout << "Usuario: ";
	cin >> usuario;
	cout << "Senha: ";
	cin >> senha;

	loginArqIn.open("usuarios.txt");
	for (int i = 0; i < 20; i++) {
		loginArqIn >> usu;
		loginArqIn >> sen;

		if (usu == usuario && sen == senha)
			log = 1;
	}
	loginArqIn.close();

	if (log == 1)
		cout << "yep";
	if (log == 0)
		cout << "nop";
}

void Login::menu()
{
	int menu = -1;
	int voltar = 0;

	while (menu != 5 && log == 0) {
		voltar = 0;
		system("CLS");
		cout << "(1) Jogar" << endl;
		cout << "(2) Criar Conta" << endl;
		cout << "(3) Pontuacao" << endl;
		cout << "(4) Creditos" << endl;
		cout << "(5) Sair" << endl;
		cout << "opcao: ";
		cin >> menu;

		if (menu == 1) {
			system("CLS");
			login();
		}

		if (menu == 2) {
			system("CLS");
			setUsuario();
		}

		if (menu == 3) {
			system("CLS");
			while (voltar != 5) {
				cout << "digite (5) para voltar" << endl;
				cout << "opcao: ";
				cin >> voltar;
			}
		}

		if (menu == 4) {
			system("CLS");
			while (voltar != 5) {
				cout << "digite (5) para voltar" << endl;
				cout << "opcao: ";
				cin >> voltar;
			}
		}

	}

	system("CLS");
}

int Login::TESTE()
{
	return log;
}
