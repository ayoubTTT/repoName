#include "ScalarConverter.hpp"

bool isChar(std::string const &str)
{
    if (str.size() != 1 || isdigit(str[0]))
        return (false);
    return true;
}

bool isInt(std::string const &str)
{
    int i = 0;
    int len = str.size();

    if (str.empty())
        return (false);
    if (str[i] == '+' || str[i] == '-')
        i++;
    for(; i < len ; i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool isFloat(std::string const &str)
{
    int i = 0;
    bool flag = false;
    int len = str.size();

    if (str.empty())
        return (false);
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;
    if (str[i] == '+' || str[i] == '-')
        i++;
    for(; i < len ; i++)
    {
        if (str[i] == '.' && !flag)
            flag = true;
        else if ((str[i] == '.' && flag) \
        || (str[i] == 'f' && i != len - 1) \
        || (!isdigit(str[i]) && (str[i] != 'f' && str[i] != '.')))
            return (false);
    }
    if(str[len - 1] != 'f')
        flag = false;
    return (flag);
}

bool isDouble(std::string const &str)
{
    int i = 0;
    bool flag = false;
    int len = str.size();

    if (str.empty())
        return (false);
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;
    if (str[i] == '+' || str[i] == '-')
        i++;
    for(; i < len ; i++)
    {
        if (str[i] == '.' && !flag)
            flag = true;
        else if ((str[i] == '.' && flag) || (!isdigit(str[i]) && str[i] != '.'))
            return (false);
    }
    return (true);
}


void ScalarConverter::disply(float f)
{
    if (std::isnan(f) || std::isinf(f))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        char c = static_cast<char>(f);
        if (!isprint(c))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    std::string s;
    if (static_cast<double>(f) - static_cast<int>(f) == 0.0)
        s = ".0f";
    else
        s = "f";
    std::cout << "float: " << f << s << std::endl;
     s.erase(s.size() - 1, s.size());
    std::cout << "double: " << static_cast<double>(f) << s << std::endl;
}

void ScalarConverter::disply(double d)
{
    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        char c = static_cast<char>(d);
        if (!isprint(c))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    std::string s;
    if (static_cast<double>(d) - static_cast<int>(d) == 0.0)
        s = ".0f";
    else
        s = "f";
    std::cout << "float: " << static_cast<double>(d) << s << std::endl;
    s.erase(s.size() - 1, s.size());
    std::cout << "double: " << d  << s << std::endl;
}


void ScalarConverter::disply(int i)
{
    char c = static_cast<char>(i);
    if (!isprint(c))
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0"<< std::endl;
}

void ScalarConverter::disply(char c)
{
    if (!isprint(c))
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0"<< std::endl;
}

void ScalarConverter::convert(std::string const &str)
{
    if (isChar(str))
        disply(str[0]);
    else if (isInt(str))
        disply(atoi(str.c_str()));
    else if (isFloat(str))
        disply(strtof(str.c_str(),NULL));
    else if (isDouble(str))
        disply(strtod(str.c_str(),NULL));
    else
        std::cout << "impossible to convert" << std::endl;
}
