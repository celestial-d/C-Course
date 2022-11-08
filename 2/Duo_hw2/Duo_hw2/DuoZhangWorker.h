//DuoZhangWorker.h
//Duo Zhang
//C++ CIS554
//input and output the salary of different workers
//interface
#pragma once
#include"string"//basic String library
using std::string;//use string

class Worker//class worker
{
	public:
		Worker();//constructor
		void choosemployees();//function to choose input information
		void managerswage();//calculate manager salary
		void workerwage();//calculate hourly worker salary
		void commissionwage();//calculate commission salary
		void pieceworkerwage();//calculate pieceworker salary
		void displaywageall();//use to display image
		
private:
	int paycode; //use to choose to input which salary 
	double sum=0;	//to calculate salary
	double summ=0; //to calculate total manager salary
	double sumw=0;//to calculate tital houlrly worker salary
	double sumc=0;//use to calculate commission salary
	double sump=0;//use to calculate pueceworker salary

};