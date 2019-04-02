#include "../value_bag.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	int value1 = 100;
	int value2 = 200;

	auto d = m2d::default_value_bag<int>(value1, 0);
	std::cout << "default peek : " << d.peek() << std::endl;
	std::cout << "default take : " << d.take() << std::endl;
	std::cout << "default take : " << d.take() << std::endl;
	std::cout << "default set : " << value2 << std::endl;
	d.set(value2);
	std::cout << "default take : " << d.take() << std::endl;
	std::cout << "default take : " << d.take() << std::endl;
	std::cout << "----" << std::endl;

	auto t = m2d::toggle_value_bag<int>(value1, value2);
	std::cout << "toggle : value1 = 100, value2 = 200" << std::endl;
	std::cout << "toggle peek : " << t.peek() << std::endl;
	std::cout << "toggle take : " << t.take() << std::endl;
	std::cout << "toggle take : " << t.take() << std::endl;
	std::cout << "toggle take : " << t.take() << std::endl;
	std::cout << "toggle : the value becomes 200." << std::endl;
	t.toggle();
	std::cout << "toggle take : " << t.take() << std::endl;
	std::cout << "----" << std::endl;

	auto o = m2d::once_value_bag<int>(value1, 0);
	std::cout << "once peek : " << o.peek() << std::endl;
	std::cout << "once take : " << o.take() << std::endl;
	std::cout << "once take : " << o.take() << std::endl;
	std::cout << "once set : " << value2 << std::endl;
	o.set(value2);
	std::cout << "once take : " << o.take() << std::endl;
	std::cout << "----" << std::endl;

	return 0;
}
