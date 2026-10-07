#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i = 1;
    int j;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    return 0;
}