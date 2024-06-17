#include <stdio.h>
#include <stdlib.h>
#include "lista_tarefas.h"

// Função para inicializar a lista de tarefas
void inicializarLista(ListaDeTarefas *lista) {
    lista->cabeca = NULL; // Inicializa a lista como vazia
}

// Função para adicionar uma nova tarefa no final da lista
void adicionarTarefa(ListaDeTarefas *lista, int id, const char *descricao, int tempo_limite) {
    Tarefa *novaTarefa = criarTarefa(id, descricao, tempo_limite);

    if (lista->cabeca == NULL) {
        lista->cabeca = novaTarefa;
    } else {
        Tarefa *atual = lista->cabeca;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novaTarefa;
    }

    printf("Tarefa adicionada com sucesso.\n");
}

// Função para marcar uma tarefa como concluída
void concluirTarefa(ListaDeTarefas *lista, int id) {
    Tarefa *atual = lista->cabeca;
    while (atual != NULL) {
        if (atual->id == id) {
            atual->concluida = 1;
            printf("Tarefa ID %d marcada como concluída.\n", id);
            return;
        }
        atual = atual->prox;
    }
    printf("Tarefa ID %d não encontrada.\n", id);
}

// Função para excluir uma tarefa da lista
void excluirTarefa(ListaDeTarefas *lista, int id) {
    Tarefa *atual = lista->cabeca;
    Tarefa *anterior = NULL;

    while (atual != NULL) {
        if (atual->id == id) {
            if (anterior == NULL) { // Caso seja o primeiro nó da lista
                lista->cabeca = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Tarefa ID %d excluída.\n", id);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Tarefa ID %d não encontrada.\n", id);
}

// Função para imprimir todas as tarefas da lista
void imprimirTodasTarefas(ListaDeTarefas *lista) {
    printf("Todas as Tarefas:\n");
    printf("ID\tDescrição\t\tTempo Limite\tConcluída\n");
    printf("-------------------------------------------------\n");

    Tarefa *atual = lista->cabeca;
    while (atual != NULL) {
        imprimirTarefa(atual);
        atual = atual->prox;
    }
}

// Função para imprimir somente as tarefas ativas (não concluídas)
void imprimirTarefasAtivas(ListaDeTarefas *lista) {
    printf("Tarefas Ativas:\n");
    printf("ID\tDescrição\t\tTempo Limite\tConcluída\n");
    printf("-------------------------------------------------\n");

    Tarefa *atual = lista->cabeca;
    while (atual != NULL) {
        if (atual->concluida == 0) {
            imprimirTarefa(atual);
        }
        atual = atual->prox;
    }
}

// Função para imprimir somente as tarefas concluídas
void imprimirTarefasConcluidas(ListaDeTarefas *lista) {
    printf("Tarefas Concluídas:\n");
    printf("ID\tDescrição\t\tTempo Limite\tConcluída\n");
    printf("-------------------------------------------------\n");

    Tarefa *atual = lista->cabeca;
    while (atual != NULL) {
        if (atual->concluida == 1) {
            imprimirTarefa(atual);
        }
        atual = atual->prox;
    }
}
