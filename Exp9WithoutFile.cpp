#include <bits/stdc++.h>
using namespace std;

string pn[] = {"Sagor", "Selim", "Salma", "Nipu"};
string p[] = {"He", "She", "I", "We", "You", "They"};
string verb[] = {"read", "eat", "take", "run", "write"};
string noun[] = {"book", "cow", "dog", "home", "grass", "rice", "mango"};
int numberOfWords = 0;

bool isSubject(string word)
{
        for (string name : pn)
        {
                if (word == name)
                {
                        return true;
                }
        }

        for (string pronoun : p)
        {
                if (word == pronoun)
                {
                        return true;
                }
        }

        return false;
}

bool isVerb(string word)
{
        for (string v : verb)
        {
                if (word == v)
                {
                        return true;
                }
        }

        return false;
}

bool isVerbNoun(string firstWord, string secondWord)
{
        for (string v : verb)
        {
                if (firstWord == v)
                {
                        for (string n : noun)
                        {
                                if (secondWord == n)
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
        string word = "";

        for (auto x : sentence)
        {
                if (x == ' ')
                {
                        
                        words.push_back(word);
                        numberOfWords += 1;
                        word = "";
                }

                else
                {
                        word = word + x;
                }
        }

        words.push_back(word);
        numberOfWords += 1;
        return words;
}

int main()
{
        string inputVariable = "I eat ripe";
        bool isPresentIndefinite = false;
        int length = inputVariable.length();
        vector<string> words = separateWords(inputVariable);

        if (numberOfWords == 2)
        {
                if (isSubject(words[0]) && isVerb(words[1]))
                {
                        cout << "Valid" << endl;
                }

                else
                {
                        cout << "Not Valid" << endl;
                }
        }

        else if (numberOfWords == 3)
        {
                if (isSubject(words[0]) && isVerbNoun(words[1], words[2]))
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
                cout << "Not Valid" << endl;
        }

        return 0;
}