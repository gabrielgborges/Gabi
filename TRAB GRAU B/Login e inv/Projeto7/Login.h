#pragma once
#include <fstream>
#include <string>
#include <map>
using namespace std;

class Login
{
public:
	Login();
	~Login();

	string getUsuario();
	void setUsuario();
	void login();
	void menu();

	int TESTE();

private:
	int log = 0;
	map<string, string> LoginSenha;
	string usu, sen;
	string usuario, senha;
	ifstream loginArqIn;
	ofstream loginArqOut;

};

