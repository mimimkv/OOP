#include "Table.h"

Table::Table() : maxRows(0), maxCols(0)
{
    for (int i = 0; i < 26; ++i)
    {
        maxLength[i] = 1;
    }
}

void Table::copy(const Table& other)
{
    for(int i = 0; i < other.table.size(); ++i)
    {
        table.push_back(std::vector<Cell*>()); // empty 
        for(Cell* cell : other.table[i])
        {
            table[i].push_back(cell->clone(table));
        }
    }

    this->maxRows = other.maxRows;

    for (int i = 0; i < 26; ++i)
        this->maxLength[i] = other.maxLength[i];
}

Table::Table(const Table& other)
{
    copy(other);
}

Table& Table::operator =(const Table& other)
{
    if (&other != this)
    {
        copy(other);
    }
    return *this;
}

Table::~Table()
{
    close();
}




void Table::edit(size_t row, size_t col, std::string& data)
{
    if ( col >= 26 || col < 0 || row < 0)
    {
        std::cout << "Index not in the range!";
        return;
    }

    
    // both row and col are out of bounds of the current table
    if (row + 1 > table.size() && col + 1 > maxCols)
    {
        for (int i = maxRows; i < row + 1; ++i)
        {
            table.push_back(std::vector<Cell*>());
            table[i].resize( col + 1 , nullptr);
        }
        maxRows = row + 1;
        maxCols = col + 1;
    }
    else if (row + 1 > table.size()) // only row is out of bounds of the current table
    {
        for (int i = maxRows; i < row + 1; ++i)
        {
            table.push_back(std::vector<Cell*>());
            table[i].resize( col + 1 , nullptr);
        }
        maxRows = row + 1;
    }
    else if (col + 1 > maxCols) // only col is out of the bounds of the current table
    {
        for (int i = 0; i < row + 1; ++i)
        {
            table[i].resize( col + 1 , nullptr);
        }
        maxCols = col + 1;
    }
    

    Cell* ptr = CellFactory::make(data, table);
    if (ptr == nullptr)
    {
        std::cout << "Unknown type!\n";
        std::cout << "Tip: If you enter string, please use \"\"\n";
        return;
    }
    if (table[row][col] != nullptr)
        delete table[row][col];

    if (ptr != nullptr)
    {
        table[row][col] = ptr;
        std::cout << "Successfully edited " << (char)(col + 'a') << 
                      row + 1 << " to ";
        ptr->print(std::cout);
        std::cout << std::endl;

        if (maxLength[col] < ptr->getLength()) 
            maxLength[col] = ptr->getLength();
        else
        {
            maxLength[col] = 1;
            for (int i = 0; i < maxRows; ++i)
            {
                if (table[i][col] != nullptr && table[i][col]->getLength() > maxLength[col])
                {
                    maxLength[col] = table[i][col]->getLength();
                }
            }
        }            
    }
}

int Table::countDigits(int num) const
{
    int counter = 1;
    while(num > 9)
    {
        num /= 10;
        counter++;
    }
    return counter;
}

std::ostream& operator << (std::ostream& out, const Table& t)
{
    std::cout << '\n';

    int countMaxDigits = t.countDigits(t.maxRows);

    for(int i = 0; i < countMaxDigits + 1; ++i)
        out << ' ';

    out << '|';

    for(int i = 0; i < t.maxCols; ++i)
    {
        int spaces = t.maxLength[i] - 1;
        for (int j = 0; j < spaces; ++j)
            out << ' ';
        out << (char)(i + 'A') << '|';
    }
    out << std::endl;

    //=====================

    for (int i = 0; i < t.table.size(); ++i) 
    {
        int numSpaces = countMaxDigits - t.countDigits(i);
        for(int k = 0; k < numSpaces; ++k)
            out << ' ';
        out << i + 1 << " |";

        for (int j = 0; j < t.maxCols; ++j)
        {
            if (j < t.table[i].size() && t.table[i][j] != nullptr)
            {
                int spaces = t.maxLength[j] - t.table[i][j]->getLength();
                for (int k = 0; k < spaces; ++k)
                    out << ' ';

                t.table[i][j]->print(out);
            }
            else
            {
                int spaces = t.maxLength[j];
                for (int k = 0; k < spaces; ++k)
                    out << ' ';
            }

            out << '|';
        }
        out << std::endl;
    }

    return out;
}

std::vector<std::string> Table::split(std::string& line, const char delimeter) const
{
    std::vector<std::string> result;
    std::string word = "";
    bool openedQuotes = false;
    for (size_t i = 0; i < line.size(); ++i)
    {
        if (line[i] == delimeter)
        {
            if (openedQuotes)
            {
                word.push_back(line[i]);
                continue;
            }
            if (!openedQuotes)
                result.push_back(word);
            word = "";
        }
        else
        {
            if (line[i] == '"' && !openedQuotes)
                openedQuotes = true;
            else if (line[i] == '"' && openedQuotes)
                openedQuotes = false;
            word.push_back(line[i]);
        }
    }
    result.push_back(word);
    return result;
}

int Table::countLines(std::istream& in) const
{
    int counter = 0;
    while(!in.eof())
    {
        std::string str;
        getline(in, str);
        counter++;
    }

    return counter;
}

void Table::close()
{
 
    for(std::vector <Cell *> &col : table)
    {
        for(Cell * row: col)
        {
            delete row;
        }
        col.clear();
    }
    table.clear();
    for(int i = 0; i < 26; ++i)
        maxLength[i] = 0;
    maxCols = 0;
    maxRows = 0;
    std::cout << "Successfully closed file!\n";
}


void Table::read(std::istream& in)
{
    int counter = countLines(in);
    in.seekg(0, std::ios::beg);
    for (int i = 0; i < counter; ++i)
    {
        std::string str;
        getline(in, str, '\n');
        

        table.push_back(std::vector<Cell*>());

        std::vector<std::string> objects = split(str, ',');
        
       // for (int i = 0; i < objects.size(); ++i)
       //     std::cout << objects[i] << "    ";

        if (objects.size() > maxCols)
            maxCols = objects.size();


        for(int i = 0; i < objects.size(); ++i)
        {

            Cell* ptr = CellFactory::make(objects[i], table);

            if (ptr == nullptr && !objects[i].empty())
            {
                std::cout << "Row: " << table.size() << " Col: " <<
                             i + 1<< ", " << objects[i] << " is unknown data type\n"; 
            }
            table[table.size() - 1].push_back(ptr);

            if (ptr != nullptr && ptr->getLength() > maxLength[i])
                maxLength[i] = ptr->getLength();

        }

    }
    maxRows = table.size();
}


void Table::save(std::ostream& out) 
{
    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < table[i].size(); ++j)
        {

            if (table[i][j] != nullptr)
                table[i][j]->save(out);

            if (j < table[i].size() - 1)
                out << ',';
        }
        if (i < table.size() - 1)
            out << std::endl;
    }
}