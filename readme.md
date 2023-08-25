# ELF-reader
***objetivo*** deste trabalho de sistemas digitais é implementar programa que receba um arquivo executável ou objeto (.o) gerado no ambiente linux e apresente na saída (em arquivo texto) as informações do cabeçalho ELF desse referido arquivo de entrada. 

### Diretorios

* ***asm*** código fonte de assembly

* ***bin*** binario compilado do código em C

* ***elf_playstation2*** binario de ps2 que é formato ELF

* ***exec*** executaveis do código objeto

* ***include*** arquivos de .h de C

* ***object*** arquivos código objeto do assembly

* ***src*** arquivos de código fonte em C

### Como usar

1. Entre no diretorio do ELF-reader
```
    cd ELF-reader
```
2. executar e ver o resultado no porpio terminal
```
    ./bin/elfreader <caminho do arquivo elf>
```

3. executar e impirmir a saída num arquivo externo 
```
    ./bin/elfreader <caminho do arquivo elf> -p <caminho do arquivo de saída>
```

### Exemplo de uso

executando
```bash
    ./bin/elfreader ./object/hello32.o -p log.txt
```

saída esperada
```
    Informações do cabeçalho ELF do arquivo ./object/hello32.o

Número magico: 7F 45 4C 46 1 1 1 0 0 0 0 0 0 0 0 0
Arquitetura: 32 bits
Data: pequena extremidade
Versão: 1
Sistem Operacional: System V
Versão ABI: 0
Tipo: código objeto
Aquitetura: x86
Versão ELF: 1
Endereço de Entrada: 0x0
Endereço do cabeçalho do programa: 0x0
Endereço de cabeçalho do seção: 0x40
Flags: 0x0
Tamanho do cabeçalho do programa: 52
Tamanho da tabela do cabeçalho do programa: 0
Número de entradas na tabela de cabeçalho e programa.: 0
Número de entradas na tabela de cabeçalho de seção: 7
Índice da entrada da tabela de cabeçalho de seção que contem os nomes de seção: 3

Cabeçalho ELF completo em hexadecimal: 

 7F 45 4C 46 01 01 01 00 00 00 00 00 00
 00 00 00 01 00 03 00 01 00 00 00 00 00
 00 00 00 00 00 00 40 00 00 00 00 00 00
 00 34 00 00 00 00 00 28 00 07 00 03 00

```