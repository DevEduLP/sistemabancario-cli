# Sistema Bancário CLI em C (v1.0)

Um sistema bancário de linha de comando modularizado e construído em C, focado em boas práticas de gestão de memória, encapsulamento de dados com `structs` e manipulação de ponteiros.

- **Modelagem de Dados**: Abstração da conta através do tipo customizado `Conta` (`struct`).
- **Gestão de Memória**: Passagem de parâmetros por referência via ponteiros (`Conta *c`), otimizando o uso da pilha (*stack*).
- **Leitura Segura (`const`)**: Proteção de dados em funções de apenas leitura (`const Conta *c`).
- **Encapsulamento**: Separação completa entre a interface com o utilizador (`main`) e as regras de negócio (`depositar`, `sacar`, `consultar_saldo`).

## Conceitos Praticados
- Estruturas heterogéneas de dados (`struct`)
- Ponteiros e desreferenciação com o operador seta (`->`)
- Protótipos e modularização de funções
- Tipos de retorno com códigos de status (`int`)

## Como Compilar e Executar

```bash
# Navegar até a pasta do projeto
cd src

# Compilar com GCC
gcc banco.c -o banco

# Executar
./banco
```
