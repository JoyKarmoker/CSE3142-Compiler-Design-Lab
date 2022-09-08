#include <bits/stdc++.h>
using namespace std;
ifstream inFile("Input9.txt");
ofstream outFile("Output9.txt");

string pn[] = {"Sagor", "Selim", "Salma", "Nipu"};
string p[] = {"He", "She", "I", "We", "You", "They"};
string verb[] = {"read", "eat", "take", "run", "write"};
string noun[] = {"book", "cow", "dog", "home", "grass", "rice", "mango"};
int numberOfWords;

bool isSubject(string word)
{
    for(string name: pn)
    {
        if(word == name)
        {
            return true;
        }
    }

    for(string pronoun:p)
    {
        if(word == pronoun)
        {
            return true;
        }
    }

    return false;
}

bool isVerb(string word)
{
    for(string v: verb)
    {
        if(word == v)
        {
            return true;
        }
    }

    return false;
}

bool isVerbNoun(string firstWord, string secondWord)
{
    for(string v: verb)
    {
        if(firstWord == v)
        {
            for(string n:noun)
            {
                if(secondWord == n)
                {
                    return true;
                }
            }
        }
    }

    return false;
}


vector<string> separateWords(string sentence)
{
    vector<string> words;
    string word="";

    for(auto x: sentence)
    {
        if(x == ' ')
        {
            //word += '\0';
            words.push_back(word);
            numberOfWords +=1;
            word = "";
        }

        else
        {
            word = word + x;
        }
        
    }

    words.push_back(word);
    numberOfWords +=1;
    return words;
}

int main()
{
    string inputVariable;
    while(getline(inFile, inputVariable))
    {
        numberOfWords = 0;
        bool isPresentIndefinite = false;
        int length = inputVariable.length();
        vector<string> words = separateWords(inputVariable);        
        //outFile << inputVariable  << ". Length is : " << length << ", Words: "<< numberOfWords << endl;
        
        /*for(int i=0; i<=numberOfWords; i++)
        {
             outFile << words[i] << endl;
        }*/

        if(words.size() == 2)
        {
            if(isSubject(words[0]) && isVerb(words[1]))
            {
                cout << "Valid" << endl;
            }

            else
            {
                cout << "Not Valid" << endl;
            }
        }

        else if(words.size() == 3)
        {
            if(isSubject(words[0]) && isVerbNoun(words[1], words[2]))
            {
                cout << "Valid" << endl;
            }

            else
            {
                cout << "Not Valid" << endl;
            }
        }

        else
        {
            cout << "Not Valid" <<endl;
        }

    }
    inFile.close();
    outFile.close();

    return 0;
}