#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefa.h"

// Função para criar uma nova tarefa
Tarefa *criarTarefa(int id, const char *descricao, int tempo_limite) {
    Tarefa *novaTarefa = (Tarefa *)malloc(sizeof(Tarefa));
    if (novaTarefa == NULL) {
        fprintf(stderr, "Erro ao alocar memória para nova tarefa.\n");
        exit(EXIT_FAILURE);
    }
    novaTarefa->id = id;
    strcpy(novaTarefa->descricao, descricao);
    novaTarefa->tempo_limite = tempo_limite;
    novaTarefa->concluida = 0; // Inicialmente a tarefa não está concluída
    novaTarefa->prox = NULL; // O próximo nó é inicializado como NULL
    return novaTarefa;
}

// Função para imprimir os detalhes de uma tarefa
void imprimirTarefa(Tarefa *tarefa) {
    printf("%d\t%-20s\t%d\t\t%s\n", tarefa->id,
           tarefa->descricao,
           tarefa->tempo_limite,
           (tarefa->concluida == 0) ? "Não" : "Sim");
}
