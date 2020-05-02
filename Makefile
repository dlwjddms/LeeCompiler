app.out: main.o lexicalAnalyzer.o initTree.o
	gcc -o app.out main.o lexicalAnalyzer.o initTree.o
	 
main.o: lexicalAnalyzer.h initTree.h main.c
	gcc -c -o main.o main.c
		 
lexicalAnalyzer.o: lexicalAnalyzer.h lexicalAnalyzer.c
	gcc -c -o lexicalAnalyzer.o lexicalAnalyzer.c
			 
initTree.o: initTree.h initTree.c
	 gcc -c -o initTree.o initTree.c
