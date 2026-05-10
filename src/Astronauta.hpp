#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>
#include <vector>

using namespace std;

class Astronauta {
public:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;

    Astronauta(string c, int i, string n) {
        cpf = c;
        idade = i;
        nome = n;
        vivo = true;
        disponivel = true;
    }
};

#endif