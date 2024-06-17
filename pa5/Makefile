all: compiler clean team
compiler:
	mkdir -p genfiles
	mkdir -p buildfiles
	flex  -o genfiles/scanner.cpp src/scanner.ll
	bison -d -o genfiles/parser.cpp src/parser.yy
	g++ -c -o buildfiles/parser.o genfiles/parser.cpp -g
	g++ -c -o buildfiles/scanner.o genfiles/scanner.cpp -g
	g++ -c -o buildfiles/main.o src/main.cpp -g
	g++ -o parse buildfiles/scanner.o buildfiles/parser.o buildfiles/main.o -g
clean:
	rm -rf genfiles
	rm -rf buildfiles
	rm -f parse
team:
	echo "Team: ksanu1998\n\nK. Sai Anuroop\n170030035@iitdh.ac.in\n\nHarshal Gajjar\n160010003@iitdh.ac.in"
