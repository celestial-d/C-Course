//DuoZhangWorkermain.cpp
//Duo Zhang
//C++ CIS554
//recursive and iteritive
//function h
#include"vector"//.h file
using std::vector;//using vector
class SelectionSort//class
{
public:
	SelectionSort();//constructor
	void RecursiveSort(int [],int,int);//use to small array recursive
	void IteritiveSort(int [],int);//use to small array iteritive
	void RecursiveSort(vector<int>&,int);//use to vector small recursive
	void IteritiveSort(vector<int>&);//use to vector small iteritive

	void lRecursiveSort(int[], int, int,int);//use to large array recrisive
	void lIteritiveSort(int[], int,int);//use to large array iteritive
	void lRecursiveSort(vector<int>&, int,int);//use to large vector recursive
	void lIteritiveSort(vector<int>&,int);//use to large vector iteritive
private:
	void resort_as(int[], int, int);//array ascending
	void resort_de(int[], int, int);//array decending
	void itsort_as(int[], int);//array ascening
	void itsort_de(int[], int);//array decending

	void resort_as(vector<int>&, int);//vector ascedning
	void resort_de(vector<int>&, int);//vector decending
	void itsort_as(vector<int>&);//vector ascending
	void itsort_de(vector<int>&);//vector decending

};