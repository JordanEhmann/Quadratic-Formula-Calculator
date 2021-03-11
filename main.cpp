//**********************************************************
//File:main.cpp
//
//DESCRIPTION
//
//
// AUTHOR1: Jordan Ehmann, 1218548396, jehmann@asu.edu
//
//COURSE INFO
//CSE100 Principles of Programming with C++, Spring 2021
//Lab Project 2 Monday 11:15am-12:05pm TA: Benjamin Martinez
//============================================================
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Test Case 1
//
// Description:
//   Tests that the program reads from the coeffs.txt then 
// calculates the correct roots, and then creats a roots.txt 
// file and saves the quadratic equation with its roots. 
// 
// Input Data:
//    A = 1
//    B = 4
//    C = 4
// Expected Output:
//    The equation 1x^2 + 4x + 4 = 0 has roots -2 and -2
//
// Actual Output:
//    The equation 1x^2 + 4x + 4 = 0 has roots -2 and -2
//
// Test Case Result: PASSED
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Test Case 2
//
// Description:
//   Tests that the program reads from the coeffs.txt then 
// calculates the correct roots, and then creats a roots.txt 
// file and saves the quadratic equation with its roots. 
// 
// Input Data:
//    A = 3
//    B = 6
//    C = -9
// Expected Output:
//    The equation 3x^2 + 6x + -9 = 0 has roots -3 and 1
//
// Actual Output:
//    The equation 3x^2 + 6x + -9 = 0 has roots -3 and 1
//
// Test Case Result: PASSED
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Test Case 3
//
// Description:
//   Tests that the program reads from the coeffs.txt then 
// calculates the correct roots, and then creats a roots.txt 
// file and saves the quadratic equation with its roots. 
// 
// Input Data:
//    A = -5.7
//    B = 9
//    C = 10
// Expected Output:
//    The equation -5.7x^2 + 9x + 10 = 0 has roots 2.33144 and -0.752491
//
// Actual Output:
//    The equation -5.7x^2 + 9x + 10 = 0 has roots 2.33144 and -0.752491
//
// Test Case Result: PASSED
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//************************************************************
//**********************************************************

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double read_coeffecients(ifstream &fin)
{ // this function reads from a file defined by the parameter of fct
 double coeff;
 fin >> coeff;
 return coeff;
}

double calc_discriminant(double a, double b, double c) 
{// calculates the discriminant
 return (-4)*a*c+ pow(b, 2); 
}

double calc_root1(double a, double b, double c)
{// calculates the first root by calling the discriminant and finishing the quad formula
 double dscrmt;
 dscrmt = calc_discriminant(a, b, c);
 return ((-b)-sqrt(dscrmt))/(2*a);
}

double calc_root2(double a, double b, double c)
{// calculates the sec0ond root by calling the discriminant and finishing the quad formula
 double dscrmt;
 dscrmt = calc_discriminant(a, b, c);

 return ((-b)+sqrt(dscrmt))/(2*a);
}

void output(double a, double b, double c, double root1, double root2)
{
  string string, string2, string3, string4, string5;
  string = "The equation ";
  string2 = "x^2 + ";
  string3 =  "x + ";
  string4 = " = 0 has roots ";
  string5 = " and ";
  
  ofstream fout;
  fout.open("roots.txt", ios::out);
  
  fout << string << a << string2 << b << string3 << c << string4 << root1 << string5 << root2 << endl;
  
  fout.close();  
}

int main()
{
  double a, b, c, root1, root2, discriminant; // coeffecients for quad formula

  ifstream fin; // opens .txt file
  fin.open("coeffs.txt", ios::in); 


  a = read_coeffecients(fin); // reading coeffecients for .txt
  b = read_coeffecients(fin);
  c = read_coeffecients(fin);

  fin.close(); // closes .txt file

  root1 = calc_root1(a, b, c); // calls fct that calcs roots via quad. formula
  root2 = calc_root2(a, b, c);

  output(a, b, c, root1, root2); //calls the function that sends equation to a .txt file

return 0;
}
