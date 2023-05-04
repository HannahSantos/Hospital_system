/*!
 * Funcionalidades de sistema dadas a um atendente pela biblioteca:
 *  + Listar médicos
 *  + Listar Especialidades
 *  + Agendar horários
 *  + Pesquisar Agendamentos (apenas leitura)
 *  + Menu de Gerenciamento Atendente
 *
 * \author Hannah Beatryz L. S.
 * \date May, 1st.
 */

#ifndef _ATENDENTES_HPP
#define _ATENDENTES_HPP

#include "HStructsInclude.hpp"

/// Lista médicos para o atendente.
void listar_medicos_atendente();

/// Lista as especialidades para o atendente.
void listar_especialidades_atendente();

/// Agendar um horário com um médico.
void agendar_horario();

/// Ver todos os agendamentos de um médico pela pesquisa por médico.
void pesquisar_agendamentos_atendente();

/// Menu gerenciador do Atendente
void menu_atendente();

#endif // _ATENDENTES_HPP