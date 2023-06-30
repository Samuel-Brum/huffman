#ifndef LEITOR_HPP
#define LEITOR_HPP

#include <string>
#include <fstream>
#include <sstream>

#include "hufftree.hpp"

using namespace std;


/// @brief Armazena o conteúdo de um arquivo em uma string  
/// @param path Caminho do sistema até o arquivo
/// @return String com conteúdos do arquivo
void lerArquivo(string path, string &s);

/// @brief Calcula a frequência de cada caractere em uma string
/// @param texto String a ser analisada
/// @return Array ordenado de caracteres e suas frequências, em ordem crescente
void charFreq(string texto, HuffNode* dict);

/// @brief Implementação de insertion sort para frequências de cada caractere
/// @param dict Dicionário com chave caractére e valor frequência
/// @return Dicionário ordenado em ordem crescente
void insertionSort(HuffNode* dict);

#endif