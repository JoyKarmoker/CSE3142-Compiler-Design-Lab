#include<bits/stdc++.h>

using namespace std;

vector<string> tree(50, "                                                  ");

void syntaxTree(string ex);
bool isOp(char x);

int main()
{
    string expression = "A+B*C";
    //cin >> expression;
    syntaxTree(expression);
    cout << "Parse tree:\n";
    for (string x: tree)
    {
        cout << x << "\n";
    }
}

void syntaxTree(string ex)
{
    cout << "a";
    int row = 0, col = 2;
    for (int i = 0; ex[i]; i++)
    {
        
        if (isOp(ex[i]))
        {
            tree[row][col] = ex[i];
            tree[row + 1][col - 1] = '/';
            tree[row + 1][col + 1] = '\\';
            tree[row + 2][col - 1] = ex[i - 1];
            row += 2;
            col += 2;
        }
    }
    tree[row][col] = ex.back();
}

bool isOp(char x)
{
    return (x == '+' or x == '-' or x == '*' or x == '\\');
}