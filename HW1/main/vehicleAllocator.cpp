#include "vehicleAllocator.h"

VehicleAllocator::VehicleAllocator(int capacity)
{
    this->capacity = capacity;
    container = new Vehicle*[capacity];
    takenSpots = 0;
    numberOfVehicles = 0;
}
    
VehicleAllocator::~VehicleAllocator()
{
    for(int i = 0; i < numberOfVehicles; ++i)
        delete container[i];

    delete [] container;
}

VehicleAllocator::VehicleAllocator(const VehicleAllocator& other)
{
    container = new Vehicle*[other.capacity];
    for (int i = 0; i < other.numberOfVehicles; ++i)
    {
        container[i] = new Vehicle(*(other.container[i]));
    }
    numberOfVehicles = other.numberOfVehicles;
    takenSpots = other.takenSpots;
    capacity = other.capacity;
}

VehicleAllocator& VehicleAllocator::operator= (const VehicleAllocator& other)
{
    if (this != &other)
    {
        Vehicle** buffer = new Vehicle*[other.capacity];
        for(int i = 0; i < other.numberOfVehicles; ++i)
        {
            buffer[i] = new Vehicle(*(other.container[i]));
        }

        for(int i = 0; i < numberOfVehicles; ++i)
            delete container[i]; // why would it be wrong if i delete it with []

        delete [] container;

        container = buffer;

        numberOfVehicles = other.numberOfVehicles;
        takenSpots = other.takenSpots;
        capacity = other.capacity;

    }
    return *this;
}
    
void VehicleAllocator::addVehicle(const char* registration, const char* description, std::size_t space)
{
    if(takenSpots + space > capacity)
        throw std::length_error("No more place!");

    Vehicle* vehicle = new Vehicle(registration, description, space);
    container[numberOfVehicles] = vehicle;
    numberOfVehicles++;
    takenSpots += space;
}

void VehicleAllocator::removeVehicle(const char* registration)
{
    for (int i = 0; i < numberOfVehicles; ++i)
    {
        if(!strcmp(container[i]->registration(), registration))
        {   
            takenSpots -= container[i]->space();
            delete container[i];

            container[i] = container[--numberOfVehicles];
            container[numberOfVehicles] = nullptr;
        }
    }
}

Vehicle* VehicleAllocator::find(const char* registration)
{
    for(int i = 0; i < numberOfVehicles; ++i)
    {
        if (!strcmp(container[i]->registration(), registration))
            return container[i];
    }
    return nullptr;
}
std::ostream& operator << (std::ostream& out, VehicleAllocator& v)
{
    for(int i = 0; i < v.numberOfVehicles; ++i)
    {
        out << v.container[i]->registration() << " "
            << v.container[i]->description() << " "
            << v.container[i]->space() << std::endl;
    }
    return out;
}