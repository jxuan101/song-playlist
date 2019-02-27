
all: hello

hello: main.o PlayList.o Song.o
	g++ main.o PlayList.o Song.o -o hello

main: main.cpp
	g++ -c main.cpp

PlayList.o: PlayList.cpp
	g++ -c PlayList.cpp

Song.o: Song.cpp
	g++ -c Song.cpp

clean:
	-rm hello *.o
