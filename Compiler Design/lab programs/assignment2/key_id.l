/*2015KUCP1018
	ANANT SHARMA
	COMPILER DESIGN LAB
	
	Compilation: flex key_id.l
				gcc lex.yy.c -lfl
	Execution: ./a.out 
	*/
%{
	int id=0;
	int key=0;
%}
%%
auto |
break |
case |
char |
const |
continue |
default |
do |
double |
else |
enum |
extern |
float |
for |
goto |
if |
int |
long |
register |
return |
short |
signed |
sizeof |
static |
struct |
switch |
typedef |
union |
unsigned |
void |
volatile |
while  {  key=1;}
[0-9]([a-zA-Z0-9_])* {id=0;}
[a-zA-Z_]([a-zA-Z0-9_])* {id=1;}

\n {if(key==1 && id==0) 
		printf("Valid keyword\n");
	else if(id==0 && key==0)	
		printf("Invalid identifier\n");
	else if(id==1)	
		printf("Valid identifier\n");	
	id=0;
	key=0;	
	}
%%
main()
{
	yylex();
}
