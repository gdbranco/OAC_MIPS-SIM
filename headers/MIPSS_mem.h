#ifndef MIPSS_MEM_H
#define MIPSS_MEM_H

#include <iostream>
#include <iomanip>
#include <string>
#define HEX 'h'
#define DEC 'd'
#define MEM_SIZE 8192
typedef struct _reg
{
    std::string name;//$xx\0
    std::string alt_name;
    int value;
}reg;
extern int pc,hi,lo;
extern reg breg[32];

void inicializa_breg();
void init(int index, const char* name, const char* _aname, int value);
void set_reg(int index, int value);
void set_reg(const char* _name, int _value);
int get_regIndex(std::string name);
void dump_reg(char format);

extern int mem[MEM_SIZE];
extern int *data;

void dump_mem(unsigned int start, unsigned int end, char format);

#endif // MEM_H



