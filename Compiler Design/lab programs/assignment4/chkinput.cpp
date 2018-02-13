//wap to check whether input string is accepted or rejected by ll1 grammar.
/*2015KUCP1018
	ANANT SHARMA
	COMPILER DESIGN LAB
	
	Compilation: g++ chkinput.cpp
	Execution: ./a.out 
	*/
#include<bits/stdc++.h>
using namespace std;
int len[1000],top=-1;
char stk[100000];
string prod[100][100];
string parsetbl[100][100];
string ter="",nonter,input="";
string firstarr[100],followarr[100];
string tmp;
int n=0,n1=0,i4=0;
void pushstk(char ch)
{
	top++;
	stk[top]=ch;
}
char popstk()
{
	if(top==-1)
		cout<<"Stack Empty"<<endl;
	char c1=stk[top];
	stk[top--]='\0';
	return c1;
}

int findpos(char ch)
{
	for(int i=0;i<n;i++)
	{
		if(ch == prod[i][0][0])
		{
			return i;
		}	
	}
}
void findnont()
{
	nonter="";
	for(int i=0;i<n;i++)
	{
		nonter+=prod[i][0];
	}	
	cout<<"Non-Terminals: "<<nonter<<endl;
}
void findt()
{
	for(int i=0;i<n;i++)
	{
		ter+=firstarr[i]+followarr[i];
	}
	sort(ter.begin(), ter.end());
	ter.erase(unique(ter.begin(), ter.end()), ter.end());
	int ii1=ter.find('?');
	if(ii1!=-1)
	{
		ter=ter.substr(0,ii1)+ter.substr(ii1+1,ter.length());
	}
	cout<<"Terminals:"<<ter<<endl;	
}
void findfirst(int id)
{
	firstarr[id]="";
	for(int i=1;i<len[id];i++)
	{
		
		for(int j=0;j<prod[id][i].length();j++)
		{
			if(!isupper(prod[id][i][j]))
			{
				firstarr[id]+=prod[id][i][j];
				if(prod[id][i][j]!='?')
					ter+=prod[id][i][j];
				break;
			}
			else
			{
				int ii=findpos(prod[id][i][j]);
				findfirst(ii);
				tmp=firstarr[ii];
				int ii1=firstarr[ii].find('?');
				if(ii1==-1)
				{
					firstarr[id]+=tmp;
					break;
				}
				else
				{
					if(j!=prod[id][i].length()-1)
						tmp=tmp.substr(0,ii1)+tmp.substr(ii1+1,tmp.length());
					firstarr[id]+=tmp;
				}	
			}
		}
	}
	return;
}
void findfollow(int id)
{
	for(int i0=0;i0<n;i0++)
	{
		for(int j=1;j<len[i0];j++)
		{
			
			for(int i1=0;i1<prod[i0][j].length();i1++)
			{
				if(prod[i0][j][i1]==prod[id][0][0])
				{
					if(i1==-1)
					{
					
					}
					else
					{
						if(i1==prod[i0][j].length()-1)
						{
							followarr[id]+=followarr[i0];
						}
						for(int k=i1+1;k<prod[i0][j].length();k++)
						{
							
							if(!isupper(prod[i0][j][k]))
							{
								followarr[id]+=prod[i0][j][k];
								
								break;
							}
							else
							{
								int ii=findpos(prod[i0][j][k]);
								tmp=firstarr[ii];
								int ii1=tmp.find('?');
								if(ii1==-1)
								{
									followarr[id]+=tmp;
									break;
								}
								else
								{
									tmp=tmp.substr(0,ii1)+tmp.substr(ii1+1,tmp.length());
									followarr[id]+=tmp;
									if(k==prod[i0][j].length()-1)
									{
										followarr[id]+=followarr[i0];
									}
								}
							}	
						}
					}
				}
			}	
		}
	}
	return;
}
int checkll1()
{
	for(int i=0;i<nonter.length();i++)
	{
		for(int j=1;j<len[i];j++)
		{
			for(int k=0;k<prod[i][j].length();k++)
			{
				if(!isupper(prod[i][j][k]))
				{
					int pos=ter.find(prod[i][j][k]);
					if(pos==-1)
					{
						for(int m=0;m<followarr[i].length();m++)
						{
							int pos1=ter.find(followarr[i][m]);
							if(parsetbl[i][pos1]=="")
							{
								parsetbl[i][pos1]=prod[i][j];
							}	
							else
							{
								return 1;
							}
						}
					}
					else
					{
						if(parsetbl[i][pos]=="")
						{
							parsetbl[i][pos]=prod[i][j];
							break;
						}	
						else
						{
							return 1;
						}
					}
				}
				else
				{
					int ii=nonter.find(prod[i][j][k]);
					tmp=firstarr[ii];
					int tmpct=0;
					for(int l=0;l<tmp.length();l++)
					{
						if(tmp[l]!='?')
						{
							int pos=ter.find(tmp[l]);
							//cout<<prod[i][j]<<prod[i][j][l]<<endl;
							if(parsetbl[i][pos]=="")
							{
								parsetbl[i][pos]=prod[i][j];
							}	
							else
							{
								return 1;
							}
						}
						else
						{
							if(k==prod[i][j].length()-1)
							{
								for(int m=0;m<followarr[i].length();m++)
								{
									int pos1=ter.find(followarr[i][m]);
									if(parsetbl[i][pos1]=="")
									{
										parsetbl[i][pos1]=prod[i][j];
									}	
									else
									{
										return 1;
									}
								}
							}
							tmpct++;
						}
					}
					if(tmpct==0)
						break;
				}
			}
			
		}
		
	}
}
int checkip()
{
	pushstk('$');
	pushstk(nonter[0]);
	int ch1;
	input+="$";
	cout<<"Stack Status\t"<<"Input Symbol"<<endl;
	cout<<stk<<"\t\t"<<input[0]<<endl;
	for(int i=0;i<input.length();)
	{
		ch1=popstk();
		if(ch1==input[i])
		{
			i++;
		}
		else
		{
			int p1=nonter.find(ch1);
			int p2=ter.find(input[i]);
			tmp=parsetbl[p1][p2];
			if(tmp=="")
			{
				cout<<"String Rejected"<<endl;
				return 1;	
			}
			for(int j=tmp.length()-1;j>=0;j--)
			{
				if(tmp[j]!='?')
					pushstk(tmp[j]);
			}
		}
		cout<<stk<<"\t\t"<<input[i]<<endl;
		if(stk[top]=='$' && i==input.length()-1)
		{
			cout<<"String Accepted"<<endl;
			return 0;
		}
	}
}
int main(int argc,char *argv[])
{
	int l=0;
	FILE *fp;
	fp=fopen("input1.txt","r");
	while(!feof(fp)){	
		n1=0;
		char string[500];
		fscanf(fp,"%[^\n]\n", string);
		char *tk0 = strtok(string, "->");
		prod[n][n1++]=tk0;
		tk0=strtok(NULL, ">");
		char *tk1 = strtok(tk0, "/");
		while (tk1 != NULL)
		{
			prod[n][n1++]=tk1;	
			tk1 = strtok(NULL, "/");
		}	
		len[l++]=n1;
		n++;
	}
	for(int i=0;i<n;i++)
	{
		findfirst(i);
		sort(firstarr[i].begin(), firstarr[i].end());
		firstarr[i].erase(unique(firstarr[i].begin(), firstarr[i].end()), firstarr[i].end());
	}	
	for(int i=0;i<n;i++)
	{
		followarr[i]="";
		if(i==0)
			followarr[i]+="$";
		findfollow(i);
		sort(followarr[i].begin(), followarr[i].end());
		followarr[i].erase(unique(followarr[i].begin(), followarr[i].end()), followarr[i].end());
	}
	findnont();
	findt();
	if(checkll1()==1)
	{
		cout<<"Grammar is not LL(1) Grammar"<<endl;
		return 1;
	}
	else
	{
		cout<<"PARSE TABLE:"<<endl;
		for(int i=0;i<ter.length();i++)
			cout<<"\t"<<ter[i];
		cout<<endl;	
		for(int i=0;i<nonter.length();i++)
		{
			cout<<nonter[i]<<"\t";
			for(int j=0;j<ter.length();j++)
			{
				cout<<parsetbl[i][j]<<"\t";
			}
			cout<<endl;
		}	
	}
	fp=fopen("input2.txt","r");
	while(!feof(fp))
	{
		char ip[10000];
		fscanf(fp,"%[^\n]\n",ip);
		input=ip;
		checkip();
	}
}			
