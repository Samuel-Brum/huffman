#ifndef ENCODEDECODE_HPP
#define ENCODEDECODE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "hufftree.hpp"

using namespace std;

/// @brief Escreve um arquivo binário comprimido através do algoritmo de Huffman
/// @param code String contendo código de Huffman a ser utilizado
/// @param texto Texto a ser comprimido
/// @param file Arquivo de saída 
/// @return 0 caso tudo der certo, 1 caso contrário
int encode(string code, string texto, ofstream &file);

/// @brief Função que lê arquivo binário comprimido através do
///        algoritmo de Huffman
/// @param inFile Arquivo binário compactado
/// @param outFile Arquivo de texto descompactado
/// @return 0 caso tudo der certo, 1 caso contrário
int decode(ifstream &inFile, ofstream &outFile);

/// @brief Converte string de texto para string de '0's e '1's de acordo 
///        com uma cifra de Huffman
/// @param code String contendo código de Huffman a ser utilizado
/// @param texto Texto a ser comprimido
/// @return String de '0's e '1's
string convert(string code, string texto);

/// @brief Reverte string de '0's e '1's de volta para uma string ASCII
///        de acordo com uma cifra de Huffman
/// @param code String contendo código de Huffman a ser utilizado
/// @param bin String de '0's e '1's
/// @return Texto descompactado
string revert(string code, string bin, HuffNode raiz);

#endif