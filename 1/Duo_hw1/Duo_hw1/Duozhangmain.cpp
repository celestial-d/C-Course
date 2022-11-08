#include"iostream" //basic class
#include"DuoZhangConvert.h"// the class Convert

int main()
{
    Convert convertnum;//define convert object
	convertnum.reveivebase();//get a base
	convertnum.reveivenum();//get a number
	if (convertnum.judgnumber() == 1) //judge base and number 
	{
		convertnum.convert1();  //if return 1, then convert
	}
	return 0;//finish the main 
}