#ifndef LISTA_TAREFAS_H
#define LISTA_TAREFAS_H

#include "tarefa.h"

// Estrutura para a lista de tarefas
typedef struct ListaDeTarefas {
    Tarefa *cabeca; // Ponteiro para o primeiro nó na lista
} ListaDeTarefas;

// Protótipos das funções relacionadas à lista de tarefas
void inicializarLista(ListaDeTarefas *lista);
void adicionarTarefa(ListaDeTarefas *lista, int id, const char *descricao, int tempo_limite);
void concluirTarefa(ListaDeTarefas *lista, int id);
void excluirTarefa(ListaDeTarefas *lista, int id);
void imprimirTodasTarefas(ListaDeTarefas *lista);
void imprimirTarefasAtivas(ListaDeTarefas *lista);
void imprimirTarefasConcluidas(ListaDeTarefas *lista);

#endif // LISTA_TAREFAS_H
