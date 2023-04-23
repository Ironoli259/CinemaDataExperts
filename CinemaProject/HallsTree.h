#pragma once
#include <iostream>
#include <functional>
#include "ShowtimeList.h"
#include "BSTree.h"

struct CinemaHall {
    int number;
    Showtime* showtime1;
    Showtime* showtime2;
    Showtime* showtime3;
    Showtime* showtime4;
    Showtime* showtime5;
    Showtime* showtime6;

    CinemaHall(int number, Showtime* show1, Showtime* show2, Showtime* show3, Showtime* show4, Showtime* show5, Showtime* show6) : number(number), showtime1(show1), showtime2(show2), showtime3(show3), showtime4(show4), showtime5(show5), showtime6(show6) {}

    bool operator<(const CinemaHall& other) const {
        return number < other.number;
    }
};
    

class HallsTree
{
private:
    int size;
    BSTree<CinemaHall> hallsTree;
public:
    HallsTree();
    ~HallsTree();
    void AddHall(int number, Showtime* show1, Showtime* show2, Showtime* show3, Showtime* show4, Showtime* show5, Showtime* show6);
    void ClearTree();
    void DisplayHalls();
    bool PrintHallInfo(const CinemaHall& hall);
    int GetSize();
    CinemaHall* GetHall(int number);
};

