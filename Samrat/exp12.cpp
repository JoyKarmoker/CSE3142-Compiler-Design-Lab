#include<bits/stdc++.h>
using namespace std;

vector <char> stck;
vector <char> temp;

void printStackAndInput(){
	cout << "\n$";
	for(auto x : stck)
		cout << x ;
	cout << "\t";
	for(auto x : temp)
		cout << x;
}

void check(){
	for(int i = 0; i < stck.size(); i ++){
		if(stck[i] == 'a' || stck[i] == '2' || stck[i] == '3' || stck[i] == '4'){
			stck[i] = 'E';
			printStackAndInput();
			cout << "$\t" << "REDUCE E->a";
			check();
		}
		if(i + 2 < stck.size() && (stck[i] == 'E' && (stck[i+1] == '+' || stck[i+1] == '-' || stck[i+1] == '*' || stck[i+1] == '/') && stck[i+2] == 'E')){
			stck.pop_back();
			stck.pop_back();
			printStackAndInput();
			if(stck[i+1] == '+')
                cout<<"$\t" << "REDUCE E->E+E";
            else if(stck[i+1] == '*')
                cout<<"$\t" << "REDUCE E->E*E";
			else if(stck[i+1] == '-')
                cout<<"$\t" << "REDUCE E->E-E";
            else if(stck[i+1] == '/')
                cout<<"$\t" << "REDUCE E->E/E";
		}
		if(i+2 < stck.size() && stck[i] == '(' && stck[i+1] == 'E' && stck[i+2] == ')'){
			stck.pop_back();
			stck.pop_back();
			stck.pop_back();
			stck.push_back('E');
			printStackAndInput();
			cout << "$\t" << "Reduce E -> (E)";
		}
	}
}

int main(){
	cout << "Grammar is: \n E -> E + E \n E -> E - E \n E -> E * E \n E -> E / E \n E -> (E) \n E -> a|2|3|4";
	string str;
	while(1){
		cout << "\n\nEnter the input string or # to terminate: ";
		getline(cin, str);
		if(str == "#")
			return 0;
		//string str = "(a+a)";
		//cout << endl << "Input String: " << str << endl;

		int sz = str.size();
		cout << endl << "Shift Reduce Parser: " << endl;
		for(int i = 0; i < sz; i++){
			temp.push_back(str[i]);
		}

		cout << "Stack\t input\t action" << endl;
		for(int i = 0; i < str.size(); i ++){
			stck.push_back(temp[i]);
			temp[i] = ' ';
			printStackAndInput();
			cout << "$\t" << "SHIFT  E->" << stck.back();
			check();
		}

		if(stck.size() == 1 && stck[0] == 'E')
			cout<<"\n\nstring accepted";
		else
			cout<<"\n\nstring rejected";
	}
	return 0;
}