/*!
 * \file gestores.cpp
 * listar_medicos_gestor, listar_especialidades_gestor, adicionar_medico, pesquisar_agendamentos_gestor, alterar_especialidade, 
 * remover_medico, menu_gestor.
 * \author Hannah Beatryz L. S.
 * \date May 1rst, 2023.
 */

#include "HGestores.hpp"

/*!
 * Returns .
 * \note Something.
 * \param name description of param.
 * \param name description of param.
 * \param name description of param.
 */
void listar_medicos_gestor(){

}


/*!
 * Returns .
 * \note Something.
 * \param Medicos_especialidade map que armazena .
 * \param especialidade string que é a chave para o map Medicos_especialidade com as informações a serem listadas.
 * \param medicos vetor de struct Medicos com .
 */
void listar_especialidades_gestor(std::map<std::string, std::vector<Medicos>> Medicos_especialidade, std::string especialidade, std::vector<Medicos> medicos){

}


/*!
 * Returns .
 * \note Something.
 * \param name description of param.
 * \param name description of param.
 * \param name description of param.
 */
void adicionar_medico(std::fstream *Agendamentos){

}


/*!
 * Returns .
 * \note Something.
 * \param name description of param.
 * \param name description of param.
 * \param name description of param.
 */
void pesquisar_agendamentos_gestor(std::string nome_medico){

}


/*!
 * Returns .
 * \note Something.
 * \param name description of param.
 * \param name description of param.
 * \param name description of param.
 */
void alterar_especialidade(std::fstream *Agendamentos, std::string nome_medico){
    std::string nova_especialidade;

}


/*!
 * Returns .
 * \note Something.
 * \param name description of param.
 * \param name description of param.
 * \param name description of param.
 */
void remover_medico(std::string nome_medico){

}


/*!
 * Executa o menu gerenciador dos gerenciadores.
 * \note Não possui parâmetros, é um auxiliar para executar as outras funções.
 */
void menu_gestor(std::string login){
    int opt;
    std::cout << "O que você deseja fazer, sr(a). " << cadastrados[login].nome_gestor << "?" << std::endl
              << "1 - Listar médicos" << std::endl
              << "2 - Listar especialidades" << std::endl
              << "3 - Adicionar novo médico" << std::endl
              << "4 - Pesquisar agendamentos de um médico" << std::endl
              << "5 - Alterar especialidade de médico" << std::endl
              << "6 - Remover médico" << std::endl;
    std::cin >> opt;
    if (opt == 1){
        listar_medicos_gestor();
    }
    else if (opt == 2){
        listar_especialidades_gestor();
    }
    else if (opt == 3){
        adicionar_medico();
    }
    else if (opt == 4){
        pesquisar_agendamentos_gestor();
    }
    else if (opt == 5){
        alterar_especialidade();
    }
    else if (opt == 6){
        remover_medico();
    }
    else {
        std::cout << "Infelizmente a opção selecionada não é válida, caso queira adicionar alguma funcionalidade, contate o dev mais próximo de você." << std::endl;
    }
}