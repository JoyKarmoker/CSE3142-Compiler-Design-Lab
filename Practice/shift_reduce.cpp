#include<bits/stdc++.h>
using namespace std;
ifstream infile("shiftreduceinput.txt");
ofstream outfile("shiftreduceoutput.txt");

string st = "$";
string input;

void printshiftreuce()
{
    outfile  << setw(10)<< st  <<setw(10) << input << "\t";
}

void reducecheck()
{
    int lengthst = st.length();
    if(st[lengthst - 1] == 'a')
    {
        st[lengthst - 1] = 'E';
        printshiftreuce();
        outfile << "Reduce E->a" << endl;
        reducecheck();
    }

    if(lengthst >= 3)
    {
        string lastThree = st.substr(lengthst - 3, lengthst - 1);

        if(lastThree == "E+E")
        {
            st.erase(lengthst - 3, lengthst);
            st = st + "E";
            printshiftreuce();
            outfile << "Reduce E->E+E" << endl;
        }

        else if(lastThree == "E*E")
        {
            st.erase(lengthst - 3, lengthst);
            st = st + "E";
            printshiftreuce();
            outfile << "Reduce E->E*E" << endl;
        }
    }

    return;


}

int main()
{

    outfile << "Grammar is : " << endl;
    outfile << "E->E+E\n"<<"E->E*E\n"<<"E->a\n";
    outfile << "Shift reduce parsing:\n\n" ; 

    infile >> input;
    input = input + "$";
    outfile << setw(10) << "\t  Stack\t\t" << "Input\t" << "Action\n";
    while(input.length()>1)
    {
        char firstletter = input[0];
        printshiftreuce();
        outfile << "Shift " << firstletter << endl;
        st = st+firstletter;
        reducecheck();

        input.erase(0,1); 
    }
    
    printshiftreuce();
    if(st == "$E" && input == "$")
        outfile << "accept";
    else
        outfile << "rejected";

    return 0;
}