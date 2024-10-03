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
    string newQuantidade, newPreco;

    // Get product ID, new quantity, and new price from user
    cout << "Introduzir ID do produto a alterar:\n";
    cin >> id;
    cout << "Introduzir nova quantidade:\n";
    cin >> newQuantidade;
    cout << "Introduzir novo preço:\n";
    cin >> newPreco;

    ifstream file("base.csv");
    stringstream buffer;
    string line;
    int indexid = id + 2; // Assuming the first two lines are headers
    int currentLine = 1;  // To track the current line number

    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    // Read the entire file into the buffer
    buffer << file.rdbuf();
    file.close();

    // Reopen the file for writing
    ofstream outfile("base.csv");
    stringstream content(buffer.str());

    // Process each line
    while (getline(content, line)) {
        if (currentLine == indexid) {
            // Modify the target line
            stringstream ss(line);
            string idStr, nome, quantidade, preco, status;

            getline(ss, idStr, ',');
            getline(ss, nome, ',');
            getline(ss, quantidade, ',');
            getline(ss, preco, ',');
            getline(ss, status, ',');

            // Update the quantity and price
            quantidade = newQuantidade;
            preco = newPreco;

            cout << "Produto com ID " << id << " alterado. Nova quantidade: " << quantidade << ", Novo preço: " << preco << endl;

            // Rebuild the modified line
            line = idStr + "," + nome + "," + quantidade + "," + preco + "," + status;
        }

        // Write the current (or modified) line back to the file
        outfile << line << endl;
        currentLine++;
    }

    outfile.close();
}

void exibirprodutos(){
    clearterminal();
    ifstream file("base.csv"); // Open the file
    string line;
    
    getline(file, line);

    // Read each line and display product information
    while (getline(file, line)) {
        stringstream ss(line); // Create a stringstream to parse the line
        string id, nome, quantidade, preco, status;

        // Read the fields separated by commas
        getline(ss, id, ',');
        getline(ss, nome, ',');
        getline(ss, quantidade, ',');
        getline(ss, preco, ',');
        getline(ss, status, ',');

        // Output the product details
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
    string line;
    int indexid = id + 2; // Assuming the first two lines are headers
    int currentLine = 1;  // To track the current line number

    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    // Prepare a buffer to store all the lines
    buffer << file.rdbuf(); 
    file.close();

    // Reopen the file for writing
    ofstream outfile("base.csv");
    stringstream content(buffer.str());

    // Process each line and modify the target one
    while (getline(content, line)) {
        if (currentLine == indexid) {
            // Modify the target line
            stringstream ss(line);
            string idStr, nome, quantidade, preco, status;

            getline(ss, idStr, ',');
            getline(ss, nome, ',');
            getline(ss, quantidade, ',');
            getline(ss, preco, ',');
            getline(ss, status, ',');

            // Check if status is 'A' and change it to 'D'
            if (status == "A") {
                status = "D";
                cout << "Produto com ID " << id << " alterado de A para D." << endl;
            } else {
                cout << "O estado do produto não é 'A'. Nenhuma alteração feita." << endl;
            }

            // Rebuild the modified line
            line = idStr + "," + nome + "," + quantidade + "," + preco + "," + status;
        }

        // Write the current (or modified) line back to the file
        outfile << line << endl;
        currentLine++;
    }

    outfile.close();
}

void addprodutos(int produtosid){
    ofstream base("base.csv", ios :: app);
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
    
    // Read each line and increment the count
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

