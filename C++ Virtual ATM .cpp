
//
//  main.cpp
//  FinalProject Sunday May 6 1630 hours
//
//  Created by Benjamin Cashman on 5/1/17.
//  Copyright © 2017 Benjamin Cashman. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


const int SIZE_OF_ARRAY= 10;
double balanceArray[SIZE_OF_ARRAY]={1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
int customerIndex;
bool isSignedIn= false;


// PROTO TYPES OF FUNCTIONS
int menuFunction();
void signIn();
void showBalanceFun(double balanceArray[], int customerIndex);
void moneyDepositFun(double balanceArray[], int customerIndex);
void moneyWithdrawalFun(double balanceArray[], int customerIndex);
void changeAccountFun(double balanceArray[], int customerIndex);





int main() {


    // TAKE IN RESPONSE FROM USER
    int menuResponse = menuFunction();

    while (menuResponse >= 0 && menuResponse <= 5){

        // MENU FUNCITON FOR SIGNING IN
        if (menuResponse == 1 && isSignedIn == false )
        {
            signIn();
        }
        // IF USER IS ALREADY SIGNED IN
        if (menuResponse == 1 && isSignedIn == true )
        {
//            cout<< "Already Signed In , Exit to change accounts " << endl;
//            cout <<  " " << endl;
        }

        // MENU RESPONSE FOR SHOWING THE BALANCE
        if ( menuResponse == 2 && isSignedIn == true)
            showBalanceFun(balanceArray,customerIndex);

        // IF NOT SIGNED IN SEND BACK TO MENU
        if (menuResponse == 2 && isSignedIn == false) {
            cout << "*******************************\n";
            cout << "Please sign into your account first"<< endl;
            cout << "*******************************\n";
            ///menuFunction();
        }
        // MENU RESPONSE TO MAKE A DEPOSIT INTO SELECTED ACCOUNT
        if (menuResponse == 3 && isSignedIn == true)
            moneyDepositFun(balanceArray, customerIndex);

        // MENU RETURNS TO MAIN MENU IF NOT SIGNED IN
        if (menuResponse == 3 && isSignedIn == false) {
            cout << "*******************************\n";
            cout << "Please sign into account first"<< endl;
            cout << "*******************************\n";
            /// menuFunction();
        }
        // MENU RESPONSE TO WITHDRAW FROM SLECTED ACCOUNT
        if ( menuResponse == 4 && isSignedIn == true)
            moneyWithdrawalFun(balanceArray, customerIndex);

        // RETURN TO MAIN MENU IF NOT SIGNED IN
        if (menuResponse == 4 && isSignedIn == false) {
            cout << "*******************************\n";
            cout << "Please sign into account first"<< endl;
            cout << "*******************************\n";
            ///menuFunction();
        }

        if (menuResponse == 5){
            changeAccountFun(balanceArray, customerIndex);
            // isSignedIn = false;
        }
        menuResponse = menuFunction();
    }


    return 0;
}



//INITIALIZE THE MENU FOR USER TO SEE
int menuFunction()
{
    // ASSIGN VALUE SO WE CAN RUN WHILE LOOP
    int userInput = 9000;
    char userSelection;

    // RUN WHILE LOOP THAT ONLY TAKES APPROPRIATE PARAMETERS
    while ((userInput != (1) || userInput != 2 || userInput != 3 || userInput != 4 || userInput != 5)){

        cout << "1. Sign in " << endl;
        cout << "2. Check balance" << endl;
        cout << "3. Make deposit" << endl;
        cout << "4. Make Withdrawal" << endl;
        cout << "5. Exit Account" << endl;
        cout << "Please enter a number on the menu : ";

        // ALLOW USER TO SELECT OPTION AND RETURN VALUE BASED ON ENTRY
        cin >> userInput;
        cout << endl;

        if ( userInput >= '0' && userInput <='5')
        {
            userSelection = static_cast<char>(userInput)-48;
            isSignedIn = true;
            customerIndex = userSelection;
            cout  << "You have chosen account # " << customerIndex<<endl;
        }



        //IF STATEMENTS THAT RETURN VALUE
        if(userInput == 1)
            return 1;
        else if(userInput  == 2)
            return 2;
        else if (userInput == 3)
            return 3;
        else if(userInput == 4)
            return 4;
        else if (userInput == 5)
            return 5;
        else
            cout << " " << endl;
        cout << "Invalid entry, Try again" << endl;
        cout << " " << endl;
        // return menuFunction();
    }
}

void signIn()
{
    // INITIALIZE USER SELECTION TO BE WITHIN ARRAY
    int userSelection;
    char userInput;
    cout << "Please enter account #, using a single integer 0 - 9 " << endl;
    cout << " here :  ";
    cin >> userInput;


    // TEST TO ENSURE USER SELECTION IS A VALID SELECTION
    // USE KEYBOARD AS CHAR  TO TEST FOR EXCLUSIVITY OF DIGITS 0 TO 9
    // USE CAST OF CHAR TO ASC(( VALUE OF CHAR) -48) TO SET customerIndex
    if ( userInput >= '0' && userInput <='9')
    {
        userSelection = static_cast<char>(userInput)-48;
        isSignedIn = true;
        customerIndex = userSelection;
        cout  << "You have chosen account # " << customerIndex<<endl;

        //RETURN BACK TO MAIN MENU




        //TEST THE VALUE FOR SIGN IN
        //cout << "User selection in signIn is " << userSelection<<endl;
    }else
    {
        cout << "Invalid Input\n";
        signIn();
    }
}

void moneyWithdrawalFun(double balanceArray[], int customerIndex)
{
    int attempt = 0;
    double withdrawalAmount = 0;

    cout << "You have " << balanceArray[customerIndex] << " in your account" << endl;
    cout <<"How much $ would you like to withdraw from your account?\n" ;
    cin >> withdrawalAmount;

    if (attempt < 2 || (balanceArray[customerIndex] - withdrawalAmount) < 0 || withdrawalAmount < 0){
        while (attempt < 1 && (balanceArray[customerIndex] - withdrawalAmount < 0)){
            {
                attempt++;
                cout << "insufficent funds, enter new amount : ";
                cin >> withdrawalAmount;
            }
        }

        if (withdrawalAmount < 0){
            cout << "Invalid entry. " << endl;
        }

    }
    // Accept input and update balance
    if ((balanceArray[customerIndex] - withdrawalAmount >= 0) && withdrawalAmount >0){
        balanceArray[customerIndex] = balanceArray[customerIndex] - withdrawalAmount;
        cout << "*******************************\n";
        cout << "The withdrawal of $"<< withdrawalAmount<<" processed sucessfully\n\n";
        cout <<"The UPDATED balance in account number " << customerIndex  << "  NOW = $" << balanceArray[customerIndex]<<endl;
    }
}

void moneyDepositFun(double balanceArray[], int customerIndex)
{
    double depositAmount;
    int attempt = 0;

    cout <<"How much $ would you like to deposit into your account?\n";
    cin >> depositAmount;
    if (depositAmount <= 0 && attempt < 2){
        while (depositAmount <= 0 && attempt < 1){
            attempt++;
            cout << "Invalid amount, make new entry." << endl;
            cin >> depositAmount;
        }
    }
    // Accept input and update balance

    else
    {
        balanceArray[customerIndex] = balanceArray[customerIndex] + depositAmount;
        cout << "*******************************\n";
        cout << "The depost of $"<< depositAmount<<" processed sucessfully\n\n";
        cout <<"The UPDATED balance in account number " << customerIndex << "  NOW = $" << balanceArray[customerIndex]<<endl;}

}


void showBalanceFun(double balanceArray[], int customerIndex)
{
    cout <<"The balance in account number " << customerIndex << " is currently = $" << balanceArray[customerIndex]<<endl;

    if (balanceArray[customerIndex] < 100){
        cout << "****************" << endl;
        cout << "Balance is low. " << endl;
        cout <<  " " << endl;

    }
}

void changeAccountFun(double balanceArray[], int customerIndex)
{
    if(isSignedIn == true){
        cout << "Good Bye. " << endl;}
    else if (isSignedIn == false){
        cout << "User not signed in" << endl;
    }
    //cout << "Select anoter Account to change Account\n";
    isSignedIn = false;

    ///menuFunction();
}
