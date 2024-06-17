all: compiler clean
compiler: trylex.l microParser.y
	bison -d -o microParser.c microParser.y
	flex trylex.l
	gcc -o parse microParser.c lex.yy.c driver.c -ll
clean:
	rm -f lex.yy.c
	rm -f microParser.c
	rm -f microParser.h
team:
	echo "Team: ksanu1998\n\nK. Sai Anuroop\n170030035@iitdh.ac.in\n\nHarshal Gajjar\n160010003@iitdh.ac.in"