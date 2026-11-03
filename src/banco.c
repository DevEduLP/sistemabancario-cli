#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    char titular[50];
    float saldo;
} Conta;

void consultar_saldo(const Conta *c);
int sacar(Conta *c, float valor);
int depositar(Conta *c, float valor);

int main() {
    Conta minha_conta;
    int opcao;
    float valor;
    
    minha_conta.numero = 1001;
    strcpy(minha_conta.titular, "Eduardo Livi");
    minha_conta.saldo = 0.0f;
    
    do {
        printf("\n=== Sistema Bancário v1.0 ===\n");
        printf("Titular: %s | Conta: %d\n", minha_conta.titular, minha_conta.numero);
        printf("----------------------------\n");
        printf("1 - Consultar saldo\n");
        printf("2 - Sacar valor\n");
        printf("3 - Depositar valor\n");
        printf("4 - Sair\n");
        printf("Selecione uma das opções: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\n[ERRO] Entrada inválida.\n");
            break;
        }
        
        switch(opcao) {
            case 1:
                consultar_saldo(&minha_conta);
                break;
                
            case 2:
                printf("\nDigite o valor que deseja sacar: ");
                scanf(" %f", &valor);
                
                if (sacar(&minha_conta, valor)) {
                    printf("\nValor sacado com sucesso.\n\n");
                } else {
                    printf("\nValor inválido ou saldo insuficiente.\n");
                }
                break;
                
            case 3:
                printf("\nDigite o valor para depósito: ");
                scanf(" %f", &valor);
                
                if (depositar(&minha_conta, valor)) {
                    printf("\nValor depositado com sucesso.\n");
                } else {
                    printf("\nO valor do depósito deve ser maior que zero.\n");
                }
                break;
                
            case 4:
                printf("Saindo do sistema. Até logo!\n\n");
                break;
                
            default: 
                printf("Digite uma opção válida.\n");
        }
    } while (opcao != 4);
    
    return 0;
}

void consultar_saldo(const Conta *c) {
    printf("\n--- EXTRATO RÁPIDO ---\n");
    printf("Titular: %s\n", c->titular);
    printf("Conta  : %d\n", c->numero);
    printf("Saldo  : R$ %.2f\n", c->saldo);
    printf("----------------------------\n");
}

int depositar(Conta *c, float valor) {
    if (valor <= 0.0f) {
        return 0;
    }
    c->saldo += valor;
    return 1;
}

int sacar(Conta *c, float valor) {
    if (valor <= 0.0f || valor > c->saldo) {
        return 0;
    } 
    c->saldo -= valor;
    return 1;
}