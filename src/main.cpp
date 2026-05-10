#include "Sistema.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Sistema sistema;
    string comando;

    while (cin >> comando && comando != "FIM") {
        
        if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome); 
            sistema.cadastrarAstronauta(cpf, idade, nome);
        } 
        else if (comando == "CADASTRAR_VOO") {
            int codigo;
            cin >> codigo;
            sistema.cadastrarVoo(codigo);
        }
        else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            sistema.adicionarEmVoo(cpf, codigo);
        }
        else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            sistema.removerDeVoo(cpf, codigo);
        }
        else if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            sistema.lancarVoo(codigo);
        }
        else if (comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            sistema.explodirVoo(codigo);
        }
        else if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            sistema.finalizarVoo(codigo);
        }
        else if (comando == "LISTAR_VOOS") {
            sistema.listarVoos();
        }
        else if (comando == "LISTAR_MORTOS") {
            sistema.listarMortos();
        }
    }

    return 0;
}