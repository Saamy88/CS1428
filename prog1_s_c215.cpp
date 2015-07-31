/*
 File: prog1_s_c215.cpp
 
 Author: Samuel Cordova
 C.S.1428.3
 Program: #1
 Due Date: 09/18/13
 
 Prix fixe (pronounced "prefix") menus are common in Europe. A prix fixe
 menu typically includes a number of pre-determined items presented as a
 multi-course meal at a set price. For example, one evening, a restaurant
 may offer a four course prix fixe menu of escargot for the first course,
 beef bourguignon (boor-geen-yuhn) for the second, a cheese platter for
 the third, and creme brulee for dessert. The prix fixe menu for the
 evening, along with its cost, is typically posted on a message board
 outside the restaurant.
 
 =======================================================================
 
 This program prompts the user for the number of prix fixe meals ordered
 by the customer(s). The program calculates the total cost of the meal(s),
 the sales tax, the tip, and the total amount due. The program then prints
 in receipt form the individual price of a prix fixe meal, the number of
 prix fixe meals ordered, the total for all prix fixe meals ordered, the
 sales tax, the tip and the total amount due. Sample layout of a receipt
 is shown below.
 
 Input (keyboard): meals_ordered      (integer)
 Constants:
 Sample Values:
 PRIX_FIXE = 50.00         (double)
 SALES_TAX_RATE = .0825    (double)
 TIP_PERCENTAGE = .15      (double)
 Variables:
 meals_ordered             (int)
 total_meals               (double)
 tax                       (double)
 total                     (double)
 tip                       (double)
 total_due
 Output (console):
 Sample Layout:
 
 Author's Name
 C.S.1428.?    // '?' represents author's lecture section #
 --/--/--      // dashes represent due date, month/day/year
 <blank line>
 Prix Fixe Price:    $   50.00
 x     8
 Total for 8 meals:     400.00
 Sales Tax @8.25%        33.00
 15% Tip                 64.95
 Total Due:          $  497.95
 
 =======================================================================
 
 <Output will vary based on actual input and values used for constants.>
 */


#include <iostream>
#include <iomanip>

using namespace std;


int main ()

{
    
    const double  PRIX_FIXE = 44.50, SALES_TAX_RATE = .0825, TIP_PERCENTAGE = .15;
    
    int meals_ordered;
    
    double total_meals, tax, total, tip, total_due;
    
    
    cout << "Enter the number of prix meals ordered: ";
    cin  >> meals_ordered;
    
    
    total_meals = PRIX_FIXE * meals_ordered;
    
    tax = SALES_TAX_RATE * total_meals;
    
    total = tax + total_meals;
    
    tip = TIP_PERCENTAGE * total;
    
    total_due = total_meals + tip + tax;
    
    
    cout << "\n\nSamuel Cordova \n"
         << "C.S.1428.3 \n"
         << "09/18/13 \n\n";
    
    cout << fixed << setprecision(2)
         << "Prix Fixe Price:   $   " << setw(6) << PRIX_FIXE << endl
         << "                     x " << setw(6) << meals_ordered << endl
         << "Total for " << meals_ordered << " meals:     " << setw(6) << total_meals << endl
         << "Sales Tax @" << SALES_TAX_RATE*100 << "%       "<< setw(6) << tax << endl
         << fixed << setprecision (0)
         << TIP_PERCENTAGE*100 << "% Tip                " << setw(6)
         << fixed << setprecision(2)
         << tip << endl
         << "Total Due:         $   " << setw(6) << total_due << endl;
    
    return 0;
    
    
    
}





