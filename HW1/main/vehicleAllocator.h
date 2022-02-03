#pragma once
#include <fstream>
#include "vehicle.h"
#include <cstring>

class VehicleAllocator 
{
    
    Vehicle** container;
    int numberOfVehicles;
    int takenSpots;
    int capacity;
public:
    VehicleAllocator(int capacity);
    ~VehicleAllocator(); 

    VehicleAllocator(const VehicleAllocator&);
    VehicleAllocator& operator= (const VehicleAllocator&);
    
    
    void addVehicle(const char* registration, const char* description, std::size_t space);
    void removeVehicle(const char* registration);
    Vehicle* find(const char* registration);
    friend std::ostream& operator << (std::ostream& out, VehicleAllocator& v);
};