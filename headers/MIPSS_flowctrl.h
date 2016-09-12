#ifndef MIPSS_FLWC_H
#define MIPSS_FLWC_H

#include "./MIPSS_ri.h"
#include "./MIPSS_ops.h"
#include "./MIPSS_mem.h"

extern int running;
enum OPCODES	  	 //	lembrem	que	so	sao	considerados	os	6	primeiros	bits	dessas	constantes
{
    EXT=0x00, LW=0x23, LB=0x20, LBU=0x24,
    LH=0x21, LHU=0x25, LUI=0x0F, SW=0x2B,
    SB=0x28, SH=0x29, BEQ=0x04, BNE=0x05,
    BLEZ=0x06, BGTZ=0x07, ADDI=0x08, SLTI=0x0A,
    SLTIU=0x0B, ANDI=0x0C, ORI=0x0D, XORI=0x0E,
    J=0x02, JAL=0x03, ADDIU=0x09
};
enum FUNCT
{
    ADD=0x20, SUB=0x22, MULT=0x18, DIV=0x1A, AND=0x24,
    OR=0x25, XOR=0x26, NOR=0x27, SLT=0x2A, JR=0x08,
    SLL=0x00, SRL=0x02, SRA=0x03, SYSCALL=0x0c, MFHI=0x10,MFLO=0x12
};

unsigned int fetch();
void execute();
void function_switcher();
void step();
void run();

#endif // MIPSS_FC_H

