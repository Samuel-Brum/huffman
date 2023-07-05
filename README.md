# Compressão de Huffman

O código de Huffman é uma forma de representar os caracteres em um texto da forma
mais econômica possível, ou seja, usando o menor número de bits para representar o texto.
De certa forma, ele é uma cifra, na qual o texto pode ser codificado e decodificado e, ao
codificá-lo, temos uma versão do texto que ocupa o menor espaço de memória possível. Se
armazenamos a cifra com algumas outras informações auxiliares, temos como recuperar
o arquivo original sabendo apenas do procedimento para gerar o código a partir de sua
cifra.

A cifra possui uma representação conveniente na forma de uma árvore binária, no
qual caminhar por seus nós nos retorna o código de cada caractere em suas folhas.

# Utilização do makefile
* `make all`: compila tanto testes quanto o programa
* `make clean`: remove binários e arquivos objeto

# Execução do programa
Seguindo a especificação, o programa comprime e descompacta arquivos passados
através de argumentos ao chamar o executável do programa:
* Ao executar `bin/huffman <caminho de entrada> <caminho de saída> -c`, o programa
irá ler o arquivo em <br> `<caminho de entrada>`, comprimi-lo e escrever a sua versão
comprimida em `<caminho de saída>`.

* Ao executar `bin/huffman <caminho de entrada> <caminho de saída> -d`, o programa
irá receber um arquivo já comprimido por esse mesmo programa em `<caminho de
entrada>`, descomprimi-lo, e escrever o arquivo original em `<caminho de saída>`.

Arquivos de teste estão incluídos na pasta test/Test-Files.
