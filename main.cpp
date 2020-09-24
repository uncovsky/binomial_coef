#include "binomial.h"

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        std::cout << "Please input 2 numbers for the binomial coefficient in the supported format (n, k ; n >= k)";
        return 0;
    }
    else
    {
        try
        {
            std::cout << binomial_coefficient(std::stoi(argv[1]), std::stoi(argv[2]));
            std::cout << std::endl;
        }
        catch (const char *e)
        {
            std::cerr << e << '\n';
            return 0;
        }
    }

    return 0;
}
