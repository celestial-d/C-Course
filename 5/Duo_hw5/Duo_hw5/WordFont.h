//DuoZhangWorker.h
//Duo Zhang
//C++ CIS554
//input and output the alphabet
//interface
#include"string"//library
using std::string;//use string
#include <vector>//library
using std::vector;//use vector


class WordFont//define a class wordfont
{
public:
	WordFont();//constructor
	void choosefont();//use to get data
	void inputfont();//use to get some parameter
	void outputfont();//use to output picture
	void buildvector();//us use to build vector
private:
	void Font_a();//use to get picture a
	void Font_b(); //use to get picture b
	void Font_c(); //use to get picture c
	void Font_e(); //use to get picture e
	void Font_f(); //use to get picture f
	void Font_h(); //use to get picture h
	void Font_i(); //use to get picture i
	void Font_j(); //use to get picture j
	void Font_l(); //use to get picture l
	void Font_o(); //use to get picture o
	void Font_p(); //use to get picture p
	void Font_q();//use to get picture q
	void Font_s(); //use to get picture s
	void Font_t(); //use to get picture t
	void Font_u();//use to get picture u
	int fontsize=0;//get a fontsize
	int col=0;//define a variable to get how many length
	string choose;//use to get a word
	char pixel;//use to get pixel
	int bold = 0;//use to assure whether bold or not
	vector<vector<char>> myMultiVector;//a vector to reserve data
};
