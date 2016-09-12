#include "../headers/MIPSS_mem.h"
void dump_mem(unsigned int start, unsigned int end, char format)
{
    unsigned int i;
    std::cout<<"\n-------------------------Memoria-------------------------\n";
    for(i = start; i<end+1; i++)
    {
        if(i%5==0)
            std::cout<<std::endl;
	if(i%25==0)
	{
		std::cout<<"\nEnter para continuar: ";
		std::cin.get();	
	}
        if(HEX)
        {
            std::cout << "0x" // show the 0x prefix
                  << std::internal // fill between the prefix and the number
                  << std::setfill('0')<<std::setw(8)<<std::hex<<mem[i]<<" "<<std::dec; // fill with 0
        }
        else
            std::cout<<mem[i]<<" ";
    }
    std::cout<<"\n---------------------------------------------------------\n";
    std::cout<<"Enter para retornar: ";
    std::cin.get();
}

