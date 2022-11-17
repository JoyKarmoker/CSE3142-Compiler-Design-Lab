#include<bits/stdc++.h>
using namespace std;
ofstream outfile("parsetreeoutput.txt");


vector<string> tree(15, "                                ");

bool isOp(char x)
{
    return (x == '+' || x == '-' || x=='*' || x=='/');
}

void syntaxtree(string ex)
{
   
    int exlength = ex.length();
    
    int row = 0; 
    int col = 2;
    for(int i=0; i<exlength; i++)
    {

        
        if(isOp(ex[i]))
        {
            tree[row][col] = ex[i];
            tree[row+1][col-1] = '/';
            tree[row+1][col+1] = '\\';
            tree[row+2][col-2] = ex[i-1];
            row = row+2;
            col = col+2;
        }
    }
    tree[row][col] = ex.back();
    return;
}

int main()
{

    string expression = "a+b*c";
    syntaxtree(expression);
    outfile << "syntaxtree\n";

    for(auto x: tree)
    {
        outfile << x <<'\n';
    }

    return 0;
}