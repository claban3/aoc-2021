#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <bitset>

int main(int argc, char** argv)
{
    const int BITSET_LENGTH = 12;
    int c_lines_of_input = 0;
    std::vector<int> vec_bit_sums(BITSET_LENGTH, 0);
    std::string str_bitset;
    while (std::cin >> str_bitset)
    {
        ++c_lines_of_input;
        std::bitset<BITSET_LENGTH> current = std::bitset<BITSET_LENGTH>(str_bitset);
        for (size_t i = 0; i < BITSET_LENGTH; ++i)
        {
            vec_bit_sums[i] += current[i];
        }
    }

    std::bitset<BITSET_LENGTH> gamma, epsilon;
    for (size_t i = 0; i < BITSET_LENGTH; ++i)
    {
        gamma[i] = (vec_bit_sums[i] > (c_lines_of_input / 2)) ? 1 : 0;
        epsilon[i] = (vec_bit_sums[i] < (c_lines_of_input / 2)) ? 1 : 0;
    }

    std::cout << "Gamma: " << gamma.to_ulong() << std::endl;
    std::cout << "Epsilon: " << epsilon.to_ulong() << std::endl;
    std::cout << "Gamma x Epsilon: " << gamma.to_ulong() * epsilon.to_ulong() << std::endl;
}
