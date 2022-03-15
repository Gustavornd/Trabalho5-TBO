#include "menu.h"

/*
* Fun��o que implementa o menu de testes.
*/
void Menu() {
	while (true) {
		unsigned opcao;
		system("cls");
		cout << "1. Ler lista" << endl;
		cout << "2. Lista aleat�ria" << endl;
		cout << "0. Sair." << endl;

		cout << "Escolha uma op��o: ";
		cin >> opcao;

		if (opcao == 0)
			break;
		//Testes com a lista informada no trabalho
		if (opcao == 1)
		{
			system("cls");
			cout << endl << "------------------LISTA ESTATICA--------------------" << endl;
			ListaEstatica le("dados.txt");
			int acessos = 0;


			le.print();
			cout << endl << "----------------XXXXXXXXXXXXXXXXXXX------------------" << endl;

			HeapSort(le, acessos, true);
			cout << "Acessos: " << acessos << endl;
			system("pause");
		}

		//Testes com as listas aleat�rias
		if (opcao == 2) {
			system("cls");
			cout << endl << "------------------LISTA ESTATICA ALEAT�RIA--------------------" << endl;
			fstream output;
			output.open("acessos.csv", ios::out);

			for (unsigned i = 1; i <= 100; i++) {
				system("cls");
				int acessos = 0;
				ListaEstatica le(i);

				le.print();
				cout << endl << "----------------XXXXXXXXXXXXXXXXXXX------------------" << endl;


				HeapSort(le, acessos, false);
				le.print();
				cout << "Tamanho da Lista: " << i << endl;
				cout << "Acessos: " << acessos << endl;
				output << i << ";" << acessos << endl;

				system("pause");
			}
			output.close();
		}
	}
}
