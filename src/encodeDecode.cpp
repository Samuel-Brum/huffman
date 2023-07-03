#include <bitset>

#include "encodeDecode.hpp"

int encode(string code, string texto, ofstream &file)
{
  unsigned int texto_size = texto.length();
  unsigned int code_size = code.length();

  string encoded = convert(code, texto);

  unsigned int encoded_size = encoded.length();

  if (!file)
  {
    cout << "Erro ao abrir o arquivo" << endl;
    return 1;
  } 
  else
  {
    file.write((char*) &encoded_size, sizeof(encoded_size));
    file.write((char*) &code_size, sizeof(code_size));
    file.write((char*) &texto_size, sizeof(texto_size));

    int buff_size = 0;
    string buffer;
    for (auto it = encoded.begin(); it != encoded.end(); it++)
    {
      if (buff_size < 8) 
      {
        buffer.push_back(*it);
        buff_size++;
      } else
      {
        bitset<8> c(buffer);
        file.put(c.to_ulong()); 
        buffer.clear();
        buff_size = 0;
      }
    }
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
        if (*char_C == '\000')
        {
          char_C--;
        }
      }
    }
  }
  return textoCode;
}
