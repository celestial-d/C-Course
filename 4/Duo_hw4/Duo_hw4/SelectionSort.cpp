//DuoZhangWorkermain.cpp
//Duo Zhang
//C++ CIS554
//recursive and iteritive
//function cpp
#include"Selectionsort.h"//some basic library
#include"iomanip"//some basic library
#include"vector"//some basic library
#include "TimeStamp.h" // TimeStamp class
#include <cstdlib> // system
#include <ctime> // time
#include <iostream> // cin, cout
#include <windows.h> // Sleep

using std::cout;//using cout
using std::cin;//using cin
using std::setw;//using setw
using std::vector;//using vector
using std::endl;//using endl

SelectionSort::SelectionSort() {}//constructor

void SelectionSort::RecursiveSort(int a[], int size, int j) //small array recursive
{
	int choose;//varaibale
	cout << "recursive array ascending(1) or decending(-1)";
	cin >> choose;//get value to choose
	
	switch (choose)//choose ascending or decending
	{
	case 1: 
		resort_as(a, size, j);  //if 1 ascending
		break;
	case -1://if -1 decending
		resort_de(a, size, j); 
		break;
	default: //other is error
		cout << "error"; 
		break;
	}
}
void SelectionSort::IteritiveSort(int a[],int size)//small iteritive array
{
	int choose;//vareable
	cout << "iterative array ascending(1) or decending(-1)";
	cin >> choose;//get choose
	switch (choose)
	{
	case 1:itsort_as(a, size); break;//if 1,ascending
	case -1:itsort_de(a, size); break;//if -1 decending
	default: cout << "error"; break;
	}
}
void SelectionSort::RecursiveSort(vector<int>&myv,int j)//vector small recursive
{
	int choose;
	cout << "recursive vector ascending(1) or decending(-1)";
	cin >> choose;//get choose
	switch (choose)
	{
	case 1:resort_as(myv, j); break;//if 1 ascending
	case -1:resort_de(myv, j); break;//if -1 decending
	default: cout << "error"; break;//if other error
	}
}

void SelectionSort::IteritiveSort(vector<int>&myv)//vector iteritive small
{
	int choose;
	cout << "iteritive vector ascending(1) or decending(-1)";
	cin >> choose;//get choose
	switch (choose)
	{
	case 1:itsort_as(myv); break;//if 1 ascending
	case -1:itsort_de(myv); break;//if -1 decending
	default: cout << "error"; break;//if other error
	}
}

void SelectionSort::lRecursiveSort(int a[], int size, int j,int choose)//large array recursive
{

	switch (choose)
	{
	case 1:
		resort_as(a, size, j);//if 1 asending
		break;
	case -1:
		resort_de(a, size, j);//if -1 decending
		break;
	default://if other error
		cout << "error";
		break;
	}
}

void SelectionSort::lIteritiveSort(int a[], int size,int choose)//large array iteritive
{
	switch (choose)
	{
	case 1:itsort_as(a, size); break;//if 1 ascending
	case -1:itsort_de(a, size); break;//if -1 decending
	default: cout << "error"; break;//if other, error
	}
}

void SelectionSort::lRecursiveSort(vector<int>&myv, int j,int choose)//large vector recursive
{
	switch (choose)
	{
	case 1:resort_as(myv, j); break;//if 1 ascending
	case -1:resort_de(myv, j); break;//if -1 decending
	default: cout << "error"; break;//if other error
	}
}

void SelectionSort::lIteritiveSort(vector<int>&myv,int choose)//large vector iteritive
{
	switch (choose)
	{
	case 1:itsort_as(myv); break;//if 1 ascending
	case -1:itsort_de(myv); break;//if -1 decending
	default: cout << "error"; break;//if other error
	}
}

void SelectionSort::resort_as(int a[], int size, int j)//small array ascending recursive
{
	if (j<size - 1)//judge all 
	{
		int min = j;//get the most small one
		for (int i = j + 1; i<size; i++)
			if (a[min] >a[i])//if get smaller one ,remember mark
			{
				min = i;
			}
		if (min != j) //if not itself, exchage
		{
			int temp = a[j];
			a[j] = a[min];
			a[min] = temp;
		}
		resort_as(a, size, ++j); //recursive all
	}

}

void SelectionSort::resort_de(int a[], int size, int j)//small array deending recursive
{
	if (j<size - 1)
	{
		int max = j;//get the most large one
		for (int i = j + 1; i<size; i++)
			if (a[max] <a[i])//if get larger ,mark
			{
				max = i;
			}
		if (max != j)
		{
			int temp = a[j];//if not itself, exchage
			a[j] = a[max];
			a[max] = temp;
		}
		resort_de(a, size, ++j);
	}

}

void SelectionSort::itsort_as(int a[], int size)//small array ascending iterirtive
{
	int i, j;//variabe
	int min = 0;//variable
	for (j = 0; j < size - 1; j++)
	{
		min = j;//get most smaller one
		for (i = j + 1; i < size; i++)
		{
			if (a[min] > a[i])//if get smaller one, mark
			{
				min = i;
			}
		}
		if (min != j)
		{
			int temp = a[j];//if not itself, exchage
			a[j] = a[min];
			a[min] = temp;
		}
	}
}

void SelectionSort::itsort_de(int a[], int size)//small array decending iteritive
{
	int i, j;//variabe
	int max = 0;//variabe
	for (j = 0; j < size - 1; j++)
	{
		max = j;//get most large one
		for (i = j + 1; i < size; i++)
		{
			if (a[max] < a[i])//if get larger one mark
			{
				max = i;
			}
		}
		if (max != j)
		{
			int temp = a[j];//if not itself, exchage
			a[j] = a[max];
			a[max] = temp;
		}
	}
}

void SelectionSort::resort_as(vector<int>&myv, int j)//small vectorascending recursive
{
	if (j<myv.size() - 1)//judge all
	{
		int min = j;//get most small one
		for (int i = j + 1; i<myv.size(); i++)
			if (myv[min] >myv[i])//if get smaller one mark
			{
				min = i;
			}
		if (min != j)
		{
			int temp = myv[j];//if not itself, exchage
			myv[j] = myv[min];
			myv[min] = temp;
		}
		resort_as(myv, ++j);
	}
}

void SelectionSort::resort_de(vector<int>&myv, int j)//small vectordecending recurtive
{
	if (j<myv.size() - 1)
	{
		int max = j;//get the most large one
		for (int i = j + 1; i<myv.size(); i++)
			if (myv[max] < myv[i])//if get larger one, mark
			{
				max = i;
			}
		if (max != j)
		{
			int temp = myv[j];//if not itself, exchage
			myv[j] = myv[max];
			myv[max] = temp;
		}
		resort_de(myv, ++j);
	}
}

void SelectionSort::itsort_as(vector<int>&myv)//small vector iteritive ascending
{
	int i, j;//variabe
	int min = 0;//variabe
	for (j = 0; j < myv.size() - 1; j++)
	{
		min = j;//get the most small one
		for (i = j + 1; i < myv.size(); i++)
		{
			if (myv[min] > myv[i])//if get smaller one mark
			{
				min = i;
			}
		}
		if (min != j)
		{
			int temp = myv[j];//if not itself, exchage
			myv[j] = myv[min];
			myv[min] = temp;
		}
	}

}

void SelectionSort::itsort_de(vector<int>&myv)//small vector decending iteritive
{
	int i, j;//variabe
	int max = 0;//variabe
	for (j = 0; j < myv.size() - 1; j++)
	{
		max = j;//get the most large one
		for (i = j + 1; i < myv.size(); i++)
		{
			if (myv[max] < myv[i])//if get larger one mark
			{
				max = i;
			}
		}
		if (max != j)
		{
			int temp = myv[j];//if not itself, exchage
			myv[j] = myv[max];
			myv[max] = temp;
		}
	}

}




