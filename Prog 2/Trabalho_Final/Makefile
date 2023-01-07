# mingw32-make
# ./teste

all: Trabalho

Trabalho: main.o prototipacao.o
	g++ -o Trabalho main.o prototipacao.o

main.o: main.cc 
	g++ -c main.cc 

prototipacao.o: prototipacao.cc 
	g++ -c prototipacao.cc 


clean:
	rm -rf *.o *~ teste