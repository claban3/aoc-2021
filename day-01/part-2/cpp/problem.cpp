#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>

class Window
{
public:
    int two;
    int one;
    int three;
};

static Window init()
{
    Window w;
    std::cin >> w.one;
    std::cin >> w.two;
    std::cin >> w.three;
    return w;
}

static bool advance(Window& r_current, Window& r_next)
{
    r_next.one = r_current.two;
    r_next.two = r_current.three;
    return !(std::cin >> r_next.three).eof();
}

static int sum(const Window& window)
{
    return window.one + window.two + window.three;
}

int main(int argc, char** argv)
{
    int c_increases = 0;
    Window current = init();
    Window next;
    while (advance(current, next))
    {
        c_increases += sum(next) > sum(current) ? 1 : 0;
        current = next;
    }

    std::cout << "Total number of increases: " << c_increases << std::endl;
	return 1;
}
