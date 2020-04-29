CXXFLAGS=-Iinc -Wall -pedantic -g -std=c++0x

__start__: grafy
	./grafy

grafy: obj/main.o obj/Listtools.o obj/Arreytools.o obj/Pathtools.o 
	g++ -Wall -pedantic -std=c++0x -o grafy obj/main.o obj/Listtools.o obj/Arreytools.o obj/Pathtools.o 

obj/main.o: scr/main.cpp inc/Graphtools.hh inc/Listtools.hh inc/Arreytools.hh
	g++ -c $(CXXFLAGS) -o obj/main.o scr/main.cpp

obj/Listtools.o: scr/Listtools.cpp inc/Listtools.hh inc/Graphtools.hh
	g++ -c $(CXXFLAGS) -o obj/Listtools.o scr/Listtools.cpp

obj/Arreytools.o: scr/Arreytools.cpp inc/Arreytools.hh inc/Graphtools.hh
	g++ -c $(CXXFLAGS) -o obj/Arreytools.o scr/Arreytools.cpp

obj/Pathtools.o: scr/Pathtools.cpp inc/Pathtools.hh inc/Arreytools.hh inc/Listtools.hh
	g++ -c $(CXXFLAGS) -o obj/Pathtools.o scr/Pathtools.cpp


clean:
	rm -f obj/*.o grafy