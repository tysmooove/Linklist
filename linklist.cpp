#include <iostream>
#include "linklist.h"
using namespace std;

// *****************************************************************
// * Function Name: LinkList (Constructor)                          *
// * Description: Initializes an empty doubly linked list with      *
// *   dummy head and tail nodes. Sets count to zero and ensures    *
// *   all pointers are properly linked.                            *
// * Parameter Description: None                                    *
// * Date: 12/19/2024                                               *
// * Author: Tyler Hawkins                                          *
// * References: Dr. David Gaitros                                  *
// *****************************************************************
LinkList::LinkList()
{
    head = new PieCake_struct;
    tail = new PieCake_struct;

    head->prev = nullptr;
    head->next = tail;

    tail->prev = head;
    tail->next = nullptr;

    current = nullptr;
    count = 0;
}

// *****************************************************************
// * Function Name: ~LinkList (Destructor)                         *
// * Description: Iterates through the list deleting each node     *
// *   (except the dummy head and tail), freeing dynamically       *
// *   allocated memory. Resets count to zero.                     *
// * Parameter Description: None                                   *
// * Date: 12/19/2024                                              *
// * Author: Tyler Hawkins                                         *
// *****************************************************************
LinkList::~LinkList()
{
    PieCake_struct* temp = head->next;

    while (temp != tail)
    {
        PieCake_struct* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    delete head;
    delete tail;

    count = 0;
}

// *****************************************************************
// * Function Name: Empty                                          *
// * Description: Checks whether the list contains zero records.   *
// *   Returns true if list has no valid data-containing nodes.    *
// * Parameter Description: None                                   *
// * Date: 12/19/2024                                              *
// * Author: Tyler Hawkins                                         *
// *****************************************************************
bool LinkList::Empty()
{
    return (count == 0 || head->next == tail);
}

// *****************************************************************
// * Function Name: Size                                           *
// * Description: Returns the count of valid records stored in     *
// *   the list.                                                   *
// * Parameter Description: None                                   *
// * Date: 12/19/2024                                              *
// * Author: Tyler Hawkins                                         *
// *****************************************************************
int LinkList::Size()
{
    return count;
}

// *****************************************************************
// * Function Name: Find                                           *
// * Description: Searches for the first record whose id matches   *
// *   the provided idnumber. Sets current to the found node.      *
// *   Returns true if found, false otherwise.                     *
// * Parameter Description:                                        *
// *   - idnumber (int): ID value to search for.                   *
// * Date: 12/19/2024                                              *
// * Author: Tyler Hawkins                                         *
// *****************************************************************
bool LinkList::Find(const int idnumber)
{
    if (Empty())
    {
        current = nullptr;
        return false;
    }

    PieCake_struct* temp = head->next;

    while (temp != tail)
    {
        if (temp->id == idnumber)
        {
            current = temp;
            return true;
        }
        temp = temp->next;
    }

    current = nullptr;
    return false;
}

// *****************************************************************
// * Function Name: Push_Back                                      *
// * Description: Inserts a valid record directly before the       *
// *   dummy tail node, preserving order.                          *
// * Parameter Description:                                        *
// *   - p (PieCake_struct*): Dynamically allocated record to add. *
// * Date: 12/19/2024                                              *
// * Author: Tyler Hawkins                                         *
// *****************************************************************
void LinkList::Push_Back(PieCake_struct* p)
{
    p->next = tail;
    p->prev = tail->prev;

    tail->prev->next = p;
    tail->prev = p;

    count++;
}

// *****************************************************************
// * Function Name: Delete                                         *
// * Description: Deletes the record at the current pointer.       *
// *   Must be called after a successful Find(). Returns true if   *
// *   deletion succeeds, false otherwise.                         *
// * Parameter Description: None                                   *
// * Date: 12/19/2024                                              *
// * Author: Tyler Hawkins                                         *
// *****************************************************************
bool LinkList::Delete()
{
    if (current == nullptr || current == head || current == tail)
        return false;

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;
    current = nullptr;

    count--;
    return true;
}

// *****************************************************************
// * Function Name: List                                           *
// * Description: Prints the contents of the current node to       *
// *   standard output. Displays basic personal data and choice.   *
// * Parameter Description: None                                   *
// * Date: 12/19/2024                                              *
// * Author: Tyler Hawkins                                         *
// *****************************************************************
void LinkList::List()
{
    if (current == nullptr || current == head || current == tail)
    {
        cout << "No current record selected.\n";
        return;
    }

    cout << "ID: " << current->id
         << "  Name: " << current->lname << ", " << current->fname << " " << current->mi
         << "  Sex: " << current->sex
         << "  Choice: " << (current->pORc == 'P' ? "Pie" : "Cake")
         << endl;
}

// *****************************************************************
// * Function Name: Print                                          *
// * Description: Prints all records in the list by temporarily    *
// *   setting current to each node and calling List(). Also       *
// *   counts and prints statistics on gender & pie/cake choices.  *
// * Parameter Description: None                                   *
// * Date: 12/19/2024                                              *
// * Author: Tyler Hawkins                                         *
// *****************************************************************

void LinkList::Print()
{
    if (Empty())
    {
        cout << "List is empty.\n";
        return;
    }

    int mPie = 0, mCake = 0;
    int fPie = 0, fCake = 0;
    int oPie = 0, oCake = 0;

    cout << "\n----- COMPLETE REPORT -----\n";

    PieCake_struct* temp = head->next;

    while (temp != tail)
    {
        current = temp;
        List();

        if (temp->sex == 'M')
        {
            if (temp->pORc == 'P') mPie++; else mCake++;
        }
        else if (temp->sex == 'F')
        {
            if (temp->pORc == 'P') fPie++; else fCake++;
        }
        else
        {
            if (temp->pORc == 'P') oPie++; else oCake++;
        }

        temp = temp->next;
    }

    cout << "\n----- STATISTICS -----\n";
    cout << "Men:    Pie = " << mPie << "   Cake = " << mCake << endl;
    cout << "Women:  Pie = " << fPie << "   Cake = " << fCake << endl;
    cout << "Other:  Pie = " << oPie << "   Cake = " << oCake << endl;
    cout << "---------------------------\n";

    current = nullptr;
}
