// ***************************************************************************
// * Name: LinkList Class ( linklist.h filename )                            *
// * Description: Definition of of the LinkList class used for the           *
// *     the COP3330 class. Definition for a double linked list with dummy   *
// *     header and tail.  Stores last name, first name, middle initial,     *
// *     sex, and whether the person believes cheesecakeis pie or cake.      *
// *                                                                         *
// * Author: Dr. Gaitros                                                     *
// * Date: December 19th, 2024 ( last modified )                             *
// * Copywright:  2024 Dr. David A. gaitros                                  *
// ***************************************************************************

#ifndef LINKLIST_H
#define LINKLIST_H
#include <string>
using namespace std;
struct PieCake_struct
{
    int     id;
    string  lname;
    string  fname;
    char    mi;
    char    sex;
    char    pORc;         // P = pie, C=Cake
    PieCake_struct * prev;
    PieCake_struct * next;
};
class LinkList {

public:
     LinkList();                       // Default constructor.
     ~LinkList();                      // Destructor
     bool Empty();                     // True = link list is empty, False otherwise
     int  Size();                      // Returns number of records minus head and tail
     bool Find(const int idnumber);    // Looks for a record with the id,

                                       // returns true if  found, false otherwise.

                                       // Sets the current to the
                                       //   record found.

                                       //   Sets current to null if not found.
     void Push_Back( PieCake_struct * p); //  Puts a record at the end of the list.
     bool Delete();                    // Deletes current record.

                                       // Must use Find() to locate the record.
     void Print();                     // Prints the report..see example.
     void List();                      // Lists current record to standard output.

                                       //    See Example.

private:
    PieCake_struct * head;         // Points to the dummy head of the list
    PieCake_struct * tail;         // Points to the dummy tail of the list
    PieCake_struct * current;      // Current record, set when find is successful.
    int count;                     // Number of records, modified when records are
                                   //   added and deleted.
};
#endif
