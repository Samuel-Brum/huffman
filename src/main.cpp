#include <iostream>
#include <cstdio>
#include <bitset>

#include "leitor.hpp"
#include "encodeDecode.hpp"

#define ASCII 256

using namespace std;

void printLine()
{
  cout << "--------------------------------------------------------" << endl;
}

int main(int argc, char* argv[])
{
  ifstream inFile(argv[1]);
  ofstream outFile(argv[2]);
  string flag = argv[3];

  if (!inFile || !outFile)
  {
    cout << "Erro ao ler um dos arquivos!" << endl;
    return 1;
  }

  if (flag == "-c")
  {
    string texto;
    lerArquivo(argv[1], texto);

    printLine();
    cout << "Texto: " << texto <<endl;

    HuffNode dict[ASCII];
    charFreq(texto, dict);

    int NoOfChars = 0;
    while (dict[NoOfChars].c != '\0')
    {
      NoOfChars++;
    }

    printLine();
    cout << "Frequências: " << endl << endl;
    for (int i = 0; i < NoOfChars; i++)
    {
      cout << dict[i].c << ": " << dict[i].freq << endl;
    }
  

    huffman(dict);

    printLine();
    string s;
    cout << "Árvore com códigos: " << endl << endl;
    printTree(dict[0], s);
    s.clear();
    printLine();

    string code, temp;
    huffCode(dict[0], code, temp);   

    cout << "Código: " << code << endl << endl;
    printLine();

    cout << "Texto convertido para binário: " << endl << endl;
    cout << convert(code, texto) << endl;
    printLine(); 

    encode(code, texto, outFile);
  }

  if (flag == "-d")
  {
    unsigned int texto_size;
    unsigned int code_size;
    unsigned int encoded_size;

    string code, bin, texto;

    // Lê os três ints do header
    inFile.read(reinterpret_cast<char*>(&encoded_size), sizeof(encoded_size));
    inFile.read(reinterpret_cast<char*>(&code_size), sizeof(code_size));
    inFile.read(reinterpret_cast<char*>(&texto_size), sizeof(texto_size));
    
    cout << "------------------------------------------------------------------" << endl;
    cout << encoded_size << endl << code_size << endl << texto_size << endl;
    cout << "------------------------------------------------------------------" << endl;

    char c[code_size];

    // Lê o código para decodificar
    for (unsigned int i = 0; i < code_size; i++)
    {
      inFile.read(&c[i],sizeof(char));
    }

    code = c;

    cout << code << endl;
    char t;
    // Lê os bits comprimidos e armazena eles em uma string
    while (inFile.get(t)) 
    {
      bin += bitset<8>(t).to_string();
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "Binário lido: " << bin << endl;
    cout << "------------------------------------------------------------------" << endl;

    HuffNode raiz = huffDecode(code);

    string s;
    printTree(raiz, s);

    string temp;
    huffCode(raiz, code, temp);

    texto = revert(code, bin, raiz);

    cout << "------------------------------------------------------------------" << endl;
    cout << texto << endl;
    cout << "------------------------------------------------------------------" << endl;


    while (texto.size() > texto_size)
    {
      texto.pop_back();
    }
    outFile << texto;
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
  cout << "bin: " << bin << endl;
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