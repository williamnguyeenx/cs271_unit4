all: test usecase

test: test_bst.o
	g++ -o test test_bst.o

test_bst.o: test_bst.cpp
	g++ -c test_bst.cpp

usecase: usecase.o
	g++ -o usecase usecase.o

usecase.o: main.cpp
	g++ -o usecase main.cpp

clean:
	rm -f test usecase *.o