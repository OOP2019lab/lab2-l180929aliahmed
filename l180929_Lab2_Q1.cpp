// l180929_Lab2_Q1.cpp : Defines the entry point for the console application.
//
#include <string>
#include <iostream>
#include "stdafx.h"
#include "gitHubUser.h"
using namespace std;
// Existence Check function
bool exists(gitHubUser* users, int size, string userName){
	for(int i=0; i<size; i++){
		if(userName==users[i].userName)
			return true;
	}
	return false;
}
//input from user
void inputFromUser(gitHubUser*& users, int size){
	string username;
	for(int i=0; i<size; i++){
		cout<<endl<<"Enter information for User "<<i+1<<endl;
		cout<<"Enter Username:";
		cin>>username;
		while(exists(users, size, username)){
			cout<<"Username already exists, enter another username!"<<endl;
			cout<<"Enter Username:";
			cin>>username;
		}
		users[i].userName=username;
		cout<<"Enter First Name:";
		cin>>users[i].firstName;
		cout<<"Enter email:";
		cin>>users[i].email;
		cout<<"Enter Password:";
		cin>>users[i].password;
		cout<<"Enter Folder Count:";
		cin>>users[i].foldercount;
	}
}
//Comparison
bool comparison(gitHubUser a, gitHubUser b){
	if(a.userName==b.userName && a.firstName==b.firstName && a.email==b.email && a.password==b.password && a.foldercount==b.foldercount)
		return true;
	return false;
}
//Search User Function
gitHubUser* searchUser(gitHubUser* users, int size, string username){
	for(int i=0; i<size; i++){
		if(username==users[i].userName)
			return &users[i];
	}
}
//Print User 
void printUser(gitHubUser* user){
	cout<<"First name: "<<user->firstName<<endl;
	cout<<"Username: "<<user->userName<<endl;
	cout<<"Email: "<<user->email<<endl;
	cout<<"Password: "<<user->password<<endl;
	cout<<"Folder Count: "<<user->foldercount<<endl;

}
			   
int _tmain(int argc, _TCHAR* argv[])
{
	gitHubUser* search=nullptr;
	string username;
	const int size=4;
	gitHubUser* users=new gitHubUser[size];
	inputFromUser(users, size);

	//Searching
	cout<<"Enter A Username you want to search:";
	cin>>username;
	search=searchUser(users, size, username);
	printUser(search);

	//Comparison
	if(comparison(users[0], users[1]))
		cout<<"Same!";
	else
		cout<<"Not Same!";
	delete[] users;
	return 0;
}

