#include <bits/stdc++.h>
using namespace std;
vector<string> words;
int totalWords = 0;

ifstream readFile("Input1.txt");
ofstream outFile("Output1.txt");

void separateWords(string str)
{
    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            words.push_back(word);
            word = "";
            totalWords = totalWords + 1;
        }

        else
        {
            word += x;
        }
    }

    words.push_back(word);
    totalWords = totalWords + 1;
}

bool isDigit(char x)
{
    if(x>='0' && x<='9')
    {
        return true;
    }

    return false;
}

bool isLetter(char x)
{
    if(x >='a' && x<='z')
    {
        return true;
    }

    else if(x >= 'A' && x<='Z')
    {
        return true;
    }
    return false;
}


void check(vector<string> words)
{
    int totalLeter = 0;
    int totalDigit = 0;
    int totalOthercharacher = 0;

    vector<char> letters;
    vector<char> digits;
    vector<char> othercharacher;

    for(auto word: words)
    {
        for(auto x: word)
        {
            if(isDigit(x))
            {
                totalDigit+=1;
                digits.push_back(x);
            }

            else if(isLetter(x))
            {
                totalLeter +=1;
                letters.push_back(x);
            }

            else
            {
                if(x != '\0')
                {
                    totalOthercharacher += 1;
                    othercharacher.push_back(x);
                }
            }
        }
    }


    outFile << "Total Letters are: " << totalLeter << " and they are: ";
    for(auto x: letters)
    {
        outFile << x << " ";
    }

    outFile << endl;

    outFile << "Total Digits are: " << totalDigit << " and they are: ";
    for(auto x: digits)
    {
        outFile << x << " ";
    }

    outFile << endl;

    outFile << "Total Other Characters are: " << totalOthercharacher << " and they are: ";
    for(auto x: othercharacher)
    {
        outFile << x << " ";
    }

    outFile << endl;

}


int main()
{
    string str;

    while (getline(readFile, str))
    {
        separateWords(str);
        outFile << "Total words are " << totalWords << " and they are listed below" << endl;
        for (auto word : words)
        {
            outFile << word << endl;
        }

        check(words);
        outFile << endl;
        words.clear();
        totalWords = 0;
    }

    return 0;
}