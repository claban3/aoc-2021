#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <bitset>

using bigint_t = unsigned long long;
const int BITSET_LENGTH = 12;

static size_t find_bit_flip(size_t i_start, size_t i_end, size_t o_shift, const std::vector<std::bitset<BITSET_LENGTH>>& vec_positions)
{
    for (size_t i = i_start; i < i_end - 1; ++i)
    {
        if ((vec_positions[i][o_shift]) != (vec_positions[i + 1][o_shift]))
        {
            return i + 1;
        }
    }
    return i_start;
}

template <typename Compare>
static std::string find_resource(const std::vector<std::bitset<BITSET_LENGTH>>& vec_positions, Compare op = Compare{})
{
    size_t i_start = 0;
    size_t i_end = vec_positions.size() - 1;
    int o_shift = BITSET_LENGTH - 1;
    std::bitset<BITSET_LENGTH> resource;
    while (i_start < i_end && o_shift >= 0)
    {
        size_t i_flip = find_bit_flip(i_start, i_end, o_shift, vec_positions);

        // std::cout << "Start: " << i_start << "   End: " << i_end << "   Offset: " << o_shift << std::endl;
        // std::cout << "index flip: " << i_flip << std::endl;
        size_t c_before_flip = i_flip - i_start;
        size_t c_after_flip = i_end - i_flip - 1;
        if (op(c_before_flip, c_after_flip))
        {
            // std::cout << "branch one: " << vec_positions[i_flip].to_string() << " " << vec_positions[i_start][o_shift] << std::endl; 
            resource[o_shift] = vec_positions[i_start][o_shift];
            i_end = i_flip;
        }
        else
        {
            // std::cout << "branch two: " << vec_positions[i_flip].to_string() << " " << vec_positions[i_flip][o_shift] << std::endl; 
            resource[o_shift] = vec_positions[i_flip][o_shift];
            i_start = i_flip;
        }

        o_shift--;
    }
    
    return resource.to_string();
}

int main(int argc, char** argv)
{
    std::vector<std::bitset<BITSET_LENGTH>> vec_positions;
    std::string str_bitset;
    while (std::cin >> str_bitset)
    {
        vec_positions.push_back(std::bitset<BITSET_LENGTH>(str_bitset));
    }

    std::sort(vec_positions.begin(), vec_positions.end(), 
        [](const auto& lhs, const auto& rhs)
        {
            return lhs.to_ullong() <= rhs.to_ullong();
        });

    using oxygen_compare = std::greater_equal<>;
    using co2_compare = std::less<>;
    std::cout << "no seg" << std::endl;
    std::string oxygen = find_resource<oxygen_compare>(vec_positions);
    std::string co2 = find_resource<co2_compare>(vec_positions);

    std::cout << "Oxygen: " << oxygen << std::endl;
    std::cout << "CO2: " << co2 << std::endl;
    std::cout << "Oxygen x CO2: " << std::bitset<BITSET_LENGTH>(oxygen).to_ullong() * std::bitset<BITSET_LENGTH>(co2).to_ullong() << std::endl;
}
