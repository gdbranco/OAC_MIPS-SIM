#ifndef MIPSS_RI_H
#define MIPSS_RI_H
typedef struct _inst
{
    unsigned int op;
    unsigned int rs;
    unsigned int rt;
    unsigned int rd;
    unsigned int s;
    unsigned int f;
    int k16;
    int k26;
}Inst;

extern Inst ri;

void inicializa_ri();
void decode(unsigned int iri);
#endif // INST_G
