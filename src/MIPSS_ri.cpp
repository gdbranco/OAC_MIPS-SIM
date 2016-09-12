#include "../headers/MIPSS_ri.h"

Inst ri;
void inicializa_ri()
{
    ri.op = 0;
    ri.rs = 0;
    ri.rd = 0;
    ri.rt = 0;
    ri.s = 0;
    ri.f = 0;
    ri.k16 = 0;
    ri.k26 = 0;
    return;
}

void decode(unsigned int iri)
{
    ri.op = ((iri>>26)&0x3F);
    ri.rs = ((iri>>21)&0x1F);
    ri.rt = ((iri>>16)&0x1F);
    ri.rd = ((iri>>11)&0x1F);
    ri.s  = ((iri>>6)&0x1F);
    ri.f  = ((iri)&0x3F);
    ri.k16 = ((iri)&0xFFFF)<<16;
    ri.k16 >>=16;
    ri.k26 = ((iri)&0x3FFFFFF)<<10;
    ri.k26 >>=10;
    return;
}
