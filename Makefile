# Tinotenda Muzambi
# MZMTIN002

default:
	@g++ main.cpp ann.cpp -o ann

main.run: main.o ann.o
	g++ main.run main.o ann.o
main.o: main.cpp ann.h
	g++ -c -o main.o main.cpp
ann.o: ann.cpp ann.h
	g++ -c -o ann.o ann.cpp

clean:
	@rm -f ./ann *.o

run:
	@./ann
