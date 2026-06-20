#include <iostream>
#include <unistd.h>

int main() {
    char* path = getcwd(nullptr, 0);

    if (!path) {
        return 1;
    }

    std::cout << path << "\n";

    delete path;
}
