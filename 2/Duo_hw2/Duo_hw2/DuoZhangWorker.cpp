//DuoZhangWorker.cpp
//Duo Zhang
//C++ CIS554
//input and output the salary of different workers
//implementation

#include"iostream"
#include"DuoZhangWorker.h"
#include"string"//some basic library
using std::string;
using std::endl;    //using sting and endl

Worker::Worker() {}   //constructor

void Worker::choosemployees() //to choose input which information
{
	int mark = 1;//use to circular
	while(mark)
	{ 
		std::cout << "enter the paycode(-1 to end):\n";
		std::cin >> paycode;//get paycode to choose
		switch (paycode)
		{
			case 1:managerswage();//if 1, choose input manager information
				break;
			case 2:workerwage();//if 2, choose input hourly worker information
				break;
			case 3:commissionwage();//if 3, choose input commission woker information
				break;
			case 4:pieceworkerwage();//if 4, choose input pieceworker information
				break;
			case -1:mark = 0;//if -1,finish input
				break;
			default:std::cout << "error!";//other input number is error
				break;
		}
	}
	displaywageall();//after, display the total image
}

void Worker::managerswage()//use to get manager information
{
	int weekly;
	std::cout << "manager selected\n";
	std::cout << "enter weekly salary\n";
	std::cin >> weekly;//get infortmation
	sum = weekly;
	summ = summ + sum;//calculate total salary
	std::cout << "Commission worker's pay is:" << summ<<endl; //output total salary
}

void Worker::workerwage() //use to get hoursly worker information
{
	float hoursalary;
	int hours;//define some basic variable
	std::cout << "hourly worker selected\n";
	std::cout << "enter the hourly salary\n";
	std::cin >> hoursalary;//get some information of hours worker
	std::cout << "enter the total hours worked\n";
	std::cin >> hours;//get some information of hours worker
	if (hours>=40)
		sum = 40 * hoursalary + (hours - 40)*1.5*hoursalary;//accoding to woking hours decide formula 
	else sum = hours*hoursalary;//use to calculate salary when hours<40
	sumw = sumw + sum;//get tital salary
	std::cout << "Commission worker's pay is:" << sumw<<endl;//output total salary
}

void Worker::commissionwage()//use to get commission information
{
	int gross; //define a varaible
	std::cout << "commission worker selected\n";
	std::cout << "enter gross weekly sales\n";
	std::cin >> gross;//use to get information
	sum = 250 + 0.057*gross; //formula to get salary
	sumc = sumc + sum;//calculate total salary when get more commission
	std::cout << "Commission worker's pay is:" << sumc<<endl;//output salary
}

void Worker::pieceworkerwage()//use to get pieceworker salary
{
	int piece;
	float wageper;//define some variables
	std::cout << "pieceworker selected\n";
	std::cout << "enter number of piece\n";
	std::cin >> piece;//get some quantity information
	std::cout << "enter wage per piece\n";
	std::cin >> wageper;//get basic information
	sum = piece*wageper;
	sump = sump + sum;//calculate total salary
	std::cout << "Commission worker's pay is:" << sump<<endl;//output outcome
}


void Worker::displaywageall()//use to display the outcome
{
	double sumre; //define a variable to display
	sumre = summ / 100; //get the manager salary
	std::cout << "manager: "; 
	static_cast<int>(sumre);//from doulbe to int
	for (; sumre > 0; sumre = sumre - 1)
		std::cout << "*";//output how many * according to the salary
	sumre = sumw / 100;//get the hourly worker salary
	static_cast<int>(sumre);//from doulbe to int
	std::cout << "\nhourly: "; 
	for (; sumre > 0; sumre = sumre - 1)
		std::cout << "*";//output how many * according to the salary
	sumre = sumc / 100;//get the commission salary
	static_cast<int>(sumre);//from doulbe to int
	std::cout <<"\ncommission: "; 
	for (; sumre > 0; sumre = sumre - 1)
		std::cout << "*";//output how many * according to the salary
	sumre = sump / 100;//get the pieceworker salary
	static_cast<int>(sumre);//from doulbe to int
	std::cout << "\npieceworker: ";
	for (; sumre > 0; sumre = sumre - 1)
		std::cout << "*";//output how many * according to the salary
	std::cout << "\n";
}

	






