#ifndef CORE_SESSION_H
#define CORE_SESSION_H

class Session : public std::enable_shared_from_this<Session> {
public:
    Session(boost::asio::ip::tcp::socket socket) : socket_(std::move(socket)) {}
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
    boost::asio::ip::tcp::socket socket_;
    char data_[4096];
};

#endif
