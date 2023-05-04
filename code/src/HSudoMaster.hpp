/*!
 * O adm.
 *  + Lê arquivo
 *  + Insert Gestores
 *  + Procurar Gestores
 *  + Comparar senhas de acordo com login
 *  + Adicionar Gestores
 *  + Excluir Gestores
 *  + Listar Gestores
 *  + Função para fechar uma execução
 *  + Menu Gerenciador SudoMaster
 *
 * \author Hannah Beatryz L. S.
 * \date May, 1st.
 */

#ifndef _SUDOMASTER_HPP
#define _SUDOMASTER_HPP

#include "HStructsInclude.hpp"
std::string senha_sudomaster = "catchmeifyoucan";
std::fstream Cadastro; // Arquivo associado ao cadastro de gestores
Gestores gestor; // Struct de gestores
std::vector<std::string> cadastro; // vetor com as linhas do cadastro de gestores
std::map<std::string, Gestores> cadastrados; // map com os gerentes do arquivo.

/// Lê o arquivo e transforma em vetor.
void ler_arquivo(std::vector<std::string> &cadastro);

/// Lê o vetor e transforma num map.
void insert_gestores(std::vector<std::string> &cadastro, std::map<std::string, Gestores> cadastrados, std::string email, Gestores gestor);

/// Procura um gestor num arquivo.
int procurar_gestor(std::string email);

/// Procura a senha de um gestor e compara com uma senha inputada. 
int senha_gestor(std::map<std::string, Gestores> cadastrados, std::string email, Gestores gestor, std::string senha);

/// Adiciona novos gestores com login e senha.
void adicionar_gestores(std::fstream *Cadastro, std::string novo_email);

/// Exclui gestores.
void excluir_gestores(std::fstream *Cadastro, std::string email);

/// Lista gestores existentes.
void listar_gestores(std::vector<std::string> &cadastro);

// Função de parada de do{}while();.
int exit_or_continue();

/// Menu gerenciador da SudoMaster
void menu_sudomaster();

#endif // _SUDOMASTER_HPP