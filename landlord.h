#pragma warning (disable:4786)
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;
/////////global methods/////////////////
void getaLine(string& inStr); //get a text
char getaChar();          //get a character

/////////////class tenant////////////////
class tenant
{
private:
    string name;   //tenant name
    int aptNumber; //tenants apartment number

public:
    tenant(string n, int aNo);
    ~tenant();
    int getAptNumber();

    //for set
    friend bool operator <(const tenant&, const tenant&);
    friend bool operator ==(const tenant&, const tenant&);

    //for I/O
    friend ostream& operator <<(ostream&, const tenant&);
}; //class tenant end

/////////////class compareTenants///////////////
class compareTenants
{
public:
    bool operator() (tenant*, tenant*) const;
};

////////////////class tenantList///////////
class tenantList
{
private:
    //set pointers to tenants
    set<tenant*, compareTenants> setPtrsTens;
    set<tenant*, compareTenants>::iterator iter;

public:
    ~tenantList();                 //destructor delete tenants
    void insertTenant(tenant*);    // put tenant on list
    int getAptNo(string);          //return apt number
    void display();                //display tenant list
}; //end of class

//////////class tenantInputScreen///////////
class tenantInputScreen
{
private:
    tenantList* ptrTenantList;
    string tName;
    int aptNo;

public:
    tenantInputScreen(tenantList* ptrTL) : ptrTenantList(ptrTL)
    {}
    void getTenant();
};//end of class

///////////////////////////class rentrow//////////////////////////
class rentRow
{
private:
    int aptNo;
    float rent[12];

public:
    rentRow(int);
    void setRent(int, float);    //record rent for 1 month
    float getSumOfRow();        //return sum of rent

    //needed to store in set
    friend bool operator <(const rentRow&, const rentRow&);
    friend bool operator ==(const rentRow&, const rentRow&);

    //for I/O
    friend ostream& operator <<(ostream&, const rentRow&);
};//end of class

//////////////////class compareRows//////////////
class compareRows
{
public:
    bool operator() (const rentRow*, const rentRow*) const;
};

////////////////class rentRecord/////////////////
class rentRecord
{
private:
    //set pointers to rentRow objects
    set<rentRow*, compareRows> setPtrsRR;
    set<rentRow*, compareRows>::iterator iter;

public:
    ~rentRecord();
    void insertRent(int, int, float);
    void display();
    float getSumOfRents();              //sum all rents in record
};//end of class

///////////////////class rentInputScreen////////////////////////
class rentInputScreen
{
private:
    tenantList* ptrTenantList;
    rentRecord* ptrRentRecord;

    string renterName;
    float rentPaid;
    int month;
    int aptNo;

public:
    rentInputScreen(tenantList* ptrTL, rentRecord* ptrRR) : ptrTenantList(ptrTL), ptrRentRecord(ptrRR)
    {}
    void getRent();
};//end of class

///////////////class expense///////////
class expense
{
public:
    int month, day;
    string category, payee;
    float amount;
    expense()
    {}
    expense(int m, int d, string c, string p, float a) : month(m), day(d), category(c), payee(p), amount(a)
    {}
    //needed to store in set
    friend bool operator <(const expense&, const expense&);
    friend bool operator ==(const expense&, const expense&);

    //for I/O
    friend ostream& operator <<(ostream&, const expense&);
};//end of class

/////////////////////////////////////////////////////////////
class compareDates
{
public:
    bool operator() (expense*, expense*) const;
};
/////////////////////////////////////////////////////////////////
class comapareCategories
{
public:
    bool operator() (expense*, expense*) const;
};

///////////////////////////class expenseRecord/////////////////////
class expenseRecord
{
private:
    //vector of pointer to expenses
    vector<expense*> vectPtrsExpenses;
    vector<expense*>::iterator iter;

public:
    ~expenseRecord();
    void insertExp(expense*);
    void display();
    float displaySummary();     //used by annual report
};//end of class

//////////////////////class expenseInputScreen////////////////////
class expenseInputScreen
{
private:
    expenseRecord* ptrExpenseRecord;

public:
    expenseInputScreen(expenseRecord*);
    void getExpense();
};//end of class

//////////////////////class annualReport////////////////////
class annualReport
{
private:
    rentRecord* ptrRR;
    expenseRecord* ptrER;
    float expenses, rents;

public:
    annualReport(rentRecord*, expenseRecord*);
    void display();
};//end of class

/////////////////class userInterface/////////////////////
class userInterface
{
private:
    tenantList* ptrTenantList;
    tenantInputScreen* ptrTenantInputScreen;
    rentRecord* ptrRentRecord;
    rentInputScreen* ptrRentInputScreen;
    expenseRecord* ptrExpenseRecord;
    expenseInputScreen* ptrExpenseInputScreen;
    annualReport* ptrAnnualReport;
    char ch;

public:
    userInterface();
    ~userInterface(); \
        void interact();
};//end of class
////////////////////////end of file///////////////////////#pragma once
