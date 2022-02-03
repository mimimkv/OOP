#include "system.h"
#include "invalidNumberOfArgumentsException.h"

System::System()
{}



void System::setFile(const std::string& filePath)
{
    this->filePath = filePath;
}


std::string System::getFile() const
{
    return filePath;
}

void System::help() const
{
    std::cout << "The following commands are supported: \n";
    std::cout << "-open [file]\n"; // opens file
    std::cout << "-close\n"; // closes current file
    std::cout << "-edit [cell] [data]\n";
    std::cout << "-print\n";
    std::cout << "-save\n"; // saves current file
    std::cout << "-saveas [file]\n";
    std::cout << "-help\n";

    std::cout << '\n';
}

void System::edit(const std::string& location, std::string& data)
{
    char col = location[0];
    int row = 0;
    for (int i = 1; i < location.length(); ++i)
    {
        row *= 10;
        row += (int)(location[i] - '0');
    }

    int colToNum = 0;

    if (col >= 'a' && col <= 'z')
    {
        colToNum = (int)(col - 'a');

    }
    else if (col >= 'A' && col <= 'Z')
    {

        colToNum = (int)(col - 'A');
    }
    else
    {

        std::cout << "Invalid row/column!\n";
        return;
    }
    tab.edit(row - 1, colToNum, data);

}

void System::print()
{
    if (!isOpen)
    {
        std::cout << "There is no open file at the moment!\n";
        return;
    }
    std::cout << tab;
}

void System::save()
{
    if (!isOpen)
    {
        std::cout << "There is no open file!\n";
        return;
    }

    std::ofstream out(getFile());
    if (!out.is_open())
    {
        std::cout << "There are problems with this file!\n";
        return;
    }
    tab.save(out);
    std::cout << "Successfully saved this file!\n";
    out.close();
}

void System::saveas(const std::string& filePath)
{
    if (filePath.empty())
        throw InvalidNumberOfArgumentsException();
    
    std::ofstream out(filePath, std::ios::trunc);
    if (!out.is_open())
    {
        std::cout << "There are problems with this file!\n";
        return;
    }
    tab.save(out);
    std::cout << "Successfully saved "<< filePath << "\n";
    out.close();
}

void System::open(const std::string& filePath)
{
    if(isOpen)
    {
        std::cout << "First close the current file!\n";
        return;
    }

    std::ifstream in(filePath);
    if (!in.is_open())
    {
        std::cout << "Cannot open this file!\n";
        return;
    }

    isOpen = true;
    setFile(filePath);
    tab.read(in);
    std::cout << "Successfully opened " << filePath << '\n';
    in.close();
}

void System::close()
{
    tab.close();
    isOpen = false;
}