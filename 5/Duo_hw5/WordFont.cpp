//DuoZhangWorker.h
//Duo Zhang
//C++ CIS554
//input and output the alphabet
//implement
#include "WordFont.h"//interface
#include <vector>//library
using std::vector;//use vector
#include <iostream>//libary
using std::cout;//use cout
using std::cin;//use cin
using std::endl;//use endl
#include <iomanip>//library

WordFont::WordFont()
{
}//constructor

void WordFont::Font_a()//use to get picture a
{
	for (int cols = col; cols<fontsize+col; cols++) //cicular cols
	{
		int rows = 0;
		myMultiVector.at(rows).at(cols) = pixel;//get pixel in the o row
		rows = fontsize/2;
		myMultiVector.at(rows).at(cols) = pixel;//get pixel in the fontsize/2 row
	}
	for (int rows = 0; rows<fontsize; rows++)//circular rows
	{
		int cols = col;
		myMultiVector.at(rows).at(cols) = pixel;//get pixel in the col's col
		cols = fontsize-1+col;
		myMultiVector.at(rows).at(cols) = pixel;	//get pixel in the fonsize+col's col
	}
	if (bold == 1)//if bold, bold
	{
		for (int cols = col+1; cols < fontsize + col; cols++)
		{
			int rows = 1;//get pixel in the 1 row
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize / 2-1;//get pixel in the fonsize/2-1 row
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = col+1;//get pixel in the col+1's col
			myMultiVector.at(rows).at(cols) = pixel;
			cols = fontsize - 2 + col;//get pixel in the fontsize +col-2 col
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_b()////use to get picture b
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = 0;//the 0 row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize / 2;//the mid row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize - 1;//the last row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = col;//the first col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		cols = fontsize - 1 + col;//the last col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col; cols < fontsize + col; cols++)
		{
			int rows = 1;//the row 1 get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize / 2 - 1;//the mid row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize - 2;//the last row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = col + 1;//the 2rd col get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			cols = fontsize - 2 + col;//the mid col get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_c()//use to get picture c
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = 0;//the row 0 get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize - 1;//the last row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = col;//the first col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col + 1; cols < fontsize + col; cols++)
		{
			int rows = 1;//the 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize - 2;//the last 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = col + 1;//the 2rd col get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}//use to get picture c

void WordFont::Font_e()//use to get picture e
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = 0;// the first row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize / 2;//the mid row get  pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize - 1;//the last row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = col;//the first col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col + 1; cols < fontsize + col; cols++)
		{
			int rows = 1;//the 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize / 2 - 1;//the mid row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize - 2;//the last 2 rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = col + 1;//the 2rd col get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_f()//use to get picture f
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = 0;//the first row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize / 2;//the mid row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = col;//the first col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col + 1; cols < fontsize + col; cols++)
		{
			int rows = 1;//the 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize / 2 - 1;//the mid row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = col + 1;//the last 2rd col get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_h()//use to get picture h
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = fontsize / 2;//the mid row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = col;//the first col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		cols = fontsize - 1 + col;//the last col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col + 1; cols < fontsize + col; cols++)
		{
			int rows = fontsize / 2 - 1;//the mid row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = col + 1;//the 2rd col get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			cols = fontsize - 2 + col;//the last 2rd col get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_i()//use to get picture i
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = 0;//the first row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize - 1;//the last row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = fontsize/2+ col;//the mid col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col; cols < fontsize + col; cols++)
		{
			int rows = 1;//the 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize - 2;//the last 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = fontsize/2 + col-1;//the mid col get pixel to bold
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_j()//use to get picture j
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = fontsize - 1;//the last row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = fontsize - 1 + col;//the last col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col; cols < fontsize + col; cols++)
		{
			int rows = fontsize - 2;//the last 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = fontsize - 2 + col;//the last 2rd col get pixel to  bold
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_l()//use to get picture l
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = fontsize - 1;//the last row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = col;//the first col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col + 1; cols < fontsize + col; cols++)
		{
			int rows = fontsize - 2;//the last 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = col + 1;//the 2ed col get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_o()//use to get picture o
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = 0;//the first row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize - 1;//the last row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = col;//the first col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		cols = fontsize - 1 + col;//the last col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col; cols < fontsize + col; cols++)
		{
			int rows = 1;//the 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize - 2;//the last 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = col + 1;//the 2rd col get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			cols = fontsize - 2 + col;//the last 2rd col get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_p()//use to get picture p
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = 0;//the first row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize / 2;//the mid row get pxiel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = col;//the first col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows < fontsize/2; rows++)
	{
		int cols = fontsize - 1 + col;//the last col get pixel with half of row
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col; cols < fontsize + col; cols++)
		{
			int rows = 1;//the 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize / 2 - 1;//the last 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = col + 1;//the 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			
		}
		for (int rows = 0; rows < fontsize/2; rows++)
		{
			int cols = fontsize - 2 + col;//bold the last col
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_q()//use to get picture q
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = 0;//the first row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize / 2;//the mid row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = fontsize - 1 + col;//the last col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows < fontsize/2; rows++)
	{
		int cols = col;//the first col get pixel with half of row
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col; cols < fontsize + col; cols++)
		{
			int rows = 1;//the 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize / 2 - 1;//the last 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = fontsize - 2 + col;//the last 2rd col get pixel
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize/2; rows++)
		{
			int cols = col + 1;//bold the first col
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_s()//use to get picture s
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = 0;//the first row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize / 2;//the mid row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		rows = fontsize - 1;//the last row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize/2; rows++)
	{
		int cols = col;//the first row get pixei with half of row
		myMultiVector.at(rows).at(cols) = pixel;
		
	}
	for (int rows = fontsize/2; rows < fontsize; rows++)
	{
		int cols = fontsize - 1 + col;//the last col get pixel wit half of row 
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col; cols < fontsize + col; cols++)
		{
			int rows = 1;//the 2rd row get pixel
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize / 2 - 1;//the mid row get bold
			myMultiVector.at(rows).at(cols) = pixel;
			rows = fontsize - 2;//the last row get bold
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize/2; rows++)
		{
			int cols = col + 1;//the first col get bold
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = fontsize/2; rows < fontsize; rows++)
		{
			int cols = fontsize - 2 + col;//the last col get bold
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_t()//use to get picture t
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = 0;//the first row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = fontsize / 2 + col;//the mid col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col; cols < fontsize + col; cols++)
		{
			int rows = 1;//the first row get bold
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = fontsize / 2 + col-1;//the mid col get bold
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::Font_u()//use to get picture u
{
	for (int cols = col; cols<fontsize + col; cols++)
	{
		int rows = fontsize - 1;//the last row get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	for (int rows = 0; rows<fontsize; rows++)
	{
		int cols = col;//the first col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
		cols = fontsize - 1 + col;//the last col get pixel
		myMultiVector.at(rows).at(cols) = pixel;
	}
	if (bold == 1)
	{
		for (int cols = col; cols < fontsize + col; cols++)
		{
			int rows = fontsize - 2;//the last row get bold
			myMultiVector.at(rows).at(cols) = pixel;
		}
		for (int rows = 0; rows < fontsize; rows++)
		{
			int cols = col + 1;//the first col get  bold
			myMultiVector.at(rows).at(cols) = pixel;
			cols = fontsize - 2 + col;//the last col get bold
			myMultiVector.at(rows).at(cols) = pixel;
		}
	}
}

void WordFont::choosefont()//according choose to get picture
{
	for (int i = 0; i < choose.size();i++)//from choose to get every letter
	{
		switch (choose[i])//according to letter to get picture to the vector
		{
		case 'a':Font_a(); break;//if a,picture a to vector
		case 'b':Font_b(); break;//if b,picture b to the vector
		case 'c':Font_c(); break;//if c, picture c to the vector
		case 'e':Font_e(); break;//if e,picture e to the vector
		case 'f':Font_f(); break;//if f,picture f to the vector
		case 'h':Font_h(); break;//if h,picture h to the vector
		case 'i':Font_i(); break;//if i,picture i to the vector
		case 'j':Font_j(); break;//if j,picture j to the vector
		case 'l':Font_l(); break;//if l, picture l to the vector
		case 'o':Font_o(); break;//if o,picture o to the vector
		case 'p':Font_p(); break;//if p,picture p to the vector
		case 'q':Font_q(); break;//if q, picture q to the vector
		case 's':Font_s(); break;//if s ,picture s to the vector
		case 't':Font_t(); break;//if t, picture t to the vector
		case 'u':Font_u(); break;//if u,picture u to the vector
		default:cout << "error"; break;//others is error
		}
		for (int i = 0; i < fontsize + 1; i++)//let col add fontsize +1 to get another letter
			col++;
	}

}

void WordFont::inputfont()//get enough data
{
	cout << "Enter a word(8 letters or less),using a,b,c,e,f,h,i,j,l,o,p,q,s,t,u: ";
	cin >> choose;//get a word to the variable--choose
	cout << "\nEnter the pixel character: ";
	cin >> pixel;//get a pixel 
	cout << "\nEnter the font size£¨from 8 to 12£© : ";
	cin >> fontsize;//get a fontsize
	cout << "Bold? (0=NO,1=yes)";
	cin >> bold;//assure whether bold or not
	
	buildvector();//get a vcetor
	choosefont();//choose which picture should be add to the vector
	outputfont();//out put the vector

}

void WordFont::outputfont()//output picture
{
	for (int rows = 0; rows < myMultiVector.size(); rows++)
	{
		for (int cols = 0; cols < myMultiVector.at(0).size(); cols++)
		{
			// put some data in each row and column, using subscript notation

			cout << myMultiVector[rows][cols];

			// alternatively, this would work as well, and be acceptable
			// cout << myMultiVector.at(rows).at(cols);
		}
		cout << "---Line" << rows+1 << endl;
	}

}

void WordFont::buildvector()//resize the vector
{
	myMultiVector.resize(fontsize);//let vector get size with 1 dimension
	
	for (int i = 0; i < fontsize; i++)
	{
		myMultiVector.at(i).resize((fontsize+1)*choose.size());//let vector get size with 2 demensions
	}
}

