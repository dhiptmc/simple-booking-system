#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <array>
using namespace std;

class Database
{
public:
    static const size_t movieAmount = 5;

    void displayMessage() const;
    void execDetermineMode();
    void setCustomer(const string &Name, const int &Number, const int &movieChosen, const int &ticketAmount);
    int setticketRemain(const int &moviechosen, const int &ticketamount);
    int getNumber() const;
    void setNumber();
    string getCustomerName(int &Number) const;
    int getmovieChosen(int &Number) const;
    int getticketAmount(int &Number) const;
    int getticketRemain(const int &moviechosen) const;
    string getmovieName(const int &Number) const;   

private:
    int customerNumber = 0;
    string customerName[100] = {}; //assume atmost 100 customers
    int ticket [2][100] = {0};
    //assume atmost 100 customers   //row0=moviechosen  row1=ticketamount
    array < int, movieAmount > ticketRemain = {20,20,20,20,20};
    string movieName [movieAmount] = {"THE BATMAN","UNCHARTED","DEATH ON THE NILE","MOONFALL","MY BEST FRIEND'S BREAKFAST"};    
};

#endif