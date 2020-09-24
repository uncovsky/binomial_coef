#include "binomial.h"

std::string add_nums(std::string num1, std::string num2)
{
    int carry = 0, digit = 0;
    std::string result;
    if (num1.length() < num2.length())
        std::swap(num1, num2);
    for (int i = 1; i <= num1.length(); ++i)
    {
        if (i > num2.length())
            digit = num1[num1.length() - i] + carry - '0';
        else
            digit = num2[num2.length() - i] + num1[num1.length() - i] + carry - 2 * '0';
        carry = digit / 10;
        digit %= 10;

        result += (digit + '0');
    }

    result += (carry) ? (std::to_string(carry)) : "";
    std::reverse(result.begin(), result.end());

    return result;
}

std::string multiply_nums(std::string num1, std::string num2)
{
    std::string result = "", temp = "";
    int digit = 0, carry = 0;

    if (num1.length() < num2.length())
        std::swap(num1, num2);

    for (int i = 1; i <= num2.length(); ++i)
    {
        int multiplier = (num2[num2.length() - i] - '0');
        for (int it = num1.length() - 1; it >= 0; --it)
        {

            digit = multiplier * (num1[it] - '0') + carry;
            carry = digit / 10;
            digit %= 10;

            temp += (digit + '0');
        }

        if (carry > 0)
        {
            temp += std::to_string(carry);
            carry = 0;
        }

        std::reverse(temp.begin(), temp.end());
        for (int it = 0; it < i - 1; ++it)
            temp += '0';

        result = add_nums(result, temp);
        temp.clear();
    }

    return result;
}

std::string huge_fact(int n, int k = 1)
{
    std::string result = "1";
    for (int i = k + 1; i <= n; ++i)
    {
        result = multiply_nums(result, std::to_string(i));
    }

    return result;
}

std::string divide_num(std::string num, int divisor)
{
    std::string temp, result;
    if (divisor == 0)
        throw "undefined behavior, division by 0";
    else if (divisor == 1)
        return num;
    else
    {
        for (int i = 0; i < num.length(); ++i)
        {
            temp += num[i];
            if (std::stoi(temp) >= divisor)
            {
                result += (char)(std::stoi(temp) / divisor) + '0';
                temp = (std::stoi(temp) % divisor) > 0 ? std::to_string(std::stoi(temp) % divisor) : "";
            }
            else
            {
                result += "0";
            }
        }
        return result;
    }
}

std::string binomial_coefficient(unsigned int n, unsigned int k)
{
    if (k > n)
        throw "please input nums in correct format (n >= k) binomial_coefficient(n,k)";
    std::string numerator = huge_fact(n, n - k);
    std::string denominator = huge_fact(k);

    /*
    std::cout << std::setw(5) << n << "!\n";
    std::cout << "−−−−−−−−\n";
    std::cout << k << "!(" << n << "-" << k << ")!\n\n";

    std::cout << std::setw(5) << numerator << "\n";
    std::cout << "−−−−−−−−\n";
    std::cout << std::setw(5) << denominator << "\n\n";
    */

    for (int i = 2; i <= k; ++i)
    {
        try
        {
            numerator = divide_num(numerator, i);
        }
        catch (const char *msg)
        {
            std::cout << msg << std::endl;
        }
    }

    numerator.erase(0, numerator.find_first_not_of('0'));
    return numerator;
}