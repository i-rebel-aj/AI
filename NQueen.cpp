#include<iostream>
#include<stdlib.h>
using namespace std;
void Initialize(int **arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
}
bool Check(int **A, int r, int C,int n) 
{ 
    int i, j; 
    for (i = 0; i < C; i++) 
        if (A[r][i]) 
            return false; 
    for (i = r, j = C; i >= 0 && j >= 0; i--, j--) 
        if (A[i][j]) 
            return false; 
    for (i = r, j = C; j >= 0 && i < n; i++, j--) 
        if (A[i][j]) 
            return false; 
  
    return true; 
} 

bool Solve(int **board, int col,int n) 
{ 

    if (col >= n) 
        return true; 
  
    for (int i = 0; i < n; i++) { 

        if (Check(board, i, col,n)) 
	{ 

            board[i][col] = 1; 

            if (Solve(board, col + 1,n)) 
                return true; 
            board[i][col] = 0;
        } 
    } 

    return false; 
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
        Initialize(a,n);
        if (Solve(a, 0,n) == false) 
        { 
            cout<<"Solution nahi hai"<<endl;
        }
        else
        {
            for(int i=0;i<n;i++)
	    {
                 for(int j=0;j<n;j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
        }
	return 0;
}      
