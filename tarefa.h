#ifndef TAREFA_H
#define TAREFA_H

// Estrutura para uma tarefa
typedef struct Tarefa {
    int id;             // Identificador único da tarefa
    char descricao[100]; // Descrição da tarefa
    int tempo_limite;   // Tempo limite em horas para realização da tarefa
    int concluida;      // Indica se a tarefa está concluída (0 para não concluída, 1 para concluída)
    struct Tarefa *prox; // Ponteiro para o próximo nó na lista encadeada
} Tarefa;

// Protótipos das funções relacionadas às tarefas
Tarefa *criarTarefa(int id, const char *descricao, int tempo_limite);
void imprimirTarefa(Tarefa *tarefa);

#endif // TAREFA_H
