#pragma once

#include<stdbool.h>

#define SIZE_HEADER 64
#define SPARC 2
#define X86 3
#define MIPS 8
#define POWERPC 0x14
#define S390 0x16
#define ARM 0x28
#define SUPERH 0x2A
#define IA_64 0x32
#define X86_64 0x3E
#define AArch64 0xB7
#define RISC_V 0xF3

char * getArch(unsigned char identifier);

char * getType(unsigned char identifier);

char * getOS(unsigned char identifier);

void mostrarHeader(const char * nomeArquivo, const unsigned char * bytes, const bool bits32);

void criarHeader(const char * path, const char * nomeArquivo, const unsigned char * bytes, const bool bits32);

void getMagicNumber(char * dist, const unsigned char * bytes);

void validaELF(const unsigned char * bytes, bool * bits32);

unsigned char * lerELF(const char * path);