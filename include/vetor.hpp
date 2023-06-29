#ifndef VETOR_HPP
#define VETOR_HPP

#include <bits/stdc++.h>
#include "hufftree.hpp"
using namespace std;

/// @brief Implementação própria de um vetor
/// @tparam T tipo do vetor
template <typename T> class Vetor {
	public:
		/// @brief Contrutor do Vetor
		Vetor() {
			arr = new T[1];
			capacidade = 1;
			numeroDeElementos = 0;
		}

		/// @brief Destrutor do Vetor
		~Vetor() {
			delete [] arr;
		}

		/// @brief Insere elemento no final do vetor
		/// @param elemento Elemento a ser inserido
		void push(T elemento) {
			if (numeroDeElementos == capacidade) {
				T* temp = new T[2 * capacidade];
				for (int i = 0; i < capacidade; i++) {
					temp[i] = arr[i];
				} // capacidade dobra caso não haja mais espaço

				delete[] arr;
				capacidade *= 2;
				arr = temp;
			}

			arr[numeroDeElementos] = elemento;
			numeroDeElementos++;
		}

		/// @brief Insere elemento em posição específica do Vetor
		/// @param elemento Elemento a ser inserido
		/// @param index Posição a ser inserido o elemento
		void push(T elemento, int index) {
			if (index == capacidade)
				push(elemento);
			else
				arr[index] = elemento;
		}

		/// @brief Seletor de elemento específico do Vetor a partir da posição
		/// @param index Posição do elemento
		/// @return Elemento na posição <index>
		T get(int index) {
			if (index < numeroDeElementos)
				return arr[index];
		}

		/// @brief Insere elemento no vetor na posição selecionada
		/// @param value 
		/// @param index 
		void set(T value, int index){
			if (index < numeroDeElementos)
				arr[index] = value;
		}

		/// @brief Remove último elemento do Vetor
		void pop() { numeroDeElementos--; }

		/// @brief Getter para tamanho do Vetor
		/// @return Número de elemento do Vetor
		int size() { return numeroDeElementos; }

		/// @brief Getter para capacidade máxima do Vetor
		/// @return Capacidade máxima do Vetor
		int getCapacidade() { return capacidade; }



	private: 
		T* arr;
		int capacidade;
		int numeroDeElementos;
};

#endif