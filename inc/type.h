#ifndef TYPE
#define TYPE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u64;

#define LOG(STR, ...) printf("LOG:" #STR "\n",__VA_ARGS__)
#endif//TYPE
