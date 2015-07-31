#include <iostream>
#include <fstream> 
#include <iomanip>
#include <math.h>

using namespace std;

void printReportHeading (ofstream &fout);
double getADouble (ifstream &fin);
double calcArea (double radius, double const PI);

int main ()
{
    
    const double PI = 3.14159;
    double radius,
           area;
    
    ifstream fin;
    ofstream fout;
    
    fin.open("input.txt");
    
    if(!fin)
    {
        cout << endl << endl
             << "***PROGAM TERMINATED***" << endl
             << "Something went wrong with the input file." << endl;
        
        fin.close ();
        
        return 0;
    }
    
    fout.open ("output.txt");
    
    if (!fout)
    {
        cout << endl << endl
             << "***PROGRAM TERMINATED*** " << endl
             << "Something went wrong with the output file." << endl;
        
        fout.close ();
        fin.close ();
        
        return 0;
    }
    
    printReportHeading (fout);
    
    for (int r = 1 ; r <= 10 ; r++)
    {
        radius = getADouble (fin);
        area = calcArea (radius, PI);
    }
    
    return 0;
}


void printReportHeading (ofstream &fout)
{
    fout << "Circle size report " << endl;
}

double getADouble (ifstream &fin)
{
    double radius;
    
    fin >> radius;
    
    return radius;
}

double calcArea (double radius, double const PI)
{
    return (PI * pow(radius, 2));
}
