%{
	int count=0;
%}
%%
[a-zA-Z] count++;
\n {return count;}
%%
main()
{	
	yylex();
	printf("count=%d\n",count);
}	



