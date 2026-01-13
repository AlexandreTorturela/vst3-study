#include <iostream>
#include <string>

int main()
{
    std::cout << "Hello from Windows binary built in WSL!" << std::endl;
    std::cout << "Press ENTER to exit..." << std::endl;

    std::string dummy;
    std::getline(std::cin, dummy);

    return 0;
}
