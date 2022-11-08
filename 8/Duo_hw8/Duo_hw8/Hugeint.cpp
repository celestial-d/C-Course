// Exercise 11.9 Solution: Hugeint.cpp
// HugeInt member-function and friend-function definitions.
#include <iostream>
#include <stdexcept>
#include <cctype> // isdigit function prototype
#include "Hugeint.h" // HugeInt class definition
using namespace std;
using std::cout;

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt( long value )
{
   // initialize array to zero
   for ( int i = 0; i < digits; ++i )
      integer[ i ] = 0;

   // place digits of argument into array
   for ( int j = digits - 1; value != 0 && j >= 0; --j )
   {
      integer[ j ] = value % 10;
      value /= 10;
   } // end for
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string
// representing a large integer into a HugeInt object
HugeInt::HugeInt( const string &number )
{
   // initialize array to zero
   for ( int i = 0; i < digits; ++i )
      integer[ i ] = 0;

   // place digits of argument into array
   int length = number.size();

   for ( int j = digits - length, k = 0; j < digits; ++j, ++k )
      if ( isdigit( number[ k ] ) )
         integer[ j ] = number[ k ] - '0';

} // end HugeInt conversion constructor

// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+( const HugeInt &op2 ) const
{
   HugeInt temp; // temporary result
   int carry = 0;

   for ( int i = digits - 1; i >= 0; --i )
   {
      temp.integer[ i ] = integer[ i ] + op2.integer[ i ] + carry;

      // determine whether to carry a 1
      if ( temp.integer[ i ] > 9 )
      {
         temp.integer[ i ] %= 10;  // reduce to 0-9
         carry = 1;
      } // end if
      else // no carry
         carry = 0;
   } // end for

   return temp; // return copy of temporary object
} // end function operator+

HugeInt HugeInt::operator-(const HugeInt &op2) const
{
	HugeInt temp;
	int carry=0;
	int mark=0;//use to judge which one is bigger
		if (*this > op2)
		{
			mark = 1;
		}
		else
		{
			mark = 0;
		}

	if (mark == 1)
	{
		for (int i = digits - 1; i >= 0; --i)
		{
			if (integer[i] < op2.integer[i])
			{
				temp.integer[i] = integer[i] + 10 - carry - op2.integer[i];
				carry = 1;
			}
			else
			{
				temp.integer[i] = integer[i] - carry - op2.integer[i];
				carry = 0;
			}
		}
	}
	if (mark == 0)
	{
		for (int i = digits - 1; i >= 0; --i)
		{
			if (integer[i] > op2.integer[i])
			{
				temp.integer[i] = op2.integer[i] + 10 - carry - integer[i];
				carry = 1;
			}
			else
			{
				temp.integer[i] = op2.integer[i] - carry - integer[i];
				carry = 0;
			}
		}
		for (int i = digits - 1; i >= 0; --i)//let the first postion  is negtive
		{
			if (temp.integer[i] == 0)
			{
				temp.integer[i+1] = 0 - temp.integer[i+1];
				break;
			}
		}
	}
	return temp;
}

HugeInt HugeInt::operator*(const HugeInt &op2) const
{
	HugeInt temp[30]; // temporary result
	HugeInt tempall=0;
	int carry = 0;
	for (int j = digits - 1; j>=0; --j)
	{
		for (int i = digits - 1; i >= 0; --i)
		{
			if (op2.integer[j] != 0)
			{
				temp[j].integer[i - digits + j + 1] = integer[i] * op2.integer[j] + carry;
				// determine whether to carry 
				if (temp[j].integer[i - digits + j + 1] > 9)
				{
					carry = temp[j].integer[i - digits + j + 1] / 10;
					temp[j].integer[i - digits + j + 1] %= 10;  // reduce to 0-9
				} // end if
				else // no carry
					carry = 0;
			}
		} // end for
	}
	carry = 0;//use to get total
	for (int j = digits - 1; j>=0; j--)
	{
		for (int i = digits - 1; i >= 0; i--)
		{
			tempall.integer[i] += temp[j].integer[i] + carry;
			if (tempall.integer[i] > 9)
			{
				tempall.integer[i] %= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}
	}

	return tempall;
}

HugeInt HugeInt::operator/(const HugeInt &op2) const
{
	if (op2 > *this)
	{
		return HugeInt(0);
	}
	if (*this == HugeInt(0))
	{
		return HugeInt(0);
	}
	if (*this == op2)
	{
		return HugeInt(1);
	}
	HugeInt former=*this;
	HugeInt later = op2;
	int formersize=0;
	int latersize = 0;
	for (int i = 0;i<digits ; i++)
	{
		if (later.integer[i] != 0)
		{
			latersize = digits - i;
			break;
		}
	}
	for (int i = 0; i<digits; i++)
	{
		if (former.integer[i] != 0)
		{
			formersize = digits - i;
			break;
		}
	}
	HugeInt result;
	int size=0;
	int cal;
	HugeInt laterf = later;
	size = formersize - latersize;
	for (int i = 0; i < size-1; i++)
	{
		later = later*HugeInt(10);
	}
	HugeInt laterl = later*HugeInt(10);
	if (laterl > former)
	{
		later = later*HugeInt(10);
	}
	else later = laterl*HugeInt(10);

	cout << laterl << endl;
	for(cal=0; later != laterf;cal++)
	{
		for (int i = 0; i<digits; i++)
		{
			if (later.integer[i] != 0)
			{
				latersize = digits - i;
				break;
			}
		}
		cout << latersize << endl;
		for (int i=digits-1;i>=digits-latersize;--i)
		{
			later.integer[i] = later.integer[i - 1];
		}
		for (int i = 0; i < digits-latersize; i++)
		{
			later.integer[i] = 0;
		}
		cout << later << endl;
		for (int i = 0; i <= 9; i++)
		{
			if ((later*HugeInt(i+1) > former)&&(later*HugeInt(i) <= former))
			{
				result.integer[cal] = i;
				//cout << i << endl;
				//cout << former << endl;
				former = former - later*HugeInt(i);
				//cout << former << endl;
				break;
			}
		}	
	} 
	HugeInt resultl;
	for (int i = 0; i <=cal; i++)
	{
		resultl.integer[digits - 1 - cal+i] = result.integer[i];
	}
	return resultl;
}

bool HugeInt::operator==(const HugeInt &op2) const
{
	for (int i = 0; i <digits - 1; ++i)
	{
		if (integer[i] != op2.integer[i])
		{
			return false;
		}
	}
	return true;
}

bool HugeInt::operator!=(const HugeInt &op2) const
{
	for (int i = 0; i <digits - 1; ++i)
	{
		if (integer[i] != op2.integer[i])
		{
			return true;
		}
	}
	return false;
}

bool HugeInt::operator<(const HugeInt &op2) const
{
	for (int i = 0; i <digits ; ++i)
	{
		if (integer[i] < op2.integer[i])
		{
			return true;
		}
		if (integer[i] == op2.integer[i])
		{
			continue;
		}
		if (integer[i] > op2.integer[i])
		{
			return false;
		}
	}
	return false;
}

bool HugeInt::operator<=(const HugeInt &op2) const
{
	for (int i = 0; i <digits; ++i)
	{
		if (integer[i] < op2.integer[i])
		{
			return true;
		}
		if (integer[i] == op2.integer[i])
		{
			continue;
		}
		if (integer[i] > op2.integer[i])
		{
			return false;
		}
	}
	return true;
}

bool HugeInt::operator>(const HugeInt &op2) const
{
	for (int i = 0; i <digits; ++i)
	{
		if (integer[i] > op2.integer[i])
		{
			return true;
		}
		if (integer[i] == op2.integer[i])
		{
			continue;
		}
		if (integer[i] < op2.integer[i])
		{
			return false;
		}
	}
	
	return false;
}

bool HugeInt::operator>=(const HugeInt &op2) const
{
	for (int i = 0; i <digits; ++i)
	{
		if (integer[i] > op2.integer[i])
		{
			return true;
		}
		if (integer[i] == op2.integer[i])
		{
			continue;
		}
		if (integer[i] < op2.integer[i])
		{
			return false;


		}
	}
	return true;
}

// addition operator; HugeInt + int
HugeInt HugeInt::operator+( int op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 );
} // end function operator+

HugeInt HugeInt::operator-(int op2) const
{
	return *this - HugeInt(op2);
}

HugeInt HugeInt::operator*(int op2) const
{
	return *this * HugeInt(op2);
}

HugeInt HugeInt::operator/(int op2) const
{
	return *this / HugeInt(op2);
}

bool HugeInt::operator==(int op2) const
{
	return (*this == HugeInt(op2));
}

bool HugeInt::operator!=(int op2) const
{
	return (*this != HugeInt(op2));
}


bool HugeInt::operator<(int op2) const
{
	return (*this < HugeInt(op2));
}


bool HugeInt::operator<=(int op2) const
{
	return (*this <= HugeInt(op2));
}

bool HugeInt::operator>(int op2) const
{
	return (*this > HugeInt(op2));
}

bool HugeInt::operator>=(int op2) const
{
	return (*this >= HugeInt(op2));
}

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+( const string &op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 );
} // end function operator+

HugeInt HugeInt::operator-(const string &op2) const
{
	return *this - HugeInt(op2);
}

HugeInt HugeInt::operator*(const string &op2) const
{
	return *this * HugeInt(op2);
}

HugeInt HugeInt::operator/(const string &op2) const
{
	return *this / HugeInt(op2);
}

bool HugeInt::operator==(const string &op2) const
{
	return (*this == HugeInt(op2));
}

bool HugeInt::operator!=(const string &op2) const
{
	return (*this != HugeInt(op2));
}

bool HugeInt::operator<(const string &op2) const
{
	return (*this < HugeInt(op2));
}

bool HugeInt::operator<=(const string &op2) const
{
	return (*this <= HugeInt(op2));
}

bool HugeInt::operator>(const string &op2) const
{
	return (*this > HugeInt(op2));
}

bool HugeInt::operator>=(const string &op2) const
{
	return (*this >= HugeInt(op2));
}


// overloaded output operator
ostream& operator<<( ostream &output, const HugeInt &num )
{
   int i;

   for ( i = 0; i < HugeInt::digits && num.integer[ i ] == 0; ++i )
      ; // skip leading zeros

   if ( i == HugeInt::digits )
      output << 0;
   else
      for ( ; i < HugeInt::digits; ++i )
         output << num.integer[ i ];

   return output;
} // end function operator<<




/**************************************************************************
 * (C) Copyright 1992-2010 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
