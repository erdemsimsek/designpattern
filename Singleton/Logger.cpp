//
// Created by erdem on 5/2/2021.
//

#include "Logger.h"

#include <iomanip>
#include <ctime>
#include <iostream>

FileLogger::FileLogger() {
    file.open(fileName, std::ios::out);
}

std::string FileLogger::getTimestampAsString(void) {
    std::stringstream ss;

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    ss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    return ss.str();
}

int FileLogger::logMessage(std::string msg) {
    file << getTimestampAsString();
    file << std::setw(5) << " " << msg;
    return 0;
}

int FileLogger::logSync(void) {
    file.flush();
    return 0;
}

FileLogger::~FileLogger() {
    file.close();
}

FileLogger * FileLogger::instance = nullptr;

FileLogger *FileLogger::getFileLogger() {

    mutex_.lock();

    if(nullptr == instance){
        instance = new FileLogger();
    }

    mutex_.unlock();

    return instance;
}


std::mutex FileLogger::mutex_;

