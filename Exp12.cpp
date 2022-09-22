#include<bits/stdc++.h>
using namespace std;

int main()
{
    string expression = "123a";
    string input = expression;
    string grammar = "EAE";
    string stac= "";
    int len = expression.length();
    string ch;
    bool isDigitCountinue = false;
    bool isPreviousArithmatic = false;

    while(expression != "")
    {
        ch = expression[0];
        if(ch >= "0" && ch<="9")
        {
            isPreviousArithmatic = false;
            isDigitCountinue = true;
        }

        else if (ch == "+" || ch == "-" || ch == "*" || ch == "/")
        {
            if(isPreviousArithmatic)
            {
                cout << input << ": INVALID" << endl;
                return 0;
            }
            
            if(isDigitCountinue == true)
            {
                stac = stac + "EA";
            }

            if(stac == "EAEA")
            {
                stac = "EA";
            }
            isDigitCountinue = false;
            isPreviousArithmatic = true;
        }

        else
        {
            cout << input << ": INVALID" << endl;
            return 0;
        }      
        
        expression.erase(0,1);
    }

    if(isDigitCountinue)
    {
        stac = stac + "E";
    }

    if((stac == "EAE") || (stac == "E"))
    {
        //printf("%s: VALID\n", expression);

        cout << input << ": VALID" << endl;
    }

    else
    {
        cout << input << ": INVALID" << endl;
    }
    
    return 0;
}