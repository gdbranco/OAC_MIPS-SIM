#include "../headers/MIPSS_filectrl.h"

int mem[MEM_SIZE]= {0};
int *data = mem + 2048;

void file_read(std::string name)
{
    name+=".bin";
    std::ifstream file(name.c_str(), std::fstream::binary);
    if(file)
    {
        file.seekg(0, file.end);
        int size_bin = file.tellg();

        file.seekg(0, file.beg);
        std::size_t found = name.find("text");
        if(found!=std::string::npos)
        {
            file.read((char *) mem, (int) size_bin);
        }
        else
        {
            file.read((char *) data, (int) size_bin);
        }
	std::cout<<"Arquivo "+name+" carregado\n";
	std::cin.get();
    }
    else
        std::cout<<"Nao foi possivel abrir o arquivo\n";
}
