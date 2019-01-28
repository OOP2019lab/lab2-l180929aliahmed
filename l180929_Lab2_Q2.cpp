// l180929_Lab2_Q2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gitHubUser.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//ReadFromFile Function
void ReadDataFromFile(gitHubUser* &users, int &size){
	ifstream fin("D:\\Sample.txt");
	if(fin.fail())
		cout<<"Unable to open!";
	else{
		int size=0;
		fin>>size;
		users=new gitHubUser[size];
		for(int i=0; i<size; i++){
			fin>>users[i].firstName;
			fin>>users[i].userName;
			fin>>users[i].email;
			fin>>users[i].foldercount;
			users[i].gitHubFolders=new string[users[i].foldercount];
			for(int f=0; f<users[i].foldercount; f++){
				fin>>users[i].gitHubFolders[f];
			}
		}
	}
}

//Print Struct Function
void printStruct(gitHubUser* users, int size){
	for(int i=0; i<size; i++){
		cout<<users[i].firstName<<endl;
		cout<<users[i].userName<<endl;
		cout<<users[i].email<<endl;
		cout<<users[i].foldercount<<endl;
		/*for(int f=0; f<users[i].foldercount; f++){
			cout<<users[i].gitHubFolders[f]<<endl;
		}*/
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int size;
	gitHubUser* users;
	ReadDataFromFile(users, size);
	printStruct(users, size);
	
	/*Deleting*/
	for(int i=0; i<size; i++)
		delete[]users[i].gitHubFolders;
	delete[]users;
	return 0;
}

