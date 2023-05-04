/*!
 * Structs e Includes úteis.
 * + Struct Gestores,
 * + Struct Medicos.
 * \author Hannah Beatryz L. S.
 * \date May, 1st.
 */

#ifndef _STRUCTSINCLUDE_HPP
#define _STRUCTSINCLUDE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

// map<chave:email, struct Gestores>
typedef struct{
    std::string nome_gestor;
    std::string senha_gestor;
} Gestores;

// map<chave:especialidade, vector<struct Medicos>>
typedef struct{
    std::string nome_medico;
    std::map<std::string, std::vector<std::string>> horarios_medico; // map<chave:mês do ano, vector<horarios>>
} Medicos;


std::string Arquivo_Gestores = "Cadastro_Gestores.txt";
std::string Arquivo_Medicos = "Medicos.txt";

#endif // _STRUCTSINCLUDE_HPP