// CIS_1111_Unit_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Dean Mason
//1/22/2025
//Program Description: To allow customers to make a purchase, utilizing discounts and additional fees, giving bill at the end
//Description update:added functionality for online ordering and shipping. Also adding a random discount to online purchases, removing credit/cash bill showing 


#include <iostream>
#include <cmath>
#include <iomanip>
#include<random>
#include<string>

using namespace std;

int main()
{
    //random discount 
    random_device randomDiscount;
    uniform_int_distribution<int> randomInt(1, 10);
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

    int buckwheatPurchase;
    int wholeWheatPurchase;
    int allPurposePurchase;

    //more vars  
    double subtotal;
    double total;
    double discount;
    double distCost;
    double poundCost;
    double discountPct;
    double shipping;
    double totalWeight;

    

    //Giving info for pricing to customers

    cout << "Good afternoon and welcome to Insane Grains!\nJust a heads up, all of my bags are 1lb and I'm not splitting them open!\n";
    cout << "For sale today we have:\n";
    cout << "26 pounds of Buckwheat\n";
    cout << "103 pounds of Whole wheat\n";
    cout << "73 pound of All-Purpose\n";

    //getting the order in

    cout << "\nHow many pounds of buckwheat would you like? ";
    cin >> buckwheatPurchase;
    cout << "\nHow many pounds of whole wheat would you like? ";
    cin >> wholeWheatPurchase;
    cout << "\nHow many pounds of all purpose would you like? ";
    cin >> allPurposePurchase;
    cout << "\nEnter a name for your order please: ";
    cin.ignore();
    getline(cin, Name);
    cout << "\nEnter an address for your order please: ";
    getline(cin, Address);
    cout << "\nEnter the distance (in miles) from the store: ";
    cin >> mileage;


    //now to do math
    int randomNum = randomInt(randomDiscount);
    discountPct = randomNum / 100.0;
    totalWeight = (buckwheatPurchase * (BW_WEIGHT / OZ_PER_LB)) + (allPurposePurchase * (AP_WEIGHT / OZ_PER_LB)) + (wholeWheatPurchase * (WW_WEIGHT / OZ_PER_LB));
    distCost = MILE_RATE * mileage; 
    poundCost = totalWeight * POUND_RATE;
    subtotal = distCost + poundCost;
    discount = discountPct * subtotal;
    total = subtotal - discount;


    //bill setup, more math
    cout << "\n\n\nCustomer Name: " << Name << endl;
    cout << "Shipping to: " << Address << endl;
    cout << setw(25) << left << "\n\nDistance Cost: " << setw(17) << right << fixed << setprecision(2) << distCost << endl;
    cout << setw(25) << left << "Pound Cost: " << setw(15) << right << fixed << setprecision(2) << poundCost << endl;
    cout << setw(25) << left << "Subtotal: " << setw(15) << right << fixed << setprecision(2) << subtotal << endl;
    cout << setw(25) << left << "Discount pct: " << setw(15) << right << fixed << setprecision(2) << discountPct << endl;
    cout << setw(25) << left << "Discount: " << setw(15) << right << fixed << setprecision(2) << discount << endl;
    cout << setw(25) << left << "\n\nTotal Shipping Cost: " << setw(15) << right << fixed << setprecision(2) << total << endl;
    cout << "\nThank you for shopping here! Have a wonderful day!" << endl;


}
