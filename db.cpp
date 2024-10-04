#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sstream>
#include <string>

using namespace std;

void clearterminal() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");  // Windows command to clear terminal
    #else
        system("clear");  // Linux/Unix command to clear terminal
    #endif
}


void alterarprodutos() {
    int id;
    string novaquantidade, novopreco;

    cout << "Introduzir ID do produto a alterar:\n";
    cin >> id;
    cout << "Introduzir nova quantidade:\n";
    cin >> novaquantidade;
    cout << "Introduzir novo preço:\n";
    cin >> novopreco;

    ifstream file("base.csv");
    stringstream buffer;
    string linha;
    int indexid = id + 2; 
    int currentLine = 1;  

    // file temporario
    buffer << file.rdbuf();
    file.close();

    ofstream outfile("base.csv");
    stringstream content(buffer.str());

    // processa cada linha
    while (getline(content, linha)) {
        if (currentLine == indexid) {

            stringstream ss(linha);
            string idStr, nome, quantidade, preco, status;

            getline(ss, idStr, ',');
            getline(ss, nome, ',');
            getline(ss, quantidade, ',');
            getline(ss, preco, ',');
            getline(ss, status, ',');


            quantidade = novaquantidade;
            preco = novopreco;

            cout << "Produto com ID " << id << " alterado. Nova quantidade: " << quantidade << ", Novo preço: " << preco << endl;


            linha = idStr + ", " + nome + ", " + quantidade + ", " + preco + ", " + status;
        }

    //guarda
        outfile << linha << endl;
        currentLine++;
    }

    outfile.close();
}

void exibirprodutos(){
    clearterminal();
    ifstream file("base.csv"); 
    string line;
    
    getline(file, line);

     while (getline(file, line)) {
        stringstream ss(line); // isto é um stringstream 👍
        string id, nome, quantidade, preco, status;

    //lê as linhas
        getline(ss, id, ',');
        getline(ss, nome, ',');
        getline(ss, quantidade, ',');
        getline(ss, preco, ',');
        getline(ss, status, ',');

    //rele as linhas
        cout << "ID: " << id << endl;
        cout << "Nome: " << nome << endl;
        cout << "Quantidade: " << quantidade << endl;
        cout << "Preço: " << preco << endl;
        cout << "Status: " << status << endl;
        cout << "===========================" << endl; 
    }

    file.close(); // Close the file

}


void eliminarprodutos() {
    int id;
    cout << "Introduzir ID a eliminar:\n";
    cin >> id;

    ifstream file("base.csv");
    stringstream buffer;
    string linha;
    int indexid = id + 2; 
    int currentLine = 1; 

//buffer
    buffer << file.rdbuf(); 
    file.close();

//abre o ficheiro
    ofstream outfile("base.csv");
    stringstream content(buffer.str());

//analisa cada linha
    while (getline(content, linha)) {
        if (currentLine == indexid) {
//modifica
            stringstream ss(linha);
            string idStr, nome, quantidade, preco, status;

            getline(ss, idStr, ',');
            getline(ss, nome, ',');
            getline(ss, quantidade, ',');
            getline(ss, preco, ',');
            getline(ss, status, ',');

//se for A muda para D
            if (status == "A") {
                status = "D";
                cout << "Produto com ID " << id << " alterado de A para D." << endl;
            } else { //case não seja A não muda
                cout << "O estado do produto não é 'A'. Nenhuma alteração feita." << endl;
            }

// linha que substitui
            linha = idStr + ", " + nome + ", " + quantidade + ", " + preco + ", " + status;
        }

// altera o ficheiro
        outfile << linha << endl;
        currentLine++;
    }

    outfile.close();
}

void addprodutos(int produtosid){
    ofstream base("base.csv", ios :: app);//APPEND MODE porque tava a limpar linhas
            clearterminal();
        string nomeprod;
            cout << "Nome do produto:\n";
                cin >> nomeprod;
                    clearterminal();
        int quantidade;
            cout << "Quantidade:\n";
                cin >> quantidade;
                    clearterminal();
        float preco;
            cout << "Preço\n";
                cin >> preco;
                    clearterminal();

    base << produtosid << ", " << nomeprod << ", " << quantidade << ", " << preco << ", A\n";

    base.close();
}

int contarlinhas(const string& filename) {
    ifstream file(filename);
    int lineCount = 0;
    string line;
    
    // lê cada linha e faz incrementação
    while (getline(file, line)) {
        ++lineCount;
    }

    file.close();
    return lineCount; 
}

int main(){

    clearterminal();
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

    int produtosid = contarlinhas("base.csv") - 1;
    clearterminal();

        int escolha;
        cout << "Sistema da loja\n\n[1] Exibir Produtos\n[2] Alterar Produtos \n[3] Eliminar Produtos \n[4] Adicionar produtos \n";
            cin >> escolha;

        switch(escolha){
            case 1:
                exibirprodutos();
                int ok;
                cout << "\nPressione qualquer botão para continuar..";
                cin >> ok;
                break;
            case 2:
                alterarprodutos();
                break;
            case 3:
                eliminarprodutos();
                break;
            case 4: 
                addprodutos(produtosid);
                break;
        }

    
    }
}

