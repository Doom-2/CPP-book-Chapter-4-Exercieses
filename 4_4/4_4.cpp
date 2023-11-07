
#include <std_lib_facilities.h>

int main()
{
    int lower = 1; // нижняя граница диапазона
    int upper = 100; // верхняя граница
    int middle; // середина

    char answer;

    while (lower < upper)
    {
        middle = (upper + lower) / 2;

        do
        {
            std::cout << "Is it less or equal then " << middle << "? (y/n)";
            std::cin >> answer;
        } while (answer != 'y' && answer != 'n');

        if (answer == 'y')
            upper = middle;
        else
            lower = middle + 1;

        std::cout << "[" << lower << " : " << upper << "]\n";
    }

    std::cout << "Your number is  " << upper << "\n";

}