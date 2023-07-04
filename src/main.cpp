#include <iostream>
#include <cstdio>

#include "leitor.hpp"
#include "encodeDecode.hpp"

#define ASCII 256

using namespace std;

int main(int argc, char* argv[])
{

  ifstream inFile(argv[0]);
  ofstream outFile(argv[1]);

  if (!inFile || !outFile)
  {
    cout << "Erro ao ler um dos arquivos!" << endl;
    return 1;
  }



}
/*
  string textoManual;
  lerArquivo("test/Test-Files/LoremIpsumSmall.txt", textoManual);
  //lerArquivo("test/Test-Files/wallOfText.txt", textoManual);
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

  cout << "--------------------------------------------------------------------------------------------------------" << endl;

  string code, temp;
  huffCode(dict[0], code, temp);
  temp.clear();
  printTree(dict[0], temp);
  // testa huffDecode
  HuffNode raiz;
  raiz = huffDecode(code);
  temp.clear();
  printTree(raiz, temp);

  string bin = convert(code, textoManual);
  string text = revert(code, bin, raiz);
  cout << "revert: " << text << endl;



  cout << "Cifra:" << code << endl;
  cout << "--------------------------------------------------------------------------------------------------------" << endl;
  cout << "Texto bin: " << convert(code, textoManual) << endl;
  cout << "--------------------------------------------------------------------------------------------------------" << endl;
  string comp = convert(code, textoManual);

  ofstream saida ("test/Test-Files/huffman-comprimido.txt", ios::binary);
  encode(code, textoManual, saida);
  ifstream entrada("test/Test-Files/huffman-comprimido.txt", ios::binary);
  ofstream normal("test/Test-Files/huffman-descomprimido.txt");
  decode(entrada, normal);
}
*/