#include <iostream>
#include <cstdlib>
#include "about.h"

int main() {
    About about;
    std::cout << about.getName() << " " << about.getType() << " on " << About::getBuild() << " at " << about.getVersion() << "." << std::endl;
    std::cout << "Created by " << about.getAuthor() << " <" << about.getContact() << ">." << std::endl;
    std::cout << "All Rights Reserved. Distributed with License " << about.getLicense() << "." << std::endl;

    std::cout << "Running ..." << std::endl;
    return 0;
}
