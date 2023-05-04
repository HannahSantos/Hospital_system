# Hospital System
O Hospital System é um projeto em C++ que permite gerenciar o sistema de um hospital. O projeto é composto por três níveis de acesso: nível básico para atendentes, nível intermediário para gestores e um nível oculto para adicionar e remover gestores.

## Funcionalidades
O sistema permite que os usuários realizem as seguintes tarefas:

Nível básico para atendentes:
* Listar médicos por nome e por especialidades;
* Listar as especialidades disponíveis e a quantidade de profissionais de cada uma;
* Agendar horários;
* Ver os agendamentos de cada médico.

Nível intermediário para gestores:
* Adicionar e remover médicos;
* Trocar as especialidades dos médicos;
* Executar as funções dos atendentes.

Nível oculto SudoMaster:
* Adicionar e remover gestores.

## Requisitos
Para executar o Hospital System, é necessário ter instalado em seu computador:

* Um compilador C++ (como o GCC);
* CMake;
* MySQL.

## Instalação
Para instalar o Hospital System, siga os seguintes passos:

1. Clone o repositório do projeto:

```bash 
git clone https://github.com/HannahSantos/Hospital_system.git
```
2. Navegue para a pasta do projeto:
```bash 
cd Hospital_system
```
3. Crie uma pasta "build" para armazenar os arquivos gerados pelo CMake:
```bash 
mkdir build
```
4. Navegue para a pasta "build":
```bash 
cd build
```
5. Configure o CMake:
```bash 
cmake ..
```
6. Compile o projeto:
```bash 
make
```
7. Crie um banco de dados MySQL com o nome "hospital_system".
8. Edite o arquivo "config.h" com as credenciais do banco de dados MySQL.
9. Execute o programa:
```bash 
./hospital_system
```
## Uso
Para usar o Hospital System, siga os seguintes passos:

1. Execute o programa:
```bash 
./hospital_system
```
2. Faça o login no nível básico, intermediário ou no nível oculto, de acordo com o seu nível de acesso.
3. Realize as tarefas disponíveis para o seu nível de acesso.

## Contribuição

Se você deseja contribuir com o projeto, siga os seguintes passos:
1. Faça um fork do repositório.
2. Crie uma nova branch com as suas modificações.
3. Faça o push da branch para o seu fork.
4. Crie um Pull Request para o repositório original.

## Autores
O Hospital System foi criado por Hannah Santos.

## Licença
O Hospital System é distribuído sob nenhuma licença, por hora.

## Agradecimentos
Agradecemos a todos que contribuíram para o desenvolvimento do Hospital System.

## Contato
Para entrar em contato com a equipe do Hospital System, envie um e-mail para hospital.system@gmail.com.