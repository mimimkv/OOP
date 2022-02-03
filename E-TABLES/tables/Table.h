#pragma once 

#include <vector>
#include "Cell.h"
#include "CellFactory.h"

class Table
{
private:
    std::vector<std::vector<Cell*>> table;
    int maxLength[26] = {0, }; ///> Maximum length for each column
    size_t maxRows, maxCols;///>Maximum rows and columns of a table

    void copy(const Table& other);

    int countDigits(int num) const;///>Counts digits of a number
    std::vector<std::string> split(std::string& line, const char delimeter) const;
    int countLines(std::istream& in) const; ///>Count lines of a file/stream


public:
    Table();
    Table(const Table& other); ///<Copy constructor
    Table& operator =(const Table& other);///>Copy assignment
    ~Table();///>Destructor, clears table contents
    void save(std::ostream& out);///>Saves the data
    void read(std::istream& in); ///> Opens, reads file and loads it into memory
    void edit(size_t row, size_t col, std::string& data);///<Edits value of a cell with the data which could be any type
    void close();///>Closes currently opened file and clears the table
    
    friend std::ostream& operator << (std::ostream& out, const Table& table); ///>Prints table contents
};

// cols <= 26 A-Z