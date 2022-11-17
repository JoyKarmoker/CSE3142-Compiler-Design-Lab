#include<bits/stdc++.h>
using namespace std;
ifstream infile("InputExp12.txt");
ofstream outfile("OutputExp12.txt");

string st = "$";
string input = "";

void printstack()
{
    outfile << st << "\t\t" << input << endl;
}


void checkreduce()
{
    int lengthst = st.length();

    if(st[lengthst-1] >= '0' && st[lengthst-1] <= '9')
    {
        st[lengthst-1] = 'E';
         printstack();
        checkreduce();
    }

    if(lengthst >3)
    {
        
        string subst = st.substr((lengthst-3));

        if(subst == "(E)")
        {   
            st.erase((lengthst-3));
            st = st + 'E';
            printstack();
            checkreduce();
        }

        else if(subst == "E+E")
        {
            st.erase((lengthst-3));
            st = st + 'E';
            printstack();
            checkreduce();
        }

        else if(subst == "E*E")
        {
            st.erase((lengthst-3));
            st = st + 'E';
            printstack();
            checkreduce();
        }

        else if(subst == "E-E")
        {
            st.erase((lengthst-3));
            st = st + 'E';
            printstack();
            checkreduce();
        }

        else if(subst == "E/E")
        {
            st.erase((lengthst-3));
            st = st + 'E';
            printstack();
            checkreduce();
        }
    }
}


int main()
{
    outfile << "String\t\tinput" << endl;
    infile >> input;
    input = input + '$';
    while(input.length() >1)
    {
        char x = input[0];
        input.erase(0,1);
        st = st+x;
        printstack();
        checkreduce();
    }

    if(st == "$E" && input == "$")
    {
       outfile << "\nVALID\n";
    }

    else
    {
        outfile << "\nINVALID\n";
    }

    return 0;
}