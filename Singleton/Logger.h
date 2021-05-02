//
// Created by erdem on 5/2/2021.
//

#ifndef OOP_LOGGER_H
#define OOP_LOGGER_H

#include <string>
#include <fstream>
#include <mutex>

class ILogger {
public:
    virtual int logMessage(std::string msg) = 0;
    virtual int logSync(void) = 0;
};

class FileLogger : public ILogger{
private:
    const std::string fileName = "logs.txt";
    const bool isTimestampEnabled = 1;
    std::ofstream file;
    std::string getTimestampAsString(void);

    static FileLogger* instance;
    static std::mutex mutex_;

    FileLogger();

public:

    static FileLogger * getFileLogger();

    int logMessage(std::string msg) override;

    int logSync(void) override;

    ~FileLogger();
};

#endif //OOP_LOGGER_H
