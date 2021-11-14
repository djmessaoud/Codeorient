#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    //Syntax is [ tee output.txt || tee -a output.txt ]
    const string _standardInput="input.txt"; //Standard input filename
    fstream file;
    //Reading content from input
    string text;
    file.open(_standardInput,ios::in); // Opening read stream from input file
    if (file.is_open())
    {
        for(string _currentLine; getline(file,_currentLine);) text+=_currentLine+"\n"; // Write content from input to our text string
        file.close();
    }else cout << "Input file doesn't exist ! " ;
    string _outputFile; //Output file name
    bool doAppend=(argc == 3); //append or not; if number of arguments is 2 means no (-a), else append
    if (doAppend)
    {
        _outputFile=argv[2]; //Output file name will be after second argument (-a)
        file.open(_outputFile,ios::app); // Open output file
    }
    else
    {
        _outputFile=argv[1]; // Output filename will be directly after first execution argument..
        file.open(_outputFile,ios::out);
    }
    //Writing content of input into output file and standard output.
    file << text;
    cout << " -------------------------------------- \n" << text << " ---------------------------------- \n" << " Has been written into " << _outputFile<< endl;
    return 0;
}
