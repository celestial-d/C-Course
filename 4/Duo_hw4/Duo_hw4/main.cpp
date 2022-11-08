//DuoZhangWorkermain.cpp
//Duo Zhang
//C++ CIS554
//recursive and iteritive
//main
#include"Selectionsort.h"//some basic library
#include"iostream"//some basic library
#include <array>//some basic library
#include <random>//some basic library
#include <vector>//some basic library
#include <time.h>//some basic library
#include "TimeStamp.h"//some basic library

using namespace std;//using all

template<typename T> void printData(T& data, int size);//use to print 
template<typename T> void addrandom(T& data, int size);//use to get data
void printtime();//use to print time

int main()
{
	const int smallsize = 20;
	const int largesize = 6000;
	srand(static_cast<unsigned int>(time(0)));
	int s_array[smallsize], scopy_array[smallsize];// declare small array
	int l_array[largesize], lcopy_array[largesize];// declare large array
	vector<int> svector(smallsize);// declare small vector
	vector<int> lvector(largesize);// declare large vector

	addrandom(s_array, smallsize);// call helper function to put random data in small array
	addrandom(l_array, largesize);// call helper function to put random data in large array

	memcpy(scopy_array, s_array, sizeof(s_array));	// call helper function to make copy of small array
	memcpy(lcopy_array, l_array, sizeof(l_array));	// call helper function to make copy of large array

	addrandom(svector, smallsize);// call helper function to put random data in small vector 
	addrandom(lvector, largesize);// call helper function to put random data in large vector


	vector<int> scopy_vector = svector;// make copy of small vector (hint: use assignment operator, no function required)
	vector<int> lcopy_vector = lvector;// make copy of large vector (hint: use assignment operator, no function required)

	SelectionSort sort;
	
	 //show that your sorting algorithms work by printing small array 
	printData(s_array, smallsize);// call helper function to print small array before sort
	sort.RecursiveSort(s_array, smallsize, 0);// sort small array with recursion
	printData(s_array, smallsize);// call helper function to print sorted small array
	sort.IteritiveSort(scopy_array, smallsize);// 	sort copy of small array with iteration
	printData(scopy_array, smallsize);// 	call helper function to print sorted small array

	printData(svector, smallsize);// 	call helper function to print small vector before sort
	sort.RecursiveSort(svector, 0);// 	sort small vector with recursion
	printData(svector, smallsize);// 	call helper function to print sorted small vector
	sort.IteritiveSort(scopy_vector);// 	sort small vector with iteration
	printData(scopy_vector, smallsize);// 	call helper function to print sorted small vector

	int choose;
	 //analyze performance of selection algorithms using large arrays.
	cout << "large array recursive ascending(1) or decending(-1)";
	cin >> choose;
	printtime();// 	print timestamp
	sort.lRecursiveSort(l_array, largesize, 0,choose);// 	sort large array with recursion
	printtime();// 	print timestamp

	cout << "large array iteritive ascending(1) or decending(-1)";
	cin >> choose;
	printtime();// 	print timestamp
	sort.lIteritiveSort(lcopy_array, largesize,choose);// 	large array with iteration
	printtime();// 	print get timestamp


	 //analyze performance of selection algorithms using large vectors.
	cout << "large vector recursive ascending(1) or decending(-1)";
	cin >> choose;
	printtime();// 	print timestamp
	sort.lRecursiveSort(lvector, 0,choose);// 	sort large vector with recursion
	printtime();// 	print timestamp

	cout << "large vector iteritive ascending(1) or decending(-1)";
	cin >> choose;
	printtime();// 	print timestamp
	sort.lIteritiveSort(lcopy_vector,choose);// 	sort large vector with iteration
	printtime();// 	print timestamp

	return 0;
}
// function template definitions
template<typename T> void printData(T& data, int size)//use to print data
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << "   ";//circular print data
	}
	cout << endl;
}
template<typename T> void addrandom(T& data, int size)//use to get data
{
	for (int i = 0; i < size; i++)
	{
		data[i] = rand() % size;//circular get data
	}
	//printData(data, size);
}
// other function definitions
void printtime()//use to get time and print
{
	TimeStamp ts;////variabe
	string timeString;//variabe
	timeString = ts.GetTime();//get time
	cout << timeString << endl;//print time
}