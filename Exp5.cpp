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

        /*else if(length == 1 && (checkBetween(inputVariable[0], '1', '9')))
        {
            outFile << inputVariable << ": ShortInt Number" << endl;
        }

        else if((length>=2 && length<=4) && (checkBetween(inputVariable[0], '1', '9')))
        {
            for (auto c : inputVariable)
            {
                if (!checkBetween(c, '0', '9'))
                {
                    outFile << inputVariable <<": Invalid" << endl;
                    isAnswered = true;
                    break;
                }
            }
            if(!isAnswered)
                outFile << inputVariable <<": ShortInt Number" << endl;
        }

        else if((length>=5) && (checkBetween(inputVariable[0], '1', '9')))
        {
            for (auto c : inputVariable)
            {
                if (!checkBetween(c, '0', '9'))
                {
                    outFile << inputVariable <<": Invalid" << endl;
                    isAnswered = true;
                    break;
                }
            }
            if(!isAnswered)
                outFile << inputVariable <<": LongInt Number" << endl;
        }*/

        else
        {
             outFile << inputVariable <<": Invalid" << endl;
        }
    }

    return 0;
}