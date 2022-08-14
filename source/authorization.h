#ifndef CORE_AUTHORIZATION_H
#define CORE_AUTHORIZATION_H


class Authorization {
private:
    std::string token;
public:
    /**
     * Authorization constructor
     */
    Authorization() {
        generateToken();
    }
    /**
     * Get token
     * @return string
     */
    std::string getToken() {
        return token;
    }
    /**
     * Generate token
     * @return void
     */
    void generateToken() {
        if (token.empty()) {
            token = boost::uuids::to_string(boost::uuids::random_generator()());
        }
    }
};

#endif
