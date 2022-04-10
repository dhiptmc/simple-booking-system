#include <iostream>
#include <string>
#include <array>
#include "Database.h"
using namespace std;

void Database::displayMessage() const
{
    cout << "Welcome to the Booking System !\n";
}

void Database::execDetermineMode()
{
    int mode1=0;
    int mode2=0;
    int curcount=0;
    
    cout << "Enter \"1\" to book , \"0\" to check or \"-1\" to exit !\n";
    cout << "Command : ";
    cin >> mode1;
    cout << "\n";

    while( mode1 != -1 )
    {
        string nameBuff;
        int numberBuff=0;
        int movieBuff=0;
        int ticketBuff=0;
        
        switch ( mode1 )
        {
            case 1: //book mode
                cout << "Enter customer's Name : ";
                cin >> nameBuff;
                cout << "\n";  

                numberBuff = getNumber();
                cout << "Customer's Number is : " << numberBuff;
                cout << "\n\n";
                cout << "Movie Lists:\n";
                cout << "0:THE BATMAN \n1:UNCHARTED\n2:DEATH ON THE NILE\n3:MOONFALL\n4:MY BEST FRIEND'S BREAKFAST\n\n";
                cout << "Movie chosen (Please enter number 0~4) : ";
                cin >> movieBuff;
                cout << "\n"; 
                if( movieBuff==0 || movieBuff==1 || movieBuff==2 || movieBuff==3 || movieBuff==4 )
                {
                    cout << "Tickets to book : ";
                    cin >> ticketBuff;
                    cout << "\n";

                    if( setticketRemain(movieBuff,ticketBuff) == 1 )
                    {
                        setCustomer(nameBuff,numberBuff,movieBuff,ticketBuff);
                    }
                    else
                    {
                        cout << "There aren't enough tickets ! Please retry again !\n\n";
                    }
                }
                else
                {
                    cout << "Incorrect command ! Please retry again !\n\n";                           
                }
            break;

            case 0: //check mode
                cout << "Enter \"1\" to check customer's booking status , \"0\" to check current left tickets or \"-1\" to exit checking !\n";
                cout << "Command : ";
                cin >> mode2;
                cout << "\n";

                while( mode2 != -1 )
                {
                    switch(mode2)
                    {
                    case 1:
                        curcount = getNumber();
                        cout << "Enter customer's Number : ";
                        cin >> numberBuff;                
                        cout << "\n";  

                        if( numberBuff <= curcount - 1 )
                        {
                            nameBuff = getCustomerName(numberBuff);
                            movieBuff = getmovieChosen(numberBuff);
                            ticketBuff = getticketAmount(numberBuff);

                            cout << "Customer's Name is : " << nameBuff;
                            cout << "\n";  
                            
                            cout << "Movie he/she chose " << movieBuff<< " : " << getmovieName(movieBuff);
                            cout << "\n";

                            cout << "Tickets amount he/she booked :" << ticketBuff;
                            cout << "\n\n";
                        }
                        else
                        {
                            cout << "Still no data !\n\n";                            
                        }
                    break;

                    case 0:
                        cout << "Movie Lists:\n";
                        cout << "0:THE BATMAN \n1:UNCHARTED\n2:DEATH ON THE NILE\n3:MOONFALL\n4:MY BEST FRIEND'S BREAKFAST\n\n";
                        cout << "Check tickets left for Movie (Please enter number 0~4) : ";
                        cin >> movieBuff;
                        if( movieBuff==0 || movieBuff==1 || movieBuff==2 || movieBuff==3 || movieBuff==4 )
                        {
                            cout << "Movie " << movieBuff << " : " << getmovieName(movieBuff) << " has " <<getticketRemain(movieBuff)<< " ticket(s) left ! ";
                            cout << "\n\n";
                        }
                        else
                        {
                            cout << "Incorrect command ! Please retry again !\n\n";                           
                        }
                    break;

                    default:
                        cout << "Incorrect command ! Please enter a new command !\n" << endl;
                    break;
                    }

                    cout << "Enter \"1\" to check customer's booking status , \"0\" to check current left tickets or \"-1\" to exit checking !\n";
                    cout << "Command : ";
                    cin >> mode2;
                    cout << "\n";
                }
            break;

            default:
                cout << "Incorrect command ! Please enter a new command !\n";
            break;
        }
        
        cout << "Enter \"1\" to book , \"0\" to check or \"-1\" to exit !\n";
        cout << "Command : ";
        cin >> mode1;
        cout << "\n";  
    }
}

void Database::setCustomer( const string &Name,const int &Number, const int &moviechosen, const int &ticketamount)
{
    setNumber();
    customerName[Number] = Name;
    ticket[0][Number] = moviechosen;
    ticket[1][Number] = ticketamount;
}

int Database::getNumber() const
{
    return customerNumber;
}

void Database::setNumber()
{
    customerNumber++;
}

string Database::getCustomerName(int &Number) const
{
    return customerName[Number];
}

int Database::getmovieChosen(int &Number) const
{
    return ticket[0][Number];
}

int Database::getticketAmount(int &Number) const
{
    return ticket[1][Number];
}

int Database::setticketRemain(const int &moviechosen, const int &ticketamount)
{   
    int ticketreg;
    ticketreg = ticketRemain[moviechosen];
    ticketRemain[moviechosen] -= ticketamount;
    
    if( ticketRemain[moviechosen] < 0 )
    {
        cout << "No tickets available !" << endl;
        ticketRemain[moviechosen] = ticketreg;
        return 0;
    }
    
    else if( ticketRemain[moviechosen] == 0 )
    {
        cout << "Tickets for movie " << moviechosen << " : " << getmovieName(moviechosen) << " are sold out now !\n" << endl;
        return 1;
    }
    
    else
    {
        cout << "There are still " << ticketRemain[moviechosen] << " tickets left for movie "<< moviechosen  << " : " << getmovieName(moviechosen) << " now !\n" << endl;
        return 1;
    }
}

int Database::getticketRemain(const int &moviechosen) const
{
    return ticketRemain[moviechosen];
}

string Database::getmovieName(const int &Number) const
{
    return movieName[Number];
}