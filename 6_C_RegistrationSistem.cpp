//LINK: https://codeforces.com/problemset/problem/4/C

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<string, string> names; //cheia:string pt nume; valoarea:string pt numar
	int n{};
	string name{};


	cin >> n;
	for (int i{ 0 }; i < n; i++)
	{
		cin >> name;

		if (names.find(name) == names.end()) {//daca nu exista numele in baza de date
			names[name] = "0";
			cout << "OK" << endl;
		}
		else { //daca exista numele in baza de date
			int lastIndex = stoi(names[name]); //luam ultimul index
			lastIndex++;
			string newIndex = to_string(lastIndex);
			names[name] = newIndex;
			cout << name + newIndex <<endl;
			
		}
	}
}