#ifndef HUFFTREE_HPP
#define HUFFTREE_HPP

#include <string>
#include <iostream>

/// @brief Nós da árvore do código de Huffman
struct HuffNode 
{
  int freq;
  char c;

  struct HuffNode* esq;
  struct HuffNode* dir;

  HuffNode() 
  {
    esq = dir = nullptr;
    this->c = '\0';
    this->freq = 0;
  }
};

/// @brief Gera árvore de Huffman a partir dos caractéres e suas frequências
/// @param dict array de nós de uma árvore binária que contém caractéres e suas
///        frequências
/// @return O primeiro elemento do array é a raiz da árvore
void huffman(HuffNode* dict);

/// @brief Gera código da cifra gerado pelo algoritmo de Huffman
/// @param raiz Raiz da árvore de Huffman
/// @param code String onde o código da cifra será escrito
/// @param temp String temporária para armazenar código de cada caractere
void huffCode(HuffNode raiz, std::string &code, std::string &temp);

/// @brief Recria árvore a partir da cifra do código de Huffman
/// @param code Cifra do código de Huffman
/// @return Nó com raiz da árvore
HuffNode huffDecode(std::string code);

/// @brief Imprime as folhas da raiz da árvores com seus códigos no terminal
/// @param raiz Raiz da árvore
/// @param temp String temporária, passada por referência
void printTree(HuffNode raiz, std::string &temp);

#endif