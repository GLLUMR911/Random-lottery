/*************************************************************************
    > File Name: Random_Lottery.cpp
    > Author: gl
    > Mail: lzs123@911gll.cn
    > Created Time: Thu 13 Sep 2018 01:47:47 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Vector"

int main(int argc, char **argv)
{
	if(2 != argc)
	{
		std::cerr << "Usage error!" << std::endl;		
		return 1;
	}

	srand(time(NULL));

	std::ifstream fin(argv[1], std::ios::in);

	if(!fin)
	{
		std::cerr << "打开"<< argv[1] <<"文件失败!" << std::endl;
		return 1;
	}

	std::string name;
	Vector<std::string> names;

	while(1)
	{
		fin >> name;
		
		if(!fin) break;
		
		names.push_back(name);
	}

	std::cout << names.size() << std::endl;
	
	int n = 0, i = 0;

	std::cout << "即将开始抽取....." << std::endl;
	
	for(i = 0; i < 20; ++i)
	{
		system("clear");
		n = rand() % names.size();
		std::cout << names[n] << std::endl;
		usleep(i * i * 1000);
	}
	return 0;
}
