// CIS_1111_Unit_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Dean Mason
//1/13/2025
//Program Description: To allow customers to make a purchase, utilizing discounts and additional fees, giving bill at the end
//Description again?


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    //declaring vars
    double buckwheatPrice;
    double wholeWheatPrice;
    double allPurposePrice;

    const double TAX_RATE = 0.075;
    const double CASH_DISCOUNT = 0.1;
    const double FINANCE_FEE = 0.15;

    int buckwheatPurchase;
    int wholeWheatPurchase;
    int allPurposePurchase;
    
    //more vars
    double totalBW;
    double totalWW;
    double totalAP;
    double totalBillPre;
    double finance;
    double discount;
    double cashBill;
    double creditBill;
    double taxCash;
    double taxCredit;
    double finalCash;
    double finalCredit;
    double avgCashPPI;
    double avgCreditPPI;
    double totalItem;
    double cashSaved;

    //setting the price/pound of the flours
    buckwheatPrice = 5;
    wholeWheatPrice = 6.5;
    allPurposePrice = 3.5;
   
    //Giving info for pricing to customers

    cout << "Good afternoon and welcome to Insane Grains!\nJust a heads up, all of my bags are 1lb and I'm not splitting them open!\n";
    cout << "For sale today we have:\n";
    cout << "Buckwheat at $" << buckwheatPrice << " per lb\n";
    cout << "Whole wheat at $" << wholeWheatPrice << " per lb\n";
    cout << "All purpose at $" << allPurposePrice << " per lb\n";

    //getting the order in

    cout << "How many pounds of buckwheat would you like? ";
    cin >> buckwheatPurchase;
    cout << "How many pounds of whole wheat would you like? ";
    cin >> wholeWheatPurchase;
    cout << "How many pounds of all purpose would you like? ";
    cin >> allPurposePurchase;
    cout << "Alrighty, one second while I get everything sorted out for you and bagged up\n\n\n";
    
    //now to do math

    totalBW = buckwheatPrice * buckwheatPurchase;
    totalWW = wholeWheatPrice * wholeWheatPurchase;
    totalAP = allPurposePrice * allPurposePurchase;
    totalBillPre = totalBW + totalWW + totalAP;
    totalItem = buckwheatPurchase + wholeWheatPurchase + allPurposePurchase;


    //bill setup, more math
    //instructions say to take discount or apply finance charge BEFORE tax, even though example output shows different, I am going by written instruction
    discount = (totalBillPre * CASH_DISCOUNT);
    cashBill = totalBillPre - discount;
    finance = (totalBillPre * FINANCE_FEE);
    creditBill = totalBillPre + FINANCE_FEE;
    
    taxCash = cashBill * TAX_RATE;
    taxCredit = creditBill * TAX_RATE;
    finalCash = taxCash + cashBill;
    finalCredit = taxCredit + creditBill;

    avgCashPPI = finalCash / totalItem;
    avgCreditPPI = finalCredit / totalItem;
    cashSaved = avgCreditPPI - avgCashPPI; 

    //setprecision(2) makes it so that we only get the 2 decimal places afterwards
    
    cout << fixed << setprecision(2);
    cout << "-------------CASH BILL---------------\n";
    cout << "Total Price Before Discount: $" << totalBillPre << endl;
    cout << "Tax Amount: $" << taxCash << endl;
    cout << "Discount Amount: $" << discount << endl;
    cout << "Subtotal with tax % discount applied: $" << finalCash << endl;
    cout << "Average cost per item: $" << avgCashPPI << endl;

    //credit bill sorting
     
    cout << "\n\n\n-------------CREDIT BILL -----------------\n";
    cout << "Total Price Before Discount: $" << totalBillPre << endl;
    cout << "Tax Amount: $" << taxCredit << endl;
    cout << "Finance Charge Amount: $" << finance << endl;
    cout << "Subtotal with tax & finance fee: $" << finalCredit << endl;
    cout << "Average price per item: $" << avgCreditPPI << endl;
    cout << "If you pay with cash, you would save $" << cashSaved << " per item!"<< endl;
    cout << "Thank you for shopping here!!!\n";

}
