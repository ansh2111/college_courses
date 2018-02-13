%%
[\t]+
is |
are |
am |
was |
were { printf("%s is a valid helping verb\n",yytext);}
[a-zA-Z]+ {printf("%s is an invalid helping verb\n",yytext);}
. | \n
%%
main()
{ yylex(); }
