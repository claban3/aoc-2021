#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>

int main(int argc, char** argv)
{
    int c_increases = 0;
    int current = INT16_MAX; 
    int next = INT16_MIN;
    while (std::cin >> next)
    {
        c_increases += next > current ? 1 : 0;
        current = next;
    }

    std::cout << "Total number of increases: " << c_increases << std::endl;
	return 1;
}
