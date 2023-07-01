#include <iostream>

#include "hufftree.hpp"
#include "leitor.hpp"

void huffman(HuffNode* dict) 
{
  int size = 0;
  while (dict[size].c != '\0')
  {
    size++;
  }

  while (size != 1)
  {
    int i = size - 1;

    HuffNode* tempDir = new HuffNode;
    tempDir->c = dict[i].c;
    tempDir->freq = dict[i].freq;
    tempDir->dir = dict[i].dir;
    tempDir->esq = dict[i].esq;

    HuffNode* tempEsq = new HuffNode;
    tempEsq->c = dict[i-1].c;
    tempEsq->freq = dict[i-1].freq;
    tempEsq->dir = dict[i-1].dir;
    tempEsq->esq = dict[i-1].esq;

    dict[i].c = '\0';
    dict[i].freq = 0;
    dict[i].esq = dict[i].dir = nullptr;


    dict[i-1].dir = tempDir;
    dict[i-1].esq = tempEsq;

    dict[i-1].freq = tempDir->freq + tempEsq->freq;

    // "Apaga" último elementos do array
    dict[i-1].c = '\200';

    insertionSort(dict);
    size--;
  }
}

void huffCode(HuffNode raiz, string &code, string &temp) 
{
  if (raiz.esq != nullptr)
  {
    temp.append("0");
    huffCode(*raiz.esq, code, temp);
  } 
  if (raiz.dir != nullptr)
  {
    temp.append("1");
    huffCode(*raiz.dir, code, temp);
  }
  if (raiz.esq == nullptr && raiz.dir == nullptr)
  {
    code.push_back(raiz.c);
    code.append(temp);
  }
  temp.pop_back();
}