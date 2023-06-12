all: build run


build:
	
	g++ -I ./include/ -o ./lib/DosyaOkuyucu.o -c ./src/DosyaOkuyucu.cpp
	g++ -I ./include/ -o ./lib/hucre.o -c ./src/hucre.cpp
	g++ -I ./include/ -o ./lib/hucreNode.o -c ./src/hucreNode.cpp
	g++ -I ./include/ -o ./lib/doku.o -c ./src/doku.cpp
	g++ -I ./include/ -o ./lib/dokuNode.o -c ./src/dokuNode.cpp
	g++ -I ./include/ -o ./lib/queue.o -c ./src/queue.cpp
	g++ -I ./include/ -o ./lib/radix.o -c ./src/radix.cpp

	g++ -I ./include/ -o ./bin/main  ./lib/DosyaOkuyucu.o ./lib/hucre.o ./lib/hucreNode.o ./lib/doku.o  ./lib/dokuNode.o ./lib/queue.o ./lib/radix.o ./src/main.cpp

run:
	./bin/main