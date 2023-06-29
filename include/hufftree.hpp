#ifndef HUFFTREE_HPP
#define HUFFTREE_HPP

struct HuffNode 
{
  int freq;
  char c;

  struct HuffNode* esq;
  struct HuffNode* dir;
};

#endif