#include <bits/stdc++.h>
#include <map>
using namespace std;
vector<string> stac;
map<string, string> rules =
{
        {"2E2", "E"},
        {"3E3", "E"},
        {"4", "E"}

};

//C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
    }
    
    return os;
}

void reducestack()
{
        int length = stac.size();
        
        if(length >= 1)
        {
                if(rules.find(stac[length-1]) != rules.end() )
                {
                        //cout << "Found value at  " << stac[length-1] <<endl;
                        stac.pop_back();
                        stac.push_back("E");
                }
        }

        if(length >= 3)
        {
                string temp = stac[length-3] + stac[length-2] + stac[length-1];
                if(rules.find(temp) != rules.end() )
                {
                        //cout << "Found value at  " << temp << endl;
                        stac.pop_back();
                        stac.pop_back();
                        stac.pop_back();
                        stac.push_back("E");
                }
        }
}



int main()
{
        printf("GRAMMAR is -\nE->2E2 \nE->3E3 \nE->4\n");
        cout << "Stack" << "       " << "Input" << endl;
        
        string input = "32423";
        int inputLength = input.length();
        string ch;

        while(input != "")
        {       
                ch = input[0];
                stac.push_back(ch);
                reducestack();
                input.erase(0,1);
                cout << stac << "       " <<input << endl;
        }

        if(stac.size() ==1  && stac[0] == "E" && input.size() == 0)
        {
                cout << "Accepted" << endl;
        }

        else
        {
                cout << "Rejected" << endl;
        }
        


        return 0;
}