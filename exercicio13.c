#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 1000

typedef struct {
    int id;
    char nome[50];
    char email[50];
    char sexo[15];
    char endereco[100];
    double altura;
    int vacina;
} Usuario;

int proximoId = 1; // Inicializa o ID para o primeiro usuário

void cadastrarUsuario(Usuario usuarios[], int *numUsuarios);
void editarUsuario(Usuario usuarios[], int numUsuarios);
void excluirUsuario(Usuario usuarios[], int *numUsuarios);
void buscarUsuarioPorEmail(Usuario usuarios[], int numUsuarios);
void imprimirUsuarios(Usuario usuarios[], int numUsuarios);

int main() {
    Usuario usuarios[MAX_USERS];
    int numUsuarios = 0;
    char opcao;

    do {
        printf("\nMENU:\n");
        printf("1 - Cadastrar usuário\n");
        printf("2 - Editar usuário\n");
        printf("3 - Excluir usuário\n");
        printf("4 - Buscar usuário por e-mail\n");
        printf("5 - Imprimir todos os usuários\n");
        printf("0 - Sair\n");

        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrarUsuario(usuarios, &numUsuarios);
                break;
            case '2':
                editarUsuario(usuarios, numUsuarios);
                break;
            case '3':
                excluirUsuario(usuarios, &numUsuarios);
                break;
            case '4':
                buscarUsuarioPorEmail(usuarios, numUsuarios);
                break;
            case '5':
                imprimirUsuarios(usuarios, numUsuarios);
                break;
            case '0':
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != '0');

    return 0;
}

void cadastrarUsuario(Usuario usuarios[], int *numUsuarios) {
    if (*numUsuarios < MAX_USERS) {
        Usuario novoUsuario;
        novoUsuario.id = proximoId++;
        
        printf("Nome completo: ");
        scanf(" %[^\n]s", novoUsuario.nome);
        
        printf("Email: ");
        scanf(" %s", novoUsuario.email);

        // Validação do campo de e-mail
        if (strchr(novoUsuario.email, '@') == NULL) {
            printf("Erro: E-mail inválido. O caractere '@' é obrigatório.\n");
            return;
        }

        printf("Sexo (Feminino/Masculino/Indiferente): ");
        scanf(" %s", novoUsuario.sexo);

        // Validação do campo de sexo
        if (strcmp(novoUsuario.sexo, "Feminino") != 0 && strcmp(novoUsuario.sexo, "Masculino") != 0 && strcmp(novoUsuario.sexo, "Indiferente") != 0) {
            printf("Erro: Sexo inválido. Aceite somente Feminino, Masculino ou Indiferente.\n");
            return;
        }

        printf("Endereço: ");
        scanf(" %[^\n]s", novoUsuario.endereco);

        printf("Altura (entre 1 e 2 m): ");
        scanf("%lf", &novoUsuario.altura);

        // Validação do campo de altura
        if (novoUsuario.altura < 1 || novoUsuario.altura > 2) {
            printf("Erro: Altura inválida. Aceite valores entre 1 e 2 metros.\n");
            return;
        }

        printf("Vacina (1 para sim, 0 para não): ");
        scanf("%d", &novoUsuario.vacina);

        usuarios[*numUsuarios] = novoUsuario;
        (*numUsuarios)++;

        printf("Usuário cadastrado com sucesso!\n");
    } else {
        printf("Erro: Limite máximo de usuários atingido.\n");
    }
}

void editarUsuario(Usuario usuarios[], int numUsuarios) {
    int id;
    printf("Digite o ID do usuário a ser editado: ");
    scanf("%d", &id);

    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == id) {
            printf("Novo nome completo: ");
            scanf(" %[^\n]s", usuarios[i].nome);

            printf("Novo email: ");
            scanf(" %s", usuarios[i].email);

            // Validação do campo de e-mail
            if (strchr(usuarios[i].email, '@') == NULL) {
                printf("Erro: E-mail inválido. O caractere '@' é obrigatório.\n");
                return;
            }

            printf("Novo sexo (Feminino/Masculino/Indiferente): ");
            scanf(" %s", usuarios[i].sexo);

            // Validação do campo de sexo
            if (strcmp(usuarios[i].sexo, "Feminino") != 0 && strcmp(usuarios[i].sexo, "Masculino") != 0 && strcmp(usuarios[i].sexo, "Indiferente") != 0) {
                printf("Erro: Sexo inválido. Aceite somente Feminino, Masculino ou Indiferente.\n");
                return;
            }

            printf("Novo endereço: ");
            scanf(" %[^\n]s", usuarios[i].endereco);

            printf("Nova altura (entre 1 e 2 m): ");
            scanf("%lf", &usuarios[i].altura);

            // Validação do campo de altura
            if (usuarios[i].altura < 1 || usuarios[i].altura > 2) {
                printf("Erro: Altura inválida. Aceite valores entre 1 e 2 metros.\n");
                return;
            }

            printf("Nova vacina (1 para sim, 0 para não): ");
            scanf("%d", &usuarios[i].vacina);

            printf("Usuário editado com sucesso!\n");
            return;
        }
    }

    printf("Erro: Usuário não encontrado.\n");
}

void excluirUsuario(Usuario usuarios[], int *numUsuarios) {
    int id;
    printf("Digite o ID do usuário a ser excluído: ");
    scanf("%d", &id);

    for (int i = 0; i < *numUsuarios; i++) {
        if (usuarios[i].id == id) {
            for (int j = i; j < *numUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            (*numUsuarios)--;
            printf("Usuário excluído com sucesso!\n");
            return;
        }
    }

    printf("Erro: Usuário não encontrado.\n");
}

void buscarUsuarioPorEmail(Usuario usuarios[], int numUsuarios) {
    char email[50];
    printf("Digite o e-mail do usuário a ser buscado: ");
    scanf(" %s", email);

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            printf("Usuário encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacina: %d\n", usuarios[i].vacina);
            return;
        }
    }

    printf("Erro: Usuário não encontrado.\n");
}

void imprimirUsuarios(Usuario usuarios[], int numUsuarios) {
    printf("\nLista de Usuários:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereço: %s\n", usuarios[i].endereco);
        printf("Altura: %.2lf\n", usuarios[i].altura);
        printf("Vacina: %d\n", usuarios[i].vacina);
        printf("----------------------------\n");
    }
}
