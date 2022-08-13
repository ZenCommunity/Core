#ifndef CORE_ABOUT_H
#define CORE_ABOUT_H

class About {
protected:
    std::string name = "Core";
    std::string type = "Platform";
    std::string build;
    std::string author = "Ian Torres";
    std::string contact = "iantorres@outlook.com";
    std::string version = "1.0.1";
    std::string license = "CC BY-NC-ND";
public:
    /**
     * About constructor
     */
    About()
    {
        setBuild();
    }
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
    std::string getBuild()
    {
        return build;
    }
    /**
     * Set build
     */
    void setBuild()
    {
        build = std::getenv("APP_ENV");
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
    /**
     * Render
     */
    void render()
    {
        std::cout << getName() << " " << getType() << " on " << getBuild() << " at " << getVersion() << "." << std::endl;
        std::cout << "Created by " << getAuthor() << " <" << getContact() << ">." << std::endl;
        std::cout << "All Rights Reserved. Distributed with License " << getLicense() << "." << std::endl;
    }
};

#endif
