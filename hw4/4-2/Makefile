main: main.o graph.o node.o operation.o mymap.o OperationMinus.o OperationPlus.o
	g++ -std=c++11 -o main main.o graph.o node.o operation.o OperationPlus.o OperationMinus.o mymap.o 
main.o: main.cpp
	g++ -c -std=c++11 -o main.o main.cpp 
graph.o: graph.cpp graph.h mymap.h node.h operation.h
	g++ -c -std=c++11 -o graph.o graph.cpp 
node.o: node.cpp node.h
	g++ -c -std=c++11 -o node.o node.cpp 
operation.o: operation.cpp operation.h node.h
	g++ -c -std=c++11 -o operation.o operation.cpp 
OperationPlus.o: OperationPlus.cpp OperationPlus.h node.h operation.h operation.cpp
	g++ -c -std=c++11 -o OperationPlus.o OperationPlus.cpp 
OperationMinus.o: OperationMinus.cpp OperationMinus.h node.h operation.h operation.cpp
	g++ -c -std=c++11 -o OperationMinus.o OperationMinus.cpp 
mymap.o: mymap.cpp mymap.h 
	g++ -c -std=c++11 -o mymap.o mymap.cpp 
clean:
	rm main *.o
