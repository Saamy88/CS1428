/*
   File: prog5_s_c215.cpp

   Author: Samuel Cordova
   C.S.1428.003
   Program: #5
   Due Date: 11/15/13

   This program reads an unknown number of simple binary expressions
   of the form 'operand1 operator operand2' from an input file. Each
   expression is evaluated. Real input values are allowed.

   A sentinel value read loop is used to process as described below:

   (Named constants to 'hold' CLASS ("C.S.1428") and DUE_DATE ("--/--/--")
   are declared in the calling routine (main).)

   - A void function, getName, is called to 'get' the user's first & last
     names using two different prompts. Two strings, one to 'hold' the
     first name and one to 'hold' the last name, are declared in the
     calling routine.
   - A typed function, getLectureSection, is called to 'get' the user's
     three digit lecture section number. A string to 'hold' the lecture
     section number is declared in the calling routine.
   - A void function, printIdInfo, is called to print the user's personal
     identifying information. One blank line is printed after the user's
     identifying information. The output is directed to the console or to
     an output file depending on the call. Refer to the sample output
     below.
   - A void function, readExpression, is called to read from an input file
     a binary expression in the form operand1 operator operand2. One read
     statement is used to "get" the parts of the expression.
   - While the operator in the expression read is not a question mark,
     the program processes as follows:
             - A void function, echoExpression, is called to echo (print)
               the expression to the output file.
             - A void function, evaluateExpression, is called. If the
               expression currently being evaluated is valid, the results
               are calculated and written to the output file; otherwise,
               an appropriate message is written to the output file. (See
               below. *)
             - The void function readExpression is called to read the next
               expression of the form operand1 operator operand2.
   - Two blank lines are written to the screen before the void function
     printIdInfo is called to print the user's personal identifying
     information to the screen.
   - A void function, writeFileLocation, is called to print an appropriate
     message to the screen indicating to the user the name of the output
     file to which the results have been written. (Refer to sample output
     below.)

==========================================================================

*The expressions are checked for the addition (+), subtraction (-),
multiplication (*), and division (/) operators. Included are a check for
division by zero when the division operator is encountered and a check for
an invalid operator (e.g. 134.6 ! 23.1). Since these are mutually exclusive
events, a switch statement with a nested double-sided alternative for
handling the division operator was used to evaluate the expressions.

If division by zero is encountered, the original expression is echoed to
the output file along with the message '   Division by zero produces an
undefined result.' If an invalid operator is encountered, the original
expression is echoed to the output file along with the message
'   Encountered unknown operator.'

Every attempt is made to eliminate repetitive code!

==========================================================================

The layout and content of the file input and the file output are shown in
the samples below. An appropriate message is displayed to the screen if
either the input file or the output file fails to open.

   Input (file - prog5_00?inp.txt):
   (contains an unknown number of binary expressions)

         operand1(double)  operator(char)  operand2(double)
         ...

   Constants: CLASS, DUE_DATE (strings)

   Sample Screen Output:

           Enter your first name:
           Enter your last name:
           Enter your three digit lecture section number:
              <blank line>
              <blank line>
           Author's Name
           C.S.1428.?        // '?' represents author's lecture section #
           --/--/--          // dashes represent due date, month/day/year
              <blank line>
           <Appropriate message indicating the name of the output file.>

   Sample File Output (file - prog5_?out.txt): //'?' - student's lect sec #

          Author's Name
          C.S.1428.?         // '?' represents author's lecture section #
          --/--/--           // dashes represent due date, month/day/year
             <blank line>
          125 $ 28   Encountered unknown operator.
          123.5 + 59.3 = 182.8
          198.7 / 0   Division by zero produces an undefined result.
          ...

          ================================================

          <Output will vary based on actual input values.>
*/

#include <iostream>
#include <fstream>

using namespace std;

void getName (string &, string &);
string getLectureSection ();
void printIdInfo (ostream&, string, string , string,const string, const string);
void readExpression (ifstream &, double &, char &, double &);
void echoExpression (ofstream &, double, char, double);
void evaluateExpression(ofstream &output, double &, char &, double &);
void writeFileLocation ();


int main ()
{
    const string CLASS = "C.S.1428";
    const string DUE_DATE = "11/15/13";

    string first_name,
           last_name,
           section_num;

    double operand1,
           operand2;

    char operatr;

    ifstream input;

    input.open ("prog5_003inp.txt");

    if(!input)
    {
        cout << endl << endl
             << " ***Program terminated.*** " << endl << endl
             << "Input file failed to open! " << endl;

        input.close ();
    }

    ofstream output;

    output.open("prog5_003out.txt");

    if ( !output )
    {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open!" << endl;

        input.close();
        output.close();

        return 0;
    }

    getName (first_name, last_name);
    section_num = getLectureSection();
    printIdInfo(output, first_name, last_name, section_num, CLASS, DUE_DATE);
    readExpression (input, operand1, operatr, operand2);

    while (operatr != '?')
    {
        echoExpression(output, operand1, operatr, operand2);
        evaluateExpression (output, operand1, operatr, operand2);
        readExpression (input, operand1, operatr, operand2);
    }

    cout << endl << endl;

    printIdInfo(cout, first_name, last_name, section_num, CLASS, DUE_DATE);
    writeFileLocation();

    output.close ();

    return 0;

}

/*
 * Function: getName
 *
 * The function getName will prompt the user for his/her first name and his/her
 * last name. Both will be saved as strings throughout the program.
 *
 * Receives: first_name (string), last_name (string)
 * Constants: None
 * Returns: By reference first_name (string), last_name (string)
 */

void getName (string &first_name, string &last_name)
{
    cout << "Enter your first name: ";
    cin >> first_name;

    cout << "Enter your last name: ";
    cin >> last_name;
}

/*
 * Function: getLectureSection
 *
 * The function getLectureSection will prompt the user for his section number
 * in a three digit fashion.
 *
 * Receives: None
 * Constants: None
 * Returns: section_num (string);
 */

string getLectureSection ()
{
    string section_num;

    cout << "Enter your three digit lecture section number: ";
    cin >> section_num;

    return section_num;
}

/*
 * Function: printIdInfo
 *
 * The function printIdInfo will print the user's information to the console
 * or if desired, to the output file.
 *
 * Receives: fist_name (string), last_name (string), section_num (string)
 * Constants: CLASS (string), DUE_DATE (string)
 * Returns: None
 */

void printIdInfo (ostream &output, string first_name, string last_name,
		          string section_num, const string CLASS, const string DUE_DATE)
{
    output << first_name << " " << last_name << endl
           << CLASS <<  "." << section_num << endl
           << DUE_DATE << endl << endl;
}

/*
 * Function: readExpression
 *
 * The function readExpression will read from an input file an operation that
 * will be evaluated.
 *
 * Receives: operand1 (double), operand2 (double), operatr (char)
 * Constants: None
 * Returns: By reference operand1(double), operand2 (double), and operatr (char)
 *
 */

void readExpression (ifstream &input, double &operand1, char &operatr,
		             double &operand2 )
{
    input >> operand1 >> operatr >> operand2;
}

/*
 * Function: echoExpression
 *
 * The function echoExpression will print to the output file the expression that
 * will be evaluated.
 *
 * Receives: operand1 (double), operand2 (double), operatr (char)
 * Constants: None
 * Returns: By reference operand1(double), operand2 (double), and operatr (char)
 */

void echoExpression (ofstream &output, double operand1, char operatr,
                     double operand2)
{
    output << operand1 << " " << operatr << " " << operand2;
}

/*
 * Function: evaluateExpression
 *
 * The function evaluateExpression will evaluate the sign and decide which
 * operations needs to execute. If there is division by zero or an unknown
 * operator then, the it will display an appropriate message.
 *
 * Receives: operand1 (double), operand2 (double), operatr (char)
 * Constants: None
 * Returns: By reference operand1(double), operand2 (double), and operatr (char)
 */

void evaluateExpression (ofstream &output, double &operand1, char &operatr,
		                 double &operand2)
{

      switch (operatr)
       {
           case '+':
                    output << " = " << operand1 + operand2 << endl;
                    break;
           case '-':
                     output << " = " << operand1 - operand2 << endl;
                     break;
           case '*':
                     output << " = " << operand1 * operand2 << endl;
                     break;
           case '/':
                     if (operand2 == 0)
                     {
                         output << "   Division by zero produces "
                        		<< "an undefined result. "
                        		<< endl;
                     }
                     else
                     {
                         output << " = " <<  operand1 / operand2 << endl;
                     }
                     break;
           default: output << "   Encountered unknown operator. " << endl;
                    break;
       }

}

/*
 * Function: writeFileLocation
 *
 * The function writeFileLocation is the last line that the console prints. It
 * says in which output file the results were written.
 *
 * Receives: None
 * Constants: None
 * Returns: None
 */

void writeFileLocation ()
{
    cout << "Program results have been written to prog5_003out.txt" << endl;
}

