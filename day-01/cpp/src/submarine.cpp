#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>

int main(int argc, char** argv) {
	std::vector<int> vec_depths;
	std::string str_line;
    uint16_t count_inc = 0;
	while (std::cin >> str_line) {
		std::stringstream ss(str_line);
		uint16_t depth;
		ss >> depth;
		vec_depths.push_back(depth);
	}

    auto itr_depth = vec_depths.begin();
    while (itr_depth != vec_depths.end())
    {
        int current = *itr_depth;
        std::advance(itr_depth, 1);
        if (itr_depth == vec_depths.end())
            break;

        int next = *itr_depth;        
        count_inc += next > current ? 1 : 0;
    }

    std::cout << count_inc << std::endl;
	return 1;
}
