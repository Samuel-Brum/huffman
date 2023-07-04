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

    // "Apaga" último elemento do array
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


HuffNode huffDecode(string code) 
{
  HuffNode raiz;
  HuffNode* ptr = &raiz;
  string temp;

  for (auto char_C = code.begin(); char_C != code.end(); char_C++)
    {
      if (*char_C == '0')
      {
       if (ptr->esq != nullptr)
       {
        ptr = ptr->esq;
       }
       else 
       {
        ptr->esq = new HuffNode;
        ptr = ptr->esq;
       }
      }
      if (*char_C == '1')
      {
        if (ptr->dir != nullptr)
        {
          ptr = ptr->dir;
        }
        else
        {
          ptr->dir = new HuffNode;
          ptr = ptr->dir;
        }
      } 
      if (*char_C != '0' && *char_C != '1')
      {
        if (temp.empty())
        {
          temp.push_back(*char_C);
        }
        else
        {
          ptr->c = temp[0];
          ptr = &raiz;
          temp.clear();
          temp.push_back(*char_C);
        }
        
      }
      raiz.c = '\0';
    }
    ptr->c = temp[0];
    temp.clear();
  return raiz;
}

void printTree(HuffNode raiz, std::string &temp)
{
  if (raiz.esq != nullptr)
  {
    temp.append("0");
    printTree(*raiz.esq, temp);
  } 
  if (raiz.dir != nullptr)
  {
    temp.append("1");
    printTree(*raiz.dir, temp);
  }
  if (raiz.esq == nullptr && raiz.dir == nullptr)
  {
    std::cout << raiz.c << ": " << temp << std::endl;
  }
  temp.pop_back();
}