// Guilherme de Moura - 2110362

#include <iostream>
#include <algorithm>
#include <vector>

struct Paciente
{
    int idade;
    std::string nome;
    // outras informações relevantes
};

int buscaSequencial(const std::vector<Paciente> &pacientes, int idade_desejada)
{
    for (int i = 0; i < pacientes.size(); i++)
    {
        if (pacientes[i].idade == idade_desejada)
        {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(const std::vector<Paciente> &pacientes, int idade_desejada)
{
    int inicio = 0;
    int fim = pacientes.size() - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (pacientes[meio].idade == idade_desejada)
        {
            return meio;
        }
        else if (pacientes[meio].idade < idade_desejada)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}

bool compararIdade(const Paciente &p1, const Paciente &p2)
{
    return p1.idade < p2.idade;
}

int main()
{
    std::vector<Paciente> pacientes = {{53, "Paciente 1"}, {30, "Paciente 2"}, {14, "Paciente 3"}, {39, "Paciente 4"}, {9, "Paciente 5"}, {23, "Paciente 6"}, {34, "Paciente 7"}, {49, "Paciente 8"}, {72, "Paciente 9"}, {61, "Paciente 10"}, {84, "Paciente 11"}, {79, "Paciente 12"}, {2, "Paciente 13"}, {3, "Paciente 14"}, {27, "Paciente 15"}, {31, "Paciente 16"}}; // preencher o vector de pacientes com informações relevantes

    // buscar um paciente com idade 30 usando busca sequencial
    int indice_sequencial = buscaSequencial(pacientes, 30);
    if (indice_sequencial != -1)
    {
        std::cout << "Paciente encontrado: " << pacientes[indice_sequencial].nome << std::endl;
    }
    else
    {
        std::cout << "Paciente nao encontrado." << std::endl;
    }

    // ordenar o vector de pacientes por idade
    std::sort(pacientes.begin(), pacientes.end(), compararIdade);

    // buscar um paciente com idade 30 usando busca binária
    int indice_binaria = buscaBinaria(pacientes, 30);
    if (indice_binaria != -1)
    {
        std::cout << "Paciente encontrado: " << pacientes[indice_binaria].nome << std::endl;
    }
    else
    {
        std::cout << "Paciente nao encontrado." << std::endl;
    }

    return 0;
}