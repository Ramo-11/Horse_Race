horseRace: Horse.o Race.o main.o
	g++ Horse.o Race.o main.o -o horseRace
Horse.o: Horse.cpp Horse.h
	g++ -c Horse.cpp
Race.o: Race.cpp Race.h Horse.h
	g++ -c Race.cpp
main.o: main.cpp Race.h Horse.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm horseRace
run: horseRace
	./horseRace

