/*!
 * \file sudomaster.cpp
 * ler_arquivo, insert_gestores, procurar_gestores, senha_gestor, adicionar_gestores, excluir_gestores, listar_gestores, exit_or_continue, menu_sudomaster.
 * \author Hannah Beatryz L. S.
 * \date May 1rst, 2023.
 */

#include "HSudoMaster.hpp"


/*!
 * Transforma um arquivo em um vetor.
 * \param vetor_armazenador vetor que receberá as linhas de um arquivo.
 * \param Arquivo arquivo para ser lido.
 */
void ler_arquivo(std::vector<std::string> &vetor_armazenador, std::string Arquivo){
    std::fstream Leitor;
    std::string linha;
    Leitor.open(Arquivo, std::ios::in|std::ios::app);
    while (std::getline(Leitor, linha)){
        vetor_armazenador.push_back(linha);
    }
    Leitor.close();
}


/*!
 * Transforma um vetor com as informações de um arquivo num map<chave:string, vector<struct>>.
 * \param cadastro_gestores vetor que possui as linhas do arquivo de gestores.
 * \param cadastrados map que vai receber as informações contidas no cadastro.
 * \param email string que será chave do map, guardando as informações de um gestor no map.
 */
void insert_gestores(std::vector<std::string> &cadastro_gestores, std::map<std::string, Gestores> cadastrados, std::string email){
    Gestores gestor;
    for (auto i{0}; i < cadastro_gestores.size(); i=+3){
        email = cadastro_gestores[i];
        gestor.nome_gestor = cadastro_gestores[i+1];
        gestor.senha_gestor = cadastro_gestores[i+2];
        cadastrados[email] = gestor;
    }
}


/*!
 * Procura no arquivo o email de um gestor, caso exista, retorna 1, caso contrário, retorna 0.
 * \param email string com o email do gestor a ser procurado
 */
int procurar_gestor(std::string email){
    std::string linha;
    std::fstream Cadastro;
    Cadastro.open(Arquivo_Gestores, std::ios::in|std::ios::app);
    while (std::getline(Cadastro, linha)){
        if (email.compare(linha) == 0){
            Cadastro.close();
            return 1;
            break;
        }
    }
    Cadastro.close(); 
    return 0;
}


/*!
 * Compara a senha inputada com a senha de determinado gestor.
 * \note O gestor precisa existir.
 * \param cadastrados map que armazena os Gestores
 * \param email chave do map.
 * \param senha string de uma senha inputada para entrar no sistema.
*/
int senha_gestor(std::map<std::string, Gestores> cadastrados, std::string email, std::string senha){
    Gestores gestor;
    if (cadastrados[email].senha_gestor == senha){
        return 1;
    }
    return 0;
}


/*!
 * Cadastra uma nova pessoa na função de gestor caso o email não exista, caso contrário retorna mensagem de erro.
 * \note Precisa ter um email diferente de um gestor já existente.
 * \param Cadastro Arquivo que armazena os logins e senhas dos gestores.
 * \param novo_email string com email da nova pessoa a ser cadastrada como gestora.
 */
void adicionar_gestores(std::fstream *Cadastro, std::string novo_email){
    std::string novo_nome, nova_senha;
    *Cadastro << novo_email << std::endl;
    std::cout << "Qual é o nome do(a) novo(a) gestor(a)?" << std::endl;
    std::getline(std::cin >> std::ws, novo_nome);
    *Cadastro << novo_nome << std::endl;
    std::cout << "Qual é a senha desse(a) novo(a) gestor(a)?" << std::endl;
    std::getline(std::cin >> std::ws, nova_senha);
    *Cadastro << nova_senha << std::endl;
}


/*!
 * Exclui uma pessoa existente da função de gestor.
 * \note O gestor precisa existir.
 * \param cadastrados map com as informações dos gestores.
 * \param email string com o email do gestor a ser excluído.
 * \param cadastro_gestores vetor que possui as linhas do arquivo de gestores.
 */
void excluir_gestores(std::map<std::string, Gestores> &cadastrados, std::string email, std::vector<std::string> &cadastro_gestores){
    std::fstream Excluir;
    remove("Cadastro_Gestores.txt");
    cadastrados.erase(email);
    for (auto j{0}; j < cadastro_gestores.size(); ++j){
        if (cadastro_gestores[j] == email){
            cadastro_gestores.erase(cadastro_gestores.end()-cadastro_gestores.size()+j);
            cadastro_gestores.erase(cadastro_gestores.end()-cadastro_gestores.size()+j+1);
            cadastro_gestores.erase(cadastro_gestores.end()-cadastro_gestores.size()+j+2);
            break;
        }
    }
    Excluir.open(Arquivo_Gestores, std::ios::out);
    for (auto i{0}; i < cadastro_gestores.size(); ++i){
        Excluir << cadastro_gestores[i] << std::endl;
    }
    Excluir.close();
    if (procurar_gestor(email) == 0){
        std::cout << "Gestor excluído com sucesso!" << std::endl;
    }
    else {
        std::cout << "O Gestor não quer ir embora. >:<" << std::endl;
    }
}


/*!
 * Lista os gestores existentes no arquivo.
 * \param cadastro_gestores vetor que possui as linhas do arquivo de gestores.
*/
void listar_gestores(std::vector<std::string> &cadastro_gestores){
    std::cout << "Os gestores cadastrados são:" << std::endl; 
    int kount{1};
    for (auto i{0}; i < cadastro_gestores.size(); i=+3){
        std::cout << kount << " - Email: " << cadastro_gestores[i] << std::endl
                  << "  - Nome: " << cadastro_gestores[i+1] << std::endl;
        ++kount;
    }
}


/*!
 * Determina a parada de uma execução do tipo "do{}while(continuar == 1);".
 * \note Sem parâmetros, apenas analisa um char que será inputado.
 */
int exit_or_continue(){
    char yes_or_no;
    std::cin >> yes_or_no;
    switch(toupper(yes_or_no)){
        case 'Y':
            return 1;
            break;
        case 'N':
            return 0;
            break;
        default:
            std::cout << "Resposta inválida, tente novamente." << std::endl;
            return exit_or_continue();
    }
}


/*!
 * Executa o menu gerenciador da SudoMaster.
 * \note É um auxiliar para executar as outras funções.
 * \param cadastro_gestores vetor que possui as linhas do arquivo de gestores.
 * \param cadastrados map com as informações dos gestores.
 */
void menu_sudomaster(std::vector<std::string> &cadastro_gestores, std::map<std::string, Gestores> &cadastrados){
    int opt, continuar{1}, confirmar;
    std::string email;
    std::fstream Cadastro;
    std::cout << "O que você deseja fazer hoje?:)" << std::endl
              << "1 - Adicionar Gestores" << std::endl
              << "2 - Excluir Gestores" << std::endl
              << "3 - Listar Gestores cadastrados" << std::endl;
    std::cin >> opt;
    if (opt == 1){
        do{
            std::cout << "Qual o email do(a) novo(a) gestor(a)?" << std::endl;
            std::getline(std::cin >> std::ws, email);
            if(procurar_gestor(email) == 0){
                Cadastro.open(Arquivo_Gestores, std::ios::out|std::ios::app);
                adicionar_gestores(&Cadastro, email);
                Cadastro.close();
                insert_gestores(cadastro_gestores, cadastrados, email);
            }
            else{
                std::cout << "Esse e-mail já está cadastrado, por favor, confira o e-mail fornecido e tente novamente.:(" << std::endl;
            }
            std::cout << "Deseja adicionar mais gestores(as)? (y/n)" << std::endl;
            continuar = exit_or_continue();
        }while(continuar == 1);
        continuar = 1;
    }
    else if (opt == 2){
        do{
            std::cout << "Qual é o email do(a) gestor(a) a ser excluído?" << std::endl;
            std::getline(std::cin >> std::ws, email);
            std::cout << "Você tem certeza? Essa ação não pode ser desfeita. (y/n)" << std::endl;
            std::cin >> confirmar;
            confirmar = exit_or_continue();
            if (confirmar == 1 && procurar_gestor(email) == 1) {
                excluir_gestores(cadastrados, email, cadastro_gestores);
            }
            else if (confirmar == 1 && procurar_gestor(email) == 0){
                std::cout << "Esse e-mail não está cadastrado." << std::endl;
            }
            else {
                std::cout << "O gestor vive mais um dia!" << std::endl;
            }
            std::cout << "Deseja excluir outros gestores(as)? (y/n)" << std::endl;
            continuar = exit_or_continue();
        }while(continuar == 1);
        continuar = 1;
    }
    else if (opt == 3){
        listar_gestores(cadastro_gestores);
    }
    else {
        std::cout << "Infelizmente a opção selecionada não é válida, caso queira adicionar alguma funcionalidade... Você já sabe. ;)" << std::endl;
    }
}
