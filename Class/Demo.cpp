#include<bits/stdc++.h>
using namespace std;
int main()
{
        //Create a dictionary for subject name
    map<string, string> subNameDictionary {
        {"31", "Digital Signal Processing"},
        {"32", "Digital Signal Processing Lab"},
        {"41", "Compiler Design Theory"}, 
        {"42", "Compiler Design Lab"},
        {"51", "Computer Networks"},
        {"52", "Computer Networks Lab"}
    };

    cout << subNameDictionary["43"] << endl;

    if(subNameDictionary["43"] == ""){
        cout << "Empty String";
    }
    return 0;
}