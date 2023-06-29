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

HuffNode* charFreq(string texto, HuffNode* mapa) 
{
  int numeroDeChars = 0;

  for (string::iterator it = texto.begin(); it != texto.end(); it++)
  {
    bool found = false;
    int index = 0;
    for (int i = 0; i < numeroDeChars + 1; i++) 
    {
      if (mapa[i].c == *it) 
      {
        index = i;
        found = true;
      }
    }

    if (!found) 
    {
      mapa[numeroDeChars].c = *it;
      mapa[numeroDeChars].freq++;
      numeroDeChars++;
    } else
    {
      mapa[index].freq++;
    }
  }
  return mapa;
}