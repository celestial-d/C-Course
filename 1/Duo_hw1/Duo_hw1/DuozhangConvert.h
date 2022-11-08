#pragma once
class Convert
{
public:
	Convert();//constructor
	void reveivenum();//get a number
	void reveivebase();//get a base
	void convert1(); //function to convert and get final result
	int judgnumber();//judge whether the number and base is allowed or not

private:
	int num, base;//define a member

};

