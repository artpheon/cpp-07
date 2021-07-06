#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main0()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        std::cout << "Trying negative index...." << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Trying index bigger than max...." << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}

int main1()
{
	Array<int>		aiempty;
	Array<float>		af;
	Array<char*>		ac;
	Array<std::string>	as;
	std::cout << "-----------" << std::endl;
	Array<int>		ai(20);
	try
	{
		for (int i = 0; i < 20; i++)
			ai[i] = i;
		for (int i = 0; i < 20; i++)
			std::cout << ai[i] << " "; 
		std::cout << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
    main0();
    Array<int>  arr;
    std::cout << "array size: " << arr.size() << std::endl;
    arr = Array<int>(10);
    std::cout << "array size: " << arr.size() << std::endl;
    for (unsigned int i = 0; i < arr.size(); i ++) {
        arr[i] = rand() % 10;
    }
    for (unsigned int i = 0; i < arr.size(); i ++) {
        std::cout << arr[i] << " - ";
    }
    std::cout << std::endl;
	return (0);
}

int main() {
    main1();
    while (1) ;
}