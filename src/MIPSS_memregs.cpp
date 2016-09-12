#include "../headers/MIPSS_mem.h"
reg breg[32];
int pc,hi,lo;
void inicializa_breg()
{
    init(0,"$zero","$0", 0);
    init(1,"$at","$1", 0);
    init(2,"$v0","$2", 0);
    init(3,"$v1","$3", 0);
    init(4,"$a0","$4", 0);
    init(5,"$a1","$5", 0);
    init(6,"$a2","$6", 0);
    init(7,"$a3","$7", 0);
    init(8,"$t0","$8", 0);
    init(9,"$t1","$9", 0);
    init(10,"$t2","$10", 0);
    init(11,"$t3","$11", 0);
    init(12,"$t4","$12", 0);
    init(13,"$t5","$13", 0);
    init(14,"$t6","$14", 0);
    init(15,"$t7","$15", 0);
    init(16,"$s0","$16", 0);
    init(17,"$s1","$17", 0);
    init(18,"$s2","$18", 0);
    init(19,"$s3","$19", 0);
    init(20,"$s4","$20", 0);
    init(21,"$s5","$21", 0);
    init(22,"$s6","$22", 0);
    init(23,"$s7","$23", 0);
    init(24,"$t8","$24", 0);
    init(25,"$t9","$25", 0);
    init(26,"$k0","$26", 0);
    init(27,"$k1","$27", 0);
    init(28,"$gp","$28", 1536*4);
    init(29,"$sp","$29", 4095*4);
    init(30,"$fp","$30", 0);
    init(31,"$ra","$31", 0);
    pc=hi=lo = 0;
    return;
}

void init(int i, const char* _name,const char* _aname, int _value)
{
    breg[i].name = _name;
    breg[i].alt_name = _aname;
    breg[i].value = _value;
    return;
}

void set_reg(int i, int _value)
{
    if(breg[i].name=="$zero"||breg[i].name=="$0")
    {
        std::cout<<"Nao pode mudar o valor do registrador $zero"<<std::endl;
        return;
    }
    breg[i].value = _value;
    return;
}

void set_reg(const char* _name, int _value)
{
    for(unsigned int i=0; i<32; i++)
    {
        if(breg[i].name==_name)
        {
            if(breg[i].name=="$zero")
            {
                std::cout<<"Nao pode mudar o valor do registrador $zero"<<std::endl;
                return;
            }
            breg[i].value = _value;
            break;
        }
    }
    return;
}

int get_regIndex(std::string _name)//Retorna index de registro com nome _name
{
    unsigned int num;
    for(num=0; num<32; num++)
    {
        if(breg[num].name == _name || breg[num].alt_name == _name)
        {
            break;
        }
    }
    return num;
}

void dump_reg(char format)
{
    std::cout<<"\n-------------------------Registradores-------------------------\n";
    if(format==HEX)
    {
	for(unsigned int i=0; i<32; i++)
    	{
	      std::cout<<breg[i].name<<": ";
              std::cout<<"0x"<<std::hex<<breg[i].value<<std::endl<<std::dec;
        }
	std::cout<<"pc: "<<std::hex<<"0x"<<pc<<std::endl;
        std::cout<<"hi: "<<std::hex<<"0x"<<hi<<std::endl;
        std::cout<<"lo: "<<std::hex<<"0x"<<lo<<std::endl<<std::dec;
    }
    else
    {
	 for(unsigned int i=0; i<32; i++)
	 {
	      std::cout<<breg[i].name<<": ";
              std::cout<<breg[i].value<<std::endl;
	 }
	 std::cout<<"pc: "<<pc<<std::endl;
         std::cout<<"hi: "<<hi<<std::endl;
         std::cout<<"lo: "<<lo<<std::endl;
    }
    std::cout<<"\n--------------------------------------------------------------\n";
    std::cout<<"Enter para retornar: ";
    std::cin.get();
}

