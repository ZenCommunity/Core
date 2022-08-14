#ifndef CORE_SERVER_H
#define CORE_SERVER_H

class Server
{
public:
    Server(boost::asio::io_context& io_context, short port) : acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
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
                [this](const boost::system::error_code& error, boost::asio::ip::tcp::socket socket)
                {
                    if (!error)
                    {
                        std::make_shared<Session>(std::move(socket))->start();
                    }
                    accept();
                });
    }
    boost::asio::ip::tcp::acceptor acceptor_;
};

#endif
