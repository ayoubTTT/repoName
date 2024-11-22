# repoName
```c
#include <iostream>

bool isChar(std::string &str)
{
    if (str.length() == 1 && std::isprint(str[0]))
    {
        if (!isdigit(str[0]))
        {
            {
                std::cout << "char: " << str << std::endl;
                int n = static_cast<int>(str[0]);
                std::cout <<  "int: " << n << std::endl;
                float f = static_cast<float>(str[0]);
                std::cout << " float: " << f << std::endl;
                double d = static_cast<double>(str[0]);
                std::cout << "double: " << d << std::endl;
            }
			return true;
        }
    }
	return false;
}

bool isInt(std::string &str)
{
	int i = 0;
    if (str.empty())
        return (false);
	if (str[0] == '+' || str[0] == '-')
		i++;
	for (;i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool isFloat(std::string &str)
{
    int i = 0;
    int check = 0;
    if (str.size() < 3)
        return false;

    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;
	if (str[0] == '+' || str[0] == '-')
		i++;
    while (str[i] && str[i] != '.' && std::isdigit(str[i]))
        i++;
    if (std::isalpha(str[i]))
        return false;
    if (str[i] == '.' && (check += 1))
        i++;
    while(str[i] && std::isdigit(str[i  ]))
        i++;
    if (str[i] == 'f' && i == str.size() - 1 && check == 1)
        return true;
    return false;
}

bool isDouble(std::string &str)
{
    int i = 0;
    bool point = false;
    if (str.empty())
        return false;
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;
	if (str[0] == '+' || str[0] == '-')
		i++;
    while (str[i] && str[i] != '.' && std::isdigit(str[i]))
        i++;
    if (std::isalpha(str[i]))
        return false;
    if (str[i] == '.' && (point = true))
        i++;
    while(str[i] && std::isdigit(str[i]))
        i++;
    if (point && str[i] == '\0')
        return true;
    return false;
}



void ScalarConverter(std::string str)
{
	if (isChar(str))
		std::cout << "char" << std::endl;
	else if (isInt(str))
		std::cout << "int" << std::endl;
	else if (isFloat(str))
		std::cout << "float" << std::endl;
    else if (isDouble(str))
		std::cout << "double" << std::endl;
	else
		std::cout << "error" << std::endl;
}

#include <sstream>

int main(int ac, char **av)
{
    float a = 2.f;
    std::cout << a << std::endl;
    
	/*
    std::stringstream a("555.5f");
    double s;

    a >> s;
    std::cout << s << std::endl;
	*/
	while (1)
	{
		std::string s;
		std::cin >> s;
		if (s == "break")
			exit(0);
		ScalarConverter(std::string(s));
	}
	}
```
