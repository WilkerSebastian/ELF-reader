#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#include"ELF.h"

int main(int argc, char const *argv[]) {    

    setlocale(LC_ALL, "Portuguese");

    bool bits32;
    unsigned char * elf = lerELF(argv[1]);
    
    validaELF(elf, &bits32);

    if(argc == 4) {

        criarHeader(argv[3], argv[1], elf, bits32);
        
    } else if (argc == 2) {

        mostrarHeader(argv[1], elf, bits32);

    } else {

        printf("Erro ao executar comando a forma correta é: \n\n");
        printf("./bin/elfreader <caminho do arquivo elf>\n");
        printf("./bin/elfreader <caminho do arquivo elf> -p <caminho do arquivo de saída> \n");

    }

    return EXIT_SUCCESS;
    
}