#ifndef MIPSS_OPS_H
#define MIPSS_OPS_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <string>
#include <sstream>
#include "./MIPSS_mem.h"
#include "./MIPSS_flowctrl.h"
enum SYSCALL_CODES
{
    PRINT_INT = 1, PRINT_STRING = 4, END = 10
};
std::string hex_to_string (std::string str, unsigned int resto,unsigned int &done);
//Operacoes aritimeticas e logicas
void addi(unsigned int rdest,unsigned int rt, signed int immediate);
void addiu(unsigned int rdest,unsigned int rt, unsigned int immediate);
void add(unsigned int rdest,unsigned int r1,unsigned int r2);
void subi(unsigned int rdest,unsigned int rt, signed int immediate);
void subiu(unsigned int rdest,unsigned int rt, unsigned int immediate);
void sub(unsigned int rdest,unsigned int r1,unsigned int r2);
void mult(unsigned int rdest,unsigned int r1);
void div(unsigned int r1,unsigned int r2);
void andi_(unsigned int rdest,unsigned int r1, int immediate);
void and_(unsigned int rdest,unsigned int r1,unsigned int r2);
void ori_(unsigned int rdest,unsigned int r1, signed int immediate);
void or_(unsigned int rdest,unsigned int r1,unsigned int r2);
void xori_(unsigned int rdest,unsigned int r1, signed int immediate);
void xor_(unsigned int rdest,unsigned int r1,unsigned int r2);
void nor(unsigned int rdest,unsigned int r1,unsigned int r2);
void slt(unsigned int rdest,unsigned int r1,unsigned int r2);
void slti(unsigned int rs,unsigned int rt,int immediate);
void sltiu(unsigned int rs,unsigned int rt,unsigned int immediate);
void sll(unsigned int rdest,unsigned int r1, unsigned int shift);
void srl(unsigned int rdest,unsigned int r1, unsigned int shift);
void sra(unsigned int rdest,unsigned int r1, unsigned int shift);
void mfhi(unsigned int rdest);
void mflo(unsigned int rdest);
//Syscall
void syscall();
//Jumps
void j(unsigned int address);
void jal(unsigned int address);
void jr(unsigned int rdest);
void beq(unsigned int rs, unsigned int rt,int address);
void bne(unsigned int rs,unsigned int rt,int address);
void blez(unsigned int rs,int address);
void bgtz(unsigned int rs,int address);
//Memoria
void lui(unsigned int rt,int immediate);
void lw(unsigned int rs,unsigned int rt,int immediate);
void lh(unsigned int rs, unsigned int rt, int immediate);
void lhu(unsigned int rs, unsigned int rt, int immediate);
void lb(unsigned int rs, unsigned int rt,int immediate);
void lbu(unsigned int rs, unsigned int rt,unsigned int immediate);
void sw(unsigned int rs, unsigned int rt, int immediate);
void sh(unsigned int rs, unsigned int rt, int immediate);
void sb(unsigned int rs, unsigned int rt, int immediate);
#endif // OPERATIONS_H
