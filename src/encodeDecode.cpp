#include <bitset>

#include "encodeDecode.hpp"
#include "hufftree.hpp"

int encode(string code, string texto, ofstream &file)
{
  unsigned int texto_size = texto.size();
  unsigned int code_size = code.size();

  string encoded = convert(code, texto);

  unsigned int encoded_size = encoded.size();

  if (!file)
  {
    cout << "Erro ao abrir o arquivo" << endl;
    return 1;
  } 
  else
  {
    // Escreve 4 bytes para cada abaixo:
    //   * Número de bits do texto comprimido
    //   * Tamanho da string com o código
    //   * Tamanho do texto original
    file.write((char*) &encoded_size, sizeof(encoded_size));
    file.write((char*) &code_size, sizeof(code_size));
    file.write((char*) &texto_size, sizeof(texto_size));

    // Escreve cifra do código de Huffman
    file.write(&code[0], code_size);
  
    int buff_size = 0;
    string buffer;
    for (auto it = encoded.begin(); it != encoded.end(); it++)
    {
      // Empurra cada bit do texto comprimido em um buffer
      if (buff_size < 8) 
      {
        buffer.push_back(*it);
        buff_size++;
      } else       // Flush no buffer
      {
        bitset<8> c(buffer);
        file.put(c.to_ulong()); 
        buffer.clear();
        buff_size = 0;
      }
    }

    // Flush no que sobrar, mais um monte de '1's
    if (buff_size > 0) 
    {
      while (buff_size < 8)
      {
        buffer.push_back('1');
        buff_size++;
      }
      bitset<8> c(buffer);
      file.put(c.to_ulong()); 
      buffer.clear();
      buff_size = 0;
    }
  }
  file.close();
  return 0;
}

string convert(string code, string texto)
{
  string textoCode;
  for (auto char_T = texto.begin(); char_T != texto.end(); char_T++)
  {
    for (auto char_C = code.begin(); char_C != code.end(); char_C++)
    {
      if (*char_T == *char_C)
      {
        char_C++;
        while (*char_C == '0' || *char_C == '1')
        {
          textoCode.push_back(*char_C);
          char_C++;
        }
        if (*char_C == '\000') // Fim da string
        {
          char_C--; // Evita pular o último char da string
        }
      }
    }
  }
  return textoCode;
}

inline bool get_bit(char c, int n)
{
  return (c >> n) & 1;
}


int decode(ifstream &inFile, ofstream &outFile)
{
  if (!inFile)
  {
    cout << "Erro ao abrir o arquivo" << endl;
    return 1;
  } 
  else
  {
    unsigned int texto_size;
    unsigned int code_size;
    unsigned int encoded_size;

    string code;
    string texto;

    // Lê os três ints do header
    inFile.read(reinterpret_cast<char*>(&encoded_size), sizeof(encoded_size));
    inFile.read(reinterpret_cast<char*>(&code_size), sizeof(code_size));
    inFile.read(reinterpret_cast<char*>(&texto_size), sizeof(texto_size));

    char c[code_size];

    // Lê o código para decodificar
    for (unsigned int i = 0; i < code_size; i++)
    {
      inFile.read(&c[i],sizeof(char));
    }

    code = c;

    char t;
    // Lê os bits comprimidos e armazena eles em um array de char
    while (inFile.get(t)) 
    {
      texto += bitset<8>(t).to_string();
    }
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "Cifra recuperada: " << code << endl;
    //cout << "Text bin recuperado: " << texto << endl;
    cout << code_size << endl;
    cout << code.size() << endl;
    HuffNode raiz = huffDecode(code);
    string temp;
    code.clear();
    huffCode(raiz, code, temp);
    //cout << revert(code, texto) << endl;
    temp.clear();
    printTree(raiz, temp);
  }
}


string revert(string code, string bin, HuffNode raiz) // TODO
{ 
  HuffNode* ptr = &raiz;
  string texto;

  for (auto bit = bin.begin(); bit != bin.end(); bit++)
  {
    if (*bit == '0')
    {
      if (ptr->esq == nullptr)
      {
        texto.push_back(ptr->c);
        ptr = &raiz;
        bit--;
        continue;
      }
      else
      {
        ptr = ptr->esq;
      }
    }
    if (*bit == '1')
    {
      if (ptr->dir == nullptr)
      {
        texto.push_back(ptr->c);
        ptr = &raiz;
        bit--;
      }
      else
      {
        ptr = ptr->dir;
      }
    }
  } 

  return texto;
} 


