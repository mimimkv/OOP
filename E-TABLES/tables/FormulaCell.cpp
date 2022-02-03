#include "FormulaCell.h"
#include <sstream>

bool FormulaCell::isInteger(double n) const
{
    // Convert float value
    // of n to integer
    int x = n;
    double temp = n - x;
 
    return !(temp > 0);
}

FormulaCell::FormulaCell(const std::string& _expression, std::vector< std::vector <Cell *> > &_table) : 
                         Cell(0), expression(_expression), table(_table)
{   
    length = 1;
    std::stringstream ss(expression);
    ss.get(); // ignore "=" sign in the beginning of the formula (=5+7)
    char ch;
    isValid = true;

    double result = secondPriority(ss);
    while (ss.peek() == '+' || ss.peek() == '-')
    {
        ss.get(ch);

        if (ch == '+')
            result += secondPriority(ss);
        else
            result -= secondPriority(ss);
    }

    if (isValid)
    {
        value = result;

        if (!isInteger(value))
        {
            std::string temp = std::to_string(result);
            length = temp.length();
        }
        else
        {
            int counter = 1;
            while(result > 9)
            {
                counter++;
                result /= 10;
            }

            length = counter;
        }
        
    }

}


void FormulaCell::save(std::ostream& out) const
{ 
    out << expression;
}

Cell *FormulaCell::clone(std::vector < std::vector<Cell *>>& _table)
{
    return new FormulaCell(expression, _table);
}

double FormulaCell::firstPriority(std::stringstream& ss)
{   
    char ch;
    double result = getNum(ss);
    while(ss.peek() == '^')
    {
        ss.get(ch);
        double number = getNum(ss);

        result = pow(result, number);
    }

    return result;
}

double FormulaCell::secondPriority(std::stringstream& ss)
{
    char ch;
    double result = firstPriority(ss);
    while (ss.peek() == '*' || ss.peek() == '/')
    {
        ss.get(ch);
        double number = firstPriority(ss);

        if (ch == '*')
            result *= number;
        else if(number == 0 && ch == '/')
        {
            isValid = false;
            length = 5;
            return 0;
        }
        else
            result /= number;
    }
    return result;
}

double FormulaCell::getNum(std::stringstream& ss)
{
    double number;
    char ch;

    while (ss.peek() == ' ') 
        ss.get(); // Skip spaces

    int pos = ss.tellg();

    if(!(ss >> number)) // Reference found
    {
        size_t row = 0;
        char colChar;

        ss.clear();
        ss.seekg(pos);
        
        ss >> colChar; 
        ss >> row;
        
        size_t col = 0;
        if (colChar >= 'a' && colChar <= 'z')
            col = (size_t)(colChar - 'a');

        if (colChar >= 'A' && colChar <= 'Z')
            col = (size_t)(colChar - 'A'); 

        
        
        if(row - 1 >= table.size() || col >= table[row - 1].size()) 
        {

            std::cout << "Element at row " << row << " col " << col + 1 << " does not exits\n";
            number = 0;
            length = 1;
        }
        else if(table[row-1][col] == nullptr)
        {
            std::cout << "Element at row " << row << " col " << col + 1 << " is empty\n";
            length = 1;
            number = 0;
        }
        else if ((row - 1 <= table.size() && col <= table[row - 1].size()))
        {
            number = table[row-1][col]->getValue();
        }
        else
        {
            isValid = false;
            length = 5;
            std::cout << "Element at row " <<  row << " col " << col + 1 << " contains recursive definition\n";
            number = 0;
        }

    }

    while (ss.peek() == ' ') 
        ss.get(); // Skip spaces

    return number;
}

void FormulaCell::print(std::ostream& out) const
{
    if(isValid)
    {
        out << value;
    }
    else
    {
        out << "ERROR"; // if we divide by 0, for example
    }
}

double FormulaCell::getValue() const
{
    return value;
}

