//wap to find first and follow.
/*2015KUCP1018
	ANANT SHARMA
	COMPILER DESIGN LAB
	
	Compilation: g++ ff.cpp
	Execution: ./a.out 
	*/
#include<bits/stdc++.h>
using namespace std;
int len[1000];
string prod[100][100];
string firstarr[100],followarr[100];
string tmp;
int n=0,n1=0;
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
int main()
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
	cout<<"Non-Terminal\tFIRST"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<prod[i][0]<<"\t\t{";
		for(int j=0;j<firstarr[i].length();j++)
		{
			cout<<firstarr[i][j];
			if(j!=firstarr[i].length()-1)
				cout<<",";
		}	
		cout<<"}"<<endl;
	}
	cout<<"Non-Terminal\tFOLLOW"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<prod[i][0]<<"\t\t{";
		for(int j=0;j<followarr[i].length();j++)
		{
			cout<<followarr[i][j];
			if(j!=followarr[i].length()-1)
				cout<<",";
		}	
		cout<<"}"<<endl;
	}
	cout<<"(? is Epsilon and $ is input right end marker.)"<<endl;
}			
