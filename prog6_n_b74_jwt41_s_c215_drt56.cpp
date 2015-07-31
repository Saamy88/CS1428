/*
   File: prog6_n_b74_jwt41_s_c215_drt56.cpp

   Author: Nick Braswell, Justin Trybula, Samuel Cordova, Donovan Trevino
   C.S.1428.3
   Program: #6
   Due Date: 11/25/13

   This program prints to an output file a title and column headers for a
   payroll report. It then reads an employees work record from an input file.
   The number of overtime hours worked, gross pay, state tax, federal tax,
   and net pay are calculated for each employee. The authors' personal
   identification information followed by the company payroll report is
   printed to the output file. Monetary values are displayed to two decimal
   places.

   An attempt to avoid repetitive code is made.

   An appropriate message is displayed to the console screen if either the
   input or the output file fails to open.

   An appropriate message is written to the console screen informing the
   user of the output file name to which the results have been written.

   The client file (main) calls the following void functions to process
   the data:

	  - printIdInfo prints the authors' personal information - name(s),
        class/section number, due date - on the first, second and third
        lines. Two blank lines are left after the due date. The section
        number is displayed in a three digit field with leading zeros
        shown. The calling routine determines the output stream to which
        the information is directed. (Refer to sample output below.)
	  - printReportHeadings prints to the output file the title & column
        headings for the payroll report. One blank line is left after the
        centered report title. Column headers are displayed on two lines.
        (Refer to sample output below.)
      - dataIn reads the employee ID#, hours worked and pay rate from
        an input file storing the values read into parallel arrays. The
        employee ID# is stored in a 1D array of integers. The hours worked
        and the pay rate are stored in the first and second columns of a
        2D array of reals.
	  - overTime calculates the number of overtime hours worked by the
        employee based on a 40 hour work week.
	  - grossPay calculates the employee's gross pay for the week. If the
        employee worked 40 hours or less, gross pay is the hourly pay rate
        multiplied by the number of hours worked; otherwise, the employee
        worked more than 40 hours, and they are paid the regular hourly
        rate for the first 40 hours plus time and a half for any hours
        over 40.
	  - stateTax calculates state taxes owed by the employee, which is
        calculated at a straight 6% of the employee's weekly gross pay.
        (6% is a sample tax rate. The tax rate will vary with each state.)
	  - federalTax calculates federal taxes owed by the employee. If
        weekly gross pay is $400.00 or less, the tax rate is 20%; otherwise,
        the employee's weekly gross pay is more than $400.00, and the tax
        rate is calculated at 20% for the first $400.00 and 31% for any
        amount over $400.00.
        (These rates will vary based on current federal tax regulations.)
	  - netPay calculates the employee's net pay for the week.
        (gross pay minus calculated taxes both state & federal).
	  - printReportData prints to the output file the information for each
        employee in tabular form. Monetary values are displayed to two
        digits of precision. (Refer to sample output below.)
	  - writeFileLocation prints an appropriate message to the console
        screen indicating to the user the name of the output file to which
        the results have been written. The output file name is provided by
        the calling routine.(Refer to sample output below.)


   The following named constants are declared globally:
      - the number of hours in a normal work week (40.00)
      - the state tax rate (0.06)
      - the federal tax rates (0.20; 0.31)
      - the cut off at which federal taxes increase (400.00)
      - parallel array dimensions
      - names used to reference individual columns in the payroll array

   Locally declared named constants include:
      - a string to hold the authors' names
      - a string to hold the project's due date
      - an integer to hold the section number
      - an integer representing the maximum string length allowed for
        input and output file names which are stored in character arrays
        of that length

==========================================================================

   Layout and content of the output are shown in the samples below.

   Input (file - prog6_00?inp.txt)
          one record per employee / each record containing three numbers

          ID#(integer)  hours worked (real)  pay rate (real)
          ...

   Constants: globally declared:
                 integer: ROWS
                          COLS
	                      (2D array column indices)
                              HRS_WRKD = 0,
                              PAYRATE = 1,
                              OVRTIME = 2,
                              GROSS = 3,
                              ST_TAX = 4,
                              FED_TAX = 5,
                              NETPAY = 6;

                 double: CUT_OFF (hours in a work week)
                         STATE_TX_RATE
                         TAX_CUT_OFF (division @ which net pay is taxed higher)
	  	                 LOW_TAX_RATE
                         HI_TAX_RATE

   Constants: locally declared:
                 string:  AUTHORS
                          DUE_DATE

                 integer: SECTION
                          MAX_LENGTH_FN = ?  // filename's maximum length

   Output (console):
     Sample Console Output

     List of Authors' names
     C.S.1428.00?
     --/--/--
          <blank line>
          <blank line>
     Program results have been written to prog6_00?out.txt.

   Output (file: prog6_00?out.txt):
     Sample File Output

     List of Authors' names
     C.S.1428.00?
     --/--/--
          <blank line>
          <blank line>
                          Monthly Payroll Report
          <blank line>
      ID#     Hours    Hourly    Overtime   Gross    State   Federal    Net
             Worked     Rate       Hours     Pay      Tax      Tax      Pay
     1000     51.00      6.55      11.00   370.07    22.20    74.02   273.86
     ...
     1002     26.00     15.00       0.00   390.00    23.40    78.00   288.60
     ...

     =======================================================================

     <Output will vary based on actual input values.>
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ROWS = 10,    // number of employees
          COLS = 7;

// 2D array (payroll) column indices
const int HRS_WRKD = 0,
          PAYRATE = 1,
          OVRTIME = 2,
          GROSS = 3,
          ST_TAX = 4,
          FED_TAX = 5,
          NETPAY = 6;

const double CUT_OFF = 40.00,     // work week
             STATE_TX_RATE = 0.06,
             TAX_CUT_OFF = 400.00,// earnings after which taxed at a higher rate
             LOW_TAX_RATE = 0.20,
             HI_TAX_RATE = 0.31;


void printIdInfo( ostream &out, const string AUTHORS, const int SECTION,
		          const string DUE_DATE  );
void printReportHeadings ( ofstream & );
void dataIn ( ifstream &fin, int employee[], double payroll[][COLS] );
void overTime ( double payroll[][COLS] );
void grossPay( double payroll[][COLS] );
void stateTax ( double payroll[][COLS] );
void federalTax ( double payroll[ ][COLS] );
double netPay ( double [][COLS] );
void printReportData( ofstream& fout ,int employee[], double payroll[][COLS] );
void writeFileLocation( char [] );

int main( )
{
    const string AUTHORS = "Nick Braswell; Justin Trybula; "
                           "Samuel Cordova; Donovan Trevino",
                 DUE_DATE = "11/25/13";

    const int SECTION = 3;

    const int MAX_LENGTH_FN = 16;

    char input_filename[MAX_LENGTH_FN + 1] = "prog6_003inp.txt",
         output_filename[MAX_LENGTH_FN + 1] = "prog6_003out.txt";

    int employee[ROWS];          // employee ID#s
    double payroll[ROWS][COLS];  // payroll data

    ifstream fin;
    fin.open( input_filename );

    if( !fin )
    {
        cout << endl << endl
             << "***PROGRAM TERMINATED***" << endl << endl
             << "Input file failed to open! " << endl;

        fin.close ();

        return 1;
    }

    ofstream fout;
    fout.open( output_filename );

    if( !fout )
    {
        cout << endl << endl
             << "***PROGRAM TERMINATED***" << endl << endl
             << "Output file failed to open! " << endl;

        fin.close ( );
        fout.close ( );

        return 1;
    }

    printIdInfo( fout, AUTHORS, SECTION, DUE_DATE );
    printReportHeadings ( fout );
    dataIn ( fin, employee, payroll );
    overTime ( payroll );
    grossPay ( payroll );
    stateTax ( payroll );
    federalTax ( payroll );
    netPay ( payroll );
    printReportData ( fout, employee, payroll );
    printIdInfo( cout, AUTHORS, SECTION, DUE_DATE );
    writeFileLocation ( output_filename );

    fin.close ( );
    fout.close ( );

    return 0;
}

/*
   Function: printIdInfo

   Author(s): Nick Braswell, Justin Trybula, Samuel Cordova, Donovan Trevino
   C.S.1428.003
   Program 6 Function
   11/20/2013

   The function printIdInfo prints the authors' personal information - name(s),
   class/section number, due date - on the first, second and third lines. Leave
   two blank lines after the due date. Display the section number in a three
   digit field with leading zeros shown. The calling routine should determine
   the output stream to which the information is directed. (Refer to sample
   output above.)

   Receives: out ( ostream - pass by reference )
             AUTHORS ( string ),
             DUE_DATE ( string ),
             SECTION ( int )
   Constants: AUTHORS, DUE_DATE, SECTION
   Returns: None
 */

void printIdInfo( ostream &out, const string AUTHORS, const int SECTION,
                  const string DUE_DATE )
{
    out << AUTHORS << endl
        << "C.S.1428." << setw(3) << setfill('0') << SECTION << endl
        << DUE_DATE << endl << endl << endl;
}

/*
   Function: printReportHeadings

   Author(s): Steven Dudich, Dustin Seymour, Martina Coad, John Williamson
   C.S. 1428.003
   Program 6 Function
   11/20/13

   Edited by: Nick Braswell, Justin Trybula, Samuel Cordova, Donovan Trevino

   The function, printReportHeadings, prints to the output file the title &
   column headings for the payroll report. Leave one blank line after the
   centered report file. Display column headers on two lines. (Refer to sample
   output above).

   Receives: fout (pass by reference)
   Constants: None
   Return: title & column heading to prog6_003out.txt
 */

void printReportHeadings ( ofstream &fout )
{
    fout << "                     Monthly Payroll Report " << endl << endl
         << " ID#     Hours    Hourly   Overtime    Gross     State    Federal"
         << "     Net" << endl
         << "        Worked     Rate      Hours      Pay       Tax       Tax   "
         << "    Pay" << endl;
}

/*
   Function: dataIn

   Author(s): Bernadette Aguirre, Mario Gomez, Broderick Mathis, Jamal Gillis
   C.S.1428.003
   Program 6 Function
   11/20/13

   The function, dataIn, reads the employee ID#, hours worked and pay rate
   from an input file (prog6_003inp.txt) storing the values read into
   parallel arrays. The hours worked and the pay rate should be stored in
   the first and second columns of a 2D array of reals.

   Receives: fin (ifstream), employee (integer), payroll (double)
   Constants: globally declared variables
              row_counterS (integer),
              COLS (integer),
              HRS_WRKD (integer),
              PAY_RATE (integer)
  Returns: nothing, reads the employee ID#, hours worked and pay rate
           from an input file (prog6_003inp.txt) storing the values read into
           parallel arrays. The hours worked and the pay rate should be stored
           in the first and second columns of a 2D array of reals.
 */

void dataIn ( ifstream &fin, int employee[], double payroll[][COLS] )
{
    for ( int row_counter = 0; row_counter < ROWS; row_counter++ )
        fin >> employee[row_counter] >> payroll[row_counter][HRS_WRKD]
            >> payroll[row_counter][PAYRATE];
}

/*
   Function: overTime

   Author(s): Leah Ramirez, Joshua Rendon, Vitali Taranto, Rene Moreda
   C.S.1428.003
   Program 6 Function
   11/20/13

   The function, overTime, calculates the number of overtime hours worked by
   each employee based on a work week with number of hours determined by the
   globally declared constant, CUT_OFF, and stores each value to a 2D array.

   Receives: double payroll[][COLS]
   Constants:
           ROWS (globally declared integer that represents the number of rows
                  in the payroll array),
           COLS (globally declared integer that represents the number of columns
                  in the payroll array),
           CUT_OFF (globally declared double that represents the number of hours
                    in the work week),
           OVRTIME (globally declared integer that represents the column number
                    for overtime hours in the payroll array),
           HRS_WRKD (globally declared integer that represents the column number
                     for total hours worked by an employee in the payroll array)
   Returns: an overtime value to each row in OVRTIME column of payroll array
 */

void overTime ( double payroll[][COLS] )
{
    for ( int row = 0; row < ROWS; row++ )
    {
        if ( payroll[row][HRS_WRKD] > CUT_OFF )
            payroll[row][OVRTIME] = payroll[row][HRS_WRKD] - CUT_OFF;

        else
            payroll[row][OVRTIME] = 0;
    }
}

/*
   Function: grossPay

   Authors: Robert Hutton, Travis Kovar, Shawn King, Anthony Ross
   C.S.1428.003
   Program 6 Function
   11/20/13

   Edited by: Nick Braswell, Justin Trybula, Samuel Cordova, Donovan Trevino

   The void function, grossPay, calculates the employee's gross pay for the
   week. If the employee worked 40 hours or less, gross pay is the hourly pay
   rate multiplied by the number of hours worked; otherwise, the employee
   worked the more than 140 hours plus and a half for any hours over 40.

   Receives: payroll[][COLS]
   Constants: Global double CUT_OFF (# of hours before overtime)
              Global int ROWS,
              COLS (array dimensions)
   Returns: Gross pay into payroll[][3]
 */

void grossPay( double payroll[][COLS] )
{
	int const first_col = 0,
			  second_col = 1,
			  third_col = 2,
			  fourth_col = 3;

    for( int i = 0; i < ROWS; ++i )
    {
        if( payroll[i][third_col] == 0 )
            payroll[i][fourth_col] = payroll[i][first_col] *
                                     payroll[i][second_col];


        else
            payroll[i][fourth_col]= ( CUT_OFF * payroll[i][second_col] ) +
                                    ( payroll[i][third_col] *
                                      payroll[i][second_col] * 1.5 );

    }
}

/*
   Function: stateTax

   Authors: Jonathan Rodriguez, Conner Green, Latravian Haggerty, Michael Raney
   C.S.1428.003
   Program 6 stateTax
   11/20/13

   The function, stateTax, calculates the amount of the state tax based on the
   gross pay.

   Receives: double payroll[][COLS]
   Constants: GROSS (global integer) is from the 2D array payroll in column 3
              ST_TAX (global integer) is from the 2D array payroll in column 4
              STATE_TX_RATE (global double)
              COLS (global integer)
   Returns: Calculates the state tax and fills the value into column 4 of
   the payroll array.
 */

void stateTax ( double payroll[][COLS] )
{
    for ( int row = 0; row < ROWS; ++row )
        payroll[row][ST_TAX] = payroll[row][GROSS] * STATE_TX_RATE;
}

/*
   Function: federalTax

   Author(s): Chris Smith, Pedro Balderas, Zachery Dettling, Branden Jodoi
   C.S.1428.003
   Program 6 Function
   11/20/2013

   The function federalTax calculates federal taxes owed by the employee.
   If weekly gross pay is $400.00 or less, then the rate is 20%; otherwise,
   the employee's weekly gross pay is more than $400.00, and the tax rate is
   calculated at 20% for the first $400.00 and 31% for any amount
   over $400.00.

   Receives: payroll [ ][COLS] (double),
             LOW_TAX_RATE (const double, global),
             HI_TAX_RATE (const double, global),
             TAX_CUT_OFF (conts double, global),
             COLS (const int, global),
             ROWS, (const int, global),
             GROSS, (const double, global),
             FED_TAX (const int, global)
   Constants: LOW_TAX_RATE - tax rate for earnings less than or equal to
                             TAX_CUT_OFF
              HI_TAX_RATE - tax rate for earnings greater than TAX_CUT_OFF
              TAX_CUT_OFF - the break even point for the higher tax rate
              COLS - size of the 2nd dimension of payroll array
              ROWS - number of elements in the first dimension of the array
                     (# of employees)
              GROSS - index of the column where the gross earnings are
                      stored
              FED_TAX - index of the column where the federal tax amounts
                        are stored
   Returns: Values in the column [FED_TAX] in the array payroll[ROWS][COLS]
 */

void federalTax ( double payroll[ ][COLS] )
{
    for ( int row_counter = 0; row_counter < ROWS; row_counter++ )
    {
        if ( payroll[row_counter][GROSS] <= TAX_CUT_OFF )
            payroll[row_counter][FED_TAX] =
            payroll[row_counter][GROSS] * LOW_TAX_RATE;
        else
            payroll[row_counter][FED_TAX] = TAX_CUT_OFF * LOW_TAX_RATE +
            ( payroll[row_counter][GROSS] - TAX_CUT_OFF ) * HI_TAX_RATE;
    }
}

/*
   Function: netPay

   Author(s): Steven Dudich, Dustin Seymour, Martina Coad, John Williamson
   C.S. 1428.003
   Program 6 Function
   11/20/13

   The function, netPay, calculates the employee's net pay for the week,
   and populates the NETPAY column of the array with the total)

   Receives: double payroll [][COLS]
   Constants : (global constants)
                  double STATETAX ( for the state tax rate),
                  FEDERALTAX (for the federal tax rate),
                  COLS ( tells the function how may columns are in the 2D array)
   Returns: populates the NETPAY column with the net pay after the calculation.
 */

double netPay ( double payroll [][COLS] )
{

    for ( int row = 0; row < ROWS; row++ )
    {

        payroll[row][NETPAY] = payroll [row][GROSS] -
        		               ( payroll [row][ST_TAX] +
        		                 payroll [row][FED_TAX] );
    }
}


/*
   Function: printreportdata

   Author(s): ci1030, ajs118, pbl8, as1988
   C.S1428.003
   Program 6 Function
   11/20/13

   Edited by: Nick Braswell, Justin Trybula, Samuel Cordova, Donovan Trevino

   The function printReportData prints to an output file the information for
   each employee in tabular form. Display monetary values to two digits of
   precision. The program will use a nested loop to create a spread sheet of
   monetary values with appropriate labels for the axis.

   Receives: fout (ofstream), employee (int), payroll (double).
   Constants: employee, payroll
   Returns: None
 */

void printReportData( ofstream& fout ,int employee[], double payroll[][COLS] )
{

    fout << fixed << setprecision(2) << setfill(' ');

    for ( int row = 0; row < ROWS; ++row )
    {
        fout <<  employee [row];

        for ( int col = 0; col < COLS; ++col )
            fout << setw(10) << payroll[row][col];

        fout << endl;
    }
}

/*
   Function: writeFileLocation

   Author(s): Jorge Iglesias, Michael Pedraza, Gustavo Prieto,
              David Mejia Saldivar
   C.S1428.003
   Program 6 Function
   11/20/13

   Edited by: Nick Braswell, Justin Trybula, Samuel Cordova, Donovan Trevino

   The function writeFileLocation prints an appropriate message to the console
   screen indicating to the user the name of the output file to which the
   results have been written. The output file name should be provided by the
   calling routine. (Refer to sample output above.)

   Receives: output_filename (char array)
   Constants: None
   Returns: None
 */

void writeFileLocation(char output_filename [])
{
    cout << "Program results have been written to " << output_filename << endl;

}
