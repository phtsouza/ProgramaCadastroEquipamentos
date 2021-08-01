#include<iostream>
#include<string.h>
#include<stdbool.h>
#include<fstream>
#define N 5

using namespace std;

class TipoEquipamento{ //Criacao a classe do tipo equipamento

private: // Atributos da classe
    string codigo;
    string descricao;

public: // Metodos da classe
    TipoEquipamento(){ // Construtor dos atributos
        descricao = "";
        codigo = "";
    }
    string getCodigo(){ // Metodo para acessar a parte privada da classe
        return codigo;
    }
    void setCodigo(string codigo){ // Metodo para setar o codigo da classe com o codigo recebido
        this->codigo = codigo;
    }
    string getDescricao(){
        return descricao;
    }
    void setDescricao(string descricao){
        this->descricao = descricao;
    }
    void resetCodigoDescricao(string codigo, string descricao){
        codigo = "";
        descricao= "";
    }
}TipoEquipamento[N];
/*
Procedimento para inserir um tipo de equipamento
Entrada: codigo e descricao do tipo do equipamento
Saida: Tipo de Equipamento preenchido
*/
void inserir(){
    string codigo;
    string descricao;

    cout << "Ditite o codigo do seu prodouto: ";
    fflush(stdin);
    getline(cin, codigo);
    cout << "Digite uma descricao para seu produto: ";
    fflush(stdin);
    getline(cin, descricao);
    for(int i=0; i<N; i++){
        if(TipoEquipamento[i].getCodigo()==""){
            TipoEquipamento[i].setCodigo(codigo);
            TipoEquipamento[i].setDescricao(descricao);
            break;
        }
    }
}
/*
Procedimento para pesquisar um tipo de equipamento
Entrada: codigo do tipo do equipamento
Saida: COdigo e descricao do tipo do equipamento informado
*/
void pesquisar(){

    string codigo;
    string descricao;

    cout << "Digite o codigo do seu produto: ";
    fflush(stdin);
    getline(cin, codigo);
    cout << "Caso nao mostre nada o produto nao foi registrado! " << endl;

    for(int i=0; i<N;i++){
        if(TipoEquipamento[i].getCodigo()!=""){
            if(TipoEquipamento[i].getCodigo()==codigo){
                descricao = TipoEquipamento[i].getDescricao();
                cout << "O codigo " << codigo << endl;
                cout << "Descricao: " << descricao << endl;
            }
        }
    }
}
/*
Procedimento para atualizar um tipo de equipamento
Entrada: codigo do tipo do equipamento
Saida: Tipo do equipamento atualizado a descricao e seu codigo
*/
void atualizar(){

    string codigo;
    string descricao;

    cout << "Informe qual codigo voce deseja atualizar: ";
    fflush(stdin);
    getline(cin, codigo);

    for(int i=0; i<N;i++){
        if(TipoEquipamento[i].getCodigo()!=""){
            if(TipoEquipamento[i].getCodigo()==codigo){
                TipoEquipamento[i].resetCodigoDescricao(codigo, descricao);
                cout << "Ditite um novo codigo do seu prodouto: ";
                fflush(stdin);
                getline(cin, codigo);
                cout << "Digite uma nova descricao para seu produto: ";
                fflush(stdin);
                getline(cin, descricao);
                TipoEquipamento[i].setCodigo(codigo);
                TipoEquipamento[i].setDescricao(descricao);
            }
            else{
                cout << "Esse produto nao foi registrado!" << endl;
            }
        }
    }
}
/*
Procedimento para excluir um tipo de equipamento
Entrada: codigo do tipo do equipamento
Saida: Deleta um tipo de equipamento, dando espaco para registrar um novo em seu lugar.
*/
void excluir(){

    string codigo;
    string descricao;
    int op;

    cout << "Informe qual codigo voce deseja excluir: ";
    fflush(stdin);
    getline(cin, codigo);

    for(int i=0; i<N;i++){
        if(TipoEquipamento[i].getCodigo()!=""){
            if(TipoEquipamento[i].getCodigo()==codigo){
                codigo = "";
                descricao = "";
                TipoEquipamento[i].setCodigo(codigo);
                TipoEquipamento[i].setDescricao(descricao);
                cout << "Seu produto foi excluido com sucesso!" << endl;
            }
            else{
                cout << "Esse produto nao foi registrado!" << endl;
            }
        }
    }
}
/*
Procedimento para realizar o CRUD do tipo do equipamento.
Entrada: opcao que voce deseja fazer no tipo do equipamento
*/
void CrudTipoEquipamento(){

    char op;
    do{
        cout << "[A] Inserir" << endl;
        cout << "[B] Pesquisar" << endl;
        cout << "[C] Atualizar" << endl;
        cout << "[D] Excluir" << endl;
        cout << "[Z] Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> op;

        switch(op){
            case 'A':
                inserir();
                break;
            case 'B':
                pesquisar();
                break;
            case 'C':
                atualizar();
                break;
            case 'D':
                excluir();
                break;
        }
    }while(op!='Z');
}

class Departamento : public TipoEquipamento{ // Criacao da classe Departamento, pelo qual eh filha do TipoEquipamento
private: // Atributos da classe
    string nome;
    string local;

public: // Metodos da classe
    Departamento(){ // Criacao do construtor dos atributos
        nome = "";
        local = "";
    }
    string getNome(){
        return nome;
    }
    void setNome(string nome){
        this->nome = nome;
    }
    string getLocal(){
        return local;
    }
    void setLocal(string local){
        this->local = local;
    }
    void resetNomeLocal(string nome, string local){
        nome = "";
        local= "";
    }
}departamento[N];
/*
Procedimento para inserir um departamento
Entrada: nome, local, codigo e descricao do departamento
Saida: departamento preenchido
*/
void inserirDepartamento(){

    string nome;
    string local;
    string codigo;
    string descricao;

    cout << "Ditite o codigo do seu departamento: ";
    fflush(stdin);
    getline(cin, codigo);
    cout << "Digite um nome para seu departamento: ";
    fflush(stdin);
    getline(cin, nome);
    cout << "Ditite uma descricao para seu departamento: ";
    fflush(stdin);
    getline(cin, descricao);
    cout << "Digite o local do seu departamento: ";
    fflush(stdin);
    getline(cin, local);

    for(int i=0; i<N; i++){
        if(departamento[i].getCodigo()==""){
            departamento[i].setCodigo(codigo);
            departamento[i].setDescricao(descricao);
            departamento[i].setNome(nome);
            departamento[i].setLocal(local);
            break;
        }
    }
}
/*
Procedimento para pesquisar um departamento
Entrada: codigo do departamento
Saida: Informacoes do departamento
*/
void pesquisarDepartamento(){

    string nome;
    string local;
    string codigo;
    string descricao;

    cout << "Digite o codigo do seu departamento: ";
    fflush(stdin);
    getline(cin, codigo);
    cout << "Caso nao mostre nada o seu departamento nao foi registrada" << endl;

    for(int i=0; i<N;i++){
        if(departamento[i].getCodigo()!=""){
            if(departamento[i].getCodigo()==codigo){
                descricao = departamento[i].getDescricao();
                local = departamento[i].getLocal();
                nome = departamento[i].getNome();
                cout << "O codigo " << codigo << endl;
                cout << "Nome: " << nome << endl;
                cout << "Descricao: " << descricao << endl;
                cout << "Local: " << local << endl;
            }
        }
    }
}
/*
Procedimento para atualizar um departamento
Entrada: codigo do departamento
Saida: Informacoes atualizadas do departamento
*/
void atualizarDepartamento(){

    string nome;
    string local;
    string codigo;
    string descricao;

    cout << "Informe qual codigo voce deseja atualizar: ";
    fflush(stdin);
    getline(cin, codigo);

    for(int i=0; i<N;i++){
        if(departamento[i].getCodigo()!=""){
            if(departamento[i].getCodigo()==codigo){
                departamento[i].resetCodigoDescricao(codigo, descricao);
                departamento[i].resetNomeLocal(nome, local);
                cout << "Digite um novo codigo do seu departamento: ";
                fflush(stdin);
                getline(cin, codigo);
                cout << "Digite um novo nome para seu departamento: ";
                fflush(stdin);
                getline(cin, nome);
                cout << "Digite uma nova descricao para seu departamento: ";
                fflush(stdin);
                getline(cin, descricao);
                cout << "Digite uma nova localizacao para seu departamento: ";
                fflush(stdin);
                getline(cin, local);
                departamento[i].setCodigo(codigo);
                departamento[i].setDescricao(descricao);
                departamento[i].setNome(nome);
                departamento[i].setLocal(local);
            }
            else{
                cout << "Esse produto nao foi registrado!" << endl;
            }
        }
    }
}
/*
Procedimento para excluir um departamento
Entrada: codigo do departamento
Saida: Exclusao de um departamento
*/
void excluirDepartamento(){

    string nome;
    string local;
    string codigo;
    string descricao;
    int op;

    cout << "Informe qual codigo voce deseja excluir: ";
    fflush(stdin);
    getline(cin, codigo);

    for(int i=0; i<N;i++){
        if(departamento[i].getCodigo()!=""){
            if(departamento[i].getCodigo()==codigo){
                codigo = "";
                local = "";
                nome = "";
                descricao = "";
                departamento[i].setCodigo(codigo);
                departamento[i].setDescricao(descricao);
                departamento[i].setNome(nome);
                departamento[i].setLocal(local);
                cout << "Seu produto foi excluido com sucesso!" << endl;
            }
            else{
                cout << "Esse produto nao foi registrado!" << endl;
            }
        }
    }
}

void CrudDepartamento(){

char op;
    do{
        cout << "[A] Inserir" << endl;
        cout << "[B] Pesquisar" << endl;
        cout << "[C] Atualizar" << endl;
        cout << "[D] Excluir" << endl;
        cout << "[Z] Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> op;

        switch(op){
            case 'A':
                inserirDepartamento();
                break;
            case 'B':
                pesquisarDepartamento();
                break;
            case 'C':
                atualizarDepartamento();
                break;
            case 'D':
                excluirDepartamento();
                break;
        }
    }while(op!='Z');
}
 //Tentei porem meu CRUD equipamentos nao estava dando certo de nenhuma maneira.
class Equipamentos : public Departamento{
private:
    float preco;
    TipoEquipamento equip;
    Departamento depart;

public:
    Equipamentos(){
        preco = 0;
    }
    float getPreco(){
        return preco;
    }
    void setPreco(float preco){
        this->preco = preco;
    }
    TipoEquipamento getTipo(){
        return equip;
    }
    void setTipo(TipoEquipamento equipament){
        equip = equipament;
    }
    Departamento getDepartamento(){
        return depart;
    }
    void setDepart(Departamento depart){
        this->depart = depart;
    }

} Equipamentos[N];

void inserirEquipamento(){

    float preco;
    string codigoDepartamento, codigoTipoEquipamento, codigo;
    string nome;

    cout << "Informe o nome do seu produto: ";
    fflush(stdin);
    getline(cin, nome);
    cout << "Informe o codigo do seu produto: ";
    fflush(stdin);
    getline(cin, codigo);
    cout << "Informe o preco do seu produto: ";
    cin >> preco;
    cout << "Informe o seu codigo do Tipo de Equipamento ja existente: ";
    fflush(stdin);
    getline(cin, codigoTipoEquipamento);
    cout << "Informe o seu codigo do Departamento ja existente: ";
    fflush(stdin);
    getline(cin, codigoDepartamento);

    for(int i=0; i<N; i++){
        if(codigoTipoEquipamento == TipoEquipamento[i].getCodigo()){
            Equipamentos[i].setTipo(TipoEquipamento[i]);
            break;
        }
    }
    for(int i=0; i<N; i++){
        if(codigoDepartamento == departamento[i].getCodigo()){
            Equipamentos[i].setDepart(departamento[i]);
            break;
        }
    }
    for(int i=0; i<N; i++){
        if(Equipamentos[i].getCodigo()==""){
            Equipamentos[i].setCodigo(codigo);
            Equipamentos[i].setNome(nome);
            Equipamentos[i].setPreco(preco);
            break;
        }
    }
}

void pesquisarEquipamento(){

    string codigo;

    cout << "Digite o codigo do seu equipamento: ";
    fflush(stdin);
    getline(cin, codigo);
    cout << "Caso nao mostre nada o seu equipamento nao foi registrada" << endl;

    for(int i=0; i<N;i++){
        if(Equipamentos[i].getCodigo()!=""){
            if(Equipamentos[i].getCodigo()==codigo){
                cout << "Codigo: " << codigo << endl;
                cout << "Nome: " << Equipamentos[i].getNome() << endl;
                cout << "Preco: " << Equipamentos[i].getPreco() << endl;
                cout << "Descricao do equipamento: "<< Equipamentos[i].getTipo().getDescricao() << endl;
                cout << "Departamento: " << Equipamentos[i].getDepartamento().getNome() << endl;
                cout << "Localidade: " << Equipamentos[i].getDepartamento().getLocal() << endl;
                cout << "Descricao do tipo: " << Equipamentos[i].getTipo().getDescricao() << endl;
            }
            else{
                cout << "Esse produto nao foi registrado!" << endl;
            }
        }
    }
}
/*
Procedimento para atualizar um equipamento
Entrada: codigo de um equipamento e o novo codigo, nome e preco
Saida: Equipamento com suas caracteristicas atualizada.
*/
void atualizarEquipamentos(){

    string codigo;
    string nome;
    float preco;

    cout << "Digite o codigo do equipamento que deseja atualizar: ";
    fflush(stdin);
    getline(cin, codigo);

    for(int i=0; i<N;i++){
        if(Equipamentos[i].getCodigo()!=""){
            if(Equipamentos[i].getCodigo()==codigo){
                codigo = "";
                nome = "";
                preco = 0;
                cout << "Digite um novo codigo: " << endl;
                fflush(stdin);
                getline(cin, codigo);
                cout << "Digite um novo nome: " << endl;
                fflush(stdin);
                getline(cin, nome);
                cout << "Digite um novo preco: " << endl;
                cin >> preco;

                Equipamentos[i].setCodigo(codigo);
                Equipamentos[i].setNome(nome);
                Equipamentos[i].setPreco(preco);
                break;
            }
            else{
                cout << "Esse produto nao foi registrado!" << endl;
            }
        }
    }
}
/*
Procedimento feito para excluir um equipamento
Entrada: codigo de um equipamento que deseja excluir
Saida: Set o codigo como nada.
*/
void excluirEquipamento(){

    string codigo;

    cout << "Digite o codigo do equipamento que deseja atualizar: ";
    fflush(stdin);
    getline(cin, codigo);

    for(int i=0; i<N;i++){
        if(Equipamentos[i].getCodigo()!=""){
            if(Equipamentos[i].getCodigo()==codigo){
                codigo = "";
                Equipamentos[i].setCodigo(codigo);
                cout << "Produto excluido com sucesso!" << endl;
                break;
            }
            else{
                cout << "Esse produto nao foi registrado!" << endl;
            }
        }
    }
}

void CrudEquipamentos(){

char op;
    do{
        cout << "[A] Inserir" << endl;
        cout << "[B] Pesquisar" << endl;
        cout << "[C] Atualizar" << endl;
        cout << "[D] Excluir" << endl;
        cout << "[Z] Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> op;

        switch(op){
        case 'A':
            inserirEquipamento();
            break;
        case 'B':
            pesquisarEquipamento();
            break;
        case 'C':
            atualizarEquipamentos();
            break;
        case 'D':
            excluirEquipamento();
            break;
        }
    }while(op!='Z');
}

/*
Procedimento para listar os tipos de equipamentos registrados
*/
void listaTipoEquipamentos(){

    string codigo;
    string descricao;

    for(int i=0; i<N;i++){
        if(TipoEquipamento[i].getCodigo()!=""){
            codigo = TipoEquipamento[i].getCodigo();
            descricao = TipoEquipamento[i].getDescricao();
            cout << "O codigo: " << codigo << endl;
            cout << "Descricao: " << descricao << endl;
        }
    }
}
/*
Procedimento para listar os departamentos preenchidos
*/
void listaDepartamentos(){

    string nome;
    string local;
    string codigo;
    string descricao;
    int op;

    for(int i=0; i<N;i++){
        if(departamento[i].getCodigo()!=""){
            cout << "Voce deseja filtra por codigo e descricao? [1]Sim [2] Nao"<< endl;
            cin >> op;

            codigo = departamento[i].getCodigo();
            descricao = departamento[i].getDescricao();
            local = departamento[i].getLocal();
            nome = departamento[i].getNome();
            if(op==2){
            cout << "O codigo " << codigo << endl;
            cout << "Nome: " << nome << endl;
            cout << "Descricao: " << descricao << endl;
            cout << "Local: " << local << endl;
            }
            if(op==1){
                cout << "O codigo " << codigo << endl;
                cout << "Descricao: " << descricao << endl;
            }
        }
    }
}
// Procedimento para listar todos os equipamentos e suas caracteristicas ja cadastradas
void listarEquipamentos(){

    for(int i=0; i<N;i++){
        if(Equipamentos[i].getCodigo()!=""){
            cout << "Codigo: " << Equipamentos[i].getCodigo() << endl;
            cout << "Nome: " << Equipamentos[i].getNome() << endl;
            cout << "Preco: " << Equipamentos[i].getPreco() << endl;
            cout << "Descricao do equipamento: "<< Equipamentos[i].getTipo().getDescricao() << endl;
            cout << "Departamento: " << Equipamentos[i].getDepartamento().getNome() << endl;
            cout << "Localidade: " << Equipamentos[i].getDepartamento().getLocal() << endl;
            cout << "Descricao do tipo: " << Equipamentos[i].getTipo().getDescricao() << endl;
        }
    }
}
/*
Procedimento para salvar no arquivo todas as informacoes passadas
Entrada: nome do arquivo que deseja salvar
Saida: Arquivo preenchido com as informacoes passadas.
*/
void salvarDadosArquivo(){
    string arquivo;

    cout << "Informe o nome do arquivo.txt que voce deseja salvar: " << endl;
    fflush(stdin);
    getline(cin, arquivo); // Salva o nome do arquivo informado
    ofstream out(arquivo); // Abre o arquivo para escrita
    out << "Tipos de equipamentos" << endl;
    out << endl;
    for(int i=0; i<N; i++){
        if(TipoEquipamento[i].getCodigo()!=""){
            out << "Codigo: " << TipoEquipamento[i].getCodigo() << endl;
            out << "Descricao: " << TipoEquipamento[i].getDescricao() << endl;
            out << endl;
        }
    }

    out << "Departamentos" << endl;
    out << endl;
    for(int i=0; i<N; i++){
        if(departamento[i].getCodigo()!=""){
            out << "Codigo: " << departamento[i].getCodigo() << endl;
            out << "Nome: " << departamento[i].getNome() << endl;
            out << "Localidade: " << departamento[i].getLocal() << endl;
            out << "Descricao: " << departamento[i].getDescricao() << endl;
            out << endl;
        }
    }

    out << "Equipamentos" << endl;
    out << endl;
    for(int i=0; i<N;i++){
        if(Equipamentos[i].getCodigo()!=""){
            out << "Codigo: " << Equipamentos[i].getCodigo() << endl;
            out << "Nome: " << Equipamentos[i].getNome() << endl;
            out << "Preco: " << Equipamentos[i].getPreco() << endl;
            out << "Descricao do equipamento: "<< Equipamentos[i].getTipo().getDescricao() << endl;
            out << "Departamento: " << Equipamentos[i].getDepartamento().getNome() << endl;
            out << "Localidade: " << Equipamentos[i].getDepartamento().getLocal() << endl;
            out << "Descricao do tipo: " << Equipamentos[i].getTipo().getDescricao() << endl;
            out << endl;
        }
    }
    out.close(); // Fecha o arquivo
}
/*
Procedimento para listar as informacoes dentro de um arquivo
Entrada: nome de um arquivo para leitura
Saida: Listagem dos dados preenchidos dentro do arquivo informado
*/
void listaDadosArquivo(){
    string arquivo;
    cout << "Informe o nome do arquivo txt que voce deseja ler" << endl;
    fflush(stdin);
    getline(cin, arquivo); // Armazena o nome do arquivo para leitura

    ifstream in(arquivo); // Abre o arquivo para leitura
    if(in.is_open()){
        while(!in.eof()){
            getline(in, arquivo);
            cout << arquivo << endl;
        }
    }
    else{
        cout << "Impossivel abrir o arquivo!";
    }
    in.close(); // Fecha o arquivo
}
/*
Procedimento pelo qual demonstra as opcoes para a escolha do usuario
Entrada: Alguma letra de escolha do usuario
Saida: chama o procedimento relacionado de cada opcao.
*/
void menuOpcoes(){
    char opc;

    do{
        cout << "[C] CRUD de tipo de equipamento" << endl;
        cout << "[D] CRUD de departamento" << endl;
        cout << "[E] CRUD de  equipamentos " << endl;
        cout << "[F] Lista de tipos de equipamento" << endl;
        cout << "[G] Lista de departamento" << endl;
        cout << "[H] Lista de equipamentos" << endl;
        cout << "[I] Salvar os dados em arquivo" << endl;
        cout << "[J] Listar os dados armazenados em um arquivo" << endl;
        cout << "[Z] Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opc;

        switch(opc){
            case 'C':
                CrudTipoEquipamento();
                break;
            case 'D':
                CrudDepartamento();
                break;
            case 'E':
                CrudEquipamentos();
                break;
            case 'F':
                listaTipoEquipamentos();
                break;
            case 'G':
                listaDepartamentos();
                break;
            case 'H':
                listarEquipamentos();
                break;
            case 'I':
                salvarDadosArquivo();
                break;
            case 'J':
                listaDadosArquivo();
                break;
        }
    }while(opc!='Z');
}

int main(){

    menuOpcoes();
}
