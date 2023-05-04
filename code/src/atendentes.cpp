/*!
 * \file atendentes.cpp
 * listar_medicos_atendente, listar_especialidades_atendente, agendar_horario, pesquisar_agendamentos_atendente, menu_atendente.
 * \author Hannah Beatryz L. S.
 * \date May 1rst, 2023.
 */

#include "HAtendentes.hpp"

/*!
 * Returns .
 * \note Something.
 * \param name description of param.
 * \param name description of param.
 * \param name description of param.
 */
void listar_medicos_atendente(){

}


/*!
 * Returns .
 * \note Something.
 * \param name description of param.
 * \param name description of param.
 * \param name description of param.
 */
void listar_especialidades_atendente(){

}


/*!
 * Returns .
 * \note Something.
 * \param name description of param.
 * \param name description of param.
 * \param name description of param.
 */
void agendar_horario(){ //Fazer um map<chave:especialidade, :vector<struct Medicos>>
    std::cout << "Qual é a especialidade do médico?" << std::endl;

}


/*!
 * Returns .
 * \note Something.
 * \param name description of param.
 * \param name description of param.
 * \param name description of param.
 */
void pesquisar_agendamentos_atendente(){

}


/*!
 * Returns .
 * \note Something.
 * \param name description of param.
 * \param name description of param.
 * \param name description of param.
 */
void menu_atendente(){

}


/*!
 * Executa o menu gerenciador dos atendentes.
 * \note Não possui parâmetros, é um auxiliar para executar as outras funções.
 */
void menu_atendente(){
    int opt;
    std::string medico, horario;
    std::cout << "Do que você precisa hoje?" << std::endl
              << "1 - Listar médicos" << std::endl
              << "2 - Listar especialidades" << std::endl
              << "3 - Agendar horário" << std::endl
              << "4 - Pesquisar agendamentos de um médico" << std::endl;
    std::cin >> opt;
    if (opt == 1){
        listar_medicos_atendente();
    }
    else if (opt == 2){
        listar_especialidades_atendente();
    }
    else if (opt == 3){
        agendar_horario();
    }
    else if (opt == 4){
        pesquisar_agendamentos_atendente();
    }
    else {
        std::cout << "Infelizmente a opção selecionada não é válida, caso queira adicionar alguma funcionalidade, contate o dev mais próximo de você." << std::endl;
    }
}