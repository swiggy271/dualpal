/*
ID: stwiege1
TASK: dualpal
LANG: C++
*/

using namespace std;

#include <iostream>
#include <fstream>

// prepare files for input and output
ifstream fin ("dualpal.in");
ofstream fout ("dualpal.out");

// function and variable declaration
string baseConvert(int number, int base);
bool palindromeCheck(string b);
int numNums, startNum, found, check;

int main()
{
    fin >> numNums >> startNum;
    found = 0;
    for(int j = startNum + 1; j < 10000; j++)
    {
        check = 0;
        if(found < numNums)
        {
            for(int q = 2; q < 11; q++)
            {
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
        }
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
