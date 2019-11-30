#pragma once

#include <iostream>
#include <fstream>

void FileInputOutput()
{
    std::ofstream fileOutput( "src/examples/Working_with_files/inputOutput.txt" );

    if ( !fileOutput )
    {
        cout << "Error in opening the file." << endl;
        return;
    }

    fileOutput << "Hello from the file.\n";
    fileOutput << "We can write in different lines.\n";

    fileOutput.close();

    std::ifstream fileInput( "src/examples/Working_with_files/inputOutput.txt" );
    if (!fileInput)
    {
        cout << "Error in opening the file." << endl;
        return;
    }

    // don't skip whitespaces
    fileInput.unsetf(std::ios::skipws);

    cout << "We can read character by character :" << endl;
    char ch;
    while(!fileInput.eof())
    {
        fileInput >> ch;
        cout << ch;
    }

    cout << "Or we can read line by line :" << endl;
    std::string str;

    // the eof flag will be set up in the stream 
    // after the previous loop so we need to clear it
    fileInput.clear();
    // return file pointer to beginning of the file
    fileInput.seekg(0, std::ios::beg);

    while (getline(fileInput, str))
    {
        std::cout << str << std::endl;    
    }

    fileInput.close();
}

