#include <bitset>

#include "encodeDecode.hpp"

int encode(string code, string texto, ofstream &file)
{
  unsigned int texto_size = texto.length();
  unsigned int code_size = code.length();
  
  string encoded = convert(code, texto);

  if (!file)
  {
    cout << "Erro ao abrir o arquivo" << endl;
    return 1;
  } 
  else
  {

  }
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
