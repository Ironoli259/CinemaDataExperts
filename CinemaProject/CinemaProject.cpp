#include <iostream>
#include "CinemaReservation.h"
#include "Administrator.h"
int main()
{
    Administrator admin = Administrator("admin", "admin", true);
    CinemaReservation* cinemaReservation = new CinemaReservation();
    cinemaReservation->Initialize();
    delete cinemaReservation;
    return 0;    
}
