
 #include <bits/stdc++.h>

using namespace std;
class ErrorEenterException {
private:
    string msg;
public:
    ErrorEenterException(string m)
    {
        msg = m;
    }
    string getMsg()
    {
        return msg;
    }
};

void CreateAccount ();
void InfoAboutSavingAccount ();
void InfoAboutCheckingAccount ();
void InfoAboutCertificateOfDeposit ();
void InfoAboutServiceChargeChecking ();
void InfoAboutNoServiceChargeChecking ();
void InfoAboutHighInterestChecking ();
void InfoAboutHighInterestSavings ();
void TheBeginning ();


/// ### ### ### ### ### ### ### ### ### ### ### ### ### ### /// ### ### ### ### ### ### ### ### ### ### ### ### ### ### ///


class BankAccount  // done
{
private:
    string accountNumber;
    string name;
    double balance;
public:

///set functions:

void setAccountNumber(string x)
{
    for(int i=0;i<x.size();i++){
    if(x[i]>='A'&&x[i]<='z')
    throw ErrorEenterException("You should enter a number without any character ! ");
    accountNumber = x ;
}}

void setNameOfTheOwner (string x)
{
    name = x ;
}

void setBalance (double x)
{
    balance = x ;
}

void PrintInformation()
{
    cout << " Customer information :\n Name : " << getNameOfTheOwner() << "\n Account number: " << getAccountNumber() << "\n Balance: " << getBalance() << endl;
}

///get functions:
    string getAccountNumber () { return accountNumber ; }
    string getNameOfTheOwner () { return name ; }
    double getBalance () { return balance ; }

///functions:
//Desposit:
virtual void Deposit () = 0 ;
//withdraw:
virtual void Withdraw () = 0 ;

///constractor:
BankAccount ()
{
     cout <<"\n Please enter your infromation :\n\n Your name: ";
     string name ; cin >> name ; setNameOfTheOwner(name);
     cout << " Your Account number: " ;
     string acnum ; cin >> acnum ; setAccountNumber(acnum);
     cout << " Your starting balance: ";
     double bal ; cin >> bal ; setBalance(bal) ;


}

};


/// ### ### ### ### ### ### ### ### ### ### ### ### ### ### /// ### ### ### ### ### ### ### ### ### ### ### ### ### ### ///


class checkingAccount : public BankAccount // done
{
    double monthlyServiceCharge;
    int limCheckWriting;
    double minBalance;
    double interest;

public:
///set functions:
void setMonthlyServiceCharge(double e) { monthlyServiceCharge = e; }
void setMinimumBalance(double w) { minBalance = w; }
void setInterest(double t) { interest = t; }
void setLimitCheckWriting(int r)  { limCheckWriting = r ; }

///get functions:
double getMonthlyServiceCharge() { return monthlyServiceCharge ; }
int    getLimChrckingWriting() { return limCheckWriting ; }
double getMinimumBalance() { return 0.0 ; }
double getInterest() { return 0.0 ; }

///pure virtual call:
void Deposit () {} ;

///pure virtual:
virtual void setwriteChecking () = 0 ;

};

class serviceChargeChecking : public checkingAccount  // done
{

public:
///pure virtual call:
void setwriteChecking ()
{
    cout << " write a limited number of checks each month: " ;
    int limNumOfCheck ; cin >> limNumOfCheck ;
    if ( limNumOfCheck < 0 )
        throw ErrorEenterException("You entered a negative number which isn't acceptable number.");
    setLimitCheckWriting(limNumOfCheck);
}
void Deposit()
{
    cout << " Enter the money you want to deposit: " ;
    double f ; cin >> f ;
    if ( f<0 )
        throw ErrorEenterException(" Not allowed  to deposit a negative number of money") ;
    setBalance(getBalance() + f) ;
    cout << " Your balance now = " << getBalance();
}

void Withdraw ()
{
    if (getBalance() <=0)
        {throw ErrorEenterException(" Your bank balance is less than or equal to zero, it is not allowed to withdraw money in this case.");}
        cout << " Enter the money you want to withdraw: " ;
        double f ; cin >> f ;
     if  (getBalance()-f < 0)
        {throw ErrorEenterException(" Your balance contains less than this amount, and it is not allowed to be negative");}
    setBalance(getBalance()-f);
    cout << " Your balance now = " << getBalance();
}

void PrintInterest ()
{
    cout <<  " There is no interest in this type of account." ;
}

///constractor:
serviceChargeChecking ()
{
    int choiceOfOneOfChecking ;
    for ( int i=0 ; choiceOfOneOfChecking !=6 ; i++)
    {
    cout << " \n >> Choose the transaction: << \n 1- Add to your balance. \n 2- Make a Withdraw from your balance. \n 3- print the interest. \n 4- print your information.\n 5- The limit number of check.\n 6- Exit. \n";

    cin>> choiceOfOneOfChecking;

    switch(choiceOfOneOfChecking)
     {
     case 1 :  { Deposit() ; break; }
     case 2 :  { Withdraw() ; break; }
     case 3 :  { PrintInterest() ; break; }
     case 4 :  { PrintInformation() ; break; }
     case 5 :  { setwriteChecking(); break; }
     case 6 :  {cout << " Thank you .\n\n"; break ; break; }}
     }
}

};

class noServiceChargeChecking : public checkingAccount  // done
{
public:
    double getMinimumBalance() { return 50 ;}
///pure virtual call:
void setwriteChecking ()
{
    cout << " This account without limit number of checks , you can write infinite checks. " ;
}

void Deposit()
{
    cout << " Enter the money you want to deposit: " ;
    double f ; cin >> f ;
    if ( f<0 )
        throw ErrorEenterException(" Not allowed  to deposit a negative number of money") ;
    setBalance(getBalance() + f) ;
    cout << " Your balance now = " << getBalance();
}

void Withdraw ()
{
    if (getBalance() <=getMinimumBalance())
        {throw ErrorEenterException(" Your bank balance is less than or equal to minimum balance, it is not allowed to withdraw money in this case.");}
        cout << " Enter the money you want to withdraw: " ;
        double f ; cin >> f ;
     if  (getBalance()-f < getMinimumBalance())
        {throw ErrorEenterException(" Your balance contains less than this amount, and it is not allowed to be negative");}
    setBalance(getBalance()-f);
    cout << " Your balance now = " << getBalance();
}

  void PrintInterest ()
{
    setInterest(getBalance()*0.2) ;
    cout << " The interest : " << getInterest();
}

///constractor:
noServiceChargeChecking ()
{
    int choiceOfOneOfChecking ;

     for ( int i=0 ; choiceOfOneOfChecking !=6 ; i++)
     {
     cout << " \n >> Choose the transaction: << \n 1- Add to your balance. \n 2- Make a Withdraw from your balance. \n 3- print the interest. \n 4- print your information.\n 5- The limit number of check.\n 6- Exit. \n";

     cin>> choiceOfOneOfChecking;

     switch(choiceOfOneOfChecking)
     {
     case 1 :  { Deposit() ; break; }
     case 2 :  { Withdraw() ; break; }
     case 3 :  { PrintInterest() ; break; }
     case 4 :  { PrintInformation() ; break; }
     case 5 :  { setwriteChecking(); break; }
     case 6 :  {cout << " Thank you .\n\n"; break ; break; }
     default : cout <<  " ðWrong number!";
     }
     }
}

};

class highInterestChecking : public noServiceChargeChecking  // done
{
public:
   void PrintInterest ()
{
    setInterest(getBalance()*0.3) ;
    cout << " The interest : " << getInterest();
}

double getMinimumBalance() { return 500 ;}

///constractor:
highInterestChecking ()
{
    int choiceOfOneOfChecking ;

     for ( int i=0 ; choiceOfOneOfChecking !=6 ; i++)
     {
     cout << " \n >> Choose the transaction: << \n 1- Add to your balance. \n 2- Make a Withdraw from your balance. \n 3- print the interest. \n 4- print your information.\n 5- The limit number of check.\n 6- Exit. \n";

     cin>> choiceOfOneOfChecking;

     switch(choiceOfOneOfChecking)
     {
     case 1 :  { Deposit() ; break; }
     case 2 :  { Withdraw() ; break; }
     case 3 :  { PrintInterest() ; break; }
     case 4 :  { PrintInformation() ; break; }
     case 5 :  { setwriteChecking(); break; }
     case 6 :  {cout << " Thank you .\n\n"; break ; break; }
     default : cout <<  "  Wrong number!";
     }
     }
}

};


/// :) >_< )_( ^_^   /// ### ### ### ### ### ### ### ### ### ### ### ### ### ### ///


class savingsAccount : public BankAccount  //done
{
    double interest;

public:

void setInterest(double t) { interest = t; }
double getInterest() { return interest ; }
void PrintInterest ()
{
    setInterest(getBalance()*0.06) ;
    cout << " The interest : " << getInterest();
}

///virtual functions call:

void Deposit()
{
    cout << " Enter the money you want to deposit: " ;
    double f ; cin >> f ;
    if ( f<0 )
        throw ErrorEenterException(" Not allowed  to deposit a negative number of money") ;
    setBalance(getBalance() + f) ;
    cout << " Your balance now = " << getBalance();
}

void Withdraw ()
{
    if (getBalance() <=0)
        {throw ErrorEenterException(" Your bank balance is less than or equal to zero, it is not allowed to withdraw money in this case.");}
        cout << " Enter the money you want to withdraw: " ;
        double f ; cin >> f ;
     if  (getBalance()-f < 0)
        {throw ErrorEenterException(" Your balance contains less than this amount, and it is not allowed to be negative");}
    setBalance(getBalance()-f);
    cout << " Your balance now = " << getBalance();
}

///constractor:
savingsAccount ()
{
     int choiceOfOneOfSaving ;
     for ( int i=0 ; choiceOfOneOfSaving !=5 ; i++)
     {
     cout <<"\n >> Choose the transaction: << \n 1- Add to your balance. \n 2- Make a Withdraw from your balance. \n 3- print the interest. \n 4- print your information.\n 5- Exit. \n";
     cin>> choiceOfOneOfSaving;
     switch(choiceOfOneOfSaving)
     {
     case 1 : {Deposit() ; break ;}
     case 2 : {Withdraw() ; break ;}
     case 3 : {PrintInterest() ; break ;}
     case 4 : {PrintInformation() ; break ;}
     case 5 :  {cout << " Thank you .\n\n"; break ; break;}
     default : cout <<  " Wrong number!";break ;}}

}

};

class highInterestSavings : public savingsAccount  //done
{
public:
    double getMinimumBalance() { return 200 ;}
    void PrintInterest() // why it didn't call this function ?
    {
        setInterest(getBalance()*0.21) ;
        cout << " The interst ::: " << getInterest();
    }

highInterestSavings ()
{
     int choiceOfOneOfSaving ;
     for ( int i=0 ; choiceOfOneOfSaving !=5 ; i++)
     {
     cout <<"\n >> Choose the transaction: << \n 1- Add to your balance. \n 2- Make a Withdraw from your balance. \n 3- print the interest. \n 4- print your information.\n 5- Exit. \n";
     cin>> choiceOfOneOfSaving;
     switch(choiceOfOneOfSaving)
     {
     case 1 : {Deposit() ; break ;}
     case 2 : {Withdraw() ; break ;}
     case 3 : {PrintInterest() ; break ;}
     case 4 : {PrintInformation() ; break ;}
     case 5 :  {cout << " Thank you .\n\n"; break ; break;} // why it doesn't stop here ?
     default : cout <<  " Wrong number!";break ;}}

}

};

/// ### ### ### ### ### ### ### ### ### ### ### ### ### ### /// ### ### ### ### ### ### ### ### ### ### ### ### ### ### ///


class certificateOfDeposit : public BankAccount
{
    double interest ;
    int numberOfCDMonth[2] ;
    int currentCDMonth[2] ;
public :

void setInterest(double t) { interest = t; }
double getInterest() { return 0.0 ; }
void PrintInterest ()
{
    setInterest(getBalance()*0.4) ;
    cout << " The interest : " << getInterest();
}

void setNumberOfCDMonth ( int e[] ) { numberOfCDMonth[0] = e[0] ; numberOfCDMonth[1] = e[1] ;}
string DateOfCD ()
{
    string DateOfCD ;
    DateOfCD[0] = numberOfCDMonth[0];
    DateOfCD[1] = numberOfCDMonth[1];
    return DateOfCD ;
}

void setCurrentCDMonth ( int e[] ) { currentCDMonth[0] = e[0] ; currentCDMonth[1] = e[1] ;}
string DateOfNow ()
{
    string DateOfNow ;
    DateOfNow[0] = currentCDMonth[0];
    DateOfNow[1] = currentCDMonth[1];
    return DateOfNow ;
}
void CurrentDate ()
{
    cout << "\n Enter the number of this month : ";
    int month ; cin >> month ;
    cout << " Enter the number of this year : ";
    int year ; cin >> year ;
    int date[2] ;
    date[0] = month;
    date[1] = year;
    setCurrentCDMonth(date);
}

void DrawDate ()
{
    cout << "\n Enter the number of this month : ";
    int month ; cin >> month ;
    cout << " Enter the number of this year : ";
    int year ; cin >> year ;
    int date[2] ;
    date[0] = month;
    date[1] = year;
    setNumberOfCDMonth(date);
}


void Deposit ()
{
    cout << " Enter the balance you would left for some time: " ;
    double f ; cin >> f ;
    if ( f<0 )
        throw ErrorEenterException(" Not allowed  to deposit a negative number of money") ;
    setBalance(getBalance() + f) ;
    cout << " Your balance now = " << getBalance();
}

void Withdraw() //not done
{



    cout << " Enter the money you want to withdraw: " ;
    double f ; cin >> f ;
     if  (getBalance()-f < 0)
        {throw ErrorEenterException(" Your balance contains less than this amount, and it is not allowed to be negative");}
    setBalance(getBalance()-f);
    cout << " Your balance now = " << getBalance();
}
///constractor:
certificateOfDeposit ()
{
    cout << "\n In an account of this type, money is left for some time, and these accounts draw higher interest rates. \n";
    CurrentDate();
    int choiceOfOneOfSaving ;
    for ( int i=0 ; choiceOfOneOfSaving !=5 ; i++)
    {
    cout <<"\n >> Choose the transaction: << \n 1- Add to your balance. \n 2- Make a Withdraw from your balance. \n 3- print the interest. \n 4- print your information.\n 5- Exit. \n";
    cin>> choiceOfOneOfSaving;
    switch(choiceOfOneOfSaving)
    {
    case 1 : {Deposit() ; break ;}
    case 2 : {Withdraw() ; break ;}
    case 3 : {PrintInterest() ; break ;}
    case 4 : {PrintInformation() ; break ;}
    case 5 :  {cout << " Thank you .\n\n"; break ; break;}
    default : cout <<  " Wrong number!";break ;}}


}



} ;

int main()
{

    CreateAccount();
}

void CreateAccount ()
{
     cout << "                                          *************************\n                                          *Welcome to AlASEEL Bank*\n                                          *************************";
     cout << " \n We have three types of accounts:\n 1- savings. \n 2- checking. \n 3- certificate of deposit.\n >> Choose the account number you want to create: ";
     int choice;
     cin >> choice;
     if ( choice >3 || choice<1 ){
     for ( int i=0 ; choice >3 || choice<1 ;i++){
        cout << " Wrong choice! Try again : ";
        cin >> choice;}}

     switch (choice)
     {
     case 1: {cout << "\n >>> Saving account <<< \n\n "; InfoAboutSavingAccount();break;}
     case 2: {cout << "\n >>> Checking acount <<< \n\n"; InfoAboutCheckingAccount();break;}
     case 3: {cout << "\n >>> Certificate of deposit account <<< \n\n"; InfoAboutCertificateOfDeposit();break;}
     default: {cout << " Invalid number !";
        }}
}

void InfoAboutSavingAccount ()
{
    cout << " ** We have two types of saving accounts:\n 1- Account that has no minimum balance and a lower interest rate \n ";
    cout << "2- Account that requires a minimum balance and has a higher interest rate. \n >> Choose a number of your choice: ";
    int choiceOfSavingAccount ; cin>>choiceOfSavingAccount;
    if (choiceOfSavingAccount >2 || choiceOfSavingAccount<1){
     for ( int i=0 ;choiceOfSavingAccount >2 || choiceOfSavingAccount<1 ;i++){
        cout << " Try again : ";
        cin >> choiceOfSavingAccount;} }
     switch (choiceOfSavingAccount)
     {
     case 1:{ savingsAccount Hi ; break ;}
     case 2:{ highInterestSavings Bye ; break;}
}};

void InfoAboutCheckingAccount ()
{
    cout << " ** We have three types of checking accounts:\n  1- Account that has monthly service charge, limited check writing, no minimum balance, and no interest.\n ";
    cout << " 2- Account that has no monthly service charge, a minimum balance requirement, unlimited check writing and lower interest. \n ";
    cout << " 3- Account that has no monthly service charge, a higher minimum requirement, a higher interest rate, and unlimited check writing. \n >> Choose a number of your choice : ";
    int choiceOfCheckingAccount ; cin>>choiceOfCheckingAccount;
    if (choiceOfCheckingAccount >3 || choiceOfCheckingAccount<1){
     for ( int i=0 ; choiceOfCheckingAccount >3 || choiceOfCheckingAccount<1 ;i++){
        if (choiceOfCheckingAccount >3 || choiceOfCheckingAccount<1){
        cout << " Try again : ";
        cin >> choiceOfCheckingAccount;}}
        }

    switch (choiceOfCheckingAccount)
     {
     case 1: { serviceChargeChecking Iam ; break; }
     case 2 : { noServiceChargeChecking so ; break; }
     case 3 :{ highInterestChecking bored ; break; }
    }
}

void InfoAboutCertificateOfDeposit ()
{
    certificateOfDeposit Ok ;
}

/*void InfoAboutNoServiceChargeChecking ()
{
     noServiceChargeChecking SS ;

     int choiceOfOneOfChecking ;

     for ( int i=0 ; choiceOfOneOfChecking !=6 ; i++)
     {
     cout << " \n >> Choose the transaction: << \n 1- Add to your balance. \n 2- Make a Withdraw from your balance. \n 3- print the interest. \n 4- print your information.\n 5- The limit number of check.\n 6- Exit. \n";

     cin>> choiceOfOneOfChecking;

     switch(choiceOfOneOfChecking)
     {
     case 1 :  { SS.Deposit() ; break; }
     case 2 :  { SS.Withdraw() ; break; }
     case 3 :  { SS.PrintInterest() ; break; }
     case 4 :  { SS.PrintInformation() ; break; }
     case 5 :  { SS.setwriteChecking(); break; }
     case 6 :  {cout << " Thank you .\n\n"; break ; break; }
     default : cout <<  " ðWrong number!";
     }
     }}
*/
/*void InfoAboutHighInterestChecking ()
{
     highInterestChecking SS ;

     int choiceOfOneOfChecking ;

     for ( int i=0 ; choiceOfOneOfChecking !=6 ; i++)
     {
     cout << " \n >> Choose the transaction: << \n 1- Add to your balance. \n 2- Make a Withdraw from your balance. \n 3- print the interest. \n 4- print your information.\n 5- The limit number of check.\n 6- Exit. \n";

     cin>> choiceOfOneOfChecking;

     switch(choiceOfOneOfChecking)
     {
     case 1 :  { SS.Deposit() ; break; }
     case 2 :  { SS.Withdraw() ; break; }
     case 3 :  { SS.PrintInterest() ; break; }
     case 4 :  { SS.PrintInformation() ; break; }
     case 5 :  { SS.setwriteChecking(); break; }
     case 6 :  {cout << " Thank you .\n\n"; break ; break; }
     default : cout <<  "  Wrong number!";
     }
     }

}
*/
/*void InfoAboutHighInterestSavings ()
{
    highInterestSavings S ;

     int choiceOfOneOfChecking ;
     for ( int i=0 ; choiceOfOneOfChecking !=6 ; i++)
     {
     cout <<"\n >> Choose the transaction: << \n 1- Add to your balance. \n 2- Make a Withdraw from your balance. \n 3- print the interest. \n 4- print your information.\n 5- Exit. \n";
     int choiceOfOneOfSaving ; cin>> choiceOfOneOfSaving;
     switch(choiceOfOneOfSaving)
     {
     case 1 : {S.Deposit() ; break ;}
     case 2 : {S.Withdraw() ; break ;}
     case 3 : {S.PrintInterest() ; break ;}
     case 4 : {S.PrintInformation() ; break ;}
     default: cout << " Thank you . ";break;}; break;}
}
*/

