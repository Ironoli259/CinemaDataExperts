#pragma once
#include <iostream>
#include <functional>
struct cinemahall {
    int ID;
    //other members to implement
    std::string showtime;

    cinemahall(int id, std::string st) : ID(id), showtime(st) {}

    bool operator<(const cinemahall& other) const {
        return ID < other.ID;
    }
};

class HallsList
{


};

