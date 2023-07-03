#include <iostream>

#include "leitor.hpp"
#include "encodeDecode.hpp"

#define ASCII 128

using namespace std;

int main(int argc, char* argv[])
{
  string textoManual;
  lerArquivo("test/Test-Files/LoremIpsumSmall.txt", textoManual);
  //textoManual = "Stressed-desserts";
  //textoManual = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
  HuffNode dict[ASCII];

  charFreq(textoManual, dict);

  int NoOfChars = 0;
  while (dict[NoOfChars].c != '\0')
  {
    NoOfChars++;
  }

  for (int i = 0; i < NoOfChars; i++)
  {
    cout << dict[i].c << ": " << dict[i].freq << endl;
  }


  huffman(dict);

  cout << "----------------------------------" << endl;

  string code, temp;
  huffCode(dict[0], code, temp);
  cout << code << endl;
  cout << "-----------------" << endl;
  //cout << convert(code, textoManual) << endl;
  string comp = convert(code, textoManual);
  cout << (((float) comp.length() / 8) + code.length() + 2)/ textoManual.length() << endl;
  
}