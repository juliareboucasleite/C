#include <iostream>
#include <vector>
using namespace std;

struct Livro {
    string nome;
};

int main() {
    vector<Livro> livros;
    int opcao;

    do {
        cout << "\nMENU\n";
        cout << "1 - Adicionar livro\n";
        cout << "2 - Listar livros\n";
        cout << "3 - Buscar livro\n";
        cout << "4 - Remover livro\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        if (opcao == 1) {
            Livro l;
            cout << "Nome do livro: ";
            cin.ignore(); 
            getline(cin, l.nome);

            livros.push_back(l);
            cout << "Livro adicionado!\n";
        }

        else if (opcao == 2) {
            cout << "\n--- LISTA ---\n";
            for (int i = 0; i < livros.size(); i++) {
                cout << i + 1 << " - " << livros[i].nome << endl;
            }
        }
        else if (opcao == 3){
            string busca;
            cout <<"Nome do livro a ser buscado: ";
            cin.ignore();
            getline(cin, busca);
            bool encontrado = false;
            for (int i = 0; i < livros.size(); i++) {
                if (livros[i].nome == busca) {
                    cout << "Livro encontrado: " << livros[i].nome << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Livro não encontrado.\n";
            }


        }
        else if (opcao == 4){
            string busca;
            cout <<"Nome do livro a ser removido: ";
            cin.ignore();
            getline(cin, busca);
            bool encontrado = false;
            for (int i = 0; i < livros.size(); i++) {
                if (livros[i].nome == busca) {
                    livros.erase(livros.begin() + i);
                    cout << "Livro removido: " << busca << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Livro não encontrado.\n";
            }
        }

    } while (opcao != 0);

    cout << "Saindo...\n";
}