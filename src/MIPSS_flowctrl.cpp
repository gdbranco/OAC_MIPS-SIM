#include "../headers/MIPSS_flowctrl.h"
int running;
unsigned int fetch()
{
    unsigned int iri = mem[pc>>2];
    pc += 4;
    return iri;
}

void step()
{
    unsigned int iri = fetch();
    decode(iri);
    execute();
}

void run()
{
    running = 1;
    inicializa_breg();
    inicializa_ri();
    while(running)
    {
        step();
    }
}

void execute()
{
    switch(ri.op)
    {
    case EXT:
        function_switcher();
        break;
    case LW:
        lw(ri.rs,ri.rt,ri.k16);
        break;
    case LB:
        lb(ri.rs,ri.rt,ri.k16);
        break;
    case LBU:
        lbu(ri.rs,ri.rt,ri.k16);
        break;
    case LH:
        lh(ri.rs,ri.rt,ri.k16);
        break;
    case LHU:
        lhu(ri.rs,ri.rt,ri.k16);
        break;
    case LUI:
        lui(ri.rt,ri.k16);
        break;
    case SW:
        sw(ri.rs,ri.rt,ri.k16);
        break;
    case SB:
        sb(ri.rs,ri.rt,ri.k16);
        break;
    case SH:
        sh(ri.rs,ri.rt,ri.k16);
        break;
    case BEQ:
        beq(ri.rs,ri.rt,ri.k16);
        break;
    case BNE:
        bne(ri.rs,ri.rt,ri.k16);
        break;
    case BLEZ:
        blez(ri.rs,ri.k16);
        break;
    case BGTZ:
        bgtz(ri.rs,ri.k16);
        break;
    case ADDI:
        addi(ri.rt,ri.rs,ri.k16);
        break;
    case SLTI:
        slti(ri.rs,ri.rt,ri.k16);
        break;
    case SLTIU:
        sltiu(ri.rs,ri.rt,ri.k16);
        break;
    case ANDI:
        andi_(ri.rt,ri.rs,ri.k16);
        break;
    case ORI:
        ori_(ri.rt,ri.rs,ri.k16);
        break;
    case XORI:
        xori_(ri.rt,ri.rs,ri.k16);
        break;
    case J:
        j(ri.k26);
        break;
    case JAL:
        jal(ri.k26);
        break;
    case ADDIU:
        addiu(ri.rt,ri.rs,ri.k16);
        break;
    }
}

void function_switcher()
{
    switch(ri.f)
    {
    case ADD:
        add(ri.rd,ri.rs,ri.rt);
        break;
    case SUB:
        sub(ri.rd,ri.rs,ri.rt);
        break;
    case MULT:
        mult(ri.rs,ri.rt);
        break;
    case DIV:
        div(ri.rs,ri.rt);
        break;
    case AND:
        and_(ri.rd,ri.rs,ri.rt);
        break;
    case OR:
        or_(ri.rd,ri.rs,ri.rt);
        break;
    case XOR:
        xor_(ri.rd,ri.rs,ri.rt);
        break;
    case NOR:
        nor(ri.rd,ri.rs,ri.rt);
        break;
    case SLT:
        slt(ri.rd,ri.rs,ri.rt);
        break;
    case JR:
        jr(ri.rs);
        break;
    case SLL:
        sll(ri.rd,ri.rt,ri.s);
        break;
    case SRL:
        srl(ri.rd,ri.rt,ri.s);
        break;
    case SRA:
        sra(ri.rd,ri.rt,ri.s);
        break;
    case MFHI:
        mfhi(ri.rd);
        break;
    case MFLO:
        mflo(ri.rd);
        break;
    case SYSCALL:
        syscall();
        break;
    }
}
