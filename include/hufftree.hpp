#ifndef HUFFTREE_HPP
#define HUFFTREE_HPP

#include <string>

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

/// @brief 
/// @param dict 
/// @return 
void huffman(HuffNode* dict);


/// @brief 
/// @param raiz 
/// @param code 
void huffCode(HuffNode raiz, std::string &code, std::string &temp);

#endif