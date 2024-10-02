#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

int produtosid = 1;


void alterarprodutos(){

}
void exibirprodutos(){

}
void eliminarprodutos(){

}
void eliminar(){
    system("clear");
    cout << "Esta ação irá eliminar todos os dados da base de dados" << endl;
    cout << "De certeza que quer continuar?\n\n[1] - Sim\n[2] - Não\n";
    int eliminarcheck;
    cin >> eliminarcheck;
switch(eliminarcheck){
    case 1:
    system("clear");
    cout << "Ação cancelada.";
    system("clear");
    break;
    case 2:
    system("clear");
    remove("base.csv");
    cout << "Base de dados eliminada.\n\n";
    break;
    default:
    cout << "Opção inválida";
    break;
}
}
void addprodutos(){
    ofstream base("base.csv", ios :: app);
            system("clear");
        string nomeprod;
        cout << "Nome do produto:\n";
        cin >> nomeprod;
            system("clear");
        int quantidade;
        cout << "Quantidade:\n";
        cin >> quantidade;
            system("clear");
            
        float preco;
        cout << "Preço (Aceita vírgula)";
        cin >> preco;
            system("clear");


    base << produtosid << ", " << nomeprod << ", " << quantidade << ", " << preco << ", A\n";
    produtosid += 1;

    base.close();
}


int main(){
    system("clear");
    while(true){

    ifstream base;
    base.open("base.csv");

    if (base){
        cout << "Base de dados carregada\n";

    } else if (!base){
        cout << "Base de dados não encontrada\nPretende:\n[1] Criar base de dados\n[2] Ignorar e sair.\n";
        int createoption;
        cin >> createoption;
        
            if (createoption == 1){
                ofstream base("base.csv");
                base << "ID, NOME_DO_PRODUTO, QUANTIDADE, PRECO, STATUS\n";
                base.close();
                cout << "\nBase de dados criada.\n";
                sleep(1);

            }else{
                cout << "A sair..";
                return 0;
            }

    }

    system("clear");
        int escolha;
        cout << "Sistema da loja\n\n[1] Adicionar produtos \n[2] Exibir produtos \n[3] Calcular e exibir stock \n[0] Eliminar base de dados\n";
            cin >> escolha;

        switch(escolha){
            case 1:
                exibirprodutos();
                break;
            case 2:
                alterarprodutos();
                break;
            case 3:
                eliminarprodutos();
                break;
            case 4: 
                addprodutos();
                break;
            case 0:
            eliminar();
            break;
        }

    
    }
}

