#include "headers.h"

int main() {
    About about;
    std::cout << about.getName() << " " << about.getType() << " on " << about.getBuild() << " at " << about.getVersion() << "." << std::endl;
    std::cout << "Created by " << about.getAuthor() << " <" << about.getContact() << ">." << std::endl;
    std::cout << "All Rights Reserved. Distributed with License " << about.getLicense() << "." << std::endl;
    About::check();
    Authorization authorization;
    Network network;
    network.run();
    std::cout << "Running ..." << std::endl;
    return 0;
}
