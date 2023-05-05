#include "HAtendentes.hpp"
#include "HGestores.hpp"
#include "HSudoMaster.hpp"

int main(){
    int opt, carry_on{1}, menu_on;
    std::string login, senha;
    std::vector<std::string> cadastro_gestores, cadastro_medicos; // vetor com as linhas do cadastro de gestores e vetor com as linhas do cadastro de medicos.
    std::map<std::string, Gestores> cadastrados; // map com os gerentes do arquivo.

    do{
        std::cout << "Bem vindo(a), antes de começarmos, informe-nos sua função." << std::endl
                  << "1 - Gestor(a)" << std::endl
                  << "2 - Atendente" << std::endl;
        std::cin >> opt;
        menu_on = 1;
        if (opt == 0){
            ler_arquivo(cadastro_gestores, Arquivo_Gestores);
            std::cout << "Oh! Bem vinda, SudoMaster!" << std::endl
                      << "Prezamos por sua segurança, portanto, confirme sua senha.;)" << std::endl;
            std::getline(std::cin >> std::ws, senha);
            if (senha.compare(senha_sudomaster) == 0){
                do{
                    menu_sudomaster(cadastro_gestores, cadastrados);
                    std::cout << "Deseja continuar? (y/n)" << std::endl;
                    menu_on = exit_or_continue();
                }while (menu_on == 1);
            }
            else{
                std::cout << "Você não é a verdadeira SudoMaster.>:C" << std::endl
                          << "Volte para onde veio, Impostor!" << std::endl;
            }
        }
        if (opt == 1){
            ler_arquivo(cadastro_gestores, Arquivo_Gestores);
            std::cout << "Bem vindo, gestor(a), antes de começarmos, informe-nos seu login e senha." << std::endl
                      << "Login: " << std::endl;
            std::getline(std::cin >> std::ws, login);
            if (procurar_gestor(login) == 1){
                std::cout << "Senha: " << std::endl;
                std::getline(std::cin >> std::ws, senha);
                if (senha_gestor(cadastrados, login, senha) == 1){
                    ler_arquivo(cadastro_medicos, Arquivo_Medicos);
                    do{
                        menu_gestor(cadastrados, login, cadastro_medicos);
                        std::cout << "Deseja continuar? (y/n)" << std::endl;
                        menu_on = exit_or_continue();
                    }while (menu_on == 1);
                }
                else{
                    std::cout << "Senha incorreta." << std::endl;
                }
            }
            else{
                std::cout << "Login inválidos, contate o centro de atendimento e confirme o seu cadastro." << std::endl;
            }
        }
        else if (opt == 2){
            ler_arquivo(cadastro_medicos, Arquivo_Medicos);
            do{
                menu_atendente(cadastro_medicos);
                std::cout << "Deseja continuar? (y/n)" << std::endl;
                menu_on = exit_or_continue();
            }while (menu_on == 1);
        }
        else {
            std::cout << "Volte ao menu, por favor, e entenda as opções." << std::endl; 
        }
        std::cout << "Deseja voltar ao menu inicial? (y/n)" << std::endl;
        carry_on = exit_or_continue();
    }while (carry_on == 1);

    return 0;
}
