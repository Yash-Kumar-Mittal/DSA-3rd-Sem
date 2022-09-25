// YASH KUMAR MITTAL   
// 21105069  
// ECE


#include <bits/stdc++.h> 
using namespace std;     

class Member
{
public:
    string Member_name;
    int Member_Age;
    Member *Next_Member;
    Member *Prev_Member;
    Member(string Member_name, int Member_Age)
    {
        this->Member_name = Member_name;
        Next_Member = NULL;
        this->Member_Age = Member_Age;
        Prev_Member = NULL;
    }
}; 
void Add_Family_Member(Member *&Family_head, string Member_name, int Member_Age)
{
    if (Family_head == NULL)
    {
        Family_head = new Member(Member_name, Member_Age);
        return;
    }
    Member *Temporary_Member = Family_head;
    while (Temporary_Member->Next_Member != NULL)
    {
        Temporary_Member = Temporary_Member->Next_Member;
    }
    Temporary_Member->Next_Member = new Member(Member_name, Member_Age);
    Temporary_Member->Next_Member->Prev_Member = Temporary_Member;
}

void displayByFamily_Head(Member *Family_head)
{
    if (Family_head == NULL)
        return;
    Member *Temporary_Member = Family_head;
    while (Temporary_Member->Next_Member != NULL)
    {
        cout << "Name : " << Temporary_Member->Member_name << " , "
             << "Age : " << Temporary_Member->Member_Age << " <===>\n";
        Temporary_Member = Temporary_Member->Next_Member;
    }
    cout << "Name : " << Temporary_Member->Member_name << " , "
         << "Age : " << Temporary_Member->Member_Age;
}

void displayByFamily_junior(Member *Family_junior)
{
    if (Family_junior == NULL)
        return;
    Member *Temporary_Member = Family_junior;
    while (Temporary_Member->Prev_Member != NULL)
    {
        cout << "Name : " << Temporary_Member->Member_name << " , "
             << "Age : " << Temporary_Member->Member_Age << " <===>\n";
        Temporary_Member = Temporary_Member->Prev_Member;
    }
    cout << "Name : " << Temporary_Member->Member_name << " , "
         << "Age : " << Temporary_Member->Member_Age;
}

Member *Family_junior(Member *Family_head)
{
    Member *Temporary_Member = Family_head;
    while (Temporary_Member->Next_Member != NULL)
    {
        Temporary_Member = Temporary_Member->Next_Member;
    }
    return Temporary_Member;
}

int main()
{

    Member *Family_head = NULL;
    Add_Family_Member(Family_head,"GrandFather", 82);
    Add_Family_Member(Family_head, "GrandMother", 75);
    Add_Family_Member(Family_head, "Father", 45);
    Add_Family_Member(Family_head, "Mother", 40);
    Add_Family_Member(Family_head, "Brother", 23);
    Add_Family_Member(Family_head, "Me", 16);

    cout << "Display From Family Head First\n"
         << endl;
    displayByFamily_Head(Family_head);
    cout << '\n'
         << endl
         << endl
         << endl;
    cout << "Display From Family Junior First\n"
         << endl;
    displayByFamily_junior(Family_junior(Family_head));

    return 0;
}
/*BONUS QUESTION
Q.Try to find a way to link the family members' doubly-linked list based on their relationship.
Ans. We can do such by having the linked list sort in either ascending or descending order by age so that family members come in hierarchical order.*/