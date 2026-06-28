#include <iostream>

int main()
{
	std::cout << "Hello!" << std::endl;

	int x = 0;
	int y = 0;
	int c = 0;
	char op;
	while (true)
	{
		std::cout << "choose an operation (+ - * /): ";
		std::cin >> op;

		if (op == 'q')
		{
			std::cout << "goodbye" << std::endl;
			break;
		}

		std::cout << "enter 2 numbers: ";
		std::cin >> x;
		std::cin >> y;

		
		if (op == '+')
		{
			std::cout << "result: " << x + y << std::endl;
		}
		if (op == '-')
		{
			std::cout << "result: " << x - y << std::endl;
		}
		if (op == '*')
		{
			std::cout << "result: " << x * y << std::endl;
		}
		if (op == '/' && y != 0)
		{
			std::cout << "result: " << x / y << std::endl;
		}
		else
		{
			std::cout << "division by zero!!!" << std::endl;
			continue;
		}
	}

	return 0;
}
