/*!
 * Funcionalidades de sistema dadas a um gestor pela biblioteca:
 *  + Listar médicos
 *  + Listar Especialidades
 *  + Adicionar médicos
 *  + Pesquisar agendamentos (com possibilidade de desmarcar)
 *  + Alterar a especialidade de um médico
 *  + Remover médicos
 *  + Menu Gerenciador Gestor
 *
 * \author Hannah Beatryz L. S.
 * \date May, 1st.
 */

#ifndef _GESTORES_HPP
#define _GESTORES_HPP

#include "HStructsInclude.hpp"
#include "HSudoMaster.hpp"

/// Lista médicos para o gestor.
void listar_medicos_gestor();

/// Lista as especialidades para o gestor.
void listar_especialidades_gestor(std::map<std::string, std::vector<Medicos>>, std::string especialidade, std::vector<Medicos> medicos);

/// Adiciona um novo médico.
void adicionar_medico(std::fstream *Agendamentos);

/// Ver todos os agendamentos de um médico pela pesquisa por médico, com a opção de excluir um agendamento.
void pesquisar_agendamentos_gestor(std::string nome_medico);

/// Altera a especialidade de um médico.
void alterar_especialidade(std::fstream *Agendamentos, std::string nome_medico);

/// Remove um médico
void remover_medico(std::string nome_medico);

/// Menu gerenciador do gestor
void menu_gestor(std::string login);

#endif // _GESTORES_HPP