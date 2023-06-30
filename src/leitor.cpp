#include "leitor.hpp"
#include "hufftree.hpp"

void lerArquivo(string path, string &s) 
{
  ifstream in(path);  
  stringstream buffer;

  buffer << in.rdbuf();
  string temp(buffer.str());
  s = temp;
}

void insertionSort(HuffNode* dict) 
{
  int size = 0;
  while (dict[size].c != '\0')
  {
    size++;
  }

  int i, j;
  HuffNode key;
  for (int i = 1; i < size; i++)
  {
    key = dict[i];
    j = i - 1;

    while (j >= 0 && dict[j].freq > key.freq) 
    {
      dict[j+1].freq = dict[j].freq;
      dict[j+1].c = dict[j].c;
      j = j - 1;
    }
    dict[j+1] = key;
  }
}

HuffNode* charFreq(string texto, HuffNode* dict) 
{
  int numeroDeChars = 0;

  for (string::iterator it = texto.begin(); it != texto.end(); it++)
  {
    bool found = false;
    int index = 0;
    for (int i = 0; i < numeroDeChars + 1; i++) 
    {
      if (dict[i].c == *it) 
      {
        index = i;
        found = true;
      }
    }

    if (!found) 
    {
      dict[numeroDeChars].c = *it;
      dict[numeroDeChars].freq++;
      numeroDeChars++;
    } else
    {
      dict[index].freq++;
    }
  }
  insertionSort(dict);
  return dict;
}


