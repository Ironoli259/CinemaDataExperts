#include "HallsTree.h"
#include "BSTree.h"
using std::cout;
using std::endl;


HallsTree::HallsTree() : hallsTree(), size(0) {
}

HallsTree::~HallsTree()
{
}
//Cout helper function
std::ostream& operator<<(std::ostream& os, const CinemaHall& hall) {
    os << "Hall number : " << hall.number << std::endl;
    os << "----------------------------------------------" << std::endl;
    os << "1st Movie : " << hall.showtime1->movie->title << std::endl;
    os << "Starts at : " << hall.showtime1->startTime << std::endl;
    os << "Ends at   : " << hall.showtime1->endTime << std::endl;
    os << "---------------------------------------------" << std::endl;
    os << "2nd movie : " << hall.showtime2->movie->title << std::endl;
    os << "Starts at : " << hall.showtime2->startTime << std::endl;
    os << "Ends at   : " << hall.showtime2->endTime << std::endl;
    os << "---------------------------------------------" << std::endl;
    os << "3rd movie : " << hall.showtime3->movie->title << std::endl;
    os << "Starts at : " << hall.showtime3->startTime << std::endl;
    os << "Ends at   : " << hall.showtime3->endTime << std::endl;
    os << "----------------------------------------------" << std::endl;
    os << "4th Movie : " << hall.showtime4->movie->title << std::endl;
    os << "Starts at : " << hall.showtime4->startTime << std::endl;
    os << "Ends at   : " << hall.showtime4->endTime << std::endl;
    os << "---------------------------------------------" << std::endl;
    os << "5th movie : " << hall.showtime5->movie->title << std::endl;
    os << "Starts at : " << hall.showtime5->startTime << std::endl;
    os << "Ends at   : " << hall.showtime5->endTime << std::endl;
    os << "---------------------------------------------" << std::endl;
    os << "6th movie : " << hall.showtime6->movie->title << std::endl;
    os << "Starts at : " << hall.showtime6->startTime << std::endl;
    os << "Ends at   : " << hall.showtime6->endTime << std::endl;
    os << "----------------------------------------------" << std::endl;
    return os;
}
void HallsTree::AddHall(int number, Showtime* show1, Showtime* show2, Showtime* show3, Showtime* show4, Showtime* show5, Showtime* show6){
	CinemaHall* newHall = new CinemaHall{ number,show1,show2,show3,show4,show5,show6 };
	hallsTree.Insert(*newHall);
	size++;
}

void HallsTree::ClearTree()
{
	hallsTree.~BSTree();
	size = 0;
}

void HallsTree::DisplayHalls()
{
    hallsTree.PrintInorder();
}

bool HallsTree::PrintHallInfo(const CinemaHall& hall) {
    if (&hall == nullptr)
        return false;
    cout << hall;
    return true;
}

int HallsTree::GetSize()
{
    return this->size;
}
CinemaHall* HallsTree::GetHall(int number)
{
    BSTree<CinemaHall>::Node* node = hallsTree.Find(number);
    if (node != nullptr) {
        return &(node->value);
    }
    else {
        return nullptr;
    }
}



