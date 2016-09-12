#include "../headers/MIPSS_uinterface.h"
enum MENU_CODES
{
    REG ='1',STEP = '2', RODAR = '2',PP = '3',MEM = '4',SAIR = '5',ARQUIVOS  = '1',VOLTAR = '3'
};

void menu()
{
    unsigned char opt;
    std::string s_text,s_data;
    bool floaded = false;
    while(opt!=SAIR)
    {
        wipe();
        std::cout<<"-------------------------MIPS SIMULATOR v3.2-------------------------\n";
        std::cout<<"\n\t 1 - Carregar arquivos de memoria \n\t 2 - Rodar programa\n\t 3 - Rodar programa passo a passo\n\t 4 - Mostrar regiao de memoria(inicio, fim)\n\t 5 - Sair\n";
        std::cout<<"(lembre-se de carregar os arquivos primeiro)\n\tInsira opcao: ";
        std::cin>>opt;
        std::cin.get();
        switch(opt)
        {
        case ARQUIVOS:
	    floaded = true;
            wipe();
            std::cout<<"\n----Deseja utilizar os arquivos binarios padroes(text.bin,data.bin)\n\t?(S|N): ";
            std::cin>>opt;
	    std::cin.get();
	    while(opt!='n'&& opt!='N' && opt!='s' && opt!='S')
	    {
		std::cout<<"\n!!!Opcao nao existe!!!. Insira novamente: ";
		std::cin>>opt;
		std::cin.get();
            }
            if(opt=='N' || opt=='n')
            {
                std::cout<<"\nInsira o arquivo com o <text> (a extensao .bin sera adicionada automaticamente)\n !!!<text> deve estar contido no nome do arquivo!!!\n\t : ";
                std::cin>>s_text;
                std::cin.get();
		std::size_t found = s_text.find("text");
		while(found==std::string::npos)
		{
		      std::cout<<"\n Arquivo inserido nao contem <text> em seu nome. Por favor insira novamente : ";
		      std::cin>>s_text;
	              std::cin.get();
		      found = s_text.find("text");
		}
                std::cout<<"\nInsira o arquivo com a <data> (a extensao .bin sera adicionada automaticamente)\n !!!<data> deve estar contida no nome do arquivo!!!\n\t : ";
                std::cin>>s_data;
                std::cin.get();
		found = s_data.find("data");
		while(found==std::string::npos)
		{
		      std::cout<<"\n Arquivo inserido nao contem <data> em seu nome. Por favor insira novamente : ";
		      std::cin>>s_data;
	              std::cin.get();
                      found = s_data.find("data");
		}
            }
            else
            {
                s_text = "text.bin";
                s_data = "data.bin";
            }
            file_read(s_text);
            file_read(s_data);
            break;
        case RODAR:
            if(!floaded)
	    {
		std::cout<<"\n\t!!!Arquivos nao carregados!!!\n";
	    	std::cout<<"\nEnter para continuar : ";
		std::cin.get();
   	    }
	    else
 	    {
		wipe();
		std::cout<<"\n-------------------------Programa-------------------------\n";
            	run();
                std::cout<<"\n----------------------------------------------------------\n";
	    	std::cout<<"\nEnter para continuar : ";
            	std::cin.get();
     	    }
            break;
        case PP:
	    if(!floaded)
	    {
		std::cout<<"\n\t!!!Arquivos nao carregados!!!\n";
	    	std::cout<<"\nEnter para continuar : ";
		std::cin.get();
   	    }
	    else
	        menu_step();
            break;
        case MEM:
	     if(!floaded)
	    {
		std::cout<<"\n\t!!!Arquivos nao carregados!!!\n";
	    	std::cout<<"\nEnter para continuar : ";
		std::cin.get();
   	    }
            else
	    {
		menu_dump_mem();
	    }
            break;
        case SAIR:
            return;
            break;
        }
    }
    return;
}

void menu_step()
{
    inicializa_breg();
    inicializa_ri();
    char opt;
    while(running || opt!= VOLTAR)
    {
        std::cout<<"\n\t 1 - Mostrar registradores\n\t 2 - Continuar o passo a passo\n\t 3 - VOLTAR\n";
        std::cout<<"\n\tInsira opcao:";
        std::cin>>opt;
        std::cin.get();
        switch(opt)
        {
        case REG:
            wipe();
            menu_dump_regs();
            break;
        case STEP:
            wipe();
	    std::cout<<"\n-------------------------Step Executado-------------------------\n";
            step();
	    std::cout<<"\n----------------------------------------------------------------\n";
	    std::cout<<"\nEnter para continuar : ";
            std::cin.get();
            break;
        case VOLTAR:
            return;
            break;
        }
    }
    return;
}


void menu_dump_regs()
{
    char frmt;
    std::cout<<"\nFormatacao hex|dec(h|d): ";
    std::cin>>frmt;
    std::cin.get();
    dump_reg(frmt);
    return;
}

void menu_dump_mem()
{
    unsigned int inicio, fim;
    char frmt;
    std::cout<<"\nInsira o inicio da regiao de memoria (0,8190) : ";
    std::cin>>inicio;
    std::cin.get();
    std::cout<<"\nInsira o fim da regiao de memoria (1,8191) : ";
    std::cin>>fim;
    std::cin.get();
    std::cout<<"\nFormatacao hex|dec(h|d): ";
    std::cin>>frmt;
    std::cin.get();
    dump_mem(inicio,fim,frmt);
    return;
}
