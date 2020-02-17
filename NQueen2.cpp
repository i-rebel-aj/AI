#include<bits/stdc++.h>
using namespace std;
void Initialize(int **arr, int n)
{
    for(int i=0;i<n;i++)
    {
	arr[i][0]=1;
        for(int j=1;j<n;j++)
	{
            arr[i][j]=0;
        }
    }
}
int check_pairs(int **arr, int n, int x,int y)
{
	int count=0;
	for(int i=x+1;i<n;i++)
	{
		if(arr[i][y]==1)
		{
			count++;
		}
	}
	int k=x+1,ld=y-1,rd=y+1;
	while(k>=0&&k<n)
	{
		if(ld>=0&&ld<n)
		{
			if(arr[k][ld]==1)
			{
				count++;
			}
			ld--;
		}
		if(rd>=0&&rd<n)
		{
			if(arr[k][rd]==1)
                        {
                                count++;
                        }
			rd++;
		}
		k++;
	}
	return count;
}
int evaluate_heuristic(int **arr, int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==1)
			{
				sum+=check_pairs(arr,n,i,j);
			}
		}
	}
	return sum;
}
void display_arr(int **a, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void copy_mat(int **arr, int **temp, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			temp[i][j]=arr[i][j];
		}
	}
}
void shift(int **temp, int x,int n)
{
	for(int j=0;j<n;j++)
	{
		if(temp[x][j]==1)
		{
			temp[x][j]=0;
			temp[x][j+1]=1;
			break;
		}
	}
}
void solve(int **arr, int n)
{
	int gn=0,heur;
	int **temp=new int*[256];
	for (int i = 0; i < 256; ++i)
	{
		temp[i] = new int[256];
	}
	int **temp2=new int *[100];
	for(int i=0;i<100;i++)
	{
		temp2[i]=new int[100];
	}
	State X[500];
	for(int i=0;i<20;i++)
	{
		X[i].Init(n);
	}
	while(evaluate_heuristic(arr,n)!=0)
	{
		if(gn==n)
		{
			break;
		}
		int min=INT_MAX;
		copy_mat(arr,temp,n);
		for(int i=0;i<n;i++)
		{
			if(i>0)
			{
				shift(temp,gn,n);
			}
			heur=evaluate_heuristic(temp,n);
			cout<<"------------------Debugging Output----------------------------"<<endl;
                        display_arr(temp,n);
			cout<<"f(n)="<<heur<<endl;
                        cout<<"--------------------------------------------------------------"<<endl;
			if(min>heur)
			{
				min=heur;
				copy_mat(temp,temp2,n);
			}
		}
		copy_mat(temp2,arr,n);
		gn++;
	}
	display_arr(arr,n);
	cout<<evaluate_heuristic(arr,n);
}
int main()
{
        int n;
        cout<<"Enter The value of n"<<endl;
        cin>>n;
        int **a=new int*[n];
        for(int i=0;i<n;i++)
        {
                a[i]=new int[n];
        }
	cout<<"Initialization"<<endl;
        Initialize(a,n);
	cout<<"start state\n";
	display_arr(a,n);
	solve(a,n);
	return 0;
}      
