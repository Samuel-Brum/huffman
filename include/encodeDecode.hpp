#ifndef ENCODEDECODE_HPP
#define ENCODEDECODE_HPP

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/// @brief 
/// @param code 
/// @param texto 
/// @param file 
/// @return 
int encode(string code, string texto, ofstream &file);

/// @brief 
/// @param file 
/// @return 
int decode(fstream &file);

/// @brief 
/// @param code 
/// @param texto 
/// @return 
string convert(string code, string texto);

/// @brief 
/// @param code 
/// @param texto 
/// @return 
string revert(string code, string texto);

#endif