//Este código tem cmo base um trecho retirado do 'Curso de C Wagner Gaspar' acrescido de pequenas modificações feitas por mim
// Encontrado em: https://wagnergaspar.com/como-implementar-uma-tabela-hash-com-vetor-na-pratica/

#include <iostream>
using namespace std;

#define TAM 31

// Função para inicializar a tabela hash com todos os elementos vazios (0)
void inicializarTabela(int t[]) {
    for (int i = 0; i < TAM; i++)
        t[i] = 0;
}

// Função de hash simples que retorna o resto da divisão da chave pelo tamanho da tabela
int funcaoHash(int chave) {
    return chave % TAM;
}

// Função para inserir um item na tabela hash
void inserirItem(int t[], int valor) {
    int id = funcaoHash(valor); // Calcula o índice usando a função de hash
    while (t[id] != 0) { // Enquanto o índice estiver ocupado, continue procurando
        id = funcaoHash(id + 1); // Utiliza sondagem linear para encontrar uma posição vazia
    }
    t[id] = valor; // Insere o valor na posição encontrada
}

// Função para buscar um item na tabela hash
int buscaItem(int t[], int chave) {
    int id = funcaoHash(chave); // Calcula o índice usando a função de hash
    cout << "\nIndice gerado: " << id << endl; // Imprime o índice gerado para fins de depuração
    while (t[id] != 0) { // Enquanto o índice estiver ocupado
        if (t[id] == chave) // Se o valor na posição for igual à chave, o valor foi encontrado
            return t[id];
        else
            id = funcaoHash(id + 1); // Caso contrário, continue procurando usando sondagem linear
    }
    return 0; // Retorna 0 se o valor não for encontrado na tabela
}

// Função para imprimir a tabela hash
void imprimirItem(int t[]) {
    for (int i = 0; i < TAM; i++) { // Percorre toda a tabela
        cout << i << " = " << t[i] << endl; // Imprime o índice e o valor armazenado naquela posição
    }
}

int main() {
    int opcao, valor, retorno, tabela[TAM]; // Declaração de variáveis

    inicializarTabela(tabela); // Inicializa a tabela hash com valores vazios

    do {
        // Menu para as operações disponíveis
        cout << "\n\t0 - Sair\n\t1 - Inserir Item\n\t2 - Buscar Item\n\t3 - Imprimir Tabela\n";
        cin >> opcao; // Lê a opção escolhida pelo usuário

        switch (opcao) {
            case 1:
                cout << "\tQual valor deseja inserir? ";
                cin >> valor;
                inserirItem(tabela, valor); // Chama a função para inserir um item na tabela
                break;
            case 2:
                cout << "\tQual valor deseja buscar? ";
                cin >> valor;
                retorno = buscaItem(tabela, valor); // Chama a função para buscar um item na tabela
                if (retorno != 0)
                    cout << "\tValor encontrado: " << retorno << endl; // Se encontrado, imprime o valor
                else
                    cout << "\tValor nao encontrado!" << endl; // Se não encontrado, exibe uma mensagem
                break;
            case 3:
                imprimirItem(tabela); // Chama a função para imprimir a tabela
                break;
            default:
                cout << "Opcao invalida!" << endl; // Mensagem para opções inválidas
        }
    } while (opcao != 0); // Continua o loop até o usuário escolher a opção de sair

    return 0; // Retorna 0 indicando que o programa foi executado com sucesso
}
