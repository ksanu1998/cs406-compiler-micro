#include <stdio.h>
int yyset_in();
int yyparse();
int main(int argc, char* argv[])
{
	FILE* fd = fopen(argv[1], "r");
	FILE* out_fd = fopen(argv[2], "w");
	yyset_in(fd);
   	if(!yyparse())
   	{
   		fprintf(out_fd, "%s\r\n", "Accepted");
   	}
      else
      {
         fprintf(out_fd, "%s\r\n", "Not accepted");
      }
   	fclose(fd);
   	fclose(out_fd);
	return 0;
}