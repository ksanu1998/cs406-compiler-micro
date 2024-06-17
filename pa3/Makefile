all: compiler clean
compiler:
	bison -d -o microParser.cpp microParser.yy
	flex -o scanner.cpp trylex.ll
	g++ -o parse microParser.cpp scanner.cpp driver_declaration_check.cpp -ll

	bison -d -o ./syntax_checker/microParser.c ./syntax_checker/microParser.y
	flex -o ./syntax_checker/lex.yy.c ./syntax_checker/trylex.l
	gcc -o syntax_check ./syntax_checker/microParser.c ./syntax_checker/lex.yy.c ./syntax_checker/driver_syntax_checker.c -ll

clean:
	rm -f scanner.cpp
	rm -f microParser.cpp
	rm -f microParser.hpp
	rm -f parse
	rm -f syntax_check
	rm -f ./syntax_checker/microParser.c
	rm -f ./syntax_checker/lex.yy.c
	rm -f ./syntax_checker/microParser.h
team:
	echo "Team: ksanu1998\n\nK. Sai Anuroop\n170030035@iitdh.ac.in\n\nHarshal Gajjar\n160010003@iitdh.ac.in"
