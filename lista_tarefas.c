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

int compararPorTempoLimite(const void *t1, const void *t2) {
    Tarefa *tarefa1 = *(Tarefa **)t1;
    Tarefa *tarefa2 = *(Tarefa **)t2;
    
    if (tarefa1->tempo_limite < tarefa2->tempo_limite) return -1;
    if (tarefa1->tempo_limite > tarefa2->tempo_limite) return 1;
    return 0;
}

void imprimirTodasTarefas(ListaDeTarefas *lista) {
    printf("Todas as Tarefas (ordenadas por tempo limite):\n");
    printf("ID\tDescrição\t\tTempo Limite\tConcluída\n");
    printf("-------------------------------------------------\n");

    // Contar o número de tarefas na lista
    int num_tarefas = 0;
    Tarefa *atual = lista->cabeca;
    while (atual != NULL) {
        num_tarefas++;
        atual = atual->prox;
    }

    // Criar um array de ponteiros para Tarefa
    Tarefa **tarefas_array = (Tarefa **)malloc(num_tarefas * sizeof(Tarefa *));
    
    // Preencher o array com as tarefas da lista
    atual = lista->cabeca;
    int i = 0;
    while (atual != NULL) {
        tarefas_array[i++] = atual;
        atual = atual->prox;
    }

    // Ordenar o array de tarefas pelo tempo limite
    qsort(tarefas_array, num_tarefas, sizeof(Tarefa *), compararPorTempoLimite);

    // Imprimir as tarefas ordenadas
    for (int j = 0; j < num_tarefas; j++) {
        imprimirTarefa(tarefas_array[j]);
    }

    // Liberar a memória do array de ponteiros
    free(tarefas_array);
}

// Função para imprimir todas as tarefas da lista
// void imprimirTodasTarefas(ListaDeTarefas *lista) {
//     printf("Todas as Tarefas:\n");
//     printf("ID\tDescrição\t\tTempo Limite\tConcluída\n");
//     printf("-------------------------------------------------\n");

//     Tarefa *atual = lista->cabeca;
//     while (atual != NULL) {
//         imprimirTarefa(atual);
//         atual = atual->prox;
//     }
// }

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
