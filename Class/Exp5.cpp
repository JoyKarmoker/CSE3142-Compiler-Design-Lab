#include <bits/stdc++.h>
using namespace std;
ifstream inFile("Input5.txt");
ofstream outFile("Output5.txt");

bool checkBetween(char input, char min, char max)
{
    if (input >= min && input <= max)
    {
        return true;
    }

    return false;
}

bool isFloatNumber(string input)
{
    bool isAnswered = false;
    int length = input.length();

    if((length==4) && (checkBetween(input[0], '0', '9')) && input[1] == '.' && (checkBetween(input[2], '0', '9')) && (checkBetween(input[3], '0', '9')))
    {
        return true;        
    }

    else if(length>=5)
    {
        if((input[length-3] == '.') && (checkBetween(input[length-2], '0', '9')) && (checkBetween(input[length-1], '0', '9')))
        {
            if((checkBetween(input[0], '1', '9')))
            {
                bool isfloat = true;
                for(int i=1; i<(length-3); i++)
                {
                    if(!checkBetween(input[i], '0', '9'))
                    {
                            isfloat = false;
                    }
                }

                if(isfloat)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool isDoubleNumber(string input)
{
    
    int length = input.length();

    if((length>=5) && (checkBetween(input[0], '0', '9')) && input[1] == '.')
    {
        bool isDouble = true;

        for(int i=2; i<length; i++)
        {
             if(!checkBetween(input[i], '0', '9'))
            {
                isDouble = false;
            }
        }

        if(isDouble)
            return true;
    }

    return false;
}

int main()
{
    string inputVariable;
    while (getline(inFile, inputVariable))
    {
        bool isAnswered = false;
        int length = inputVariable.length();
        //cout << "Length is " << length << endl;

        if ( checkBetween(inputVariable[0], 'a', 'h') || checkBetween(inputVariable[0], 'A', 'H')  || checkBetween  (inputVariable[0], 'o', 'z') || checkBetween(inputVariable[0], 'O', 'Z'))
        {
            for (auto c : inputVariable)
            {
                if (!checkBetween(c, 'a', 'z') && !checkBetween(c, 'A', 'Z') && !checkBetween(c, '0', '9'))
                {
                    outFile << inputVariable <<": Invalid" << endl;
                    isAnswered = true;
                    break;
                }
            }

            if(!isAnswered)
                outFile << inputVariable <<": Float Variable" << endl;
        }

        else if(isFloatNumber(inputVariable))
        {
            outFile << inputVariable <<": Float Number" << endl;
        }

        else if(isDoubleNumber(inputVariable))
        {
            outFile << inputVariable <<": Double Number" << endl;
        }

        else
        {
             outFile << inputVariable <<": Invalid" << endl;
        }
    }

    return 0;
}