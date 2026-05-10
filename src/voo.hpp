#ifndef VOO_HPP
#define VOO_HPP

#include <vector>
#include <string>

using namespace std;

enum EstadoVoo { PLANEJADO, EM_CURSO, SUCESSO, EXPLODIU };

class Voo {
public:
    int codigo; 
    vector<string> passageirosCPF; 
    EstadoVoo estado; 
    Voo(int c) {
        codigo = c;
        estado = PLANEJADO; 
    }
};

#endif