//wap to perform left factoring in a given grammar.
/*2015KUCP1018
	ANANT SHARMA
	COMPILER DESIGN LAB
	
		Compilation: g++ leftfact.cpp
	Execution: ./a.out 
	*/
#include<bits/stdc++.h>
using namespace std;
string longestprefix(string str1,string str2)
{
	string res;
	int n1=str1.length(),n2=str2.length(),i,j;
	for(i=0, j=0; i<=n1-1 && j<=n2-1; i++,j++)
    {
        if (str1[i] != str2[j])
            break;
        res.push_back(str1[i]);
    }
    return res;
}
int main()
{
	FILE *fp=fopen("input2.txt","r");
	char st[10000],*tk,*tk1,*tk2;
	string lst[100];
	int i1=0,n,f=0,i2,n1,g=0,i3,n2;
	while(1)
	{
		i1=0;
		fgets(st,sizeof(st),fp);
		tk=strtok(st,"->");
		tk1=strtok(NULL,"->");
		//cout<<tk1;
		tk1=strtok(tk1,"/");
		while(tk1!=NULL)
		{
			lst[i1++]=tk1;
			tk1=strtok(NULL,"/");
		}
		n=i1;
		sort(lst,lst+n);
		for(i1=0;i1<n;i1++)
		{
			//cout<<lst[i1]<<endl;
		}
		string s1,s2[100],prev=lst[0],s3=tk,s4[100],tk3;
		i2=0;
		f=0;
		g=0;
		int pos=0;
		i3=0;
		for(i1=0;i1<n;i1++)
		{
			s1=longestprefix(lst[i1],prev);
			if(s1.length()>0)
			{
				prev=s1;
				pos=lst[i1].find(prev);
				s4[i3++]=lst[i1].substr(pos+prev.length());
				g=1;
			}
			else
			{
				if(g==1 && i1!=1)
				{
					prev=prev+tk+"'";
					
				}	
				s2[i2++]=prev;
				prev=lst[i1];
				g=0;
			}
			f++;
		}
		if(g==1)
			prev=prev+tk+"'";
		s2[i2++]=prev;
		n2=i3;
		n1=i2;
		s3+="->";
		for(i2=0;i2<n1;i2++)
		{
			//cout<<s2[i2]<<" ";
			s3+=s2[i2];	
			if(i2!=n1-1)
				s3+="/";
		}	
		cout<<s3<<endl;
		tk3=tk;
		tk3+="'->";
		for(i3=0;i3<n2;i3++)
		{
			if(s4[i3]=="")
				tk3+="NULL";
			else
				tk3+=s4[i3];
			if(i3!=n2-1)
				tk3+="/";	
		}
		cout<<tk3<<endl;
		if(feof(fp))
			break;
	}
	return 0;
}
