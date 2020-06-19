# Tinotenda Muzambi
# MZMTIN002

default:
	@g++ main.cpp neuron.cpp matrix.cpp layer.cpp ann.cpp -o ann --std=c++11

main.run: main.o neuron.o matrix.o layer.o ann.o
	g++ main.run main.o ann.o --std=c++11
main.o: main.cpp neuron.h matrix.h layer.h ann.h
	g++ -c -o main.o main.cpp --std=c++11
neuron.o: neuron.cpp neuron.h
	g++ -c -o neuron.o neuron.cpp --std=c++11
matrix.o: matrix.cpp matrix.h
	g++ -c -o matrix.o matrix.cpp --std=c++11
layer.o: layer.cpp layer.h
	g++ -c -o layer.o layer.cpp --std=c++11
ann.o: ann.cpp ann.h
	g++ -c -o ann.o ann.cpp --std=c++11

clean:
	@rm -f ./ann *.o

run:
	@./ann
