#include <iostream>
#include <iomanip>
#include <fstream>
  
using namespace std;
  
const int STUDENTS = 4,
          EXAMS = 3;
  
const int EXI = 0,
          EXII = 1,
          FINAL = 2;

void dataIn( ifstream &, int [][EXAMS] );
void calcAvg( int [][EXAMS], double [] );
  
int main( )
{
    
    const int MAX_LENGHT = 9;
    const double A_FLOOR = 89.5;
    
    char student_id[STUDENTS][MAX_LENGHT + 1] = {"A02345670", "A00345600", "A01205078", "A10300608"};
    
    int exam_scores[STUDENTS][EXAMS];
    
    double average[STUDENTS],
           highest; 
    
    int a_students = 0;
    
    ifstream fin;
    
    fin.open( "input.txt" );
    
    if ( !fin )
    {
        cout << endl << endl
             << "***PROGRAM TERMINATED.***" << endl << endl
             << "Input file failed to open! " << endl ;
             
        fin.close ( );
        
        system ("PAUSE");
             
        return 1;      
    }
    
    dataIn(fin, exam_scores);
    calcAvg(exam_scores, average);
    average[3] + 2;
    
    cout << fixed << setprecision (1) 
         << "Student      Average" << endl;
    
    for(int i = 0; i < STUDENTS; i++)
    {
        cout << student_id[i] << "    " << average[i] << endl;
    }
    
    for(int i = 0; i < STUDENTS; i++)
    {
        if (average[i] > A_FLOOR )
            a_students++; 
    }
    
    cout << endl 
         << "The number of students that made an 'A' were: "
         << a_students;
         
    highest = average[0]; 
    
    for(int i = 0; i < STUDENTS; i++)
    {
        if( average[i] > highest )
            highest = average[i];
    }
    
    cout << endl 
         << "The highest average was: " << highest
         << endl;
    
    fin.close( );
      
    system ( "PAUSE" );
} 


//FUNCTION DEFINITIONS

void dataIn ( ifstream &fin, int exam_scores[][EXAMS] )
{
    for(int i = 0; i < STUDENTS; i++)
    {   
        fin >> exam_scores[i][EXI] >> exam_scores[i][EXII] >> exam_scores[i][FINAL];
    }
}

void calcAvg(int exam_scores[][EXAMS], double average[] )
{
     
     double total = 0.0;
     
     for(int i = 0; i < STUDENTS; i++)
    {
        total = 0.0;
           
        for(int j = 0; j < EXAMS; j++)
        {
            total = total + exam_scores[i][j];  
        }
        
        average[i] = total / static_cast<double>(EXAMS);
    }
}

