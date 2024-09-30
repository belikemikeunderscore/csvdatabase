#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;




void eliminar(){
    system("clear");
    cout << "Esta ação irá eliminar todos os dados da base de dados\nDe certeza que quer continuar?\n\n[1] - Sim\n[2] - Não\n";
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
    base << "thing\n";
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
                base << "ID, NOME_DO_PRODUTO, QUANTIDADE, PRECO, STATUS";
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
                addprodutos();
                break;
            case 2:

            case 3:

            case 4:


            case 0:
            eliminar();
        }

    
    }
}

