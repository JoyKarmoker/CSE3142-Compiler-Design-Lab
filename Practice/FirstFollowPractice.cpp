#include <bits/stdc++.h>
using namespace std;
ifstream readFIle("firstfollowinput.txt");

map<char, vector<string>> productionRules;
map<char, set<char>> first, follow;
set<char> nonTerminal;
set<char> isVisited;

void printProductionRule()
{
    cout << "Production rule is: " << endl;
    for (auto itr = productionRules.begin(); itr != productionRules.end(); ++itr)
    {
        cout << itr->first << "->";

        for (auto ptr : itr->second)
        {
            cout << ptr << " ";
        }

        cout << endl;
    }
    cout << endl;
}

void insertProduction(string &prod)
{
    productionRules[prod[0]].push_back(prod.substr(3));
    nonTerminal.insert(prod[0]);
}

void takeInput()
{
    //"Instruction:\n";
    //"1) Make the grammer unambigouse.\n";
    //"2) Production must start from S->someting.\n";
    //"3) Use the production rules as 'Non-Terminal' '->' 'production ruls'.\n\n\n";
    //"Enter the number of production" << endl;
    int numberOfProduction;
    readFIle >> numberOfProduction;

    for (int i = 0; i < numberOfProduction; i++)
    {
        string prod;
        readFIle >> prod;
        insertProduction(prod);
    }
}

bool isCapital(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return true;
    }

    return false;
}

void getFirst(char ch)
{
    if (isVisited.count(ch))
        return;
    isVisited.insert(ch);

    for (string production : productionRules[ch])
    {

        if (isCapital(production[0]))
        {
            getFirst(production[0]);

            for (char child : first[production[0]])
            {
                first[ch].insert(child);
            }
        }

        else
        {
            first[ch].insert(production[0]);
        }
    }
}

void printFirst()
{
    cout << "First:\n";
    for (char ch : nonTerminal)
    {
        cout << ch << " ->";
        for (char x : first[ch])
        {
            cout << " " << x;
        }
        cout << endl;
    }
}
void calFirst()
{
    for (char ch : nonTerminal)
    {
        if (isVisited.count(ch))
            continue;
        getFirst(ch);
    }

    printFirst();
    isVisited.clear();
}

void getFollow(char ch)
{
    if (isVisited.count(ch))
        return;
    isVisited.insert(ch);

    for (char left : nonTerminal)
    {
        for (string production : productionRules[left])
        {
            int len = production.size();
            bool isGet = false;

            for (int i = 0; i < len; i++)
            {

                if (isGet)
                {
                    if (isCapital(production[i]))
                    {
                        for (char x : first[production[i]])
                        {
                            follow[ch].insert(x);
                        }

                        if (first[production[i]].count('e'))
                        {
                            continue;
                        }
                        else
                            isGet = false;
                    }

                    else
                    {
                        follow[ch].insert(production[i]);
                        isGet = false;
                    }
                    continue;
                }

                if (production[i] == ch)
                {
                    isGet = true;
                }
            }

            if(isGet)
            {
                getFollow(left);

                for(auto x: follow[left])
                {
                    follow[ch].insert(x);
                }

            }
        }
    }

    follow[ch].erase('e');
}

int main()
{
    // cout << "e is for epsilon";
    takeInput();
    // printProductionRule();
    calFirst();

    follow['S'].insert('$');
    for (auto ch : nonTerminal)
    {
        if (isVisited.count(ch))
            continue;
        getFollow(ch);
    }

    cout << "\n\n\nFollow:\n";
    for(char ch: nonTerminal)
    {
        cout << ch << "-> ";

        for(char x: follow[ch])
        {
            cout << x <<" ";
        }

        cout << endl;
    }
    return 0;
}