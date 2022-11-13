#include<bits/stdc++.h>
using namespace std;
ifstream inFile("Input3.txt");
ofstream outFile("OutFile3.txt");

string separateDept(string code)
{
    string deptCode = "";
    bool isDeptCodeValide = false;
    for(auto c: code)
    {
        if(c != '-')
        {
            deptCode+= c;
        }

        else if(c == '-')
        {
            isDeptCodeValide = true;
            break;

        }
    }

    if(isDeptCodeValide)
    {
        return deptCode;
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
    else
        return "invalid";
}

string findYear(string code)
{
    int length = code.length();
    char hypen = code[length-5];
    string ans="";
    if(hypen != '-')
    {
        return "xx";
    }
    ans += code[length-4];
    ans += code[length-3];
    return ans;
}

string findSubject(string code)
{
    int length = code.length();
    char hypen = code[length-5];
    string ans="";
    if(hypen != '-')
    {
        return "xx";
    }
    ans += code[length-2];
    ans += code[length-1];
    return ans;
}

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

    string subCode;
    string deptCode;
    string deptName;
    string subName="";
    string ans = "";
    string year;
    while(getline(inFile, subCode))
    {
        ans = " ";
        deptCode = separateDept(subCode);
        //cout << "Dept code " << deptCode; 
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
            year = findYear(subCode);
            //cout << " Year is " << year <<endl;
            if(year == "11")
            {
                ans += "1st Year 1st Semester";
            }
            else if(year == "12")
            {
                ans += "1st Year 2nd Semester";
            }
            else if(year == "21")
            {
                ans += "2nd Year 1st Semesterr";
            }
            else if(year == "22")
            {
                ans += "2nd Year 2nd Semester";
            }
            else if( year == "31")
            {
                ans += "3rd Year 1st Semester";
            }
            else if(year == "41")
            {
                ans += "4th Year 1st Semester";
            }
            else if(year == "42")
            {
                ans+= "4th Year 2nd Semester";
            }
            else
            {
                //cout << "Invalid ";
                outFile << subCode << ": Invalid Code"<<endl;
                continue;
            }

            subName = findSubject(subCode);
            if(subName == "xx")
            {
                //cout << "Invalid ";
                outFile << subCode << ": Invalid Code"<<endl;
                continue;
            }

            else
            {
                //cout << "Subject Number is " << subName << endl;
                if(subNameDictionary[subName] == "")
                {
                    //cout << "Invalid ";
                    outFile << subCode << ": Invalid Code"<<endl;
                    continue;
                }

                else
                {
                    ans += " ";
                    ans += subNameDictionary[subName];
                }

            }

            outFile << subCode << ": " << ans <<endl;
            
        }

        else
        {
            outFile << subCode << ": Invalid Code"<<endl;
        }

    }



    return 0;
}