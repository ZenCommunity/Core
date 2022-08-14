#ifndef CORE_NETWORK_H
#define CORE_NETWORK_H

class Network {
protected:
    short port = 0;
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
        port = boost::lexical_cast<short>(input);
    }
    /**
     * Run
     * @return void
     */
    void run() {
        boost::asio::io_context io_context;
        Server server(io_context, getPort());
        boost::thread network_thread(boost::bind(&boost::asio::io_context::run, &io_context));
        network_thread.detach();
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
    short getPort()
    {
        return port;
    }
};
#endif
