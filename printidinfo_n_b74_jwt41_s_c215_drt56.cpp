// PROTOTYPE 
void printIdInfo(ostream &, const string , const int, const string ); 
      
/* Function: printIdInfo
 * 
 * Author(s): Dononvan Trevino, Nick Braswell, Samuel Cordova, Justin Trybula 
 * C.S.1428.003 
 * Program 6 Function
 * 11/20/2013 
 * 
 * The function printIdInfo will print the authors' personal information 
 * (name(s), class/section number) on the first, second, and third line 
 * respectively. After thsi information is displayed there are two blank 
 * lines. The section number needs to get filled by two zeros before displaying 
 * the number. 
 *
 * The function can can display this information the output on the console or on 
 * the output file. To display the information on the console, in the calling
 * section of the function(main), you have to type the following as your first 
 * variable "cout". To display the information on the console, in the calling
 * section of the function(main), you have to type the following as your first 
 * variable "fout". Whether you are displaying to the console or to the output
 * file, dont forget to add the symbol '&' before or after your first variable. 
 * 
 * Receives: AUTHORS (string), DUE_DATE (string), SECTION (int) 
 * Constants: AUTHORS (string), DUE_DATE (string), SECTION (int) 
 * Returns: None 
 */
 
 
 //DEFINITION
void printIdInfo(ostream &out, const string AUTHORS, const string DUE_DATE, 
                 const int SECTION) 
{ 
    out << AUTHORS << endl 
         << "C.S.1428." << setw(3) << setfill('0') << SECTION << endl 
         << DUE_DATE << endl << endl << endl; 
} 
