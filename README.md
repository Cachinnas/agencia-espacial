# Agência Espacial Brasileira Digital (AEBD)

Por: Caio Cesar Cachina de Souza

Este projeto foi desenvolvido como parte da disciplina de **Linguagem de Programação 1** no Bacharelado em Tecnologia da Informação (BTI) da **UFRN**.

O objetivo do sistema em C++ é gerenciar astronautas e voos espaciais, controlando estados de missão (planejado, em curso, finalizado com sucesso ou explodido) e garantindo que regras de negócio e disponibilidade de tripulação sejam respeitadas.

## 🚀 Funcionalidades Suportadas

O programa processa arquivos de lote ou entrada padrão com os seguintes comandos:
- `CADASTRAR_ASTRONAUTA <cpf> <idade> <nome completo>`: Registra um astronauta.
- `CADASTRAR_VOO <codigo>`: Registra um voo no estado planejado.
- `ADICIONAR_ASTRONAUTA <cpf> <codigo>`: Aloca tripulantes a um voo.
- `REMOVER_ASTRONAUTA <cpf> <codigo>`: Remove tripulantes de um voo planejado.
- `LANCAR_VOO <codigo>`: Inicia a missão (passa para "em curso").
- `EXPLODIR_VOO <codigo>`: Falha catastrófica. Registra a morte da tripulação.
- `FINALIZAR_VOO <codigo>`: Conclui a missão com sucesso e libera a tripulação.
- `LISTAR_VOOS`: Exibe todos os voos agrupados por estado atual.
- `LISTAR_MORTOS`: Lista astronautas falecidos e as missões que participaram.
- `FIM`: Encerra o processamento.

## 🛠️ Como Compilar e Executar

### Pré-requisitos
- Compilador `g++` instalado no ambiente (Linux/WSL ou Windows com MinGW).

### Usando o Makefile (Linux/WSL)
Para compilar:
```bash
make