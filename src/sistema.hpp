#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "Astronauta.hpp"
#include "Voo.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sistema {
public:
    vector<Astronauta> todosAstronautas;
    vector<Voo> todosVoos;

    Astronauta* buscarAstronauta(string cpf) {
        for(auto &a : todosAstronautas) {
            if(a.cpf == cpf) return &a;
        }
        return nullptr;
    }

    Voo* buscarVoo(int codigo) {
        for(auto &v : todosVoos) {
            if(v.codigo == codigo) return &v;
        }
        return nullptr;
    }

    void cadastrarAstronauta(string cpf, int idade, string nome) {
        if(buscarAstronauta(cpf)) {
            cout << "Erro: CPF ja cadastrado." << endl;
            return;
        }
        todosAstronautas.push_back(Astronauta(cpf, idade, nome));
    }

    void cadastrarVoo(int codigo) {
        if(buscarVoo(codigo)) {
            cout << "Erro: Codigo de voo ja existe." << endl;
            return;
        }
        todosVoos.push_back(Voo(codigo));
    }

    void adicionarEmVoo(string cpf, int codigo) {
        Astronauta* a = buscarAstronauta(cpf);
        Voo* v = buscarVoo(codigo);

        if(!a || !v) { cout << "Erro: Registro nao encontrado." << endl; return; }
        if(v->estado != PLANEJADO) { cout << "Erro: Voo nao planejado." << endl; return; }
        if(!a->vivo) { cout << "Erro: Astronauta morto." << endl; return; }

        for(string c : v->passageirosCPF) {
            if(c == cpf) { cout << "Erro: Ja esta no voo." << endl; return; }
        }
        v->passageirosCPF.push_back(cpf);
    }

    // Função que estava a causar o erro no main.cpp:
    void removerDeVoo(string cpf, int codigo) {
        Voo* v = buscarVoo(codigo);
        Astronauta* a = buscarAstronauta(cpf);

        if (!v || !a) {
            cout << "Erro: Voo ou Astronauta nao encontrado." << endl;
            return;
        }
        if (v->estado != PLANEJADO) {
            cout << "Erro: Nao e possivel remover de um voo que ja saiu." << endl;
            return;
        }

        for (size_t i = 0; i < v->passageirosCPF.size(); i++) {
            if (v->passageirosCPF[i] == cpf) {
                v->passageirosCPF.erase(v->passageirosCPF.begin() + i);
                return;
            }
        }
        cout << "Erro: Astronauta nao estava nesse voo." << endl;
    }

    void lancarVoo(int codigo) {
        Voo* v = buscarVoo(codigo);
        if(!v || v->estado != PLANEJADO) return;
        if(v->passageirosCPF.empty()) { cout << "Erro: Voo vazio." << endl; return; }

        for(string cpf : v->passageirosCPF) {
            Astronauta* a = buscarAstronauta(cpf);
            if(!a->vivo || !a->disponivel) {
                cout << "Erro: Astronauta " << a->nome << " indisponivel." << endl;
                return;
            }
        }

        v->estado = EM_CURSO;
        for(string cpf : v->passageirosCPF) buscarAstronauta(cpf)->disponivel = false;
    }

    void explodirVoo(int codigo) {
        Voo* v = buscarVoo(codigo);
        if(!v || v->estado != EM_CURSO) return;

        v->estado = EXPLODIU;
        for(string cpf : v->passageirosCPF) {
            Astronauta* a = buscarAstronauta(cpf);
            a->vivo = false;
            a->disponivel = false;
        }
    }

    void finalizarVoo(int codigo) {
        Voo* v = buscarVoo(codigo);
        if(!v || v->estado != EM_CURSO) return;

        v->estado = SUCESSO;
        for(string cpf : v->passageirosCPF) buscarAstronauta(cpf)->disponivel = true;
    }

    void listarVoos() {
        string labels[] = {"Planejados", "Em Curso", "Sucesso", "Explodidos"};
        for(int i = 0; i <= 3; i++) {
            cout << "--- " << labels[i] << " ---" << endl;
            for(auto &v : todosVoos) {
                if(v.estado == i) {
                    cout << "Voo: " << v.codigo << endl;
                    for(auto &cpf : v.passageirosCPF) {
                        cout << "  - " << buscarAstronauta(cpf)->nome << " (" << cpf << ")" << endl;
                    }
                }
            }
        }
    }

    void listarMortos() {
        for(auto &a : todosAstronautas) {
            if(!a.vivo) {
                cout << "Morto: " << a.nome << " [CPF: " << a.cpf << "]" << endl;
                cout << "Voos que participou: ";
                for(auto &v : todosVoos) {
                    if(v.estado != PLANEJADO) { 
                        for(auto &c : v.passageirosCPF) if(c == a.cpf) cout << v.codigo << " ";
                    }
                }
                cout << endl;
            }
        }
    }
};

#endif