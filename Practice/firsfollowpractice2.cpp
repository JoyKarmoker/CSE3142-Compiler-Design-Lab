#include<bits/stdc++.h>
using namespace std;
ifstream infile("firstfollowinput.txt");
ofstream outfile("firstfollowoutput.txt");

map<char, vector<string>> productionRules;
map<char, set<char>> first, follow;
set<char> nonterminal;
set<char> isVisited;



void printProductionRules()
{
    for(auto itr=productionRules.begin(); itr!=productionRules.end(); ++itr)
    {
        cout << itr->first << " ->";

        for(auto ptr: itr-> second)
        {
            cout << ptr << " ";
        }
        cout << endl;
    }
}

void printNonTerminal()
{
    for(auto itr= nonterminal.begin(); itr!=nonterminal.end(); ++itr)
    {
        cout << *itr  << " " << endl;
    }
}

void insertproduction(string prod)
{
    productionRules[prod[0]].push_back(prod.substr(3));
    nonterminal.insert(prod[0]);
}

void takeInput()
{
    int numberofProduction;
    infile >> numberofProduction;

    for(int i=0; i<numberofProduction;i++)
    {
        string prod;
        infile >> prod;
        insertproduction(prod);
    }


}

bool isCapital(char ch)
{
    if(ch >= 'A' && ch<='Z')
        return true;
    else
        return false;
}

void printFirst()
{
    outfile << "First:\n";
    for(auto ch: nonterminal)
    {
        outfile << ch << " -> ";

        for(auto child: first[ch])
        {
             outfile << child << " ";
        }

        outfile << endl;
    }
}

void getFirst(char ch)
{
    if(isVisited.count(ch))
     return;
    isVisited.insert(ch);

    for(auto prod: productionRules[ch])
    {
        if(isCapital(prod[0]))
        {
            getFirst(prod[0]);

            for(char child: first[prod[0]])
            {
                first[ch].insert(child);
            }
        }

        else
        {
            first[ch].insert(prod[0]);
        }
    }


}

void calFirst()
{
    for(auto x:  nonterminal)
    {
        if(isVisited.count(x))
            continue;
        getFirst(x);
    }
    printFirst();
    isVisited.clear();
}



void getFollow(char ch)
{
    if(isVisited.count(ch))
        return;
    isVisited.insert(ch);

    for(char left: nonterminal)
    {
        for(string production: productionRules[left])
        {
            int len = production.size();
            bool isGet = false;

            for(int i=0; i<len;i++)
            {
                
                if(isGet)
                {
                    if(isCapital(production[i]))
                    {
                        for(char x: first[production[i]])
                        {
                            cout << ch << " insert " << x << endl;
                            follow[ch].insert(x);
                        }

                        if(first[production[i]].count('e'))
                        {
                            continue;
                        }
                        else
                            isGet = false;
                    }

                    else
                    {
                        cout << ch << " insert non " << production[i] << endl;
                        follow[ch].insert(production[i]);
                        isGet = false;
                    }

                    continue;
                }


                if(production[i] == ch)
                {
                    isGet = true;
                }
            }


            if(isGet)
            {
                getFollow(left);

                for(auto child: follow[left])
                {
                    cout << ch << " insert follow " << child << endl;
                    follow[ch].insert(child);
                }
            }
                

        }
    }

    follow[ch].erase('e');
}

void printFollow()
{
    outfile << "\n\nFollow:\n";
    for(auto ch: nonterminal)
    {
        outfile << ch << " -> ";

        for(auto child: follow[ch])
        {
             outfile << child << " ";
        }

        outfile << endl;
    }
}

void callFollow()
{
    follow['S'].insert('$');
    for(auto ch: nonterminal)
    {
        if(isVisited.count(ch))
            continue;;
        getFollow(ch);
    }

    printFollow();
    isVisited.clear();
}


int main()
{
    first['A'] = {'+', 'e'}; 
    first['B'] = {'*', 'e'};
    first['S'] = {'(', 'i'};
    first['T'] = {'(', 'i'};
    first['V'] = {'+', 'e'};
    first['X'] = {'z', 'b', 'n'};
    nonterminal = {'A', 'B', 'S', 'T', 'V'};
    takeInput();
    //calFirst();
    printFirst();
    callFollow();

    return 0;
}