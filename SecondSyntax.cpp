#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[])
{
    //Syntax  [ tee input.txt output.txt -a || tee input.txt output.txt  ]
    fstream file;
    string text=""; // CurrentLine to read each line from file, text for Full content of the file
    string inputFilename=argv[1];
    string outputFilename=argv[2];
    bool doAppend=false;
    if (argc>3) //Check append argument
    {
      string argument = argv[3]; // if third argument is -a (append)
      doAppend=(argument=="-a");
    }
    file.open(inputFilename,ios::in);
    if (file.is_open())
    {

        for (string currentLine; getline(file,currentLine);) text+=currentLine+"\n"; //Read each line from inputFile and add it to our text string
        file.close(); // close file after reading
    }else cout << " File cannot be found ! ";
    //Copying content to output file
    if (doAppend) file.open(outputFilename,ios::app);
    else file.open(outputFilename,ios::out);
    //Writing content into output file.
    file << text;
    cout << "Content from " << inputFilename << " has been written into " << outputFilename;
    return 0;
}



