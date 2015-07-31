/* 
    File: prog0_s_c215.cpp
   
    Author:Samuel Cordova
    C.S.1428.3
    Program: #0
    Due Date: 09/04/13
 
    This program
        - prints the student's first and last names on the 1st line of output,
          last name first.
          e.g. Smith, John
        - prints 'C.S.1428.#' (without quotation marks) on the 2nd line of
          output with the student's lecture section number in place of the
          # sign
        - prints this program's due date on the 3rd line of output
        - leaves line four blank
        - prints 'Major: <student's major>'(without quotation marks)
          on the 5th line of output with the student's major in place of
          <student's major>
        - prints 'Minor: <student's minor or specialization>' (without quotation
          marks)on the 6th line of output with the student's minor or
         specialization in place of <student's minor or specialization>
          Note: the keyword 'Minor:' might be replaced with the keyword
        'Specialization:' or 'Concentration:' depending on the student
        - prints 'Favorite Hobby: <student's favorite hobby>'
          (without quotation marks) on the 7th line of output with the student's
          favorite hobby in place of <student's favorite hobby>
 
 Input: none
 Constants: none
 Output (screen): Sample Output:
 
        Boop, Betty
        C.S.1428.?     // '?' represents student's lecture section #
        --/--/--       // dashes represent due date, month/day/year
        <blank line>
        Major: ?
        Minor: ?
        Favorite Hobby: ?
 */

#include <iostream> 

using namespace std;

int main()
{
    cout << "Cordova, Samuel \n"
         << "C.S.1428.3 \n"
         << "09/04/13 \n\n";
    
    cout << "Major: Computer Science \n"
         << "Minor: Applied Math \n"
         << "Favorite Hobby: Basketball \n";
         
    return 0;
    
}


