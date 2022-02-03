#pragma once

#include "table.h"
#include <vector>
#include <string>
#include <fstream>

class System
{
private:
    Table tab;
    std::string filePath;
    bool isOpen = false;
public:
    System();

    void setFile(const std::string& filePath);
    std::string getFile() const;

    void open(const std::string& filePath);
    void close();
    void edit(const std::string& location, std::string& data);
    void print();
    void save();
    void saveas(const std::string& filePath);
    void help() const;
};