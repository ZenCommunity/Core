#ifndef CORE_ABOUT_H
#define CORE_ABOUT_H

class About {
protected:
    std::string name = "Core";
    std::string type = "Platform";
    std::string author = "Ian Torres";
    std::string contact = "iantorres@outlook.com";
    std::string version = "1.0.1";
    std::string license = "CC BY-NC-ND";
public:
    /**
     * Get name
     * @return string
     */
    std::string getName()
    {
        return name;
    }
    /**
     * Get type
     * @return string
     */
    std::string getType()
    {
        return type;
    }
    /**
     * Get version
     * @return string
     */
    std::string getVersion()
    {
        return version;
    }
    /**
     * Get license
     * @return string
     */
    std::string getLicense()
    {
        return license;
    }
    /**
     * Get build
     * @return string
     */
    static std::string getBuild()
    {
        char * mode = std::getenv("APP_MODE");
        if (mode == nullptr) {
            return "Debug";
        }
        std::string build(mode);
        return build;
    }
    /**
     * Get author
     * @return string
     */
    std::string getAuthor()
    {
        return author;
    }
    /**
     * Get contact
     * @return string
     */
    std::string getContact()
    {
        return contact;
    }
};

#endif
