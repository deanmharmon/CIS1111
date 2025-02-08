// CIS_1111_Unit_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Dean Mason
//2/07/2025
//Program Description: To allow customers to make a purchase, utilizing discounts and additional fees, giving bill at the end
//Description update: Utilizing loops to allow for multiple customers to place orders by set of 3, and writing information to file, then reading info from file to be able to do the calculations


#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    //declaring vars
    const double buckwheatPrice = 5.0;
    const double wholeWheatPrice = 6.5;
    const double allPurposePrice = 3.5;
    const double TAX_RATE = 0.075;
    const double CASH_DISCOUNT = 0.1;
    const double FINANCE_FEE = 0.15;
    const int CASH = 1, CREDIT = 2, CHECK = 3;
    int buckwheatPurchase;
    int wholeWheatPurchase;
    int allPurposePurchase;
    int totalItem; 
    //these are not constants so as to allow them to lower but it was not required this assignment and I didn't want to run out
    int bwStock = 174;
    int wwStock = 200;
    int apStock = 354;
    double discount;
    double totalBW;
    double totalWW;
    double totalAP;
    double totalBillPre;
    double taxCash;
    double cashBill;
    double finalCash;
    double taxCredit;
    double creditBill;
    double finance;
    double subtotalCash, subtotalCard, subtotalCheck; 
    double finalCheck, finalSub, totalTax, taxCheck, endAllBeAll;
    int itemCard = 0, itemCash = 0, itemCheck = 0; 
    int cont = 0;
    int beginning; //this is for the first loop, I'm bad with naming
    int paymentMeth;
    string Name; 
   
    //opening the file here, first initializing ofstream object
    ofstream oFile;
    oFile.open("Cust_Data.txt");

    cout << "Good afternoon and welcome to Insane Grains!\nJust a heads up, all of my bags are 1lb and I'm not splitting them open!\n";
    cout << "For sale today we have:\n";
    cout << bwStock << " pounds of Buckwheat at $" << buckwheatPrice << " each.\n";
    cout << wwStock << " pounds of Whole wheat at $" << wholeWheatPrice << " each.\n";
    cout << apStock << " pound of All-Purpose at $" << allPurposePrice << " each.\n";

    cout << "Would you like to enter a customer's order? Enter 1 for yes and 2 for no\n";
    cin >> beginning;
    if (beginning == 2)
    {
        cout << "Well have a good day!";
        return 0;
    }
    else if (beginning >= 2 || beginning <= 0)
    {
        cout << "You have entered an invalid input, please restart the program.";
        return 0;
    }

    //using the do version of a while statement to ensure that it runs the first time through
    do
    {
        //getting the order in
        cout << "\nPlease enter the name for your order : ";
        cin.ignore();
        getline(cin, Name);

        oFile << Name << " ";

        for (int count = 0; count < 3; count++)
        {
            //if statements here are to catch invalid input
            cout << "\nHow many pounds of buckwheat would you like? ";
            cin >> buckwheatPurchase;
            if (buckwheatPurchase > bwStock)
            {
                cout << "Unfortunately we only have " << bwStock << " pounds in stock, so we'll set that as your order\n" << endl;
                buckwheatPurchase = bwStock;
            }

            cout << "\nHow many pounds of whole wheat would you like? ";
            cin >> wholeWheatPurchase;
            if (wholeWheatPurchase > wwStock)
            {
                cout << "Unfortunately we only have " << wwStock << " pounds in stock, so we'll set that as your order\n" << endl;
                wholeWheatPurchase = wwStock;
            }

            cout << "\nHow many pounds of all purpose would you like? ";
            cin >> allPurposePurchase;

            if (allPurposePurchase > apStock)
            {
                cout << "Unfortunately we only have " << apStock << " pounds in stock, so we'll set that as your order\n" << endl;
                allPurposePurchase = apStock;
            }

            cout << "Are you paying by Cash, Card, or Check today? Please enter 1 for Cash, 2 for Card, 3 for check\n";
            cin >> paymentMeth;
            if (paymentMeth != 1 && paymentMeth != 2 && paymentMeth != 3)
            {
                cout << "You did not enter a valid option, please restart the program";
            }

            //math math
            totalItem = buckwheatPurchase + allPurposePurchase + wholeWheatPurchase;
            totalBW = buckwheatPrice * buckwheatPurchase;
            totalWW = wholeWheatPrice * wholeWheatPurchase;
            totalAP = allPurposePrice * allPurposePurchase;
            totalBillPre = totalBW + totalWW + totalAP;
            //writing to file
            oFile << totalBillPre << " ";
            oFile << paymentMeth << " ";
            oFile << totalItem << " ";
        }
        oFile << "\n";
        cout << "Would you like to place another order? Please type 1 for Yes and 2 for no: ";
        cin >> cont;

    } while (cont == 1);

    oFile.close();

    ifstream iFile;
    iFile.open("Cust_Data.txt");
    

    if (iFile.is_open())
    {
        //starts by reading first name, then loops 3 times to get the totals for everything for each type of transaction
        while (iFile >> Name) 
        {
            //resets numbers each iteration
            subtotalCash = 0;
            subtotalCard = 0;
            subtotalCheck = 0;
            itemCash = 0;
            itemCard = 0;
            itemCheck = 0; 

            for (int count = 0; count < 3; count++)
            {
                iFile >> totalBillPre >> paymentMeth >> totalItem;
                if (paymentMeth == CASH)
                {
                    subtotalCash = subtotalCash + totalBillPre;
                    itemCash = itemCash + totalItem;
                }
                else if (paymentMeth == CREDIT) 
                {
                    subtotalCard = subtotalCard + totalBillPre; 
                    itemCard = itemCard + totalItem;
                }
                else if (paymentMeth == CHECK)  
                {
                    subtotalCheck = subtotalCheck + totalBillPre;
                    itemCheck = itemCheck + totalItem;
                }
            }

            //math for cash and subtotal pretax and discount
            totalItem = itemCard + itemCash + itemCheck;
            finalSub = subtotalCard + subtotalCash + subtotalCheck;
            discount = (subtotalCash * CASH_DISCOUNT);
            cashBill = subtotalCash - discount;
            taxCash = cashBill * TAX_RATE;
            
            //math for credit

            finance = (subtotalCard * FINANCE_FEE);
            creditBill = subtotalCard + finance;
            taxCredit = creditBill * TAX_RATE;
           
            //math for check
            //don't need to discount or finance, so just figuring out tax then adding all taxes
            taxCheck = subtotalCheck * TAX_RATE;
            finalCheck = subtotalCheck + taxCheck;
            totalTax = taxCash + taxCheck + taxCredit;
            //absolute final math to show, it could be easier to do them and show them seperately with the previous code, but this is what's desired for this assign
            endAllBeAll = finalSub - discount + totalTax + finance;

            //not quite sure what's needed to be output, but outputting everything that comes below thick lines on exceel sheet
            cout << setw(35) << left << "Name for ocustomer: " << setw(13) << right << fixed << Name << endl; 
            cout << setw(35) << left << "Total items purchased: " << setw(13) << right << fixed << totalItem << endl;
            cout << setw(35) << left << "Subtotal: " << setw(13) << right << fixed << setprecision(2) << finalSub << endl;
            cout << setw(35) << left << "Tax Amt: " << setw(13) << right << fixed << setprecision(2) << totalTax << endl;
            cout << setw(35) << left << "Total Cash Discount Amt: " << setw(13) << right << fixed << setprecision(2) << discount << endl;
            cout << setw(35) << left << "Total Finance Charge: " << setw(13) << right << fixed << setprecision(2) << finance << endl;
            cout << setw(35) << left << "Final Total: " << setw(13) << right << fixed << setprecision(2) << endAllBeAll << endl;
            cout << "\n\n\n";
        }
        
    }
    else
    {
        //in case it doesn't work, but it will
        cout << "File could not be opened. Please retry with file in correct directory" << endl;
        return 0;
    }
    //close the file
    iFile.close();
    return 0;
}


