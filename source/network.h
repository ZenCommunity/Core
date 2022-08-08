#ifndef CORE_NETWORK_H
#define CORE_NETWORK_H

class Network {
protected:
    int port = 0;
    bool running = false;
public:
    /**
     * Network constructor
     */
    Network() {
        configurePort();
    }
    /**
     * Configure port
     * @return void
     */
    void configurePort() {
        std::string input(std::getenv("APP_PORT"));
        port = std::stoi(input);
    }
    /**
     * Run
     * @return void
     */
    void run() {
        running = true;
    }
    /**
     * Get running
     * @return bool
     */
    bool getRunning()
    {
        return running;
    }
    /**
     * Get port
     * @return int
     */
    int getPort()
    {
        return port;
    }
};

#endif
