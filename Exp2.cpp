// Count number of vowels ands constants
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void SeparateWordsStartedWithVowelConstant();

vector<string> words;
vector<string> startedWithVowels;
vector<string> startedWithConstants;
int totalWords = 0;
ifstream inFile("Input2.txt");
ofstream outFile("Output2.txt");

void SeparateWords(string str)
{
    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            //word += '\0';
            words.push_back(word);
            word = "";
            totalWords += 1;
        }

        else
        {
            word += x;
        }
    }
    words.push_back(word);
    totalWords += 1;

    SeparateWordsStartedWithVowelConstant();
}

void SeparateWordsStartedWithVowelConstant()
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (auto word : words)
    {
        bool isVowel = false;
        for (auto x : vowels)
        {
            if (x == word[0])
            {
                startedWithVowels.push_back(word);
                isVowel = true;
                break;
            }
        }

        if (!isVowel)
        {
            startedWithConstants.push_back(word);
        }
    }
}

void printVowelsConstants(string str)
{
    int totalVowels = 0;
    int totalConstants = 0;
    vector<char> vowels;
    vector<char> constants;
    char vowel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for (auto x : str)
    {
        bool isVowel = false;
        for (auto y : vowel)
        {
            if (y == x)
            {
                isVowel = true;
                totalVowels += 1;
                vowels.push_back(x);
                break;
            }
        }

        if (!isVowel && (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
        // if(!isVowel && x >= ' ')
        {
            totalConstants += 1;
            constants.push_back(x);
        }
    }

    outFile << "Total Vowels are " << totalVowels << ", and they are: ";
    for (auto x : vowels)
    {
        outFile << x << " ";
    }
    outFile << endl;

    outFile << "Total Constants are " << totalConstants << ", and they are: ";
    for (auto x : constants)
    {
        outFile << x << " ";
    }
    outFile << endl;
}

int main()
{
    string input;

    while (getline(inFile, input))
    {
        SeparateWords(input);
        outFile << "Words Started with Vowels are : ";
        for (auto word : startedWithVowels)
        {
            outFile << word << " ";
        }
        outFile << endl;

        outFile << "Words Started with Constants are : ";
        for (auto word : startedWithConstants)
        {
            outFile << word << " ";
        }
        outFile << endl;

        printVowelsConstants(input);
    } 

    inFile.close();
    outFile.close();

    return 0;
}
