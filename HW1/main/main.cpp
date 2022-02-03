#include <iostream>
#include "mystring.h"
#include "vehicle.h"
#include "garage.h"
#include <vector>
#include <cstring>
#include "vehicleAllocator.h"

int main()
{
    unsigned int capacity;
    std::cout << "Enter capacity of the garage: ";
    std::cin >> capacity;
    std::cin.ignore();


    //Garage garage(capacity);
    //std::vector<Vehicle> v;

    char command[20];
    Vehicle car("BG1234", "big car", 2);
    //std::cout << vector;

    VehicleAllocator va(capacity);

    while (true)
    {
        std::cout << "Enter a command: ";
        std::cin.getline(command, 20);
        if (strcmp(command, "add") == 0)
        {
            char number[20];
            std::cout << "Enter registration number: ";
            std::cin.getline(number, 20);
            char info[50];
            std::cout << "Enter description: ";
            std::cin.getline(info, 50);
            std::size_t space;
            std::cout << "How big is the vehicle: ";
            std::cin >> space;
            std::cin.ignore();

            

            //Vehicle temp((const char*)number, (const char*)info, space);
           
            //garage.insert(temp);
            
            //v.push_back(temp);

            

            va.addVehicle(number, info, space);

        }
        else if (strcmp(command, "remove") == 0)
        {
            char carToRemove[20];
            std::cout << "Enter car registration: ";
            std::cin >> carToRemove;
            std::cin.ignore();


            va.removeVehicle(carToRemove);
        }
        else if (strcmp(command, "print") == 0)
        {   
            std::cout << va;
        }
        else if (!strcmp(command, "exit"))
        {
            break;
        }
        else
        {
            std::cout << "Inavalid command!\n";
            continue;
        }
    }
    return 0;
}