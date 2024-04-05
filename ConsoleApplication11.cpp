#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Задание 1
int main() 
{
/*  ofstream iFile("Input_File.txt");
    iFile << "fffffff   aaaa   bbbbb   hhhhhh    yyyyyyyyyyy     vbvbghgh" << "\n";*/
    ifstream  iFile("Input_file.txt");
    ofstream oFile("Output_File.txt");
    
    
    if (!iFile || !oFile) 
    {
        cerr << "Error";
        exit(1);
    }

    string word;
    while (iFile >> word)
    {
        if (word.length() >= 7) 
        {
            oFile << word << " ";
        }
    }

    iFile.close();
    oFile.close();
}




//Задание 2
int main()
{
    /*ofstream File("File.txt");
    File << "Hello world" << "\n";*/
    ifstream File("File.txt");
    ofstream File1("File1.txt");


    if (!File || !File1)
    {
        cerr << "Error";
        exit(1);
    }

    string word;
    while (File >> word)
    {
        File1 << word << " ";

    }

    File.close();
    File1.close();
}





















