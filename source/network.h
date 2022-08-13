#ifndef CORE_NETWORK_H
#define CORE_NETWORK_H

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    Session(tcp::socket socket) : socket_(std::move(socket)) {}
    /**
     * Start
     */
    void start() {
        read();
    }
private:
    /**
     * Read
     */
    void read() {
        auto self(shared_from_this());
        socket_.async_read_some(boost::asio::buffer(data_),
                                [this, self](boost::system::error_code error, std::size_t length) {
                                    if (!error) {
                                        write(length);
                                    } else {
                                        disconnect();
                                    }
                                });
    }
    /**
     * Write
     * @param length
     */
    void write(std::size_t length) {
        auto self(shared_from_this());
        boost::asio::async_write(socket_, boost::asio::buffer(data_),
                                 [this, self](boost::system::error_code error, std::size_t /*length*/)
                                 {
                                     if (!error) {
                                         read();
                                     } else {
                                         disconnect();
                                     }
                                 });
    }
    /**
     * Disconnect
     */
    void disconnect() {
        socket_.close();
    }
    tcp::socket socket_;
    char data_[4096];
};

class Server
{
public:
    Server(boost::asio::io_context& io_context, short port)
            : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
    {
        accept();
    }

private:
    /**
     * Accept
     */
    void accept()
    {
        acceptor_.async_accept(
                [this](const boost::system::error_code& error, tcp::socket socket)
                {
                    if (!error)
                    {
                        std::make_shared<Session>(std::move(socket))->start();
                    }
                    accept();
                });
    }
    tcp::acceptor acceptor_;
};

class Network {
protected:
    unsigned short port = 0;
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
        port = boost::lexical_cast<unsigned short>(input);
    }
    /**
     * Run
     * @return void
     */
    void run() {
        boost::asio::io_context io_context;
        Server server(io_context, getPort());
        io_context.run();
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
