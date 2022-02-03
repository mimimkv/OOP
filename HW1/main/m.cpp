#include <iostream>
#include "mystring.h"
#include "vehicle.h"
#include "garage.h"
#include <cstring>
#include "vehicleAllocator.h"


int main()
{
    VehicleAllocator va(10);

    va.addVehicle("1234", "red car", 2);
    std::cout << va;

    return 0;
}