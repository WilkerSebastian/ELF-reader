#include "ELF.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char * getArch(unsigned char identifier) {

    char * archs[] = {

        "Sem conjunto de instruções específico",
        "SPARC",
        "x86",
        "MIPS",
        "PowerPC",
        "S390",
        "ARM",
        "SuperH",
        "IA-64",
        "x86-64",
        "AArch64",
        "RISC-V"

    };

    switch (identifier) {
    case SPARC:

        identifier = 1;

        break;
    case X86:

        identifier = 2;

        break;
    case MIPS:

        identifier = 3;

        break;
    case POWERPC:

        identifier = 4;

        break;
    case S390:

        identifier = 5;

        break;
    case ARM:

        identifier = 6;

        break;
    case SUPERH:

        identifier = 7;

        break;
    case IA_64:

        identifier = 8;

        break;
    case X86_64:

        identifier = 9;

        break;
    case AArch64:

        identifier = 10;

        break;
    case RISC_V:

        identifier = 11;

        break;
    }

    return archs[identifier];

}

char * getType(unsigned char identifier) {

    char * types[] = {

        "código objeto",
        "executável",
        "compartilhado",
        "respectivamente"

    };

    return types[identifier];

}

char * getOS(unsigned char identifier) {

    char * systens[] = {
        "System V",
        "HP-UX",
        "NetBSD",
        "Linux",
        "GNU Hurd",
        "Solaris",
        "AIX",
        "IRIX",
        "FreeBSD",
        "Tru64",
        "Novell Modesto",
        "OpenBSD",
        "OpenVMS",
        "Núcleo do NonStop",
        "AROS",
        "Fenix OS",
        "CloudABI"
    };

    return systens[identifier];

}

void mostrarHeader(const char * nomeArquivo, const unsigned char * bytes, const bool bits32) {

    char magic[48];

    printf("\nInformações do cabeçalho ELF do arquivo %s\n\n", nomeArquivo);

    getMagicNumber(magic, bytes);
    printf("Número magico: %s\n", magic);
    printf("Arquitetura: %s\n", bits32 ? "32 bits" : "64 bits");
    printf("Data: %s\n", bytes[5] == 1 ? "pequena extremidade" : "grande extremidade");
    printf("Versão: %d\n", bytes[6]);
    printf("Sistem Operacional: %s\n", getOS(bytes[7]));
    printf("Versão ABI: %d\n", bytes[8]);
    printf("Tipo: %s\n", getType(bytes[16] - 1));
    printf("Aquitetura: %s\n", getArch(bytes[18]));
    printf("Versão ELF: %d\n", bytes[20]);
    printf("Endereço de Entrada: 0x%X\n", bytes[24]);
    printf("Endereço do cabeçalho do programa: 0x%X\n", bytes[bits32 ? 28 : 32]);
    printf("Endereço de cabeçalho do seção: 0x%X\n", bytes[bits32 ? 32 : 40]);
    printf("Flags: 0x%X\n", bytes[bits32 ? 38 : 48]);
    printf("Tamanho do cabeçalho do programa: %d\n", bytes[bits32 ? 40 : 52]);
    printf("Tamanho da tabela do cabeçalho do programa: %d\n", bytes[bits32 ? 42 : 54]);
    printf("Número de entradas na tabela de cabeçalho e programa.: %d\n", bytes[bits32 ? 0x2C : 56]);
    printf("Número de entradas na tabela de cabeçalho de seção: %d\n", bytes[bits32 ? 0x30 : 0x3C]);
    printf("Índice da entrada da tabela de cabeçalho de seção que contem os nomes de seção: %d\n\n", bytes[bits32 ? 0x32 : 0x3E]);

    printf("Cabeçalho ELF completo em hexadecimal: \n");

    const int size = bits32 ? 52 : 64;

    for (int i = 0; i < size; i++) {

        if (i % (size / 4) == 0) {

            printf("\n");

        }
        printf(" %c%X", bytes[i] < 16 ? '0' : '\0', bytes[i]);

    }
    printf("\n");

}

void criarHeader(const char * path, const char * nomeArquivo, const unsigned char * bytes, const bool bits32) {

    FILE * file;

    char magic[48];

    file = fopen(path, "w");

    if (file == NULL) {
        
        printf("Erro ao tentar criar arquivo de saída\n");
        exit(EXIT_FAILURE);

    }

    fprintf(file , "Informações do cabeçalho ELF do arquivo %s\n\n", nomeArquivo);

    getMagicNumber(magic, bytes);
    fprintf(file, "Número magico: %s\n", magic);
    fprintf(file, "Arquitetura: %s\n", bits32 ? "32 bits" : "64 bits");
    fprintf(file, "Data: %s\n", bytes[5] == 1 ? "pequena extremidade" : "grande extremidade");
    fprintf(file, "Versão: %d\n", bytes[6]);
    fprintf(file, "Sistem Operacional: %s\n", getOS(bytes[7]));
    fprintf(file, "Versão ABI: %d\n", bytes[8]);
    fprintf(file, "Tipo: %s\n", getType(bytes[16] - 1));
    fprintf(file, "Aquitetura: %s\n", getArch(bytes[18]));
    fprintf(file, "Versão ELF: %d\n", bytes[20]);
    fprintf(file, "Endereço de Entrada: 0x%X\n", bytes[24]);
    fprintf(file, "Endereço do cabeçalho do programa: 0x%X\n", bytes[bits32 ? 28 : 32]);
    fprintf(file, "Endereço de cabeçalho do seção: 0x%X\n", bytes[bits32 ? 32 : 40]);
    fprintf(file, "Flags: 0x%X\n", bytes[bits32 ? 38 : 48]);
    fprintf(file, "Tamanho do cabeçalho do programa: %d\n", bytes[bits32 ? 40 : 52]);
    fprintf(file, "Tamanho da tabela do cabeçalho do programa: %d\n", bytes[bits32 ? 42 : 54]);
    fprintf(file, "Número de entradas na tabela de cabeçalho e programa.: %d\n", bytes[bits32 ? 0x2C : 56]);
    fprintf(file, "Número de entradas na tabela de cabeçalho de seção: %d\n", bytes[bits32 ? 0x30 : 0x3C]);
    fprintf(file, "Índice da entrada da tabela de cabeçalho de seção que contem os nomes de seção: %d\n\n", bytes[bits32 ? 0x32 : 0x3E]);

    fprintf(file, "Cabeçalho ELF completo em hexadecimal: \n");

    const int size = bits32 ? 52 : 64;

    for (int i = 0; i < size; i++) {

        if (i % (size / 4) == 0) {

            fprintf(file, "\n");

        }
        fprintf(file, "%s%X", bytes[i] < 16 ? " 0" : " ", bytes[i]);

    }
    fprintf(file, "\n");
    

}

void getMagicNumber(char * dist, const unsigned char * bytes) {

    sprintf(dist, "%X %X %X %X %X %X %X %X %X %X %X %X %X %X %X %X", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5], bytes[6], bytes[7], bytes[8], bytes[9], bytes[10], bytes[11], bytes[12], bytes[13], bytes[14], bytes[15]);

}

void validaELF(const unsigned char * bytes, bool * bits32) {
    
    unsigned char dist[48];

    getMagicNumber((char *)dist, bytes);
    
    if (strcmp((char *)dist, "7F 45 4C 46 2 1 1 0 0 0 0 0 0 0 0 0") == 0) {
    
        *bits32 = false;

    } else if(strcmp((char *)dist, "7F 45 4C 46 1 1 1 0 0 0 0 0 0 0 0 0") == 0) {

        *bits32 = true;

    } else {

        printf("\nErro formato de arquivo invalido, informe um arquivo em formato ELF\n");
        exit(EXIT_FAILURE);

    }

}

unsigned char * lerELF(const char * path) {
    
    FILE * file;

    file = fopen(path, "rb");

    char * conteudo = malloc(SIZE_HEADER);

    if (file == NULL) {
        
        printf("\narquvivo elf não encontrado\n");
        exit(EXIT_FAILURE);

    }

    fgets(conteudo, SIZE_HEADER, file);
    

    fclose(file);

    return (unsigned char *)conteudo; 

}