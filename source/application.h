#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

class Application {
protected:
    About about;
    Authorization authorization;
    Environment environment;
    Network network;
public:
    Application() = default;
    /**
     * Bootstrap
     */
    void boot()
    {
        about.render();
        environment.check();
        network.run();
        std::cout << "Running ..." << std::endl;
    }
};

#endif
