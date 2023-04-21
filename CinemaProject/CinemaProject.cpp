#include <iostream>
#include "CinemaReservation.h"
int main()
{
    CinemaReservation* cinemaReservation = new CinemaReservation();
    cinemaReservation->Initialize();
    delete cinemaReservation;
    return 0;    
}
