main: main.o memento.o ComplexNumber.o Store.o
	g++ -o memento main.o memento.o ComplexNumber.o Store.o


main.o: main.cpp
	g++ -c main.cpp

memento.o: memento.cpp
	g++ -c memento.cpp

ComplexNumber.o: ComplexNumber.cpp
	g++ -c ComplexNumber.cpp

Store.o: Store.cpp
	g++ -c Store.cpp

clean:
	rm -f memento
	rm -f *.o
	rm -f *.out
	rm -f *.exe
	rm -f *.stackdump