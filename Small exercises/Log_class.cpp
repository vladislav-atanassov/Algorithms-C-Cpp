#include <iostream>

class Log
{
public:

    enum Level: unsigned char
    {
        Level_Error = 0,
        Level_Warning, 
        Level_Info
    };

private:
    Level m_Log_level = Level_Info;

public:

    void set_level_warning(Level level)
    {
        m_Log_level = level;
    }

    void error(const char* message)
    {
        if(m_Log_level >= Level_Error)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    void warning(const char* message)
    {
        if(m_Log_level >= Level_Warning)
            std::cout << "[WARNING]: " << message << std::endl;
    }    

    void info(const char* message)
    {
        if(m_Log_level >= Level_Info)
            std::cout << "[INFO]: " << message << std::endl;
    }
};

int main()
{
    Log log;

    log.set_level_warning(Log::Level_Error);
    
    log.error("Error!");
    log.warning("Warning!");
    log.info("Info!");

    std::cin.get();
}