#pragma once 

#include <vector>
#include "Cell.h"
#include "CellFactory.h"

class Table
{
private:
    std::vector<std::vector<Cell*>> table;
    int maxLength[26] = {0, }; // maximum length for each column
    size_t maxRows, maxCols;

    void copy(const Table& other);

    int countDigits(int num) const; 
    std::vector<std::string> split(std::string& line, const char delimeter) const;
    int countLines(std::istream& in) const;


public:
    Table();
    Table(const Table& other);
    Table& operator =(const Table& other);
    ~Table();
    void save(std::ostream& out);
    void read(std::istream& in); // opens and reads file
    void edit(size_t row, size_t col, std::string& data);
    void close();
    
    friend std::ostream& operator << (std::ostream& out, const Table& table);
};

// cols <= 26 A-Z