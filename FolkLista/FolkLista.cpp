// FolkLista.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>


using namespace std;

class People {

private:
	string name;
	int age;

public:
	People(string n, int a) {
		name = n;
		age = a;
	}

	string print() const {
		return "name: " + name + ", age: " + to_string(age);
	}

	string getName() const {
		return name;
	}

};

vector<People*> create() {
	vector<People*> folk;
	People* p = new People("Micke", 35);
	folk.push_back(p);
	People* p2 = new People("Micke", 65);
	folk.push_back(p2);
	People* p3 = new People("Klas", 15);
	folk.push_back(p3);
	People* p4 = new People("Mimmi", 99);
	folk.push_back(p4);
	return folk;
}

void doNew(vector<People*>& vec) {
	string name;
	cout << "Name: ";
	cin >> name;
	int age;
	cout << "Age: ";
	cin >> age;
	People* p = new People(name, age);
	vec.push_back(p);

}

void doAll(const vector<People*>& vec) {
	for (auto pek : vec) {
		string toString = pek->print();
		cout << toString << endl;
	}
	cout << endl;
}

void doBort(vector<People*>& vec) {
	string name;
	cout << "Kommando: n,a,b.q?  ";
	cin >> name;
	for (vector<People*>::iterator iter = vec.begin(); iter != vec.end();)
	{
		if ((*iter)->getName() == name) {
			delete *iter;
			iter = vec.erase(iter);
		}
		else {
			iter++;
		}
	}
}


int main()
{
	vector<People*> folk = create();
	char kommando;
	do
	{
		cout << "Add person? ";
		cin >> kommando;
		switch (kommando)
		{
		case 'n': doNew(folk); break;
		case 'a': doAll(folk); break;
		case 'b': doBort(folk); break;
		default: break;
		}

	} while (kommando != 'q');

	return 0;
}



