#ifndef HUFFTREE_HPP
#define HUFFTREE_HPP

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
HuffNode* huffman(HuffNode* dict);

/// @brief 
/// @param raiz 
void printTree(HuffNode raiz);

#endif