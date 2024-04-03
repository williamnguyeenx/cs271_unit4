all: test usecase

test: test_bst.o 
	g++ -o test test_bst.o 

test_bst.o: test_bst.cpp 
	g++ -c test_bst.cpp

usecase: usecase.o 
	g++ -Wall -g -o usecase usecase.o 

usecase.o: main.cpp
	g++ -c -g -Wall main.cpp -o usecase.o

main.o: main.cpp
	g++ -c -g -Wall main.cpp

clean:
	rm -f *.o test usecase