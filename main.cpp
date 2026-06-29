#include <iostream>

int addition(int x, int y)
{

	return x + y;
}
int subtraction(int x, int y)
{
	return x - y;
}
int multiplication(int x, int y)
{
	return x * y;
}
int division(int x, int y)
{
	if (y != 0)
	{
		return x / y;
	}else{
		return 0;
	}
	
}
void printResult(int a, int b, int c, char operation)
{
	if (operation == '/' && b == 0)
	{	
		std::cout << "devision by zero" << std::endl;
		
	}
	else
	{
		std::cout << a << ' ' << operation << ' ' << b << " = " << c << '\n';
	}
}

int main()
{
	std::cout << "Hello!" << std::endl;

	int x = 0;
	int y = 0;
	int c = 0;
	char op;
	while (true)
	{
		std::cout << "choose an operation (+ - * / q): ";
		std::cin >> op;

		if (op == 'q')
		{
			std::cout << "goodbye!" << std::endl;
			break;
		}

		std::cout << "enter 2 numbers: ";
		std::cin >> x;
		std::cin >> y;
		if (op == '+')
		{
			c = addition(x, y);
			printResult(x, y, c, op);
		}
		if (op == '-')
		{
			c = subtraction(x, y);
			printResult(x, y, c, op);
		}
		if (op == '*')
		{
			c = multiplication(x, y);
			printResult(x, y, c, op);
		}
		if (op == '/')
		{
			c = division(x, y);
			printResult(x, y, c, op);
		}
	}

	return 0;
}
