// CIS_1111_Unit_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Dean Mason
//1/31/2025
//Program Description: To allow customers to make a purchase, utilizing discounts and additional fees, giving bill at the end
//Description update: adding rewards, multiple ways to place order


#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    //declaring vars

    string Name;
    string Address;
    double mileage;

    //I will do the variables and math accounting for the weight of items to show that I can, but it is unnecessary for an item that is sold by the pound
    const double POUND_RATE = 2.65;
    const double MILE_RATE = 0.45;
    const double WW_WEIGHT = 16;
    const double AP_WEIGHT = 16;
    const double BW_WEIGHT = 16;
    const double OZ_PER_LB = 16;
    const double buckwheatPrice = 5.0;
    const double wholeWheatPrice = 6.5;
    const double allPurposePrice = 3.5;
    const double TAX_RATE = 0.075;
    const double CASH_DISCOUNT = 0.1;
    const double FINANCE_FEE = 0.15;

    int buckwheatPurchase;
    int wholeWheatPurchase;
    int allPurposePurchase;
    int totalItem;

    //more vars 
    int bwStock = 174;
    int wwStock = 200;
    int apStock = 354;
    double discount;
    double distCost;
    double poundCost;
    double totalWeight;
    string currentStatus;
    string nextTier;
    double financeCharge = 1.00;
    double previousSpent;
    double upgradePrice;
    double deliveryTotal;
    double totalBW;
    double totalWW;
    double totalAP;
    double totalBillPre;
    double taxCash;
    double cashBill;
    double finalCash;
    double avgCashPPI;
    double avgCreditPPI;
    double newTotal;
    double taxCredit;
    double creditBill;
    double finalCredit;
    double finance;
    double onlineOrderTot;
    int method;

    //Giving info for pricing to customers

    cout << "Good afternoon and welcome to Insane Grains!\nJust a heads up, all of my bags are 1lb and I'm not splitting them open!\n";
    cout << "For sale today we have:\n";
    cout << bwStock << " pounds of Buckwheat at $" << buckwheatPrice << " each.\n";
    cout << wwStock << " pounds of Whole wheat at $" << wholeWheatPrice << " each.\n";
    cout << apStock << " pound of All-Purpose at $" << allPurposePrice << " each.\n";

    //getting the order in, telling reward status
    cout << "\nPlease enter the name for your order please: ";
    getline(cin, Name);
    cout << "\nHow much have you spent at Insane Grains?: $";
    cin >> previousSpent;

    if (previousSpent > 0.0 && previousSpent <= 100.0)
    {
        currentStatus = "Bronze";
        upgradePrice = 100.0 - previousSpent;
        nextTier = "Silver";
    }
    else if (previousSpent > 100.0 && previousSpent < 200.0)
    {
        currentStatus = "Silver";
        upgradePrice = 200.0 - previousSpent;
        nextTier = "Gold";
    }
    else if (previousSpent >= 200)
    {
        currentStatus = "Gold";
        upgradePrice = 0;
        financeCharge = 0;
    }
    else
    {
        cout << "Unfortunately you did not enter a valid number. Please run the program again and enter a valid number!" << endl;
        exit(0);
    }

    if (upgradePrice > 0)
    {
        cout << "\nYou are a " << currentStatus << " Member. You must spend $" << upgradePrice << " to reach " << nextTier << " Membership.\n";
    }
    else
    {
        cout << "You are a Gold member. All of your financing fees are waived, so spend away!\n";
        financeCharge = 0.0;
    }

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
   
    cout << "\n\n\nHow would you like to place your order? ";
    cout << "\nEnter 1 for cash \nEnter 2 for Card \nEnter 3 for Web Order ";
    cin >> method;
    
    //math math
    totalItem = buckwheatPurchase + allPurposePurchase + wholeWheatPurchase;
    totalBW = buckwheatPrice * buckwheatPurchase;
    totalWW = wholeWheatPrice * wholeWheatPurchase;
    totalAP = allPurposePrice * allPurposePurchase;
    totalBillPre = totalBW + totalWW + totalAP;
    

    switch (method) {
        case 1:
            //math for cash
            discount = (totalBillPre * CASH_DISCOUNT);
            cashBill = totalBillPre - discount; 
            taxCash = cashBill * TAX_RATE; 
            finalCash = taxCash + cashBill; 
            avgCashPPI = finalCash / totalItem; 
            newTotal = previousSpent + finalCash; 

            cout << "-------------CASH BILL---------------\n";
            cout << setw(35) << left << "Total Price Before Discount: $" << setw(13) << right << fixed << setprecision(2) << totalBillPre << endl;
            cout << setw(35) << left << "Tax Amount: $" << setw(13) << right << fixed << setprecision(2) << taxCash << endl;
            cout << setw(35) << left << "Discount Amount: $" << setw(13) << right << fixed << setprecision(2) << discount << endl;
            cout << setw(35) << left << "Subtotal: $" << setw(13) << right << fixed << setprecision(2) << finalCash << endl;
            cout << setw(35) << left << "Average cost per item: $" << setw(13) << right << fixed << setprecision(2) << avgCashPPI << endl;
            cout << setw(35) << left << "New total amount spent: " << setw(13) << right << fixed << setprecision(2) << newTotal << endl;
            break;


        case 2:
            //math, the financeCharge being 1 unless the if statement for gold allows the clunky version of this to work. I put too much time in to make it better this version.
            finance = (totalBillPre * FINANCE_FEE) * financeCharge;
            creditBill = totalBillPre + finance;
            taxCredit = creditBill * TAX_RATE;
            finalCredit = taxCredit + creditBill;
            avgCreditPPI = finalCredit / totalItem; 
            newTotal = previousSpent + finalCredit; 

            cout << "\n\n\n-------------CREDIT BILL -----------------\n";
            cout << setw(35) << left << "Subtotal: $" << setw(13) << right << fixed << setprecision(2) << totalBillPre << endl;
            cout << setw(35) << left << "Tax Amount: $" << setw(13) << right << fixed << setprecision(2) << taxCredit << endl;
            cout << setw(35) << left << "Finance Charge Amount: $" << setw(13) << right << fixed << setprecision(2) << finance << endl;
            cout << setw(35) << left << "Subtotal with tax & finance fee: $" << setw(13) << right << fixed << setprecision(2) << finalCredit << endl;
            cout << setw(35) << left << "Average price per item: $" << setw(13) << right << fixed << setprecision(2) << avgCreditPPI << endl;
            cout << setw(35) << left << "New total amount spent: " << setw(13) << right << fixed << setprecision(2) << newTotal << endl;
            break;


        case 3:
            cout << "\nEnter an address for your order please: ";
            cin.ignore();
            getline(cin, Address);
            cout << "\nEnter the distance (in miles) from the store: ";
            cin >> mileage;

            //math
            finance = (totalBillPre * FINANCE_FEE) * financeCharge; 
            creditBill = totalBillPre + finance; 
            taxCredit = creditBill * TAX_RATE; 
            finalCredit = taxCredit + creditBill; 
            avgCreditPPI = finalCredit / totalItem; 

            //boring
            totalWeight = (buckwheatPurchase * (BW_WEIGHT / OZ_PER_LB)) + (allPurposePurchase * (AP_WEIGHT / OZ_PER_LB)) + (wholeWheatPurchase * (WW_WEIGHT / OZ_PER_LB));
            distCost = MILE_RATE * mileage;
            poundCost = totalWeight * POUND_RATE;
            deliveryTotal = distCost + poundCost;
            onlineOrderTot = deliveryTotal + finalCredit;
            newTotal = onlineOrderTot + previousSpent;

            cout << "\n\n\n-------------CREDIT BILL -----------------\n";
            cout << setw(35) << left << "Subtotal: $" << setw(13) << right << fixed << setprecision(2) << totalBillPre << endl;
            cout << setw(35) << left << "Tax Amount: $" << setw(13) << right << fixed << setprecision(2) << taxCredit << endl;
            cout << setw(35) << left << "Finance Charge Amount: $" << setw(13) << right << fixed << setprecision(2) << finance << endl;
            cout << setw(35) << left << "Subtotal with tax & finance fee: $" << setw(13) << right << fixed << setprecision(2) << finalCredit << endl;
            cout << setw(35) << left << "Average price per item: $" << setw(13) << right << fixed << setprecision(2) << avgCreditPPI << endl;
            
            
            //i did not include the ounces section because flour is typically not sold by the ounce, but the math above works it would be very simple to add if the product were changed
            cout << "\n\n-------------SHIPPING REPORT-----------------\n";
            cout << "Customer Name: " << Name << endl;
            cout << "Shipping to: " << Address << endl;
            cout << setw(35) << left << "\n\nDistance Cost: " << setw(15) << right << fixed << setprecision(2) << distCost << endl; 
            cout << setw(35) << left << "Pound Cost: " << setw(13) << right << fixed << setprecision(2) << poundCost << endl; 
            cout << setw(35) << left << "Total Shipping cost: " << setw(13) << right << fixed << setprecision(2) << deliveryTotal << endl;
            cout << endl;
            cout << setw(35) << left << "ONLINE ORDER TOTAL: " << setw(13) << right << fixed << setprecision(2) << onlineOrderTot << endl;
            cout << setw(35) << left << "New total amount spent: " << setw(13) << right << fixed << setprecision(2) << newTotal << endl;
            break;
        
           //catch invalid input
           default:
            cout << "You have entered an invalid number. Please restart the program to try again!";
            exit(0);
    }
    //this section will decide how/what to say for their rewards status and how much to get to a new one. 
    if (newTotal <= 100.0) 
    { 
        currentStatus = "Bronze";
        upgradePrice = 100.0 - newTotal;
        cout << "\n\nYou are currently a " << currentStatus << " rewards member. You need to spend $" << upgradePrice << " to move to the next tier" << endl;
        cout << "Have a wondeful day!" << endl;
    }
    else if (newTotal > 100.0 && newTotal < 200.0 && previousSpent < 100.0)
    {
        currentStatus = "Silver";
        upgradePrice = 200.0 - newTotal;
        cout << "\n\nYou are currently a " << currentStatus << " rewards member. You need to spend $" << upgradePrice << " to move to the next tier" << endl;
        cout << "Have a wondeful day!" << endl;
    }
    else if (newTotal >= 200 && currentStatus != "Gold")
    {
        cout << "\n\nCONGRATULATIONS! You are now a Gold Rewards Member, and your next purchase will not be subject to finance charges." << endl;
        cout << "Have a wonderful day!" << endl; 
        
    }
    //the math in my previous arguments will catch everybody else that didn't start as a gold member, so this is what would go in the trailing else.
    else
    {
        cout << "\n\nYou are a Gold rewards member, we thank you for your continued support! Have a wonderful day!";
    }
    

}