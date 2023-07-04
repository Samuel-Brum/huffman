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

    // Escreve cifra do código de Huffman (8 bits/ char)
    file.write(code.c_str(), code_size);
  
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
        it--;
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
  cout << encoded_size << endl << code_size << endl << texto_size << endl;
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


