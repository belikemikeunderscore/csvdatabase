#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int quantidadedeprodutos = 0;


struct Produto {
    string nome; 
    float preco;
    int quantidade;
};
Produto itens[] = {};


void adicionarProduto(Produto produtos[], int& quantidadeAtual){
            system("clear");
            cout << "Nome: ";
                string nomeprod;
                    cin >> nomeprod;
            cout << "\nPreço: ";
                float precoprod;
                    cin >> precoprod;
            cout << "\nQuantidade: ";
                int quantidadeprod;
                    cin >> quantidadeprod;

    itens[quantidadeAtual].nome = nomeprod;
    itens[quantidadeAtual].preco = precoprod;
    itens[quantidadeAtual].quantidade = quantidadeprod;

//debug
    //cout << "index " << quantidadeAtual << endl;
    //cout << "nome " << itens[quantidadeAtual].nome << endl;
    //cout << "preco " << itens[quantidadeAtual].preco << endl;
    //cout << "quantidade " << itens[quantidadeAtual].quantidade << endl;
//debug

    quantidadedeprodutos = quantidadeAtual + 1;
    if(quantidadeAtual < 2){
        cout << quantidadeAtual << " Item registrado\n";}
    else{
        cout << quantidadeAtual << " Itens registrados\n\n";
    }

}

void exibirProdutos(const Produto produtos[], int quantidadeAtual){
    int escolha;
    system("clear");
    cout << "[1] Exibir lista completa\n[2] Exibir produto\n";
    cin >> escolha;
    system("clear");
        switch(escolha){
            case 1:
                cout << "============================\n";
                if(quantidadedeprodutos == 0){
                    cout << "Sem produtos registrados.\n";
                    cout << "============================\n"; 
                }else if(quantidadedeprodutos >= 1){
                    for(int x = 1; x <= quantidadedeprodutos; ++x ){
                        cout << "> " << itens[x - 1].nome << endl;
                        cout << "Indice do produto: " << x - 1 << endl << endl;
                        cout << "Preço do produto: " << itens[x - 1].preco << endl;
                        cout << "Quantidade em stock: " << itens[x - 1].quantidade << endl;
                        cout << "\n============================\n";

                    }
                }
                

                break;
            case 2:
                int produtonumero;
                cout << "Inserir indice do produto\n";
                cin >> produtonumero;
                cout << "\n\n============================\n";
                cout << "> " << itens[produtonumero].nome << endl << endl;
                cout << "Preço do produto: " << itens[produtonumero].preco << endl;
                cout << "Quantidade em stock: " << itens[produtonumero].quantidade << endl;
                cout << "\n============================\n";
                break;
                
                
            default:
                cout << "Opção inválida";
            
        }
}

float calcularValorTotal(const Produto produtos[], int quantidadeAtual){
    system("clear");
    if(quantidadedeprodutos == 0){
                        cout << "Parece que não existem produtos para calcular...\n";}
                        
    else {
    cout << "\nCalculando o valor do stock..\n\n============================\n";
    float valorstock = 0;
    for(int x = 1; x <= quantidadedeprodutos; ++x ){
                        cout << "> " << itens[x - 1].nome << endl;

                        cout << "Preço do produto: " << itens[x - 1].preco << endl;
                        cout << "Quantidade em stock: " << itens[x - 1].quantidade << endl;
                        cout << "Valor de stock: " << itens[x - 1].preco * itens[x - 1].quantidade << endl;
                        cout << "\n============================\n";
                        valorstock = valorstock + (itens[x - 1].preco * itens[x - 1].quantidade);
                    }
                    

                            cout << "O valor do stock é de " << valorstock <<"€\n";
                    }

    
    return 0;
}



int main(){
    system("clear");
    while(true){
        int escolha;
        cout << "\n\n[1] Adicionar produtos \n[2] Exibir produtos \n[3] Calcular e exibir stock \n[0] Eliminar base de dados\n";
            cin >> escolha;
            int quantidadeinicial = 0;
    switch(escolha){
            case 1: 
                adicionarProduto(itens, quantidadedeprodutos);
                break;
            
            case 2:
                exibirProdutos(itens, quantidadedeprodutos);
                break;
            case 3:
                calcularValorTotal(itens, quantidadedeprodutos);
                break;
            case 0:
                cout << "A eliminar..." << endl;
                return 0;
    }
}


  return 0;
}