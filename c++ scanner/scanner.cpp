#include <iostream>
#include <string>
#include <list>
#include <cctype>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <fstream>
using namespace std;

list<string> extract (list<string> codes)
{
	string pronajdeno,vlez,code;
	int found;
	list<string>part;

	list<string>::iterator it;
	//int found=code.find("AC");

	for (it = codes. begin(); it != codes. end(); it++)
	{
		code=*it;

		while(1<2)
		{
			found=code.find("AC");
																		// baram AC i proveruvam dali ima preostanati AC
			if(code.size()>8 && found!=string::npos)
			{
				found=code.find("AC");
				pronajdeno=code.substr(found,found+9);				//go secam AC i karakterite posle nego
				vlez=pronajdeno.substr(0,9);						//vmetnuvam vo listata
				if(vlez.size()>=9)
				{
					part.push_back(vlez);
				}
				code.erase(0,found+8);								//brisam golemiot string
			}
			else break;
		}
	}
	


	return part;
}

string converter(int broj)
{
	stringstream ss;
	ss << broj;
	return ss.str();
}

list<string> codeGenerator ()
{
	list<string>codes;
	string str;
	srand (time(NULL));

	for(int i=0;i<25;i++)
	{
		//*************************************	
		int broj1=rand()%78000+12000;
		str=(converter(broj1));
		str.append("AC");
		//*************************************			ovde pravam random 19 cifren broj
		int broj2=rand()%7311111+1926000;
		str.append(converter(broj2));
		str.append("P");
		//*************************************			random->od 20+30  toa znaci FROM 30 TO 50 rank
		int broj3=rand()%7800+1000;
		str.append(converter(broj3));

		codes.push_back(str);
	}
	return codes;
}


int main()
{
	//initialization
	string number;
	list<string>lista, codes,korisnickivlez;
	int izbor;
	korisnickivlez.push_back(number);

	//printing
	cout<<"HELLO WORLD"<<endl;
	cout<<endl;
	cout<<"If You want to try this program with RANDOM GENERATOR, enter --> 1 <--, if want to try with self numbers enter --> 2 <-- and if You want to read from file enter --> 3 <--"<<endl;
	cout<<endl;
	cin>>izbor;
	cout<<endl;


	//cout choice 1
	if(izbor==1)
	{
		codes=codeGenerator();

		list<string>::iterator it2;
		
		cout<<"This is a random number (code)"<<endl;
		cout<<endl;
		for (it2 = codes. begin(); it2 != codes. end(); it2++)
		{
			cout<<*it2<<endl;
		}
		cout<<endl;


		lista=extract(codes);
		list<string>::iterator it;
		lista.sort();
		for (it = lista. begin(); it != lista. end(); it++)
		{
			cout<<*it<<endl;
		}
		cout<<endl;
		cout<<"The Unique numbers are sorted"<<endl;
		cout<<endl;
	}
	
	//choice 2
	else if(izbor==2)
	{
		cout<<endl;
		cout<<"Enter any chars (string) to check for unique numbers which starts with 'AC'"<<endl;
		cout<<endl;
		cin>>number;
		cout<<endl;
		korisnickivlez.push_back(number);
		lista=extract(korisnickivlez);

		list<string>::iterator it;
		lista.sort();
		int counter=0;
		for (it = lista. begin(); it != lista. end(); it++)
		{
			cout<<*it<<endl;
			counter++;
		}
		if(counter==0)
		{
			cout<<endl;
			cout<<"There was NOT Unique numbers which start with 'AC' or have size like other unique numbers"<<endl;
			cout<<endl;
		}
	}
	//choice 3
	else if(izbor==3)
	{
		string line;
		ifstream myfile ("example.txt"); 
		if (myfile.is_open())
		{
			cout<<"This is in file: "<<endl;
			while ( getline (myfile,line) )
			{
				cout<<line<<endl;
				korisnickivlez.push_back(line);
			}
			myfile.close();
		}
		else cout << "Unable to open file"<<endl;

		lista=extract(korisnickivlez);

		list<string>::iterator it;
		lista.sort();
		int counter=0;
		cout<<endl;
		cout<<"Unique numbers: "<<endl;
		
		ofstream file;
		file.open("example.txt", ofstream::out | ofstream::app);     // da se izbrisi out i app za da ne go cuva prethodnoto napisano vo datotekata
		file<<""<<endl;
		for (it = lista. begin(); it != lista. end(); it++)
		{

			file << *it <<endl;
	
			cout<<*it<<endl;
			counter++;
		}
		myfile.close();

		cout<<"They are writen in file."<<endl;
		if(counter==0)
		{
			cout<<endl;
			cout<<"There was NOT Unique numbers which start with 'AC' or have size like other unique numbers"<<endl;
			cout<<endl;
		}

	}
	//choice 4
	else 
	{
		cout<<endl;
		cout<<"I knew you were going to try to enter the wrong entry"<<endl;
		cout<<endl;
	}

	system("pause");
	return 0;
}