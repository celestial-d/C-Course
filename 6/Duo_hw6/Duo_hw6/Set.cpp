#include "Set.h"//library
#include"iostream"//library
using std::cout;//use cout
using std::endl;//use endl

Set::Set(vector<bool>& v)//constructor
	:set(v)//initialize
{
}

bool Set::IsMember(int x)//use to get the retult of position
{
	if(set.at(x)==true)//if the element have, true
	return true;
	
	return false;
}

Set Set::Union(Set & S)//use to union
{
	Set uset = set;//get the set
	for (int i = 0; i < S.set.size(); i++)
	{
		uset.set[i]= uset.set[i]*S.set[i];//to union
	}
	return uset;//return set
}

Set Set::Intersection(Set & S)//use to intersect
{
	Set interset = set;//get the set
	for (int i = 0; i < S.set.size(); i++)
	{
		interset.set[i] = interset.set[i] + S.set[i];//to intersect 
	}
	return interset;
}

void Set::Print()//to print
{
	for (int i = 0; i < Set::set.size(); i++)
	{
		cout << Set::set[i] << " ";//print every element of the vector
	}
	cout << endl;
}
