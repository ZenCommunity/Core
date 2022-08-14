#ifndef CORE_ENVIRONMENT_H
#define CORE_ENVIRONMENT_H

class Environment {
protected:
    bool checked = false;
public:
    /**
     * Check property
     * @param name
     */
    static void checkProperty(const std::string & name)
    {
        if (hasProperty(name)) {
            std::cout << "— " << name << " is OK." << std::endl;
        } else {
            std::cout << "— " << name << " is NOT OK." << std::endl;
            exit(1);
        }
    }
    /**
     * Has property
     * @param name
     * @return
     */
    static bool hasProperty(const std::string & name)
    {
        return std::getenv(name.c_str()) != nullptr;
    }
    /**
     * Check
     * @return void
     */
    void check()
    {
        std::cout << "Environment Checking ..." << std::endl;
        checkProperty("APP_ENV");
        checkProperty("APP_PORT");
        std::cout << "Environment Checked ..." << std::endl;
        checked = true;
    }
};

#endif
