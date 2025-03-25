/*
ID: stwiege1
TASK: dualpal
LANG: C++
*/

// NAME                    : Shuler Wiegerink
// GROUP                   : Hexadecimal
// LAST MODIFIED           : 25 March 2025
// PROBLEM ID              : USACO dualpal
// PROBLEM DESCRIPTION     : Reads in a number containing a number to start at and
//                           an amount to find, and finds that number of integers greater          
//                           than the first that are palindromic in at least 2 bases 2-10.
// SOURCES I USED          : USACO website
// PEOPLE I HELPED         : 
// PEOPLE WHO HELPED ME    : Mr. Houtrouw

using namespace std;

#include <iostream>
#include <fstream>

// prepare files for input and output
ifstream fin ("dualpal.in");
ofstream fout ("dualpal.out");

// function and variable declaration
string baseConvert(int number, int base);
bool palindromeCheck(string b);
int numNums, startNum, found, check, j;

int main()
{
    // reads in input file
    fin >> numNums >> startNum;
    found = 0;
    j = startNum + 1;
    // loops through finding algortithm
    while(found < numNums)
    {
        check = 0;
        for(int q = 2; q < 11; q++)
        {
            // increments check variable until it finds 2 bases the number is palindromic in
            if(palindromeCheck(baseConvert(j, q)) == 1)
            {
                check++;
            }
            if(check > 1)
            {
                fout << j << endl;
                found++;
                break;
            }
        }
        j++;
    }
}

// base converter program
string baseConvert(int number, int base)
{
    int runningNum, a;
    int powerTotal[32] = {0};
    string g;
    string alph = "ABCDEFGHIJK";
    bool writeZ = 0;
    runningNum = number;
    a = 0;

    // calculates each number to save
    while (runningNum > 0 && a < 32)
    {
        powerTotal[a] = runningNum % base;
        runningNum /= base;
        a++;
    }
    a = 0;
    // formats powertotal array correctly, and translates double digit numbers to letters
    for(int j = 18; j >= 0; j--)
    {
        if((to_string(powerTotal[j]) == "0") && (writeZ == 0))
        {
            writeZ = 0;
        }
        else if(powerTotal[j] > 9)
        {
            g += alph[powerTotal[j] % 10];
            writeZ = 1;
        }
        else
        {
            g += to_string(powerTotal[j]);
            writeZ = 1;
        }
    }
    return g;
}

// checks if the string input is a palindrome
bool palindromeCheck(string b)
{
    bool isPal = 1;
    char check;

    // goes through the first half of the characters, and if the character
    // at the corresponding opposite end is the same, continue
    for(int q = 0; q < (b.length() / 2); q++)
    {
        check = b[q];
        if(b[(b.length() - q - 1)] != check)
        {
            isPal = 0;
            goto notPal;
        }
    }  
    notPal:
    return isPal;
}
