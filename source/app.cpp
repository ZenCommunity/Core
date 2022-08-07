#include <iostream>
#include <cstdlib>
#include "about.h"

int main() {
    About about;
    std::cout << about.getName() << " " << about.getType() << " on " << about.getBuild() << " at " << about.getVersion() << "." << std::endl;
    std::cout << "Created by " << about.getAuthor() << " <" << about.getContact() << ">." << std::endl;

    std::cout << "Running ..." << std::endl;
    return 0;
}
