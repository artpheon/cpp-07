# include "iter.hpp"
#include <iostream>

class   Test {
	private:
		std::string _str;
		int _int;
	public:
		Test() {
			setStr("");
			setInt(0);
		}
		Test&    setStr(const std::string& s) {
			_str = s;
			return *this;
		}
		Test&    setInt(int i) {
			_int = i;
			return *this;
		}
		const std::string& getStr() const {
			return _str;
		}
		int getInt() const {
			return _int;
		}
		Test(const std::string& s, int i) {
			setStr(s);
			setInt(i);
		}
		~Test() {};
		Test&	operator=(const Test& rhs) {
			if (this != &rhs) {
				setInt(rhs.getInt());
				setStr(rhs.getStr());
			}
			return *this;
		};
		Test(const Test& rhs) {
			*this = rhs;
		};
		void	show() const {
			std::cout << "Class containts int = " << getInt() << ", and string: " << getStr() << std::endl;
		}
};

void    charF(char*& word) {
	word[0] = '_';
}

void    intF(int& num) {
	num = num * 2;
}

void	classT(Test &test) {
	test.setInt(test.getInt() / 2);
	std::string rem = static_cast<std::string>(test.getStr());
	rem[0] = std::toupper(rem[0]);
	test.setStr(rem);
}

int test1() {
	char first[] = "first";
	char second[] = "second";
	char third[] = "third";
	std::cout << "Before iteration:" << std::endl;
	char* array[] = {first, second, third};
	for (int i = 0; i < 3; i++) {
		std::cout << array[i] << std::endl;
	}
	iter<char *>(array, 3, &charF);
	std::cout << "After iteration:" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << array[i] << std::endl;
	}
	return 0;
}

int test2() {
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "Int array before :";
	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " - ";
	}
	std::cout << std::endl;
	iter<int>(array, 10, &intF);

	std::cout << "Int array after :";
	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " - ";
	}
	std::cout << std::endl;
	return 0;
}

int test3() {
	Test *array = new Test[2];
	array[0].setInt(100).setStr("hello");
	array[1].setInt(555).setStr("goodbye");
	std::cout << "Before iteration:" << std::endl;
	array[0].show();
	array[1].show();
	std::cout << "After iteration:" << std::endl;
	iter<Test>(array, 2, &classT);
	array[0].show();
	array[1].show();
	delete [] array;
	return 0;
}

int main() {
	test1();
	test2();
	test3();
	return 0;
}