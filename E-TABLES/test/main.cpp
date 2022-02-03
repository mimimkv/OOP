#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "CommandLineParser.h"
#include "Cell.h"
#include "DoubleCell.h"
#include "IntCell.h"
#include "StringCell.h"
#include <iostream>
#include <cstring>

// This case tests the class IntCell
TEST_CASE("Test Int Cell")
{
    SECTION("Test constructor")
    {
        IntCell c(5, 1);
        IntCell c1(20, 2);

        REQUIRE(c.getValue() == 5);
        REQUIRE(c1.getValue() == 20);
    }

    SECTION("Test Length method in base class Cell")
    {
        IntCell c(5, 1);
        IntCell c1(20, 2);

        REQUIRE(c.getLength() == 1);
        REQUIRE(c1.getLength() == 2);
    }

    SECTION("Test Save Function")
    {
        std::ofstream file("test.txt", std::ios::trunc);
        IntCell c(5, 1);
        IntCell c1(20, 2);

        c.save(file);
        file << ' ';
        c1.save(file);
        file.close();
        std::ifstream in("test.txt");

        if (!in.is_open())
        {
            throw std::runtime_error("Cannot open file!");
        }

        try
        {
            int num1;
            int num2;

            in >> num1;
            in >> num2;

            REQUIRE(num1 == 5);
            REQUIRE(num2 == 20);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        in.close();
    }

}

// This case tests the class DoubleCell
TEST_CASE("Test Double Cell")
{
    SECTION("Test constructor")
    {
        DoubleCell c(5, 1);
        DoubleCell c1(123.123, 7);
        DoubleCell c2(1.1, 3);

        REQUIRE(c.getValue() == 5);

        // !!! comparing floating numbers is different
        const double EPS = 1.0 / (1 << 30);

        double temp = c1.getValue() - 123.123;
        REQUIRE(temp < EPS);

        temp = c2.getValue() - 1.1;
        REQUIRE(temp < EPS);
    }

    SECTION("Test Length method in base class Cell")
    {
        DoubleCell c(5, 1);
        DoubleCell c1(123.123, 7);
        DoubleCell c2(1.1, 3);

        REQUIRE(c.getLength() == 1);
        REQUIRE(c1.getLength() == 7);
        REQUIRE(c2.getLength() == 3);
    }

    SECTION("Test Save Function")
    {
        std::ofstream file("test.txt", std::ios::trunc);
        DoubleCell c(5, 1);
        DoubleCell c1(123.123, 7);
        DoubleCell c2(1.1, 3);

        c.save(file);
        file << ' ';
        c1.save(file);
        file << ' ';
        c2.save(file);

        file.close();
        std::ifstream in("test.txt");

        if (!in.is_open())
        {
            throw std::runtime_error("Cannot open file!");
        }

        try
        {
            double num1;
            double num2;
            double num3;

            in >> num1;
            in >> num2;
            in >> num3;


            REQUIRE(num1 == 5);
            // !!! comparing floating numbers is different
            const double EPS = 1.0 / (1 << 30);

            double temp = num2 - 123.123;
            REQUIRE(temp < EPS);

            temp = num3 - 1.1;
            REQUIRE(temp < EPS);
        }

        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        in.close();
    }

}

// This case tests the class StringCell
TEST_CASE("Test String Cell")
{
    SECTION("Test constructor")
    {
        StringCell c("5", 1);
        StringCell c1("123.123", 7);
        StringCell c2("1.1", 3);

        StringCell c3("", 0);

        try
        {
            double v = c3.getValue();
            REQUIRE(v == 0); // empty string
            // stod throws an exception
            // stod is a function that converts
            //  a string to double, if it is possible 
        }
        catch(const std::exception& e)
        {
            std::cerr << "Problems with function ";
            std::cerr << e.what() << '\n';
        }
        
        StringCell c4("a", 1);
        StringCell c5("abc", 3);
        StringCell c6("hi kp", 5);



        REQUIRE(c.getValue() == 5);

        // !!! comparing floating numbers is different
        const double EPS = 1.0 / (1 << 30);

        double temp = c1.getValue() - 123.123;
        REQUIRE(temp < EPS);

        temp = c2.getValue() - 1.1;
        REQUIRE(temp < EPS);

        
        
        REQUIRE(c4.getValue() == 0); // string is converted to 0
        REQUIRE(c5.getValue() == 0);
        REQUIRE(c6.getValue() == 0);
    }

    SECTION("Test Length method in base class Cell")
    {
        StringCell c("5", 1);
        StringCell c1("123.123", 7);
        StringCell c2("1.1", 3);
        StringCell c3("", 0);
        StringCell c4("a", 1);
        StringCell c5("abc", 3);
        StringCell c6("hi kp", 5);

        REQUIRE(c.getLength() == 1);
        REQUIRE(c1.getLength() == 7);
        REQUIRE(c2.getLength() == 3);
        REQUIRE(c3.getLength() == 0);
        REQUIRE(c4.getLength() == 1);
        REQUIRE(c5.getLength() == 3);
        REQUIRE(c6.getLength() == 5);
    }

    SECTION("Test Save Function")
    {
        std::ofstream file("test.txt", std::ios::trunc);
        StringCell c("5", 1);
        StringCell c1("123.123", 7);
        StringCell c2("1.1", 3);
        StringCell c3("", 0);
        StringCell c4("a", 1);
        StringCell c5("abc", 3);
        StringCell c6("hi kp", 5);

        if(!file.is_open())
        {
            throw std::runtime_error("Cannot open file!");
        }
        try
        {
            c.save(file);
            file << std::endl;
            c1.save(file);
            file << std::endl;
            c2.save(file);
            file << std::endl;
            c3.save(file);
            file << std::endl;
            c4.save(file);
            file << std::endl;
            c5.save(file);
            file << std::endl;
            c6.save(file);
            file << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        

        std::ifstream in("test.txt");

        if (!in.is_open())
        {
            throw std::runtime_error("Cannot open file!");
        }
        try
        {
            std::string temp = "";
            in >> temp;
            temp.erase(temp.begin()); // delete ""
            temp.erase(temp.end() - 1);

            REQUIRE(temp == "5");

            in >> temp;
            temp.erase(temp.begin()); // delete ""
            temp.erase(temp.end() - 1);
            REQUIRE(temp == "123.123");

            in >> temp;
            temp.erase(temp.begin()); // delete ""
            temp.erase(temp.end() - 1);
            REQUIRE(temp == "1.1");

            in >> temp;
            temp.erase(temp.begin()); // delete ""
            temp.erase(temp.end() - 1);
            REQUIRE(temp == "");

            in >> temp;
            temp.erase(temp.begin()); // delete ""
            temp.erase(temp.end() - 1);
            REQUIRE(temp == "a");
            
            in >> temp;
            temp.erase(temp.begin()); // delete ""
            temp.erase(temp.end() - 1);
            REQUIRE(temp == "abc");

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        in.close();
    }

}

// This case tests the class CellFactory
TEST_CASE("Test Cell Factory Class")
{
    std::vector<std::vector<Cell*>> tab;
    std::string temp = "15";
    Cell* ptr1 = CellFactory::make(temp, tab); // int

    SECTION("Test Value and type of int cell")
    {
        REQUIRE(ptr1->getValue() == 15);
    }

    SECTION("Test length of data")
    {
        REQUIRE(ptr1->getLength() == 2);
    }

    delete ptr1;

    temp = "1.1";
    Cell* ptr2 = CellFactory::make(temp, tab);

    SECTION("Test value and type of double cell")
    {
        const double EPS = 1.0 / (1 << 30);
        REQUIRE(ptr2->getValue() - 1.1 < EPS);
    }

    SECTION("Test length of double data")
    {
        REQUIRE(ptr2->getLength() == 3);
    }

    delete ptr2;

    temp = "\"zdr\"";
    Cell* ptr3 = CellFactory::make(temp, tab);

    SECTION("Test value and type of string cell")
    {
        REQUIRE(ptr3->getValue() == 0);
    }

    SECTION("Test length of string cell")
    {
        REQUIRE(ptr3->getLength() == 3);
    }

    delete ptr3;

    temp = "\"hi kp\"";
    Cell* ptr4 = CellFactory::make(temp, tab);

    SECTION("Test string cell with space")
    {
        REQUIRE(ptr4->getValue() == 0);
    }

    SECTION("Test string cell length with space")
    {
        REQUIRE(ptr4->getLength() == 5);
    }

    delete ptr4;
    
    temp = "qww";
    Cell* ptr5 = CellFactory::make(temp, tab);
    REQUIRE(ptr5 == nullptr);

    temp = "qw1";
    Cell* ptr6 = CellFactory::make(temp, tab);
    REQUIRE(ptr5 == nullptr);

}

//This class tests the class CommandLineParser
TEST_CASE("Test CommandLine Parser")
{
    SECTION("Test split command")
	{
		std::string line1 = "Hello world! abc     \"Ivan   Petrov\"    hahah";
		//std::cout << line1 << std::endl;
		std::vector<std::string> parts1 = CommandLineParser::split(line1, ' ');
		std::vector<std::string> parts2 = CommandLineParser::split(line1, '!');
		std::vector<std::string> parts3 = CommandLineParser::split(line1, '#');
		

		SECTION("test size")
		{
			REQUIRE(parts1.size() == 5);

			REQUIRE(parts2.size() == 2);
			REQUIRE(parts3.size() == 1);
		}

		SECTION("test splitting")
		{
			REQUIRE(parts1[0] == "Hello");
			REQUIRE(parts1[1] == "world!");

			REQUIRE(parts2[0] == "Hello world");
			REQUIRE(parts2[0].size() == 11);

			REQUIRE(parts3[0] == "Hello world! abc     \"Ivan   Petrov\"    hahah");
		}
	}


    SECTION("Test if a symbol is a capital leter")
    {
        std::string temp = "ZDR";

        SECTION("all capital letters")
        {
            for (int i = 0; i < temp.length(); ++i)
            {
                REQUIRE(CommandLineParser::isCapitalLetter(temp[i]));
            }
        }

        temp = "zdrkp";
        SECTION("no capital letters")
        {
            for (int i = 0; i < temp.length(); ++i)
            {
                REQUIRE(!CommandLineParser::isCapitalLetter(temp[i]));
            }
        }

        temp = "hElLo";
        SECTION("mixed")
        {
            for(int i = 0; i < temp.length(); ++i)
            {
                if (i % 2 == 0)
                {
                    REQUIRE(!CommandLineParser::isCapitalLetter(temp[i]));
                }
                else
                {
                    REQUIRE(CommandLineParser::isCapitalLetter(temp[i]));
                }
            }
        }
    }

    SECTION("Test conversion to upper case")
    {
        std::string temp = "hello";

        SECTION("Test with all lower case letters")
        {
            CommandLineParser::toUpperCase(temp);
            REQUIRE(temp == "HELLO");
        }

        temp = "HELLO";
        SECTION("Test with all upper case letters")
        {
            CommandLineParser::toUpperCase(temp);
            REQUIRE(temp == "HELLO");
        }

        temp = "123we";
        SECTION("Test with different symbols")
        {
            CommandLineParser::toUpperCase(temp);
            REQUIRE(temp == "123WE");
        }

        temp = "123";
        SECTION("Test with numbers only")
        {
            CommandLineParser::toUpperCase(temp);
            REQUIRE(temp == "123");
        }
    }

    SECTION("Test parse command")
    {
        std::string temp = "abc";
        try
        {
            ICommand* com = CommandLineParser::parseCommand(temp);
            REQUIRE(com == nullptr);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}

// This case tests the class Table
TEST_CASE("Test Table Class")
{
    Table tab;
    std::string temp = "12";
    tab.edit(0, 0, temp);

    SECTION("Test edit and resize")
    {
        std::ofstream out("test.txt", std::ios::trunc);
        if(!out.is_open())
        {
            throw std::runtime_error("Cannot open file!");
        }
        try
        {
            tab.save(out);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    
        out.close();

        std::ifstream in("test.txt");
        if(!in.is_open())
        {
            throw std::runtime_error("Cannot open file!");
        }
        try
        {
            int num = 0;
            //in.get(); // because of ,
            in >> num;

            REQUIRE(num == 12);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        in.close();
    }

    SECTION("Test copy constructor")
    {
        Table tab2(tab);
        std::ofstream out("test.txt", std::ios::trunc);
        if(!out.is_open())
        {
            throw std::runtime_error("Cannot open file!");
        }
        try
        {
            tab2.save(out);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    
        out.close();

        std::ifstream in("test.txt");
        if(!in.is_open())
        {
            throw std::runtime_error("Cannot open file!");
        }
        try
        {
            int num = 0;
            //in.get(); // because of ,
            in >> num;

            REQUIRE(num == 12);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        in.close();
    }

    SECTION("Test copy assignment operator")
    {
        Table tab2 = tab;
        std::ofstream out("test.txt", std::ios::trunc);
        if(!out.is_open())
        {
            throw std::runtime_error("Cannot open file!");
        }
        try
        {
            tab2.save(out);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    
        out.close();

        std::ifstream in("test.txt");
        if(!in.is_open())
        {
            throw std::runtime_error("Cannot open file!");
        }
        try
        {
            int num = 0;
            //in.get(); // because of ,
            in >> num;

            REQUIRE(num == 12);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        in.close();
    }

}