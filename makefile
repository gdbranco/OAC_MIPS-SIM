all: MIPSS

MIPSS: main.o MIPSS_filectrl.o MIPSS_flowctrl.o MIPSS_mem.o MIPSS_ops.o MIPSS_ri.o MIPSS_uinterface.o
	g++ main.o MIPSS_filectrl.o MIPSS_flowctrl.o MIPSS_memtd.o MIPSS_memregs.o MIPSS_ops.o MIPSS_ri.o MIPSS_uinterface.o -o MIPSS

main.o: src/main.cpp
	g++ -g -Wall src/main.cpp -c

MIPSS_filectrl.o: src/MIPSS_filectrl.cpp headers/MIPSS_filectrl.h
	g++ -g -Wall src/MIPSS_filectrl.cpp -c

MIPSS_flowctrl.o: src/MIPSS_flowctrl.cpp headers/MIPSS_flowctrl.h
	g++ -g -Wall src/MIPSS_flowctrl.cpp -c

MIPSS_mem.o: src/MIPSS_memtd.cpp src/MIPSS_memregs.cpp headers/MIPSS_mem.h
	g++ -g -Wall src/MIPSS_memtd.cpp src/MIPSS_memregs.cpp -c

MIPSS_ops.o: src/MIPSS_ops.cpp headers/MIPSS_ops.h
	g++ -g -Wall src/MIPSS_ops.cpp -c

MIPSS_ri.o: src/MIPSS_ri.cpp headers/MIPSS_ri.h
	g++ -g -Wall src/MIPSS_ri.cpp -c

MIPSS_uinterface.o: src/MIPSS_uinterface.cpp headers/MIPSS_uinterface.h
	g++ -g -Wall src/MIPSS_uinterface.cpp -c

run:
	./MIPSS

limpa:
	rm -f *.o
	rm -f MIPSS
