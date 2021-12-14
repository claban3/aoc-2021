#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>

int main(int argc, char** argv)
{
    long total_depth = 0;
    long total_distance = 0;

    std::string str_direction;
    int magnitude; 
	while (std::cin >> str_direction && std::cin >> magnitude)
    {
        if (str_direction == "forward")
        {
            total_distance += magnitude;
        }
        else if (str_direction == "up")
        {
            total_depth -= magnitude;
        }
        else if (str_direction == "down")
        {
            total_depth += magnitude;
        }
	}

    std::cout << "Total depth: " << total_depth << std::endl;
    std::cout << "Total distance: " << total_distance << std::endl;
    std::cout << "Depth x distance: " << total_depth * total_distance << std::endl;
	return 1;
}
