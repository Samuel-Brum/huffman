#include <iostream>

#include "leitor.hpp"
#define NoOfChars 128

using namespace std;

int main(int argc, char* argv[])
{
  string texto;
  lerArquivo("test/Test-Files/LoremIpsumSmall.txt", texto);
  string textoManual = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
  HuffNode vazio[NoOfChars];
  for (int i = 0; i < NoOfChars; i++) {
    vazio[i].c = '\0';
    vazio[i].freq = 0;
  }

  HuffNode* frequencia = charFreq(textoManual, vazio);
  for (int i = 0; i < NoOfChars; i++)
  {
    cout << frequencia[i].c << ": " << frequencia[i].freq << endl;
  }
}