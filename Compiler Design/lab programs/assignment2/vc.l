/*2015KUCP1018
	ANANT SHARMA
	COMPILER DESIGN LAB
	
	Compilation: flex key_id.l
				gcc lex.yy.c -lfl
	Execution: ./a.out 
	*/
%{
	int vowels=0;
	int consonents=0;
%}
%%
[a/e/i/o/u/A/E/I/O/U] vowels++;
[a-zA-Z] consonents++;
\n {printf("count of vowels=%d consonents=%d\n",vowels,consonents);
	vowels=0;
	consonents=0;
	}
%%
main()
{	
	yylex();
	
}	



