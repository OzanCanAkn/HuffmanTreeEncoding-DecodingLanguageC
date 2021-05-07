main: main.o BinaryTree.o Filer.o LetterCounter.o
	g++ -std=c++11 main.cpp BinaryTree.o Filer.o LetterCounter.o -o main
main.o: main.cpp
	g++ -c -std=c++11 main.cpp

BinaryTree.o: BinaryTree.cpp
	g++ -c -std=c++11 BinaryTree.cpp

Filer.o: Filer.cpp
	g++ -c -std=c++11 Filer.cpp


LetterCounter.o: LetterCounter.cpp
	g++ -c -std=c++11 LetterCounter.cpp