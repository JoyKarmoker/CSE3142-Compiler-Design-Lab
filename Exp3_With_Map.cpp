#include<bits/stdc++.h>
using namespace std;
ifstream inFile("Input3_with_map.txt");
ofstream outFile("OutFile3_with_map.txt");

string separateDept(string code)
{
    string deptCode = "";
    bool isDeptCodeValid = false;
    for(auto c: code)
    {
        if(c != '-')
        {
            deptCode+= c;
        }

        else if(c == '-')
        {
             return deptCode;

        }
    }

    return "invalid";
}

string findDept(string deptCode)
{
    if(deptCode == "CSE")
        return "Computer Science & Engineering";
    else if(deptCode == "ICE")
        return "Information & Comunication Engineering";
    else if(deptCode == "EEE")
        return "Electrical & Electronics Engineering";
    else if(deptCode == "MSE")
        return "Material Science & Engineering";
    else if(deptCode == "MATH")
        return "Math";
    else
        return "invalid";
}

string findCode(string code)
{
    int length = code.length();
    char hypen = code[length-5];
    string ans="";
    if(hypen != '-')
    {
        return "invalid";
    }
    ans += code[length-4];
    ans += code[length-3];
    ans += code[length-2];
    ans += code[length-1];
    return ans;
}


int main()
{
    //Create a dictionary for subject name
    map<string, string> subNameDictionary {
        {"3111", "System Analysis and Design"},
        {"3121", "Database Management System"},
        {"3122", "Database Management System Lab"}, 
        {"3131", "Digital Signal Processing"},
        {"3132", "Digital Signal Processing Lab"},
        {"3141", "Compiler Design Theory"},
        {"3142", "Compiler Design Lab"},
        {"3211", "Software Engineering"},
        {"3212", "Software Engineering Lab"},
        {"3221", "Computer Graphics"},
        {"3222", "Computer Graphics Lab"},
        {"3231", "Microprocessor and Assembly Language"}
    };

    string subCode;
    string deptCode;
    string deptName;
    string code;
    string ans = "";
    while(getline(inFile, subCode))
    {
        ans = " ";
        deptCode = separateDept(subCode);
        //cout << "Dept code " << deptCode << endl;; 
        
        if(deptCode != "invalid")
        {
            deptName = findDept(deptCode);

            if(deptName == "invalid")
            {
                outFile << subCode << ": Invalid Code"<<endl;
                continue;
            }
            
            ans += deptName; 
            ans += " ";
            //cout << ", and Dept name is " << deptName;
            code = findCode(subCode);
            if(code != "invalid")
            {
                if(subNameDictionary[code] == "")
                {
                    //cout << "Invalid ";
                    outFile << subCode << ": Invalid Code"<<endl;
                }

                else
                {
                    ans += subNameDictionary[code];
                    outFile << subCode << ": " << ans <<endl;
                }
            }

            else
            {
                 outFile << subCode << ": Invalid Code"<<endl;
            }
            
        }

        else
        {
            outFile << subCode << ": Invalid Code"<<endl;
        }

    }



    return 0;
}