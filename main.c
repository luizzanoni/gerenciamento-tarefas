#include <stdio.h>
#include <stdlib.h>
#include "lista_tarefas.h"

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\nMenu de Opções:\n");
    printf("1. Adicionar nova tarefa\n");
    printf("2. Marcar tarefa como concluída\n");
    printf("3. Excluir tarefa\n");
    printf("4. Visualizar todas as tarefas\n");
    printf("5. Visualizar tarefas ativas\n");
    printf("6. Visualizar tarefas concluídas\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

// Função principal para demonstração
int main() {
    ListaDeTarefas lista;
    inicializarLista(&lista);

    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: {
                int id, tempo_limite;
                char descricao[100];
                printf("Digite o ID da tarefa: ");
                scanf("%d", &id);
                printf("Digite a descrição da tarefa: ");
                scanf(" %[^\n]", descricao);
                printf("Digite o tempo limite em horas: ");
                scanf("%d", &tempo_limite);
                adicionarTarefa(&lista, id, descricao, tempo_limite);
                break;
            }
            case 2: {
                int id;
                printf("Digite o ID da tarefa a ser concluída: ");
                scanf("%d", &id);
                concluirTarefa(&lista, id);
                break;
            }
            case 3: {
                int id;
                printf("Digite o ID da tarefa a ser excluída: ");
                scanf("%d", &id);
                excluirTarefa(&lista, id);
                break;
            }
            case 4:
                imprimirTodasTarefas(&lista);
                break;
            case 5:
                imprimirTarefasAtivas(&lista);
                break;
            case 6:
                imprimirTarefasConcluidas(&lista);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
