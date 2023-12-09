#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// function to write to a file
void writeToFile(string fileName, string content) {
    ofstream file;
    file.open(fileName);
    file << content;
    file.close();
}

// function to read from a file
string readFromFile(string fileName) {
    string content = "";
    ifstream file;
    file.open(fileName);
    if (file.is_open()) {
        getline(file, content);
        file.close();
    }
    return content;
}

// function to execute a shell command and get its output
string executeCommand(string command) {
    string output = "";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return "Error: failed to execute command.";
    }
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        output += buffer;
    }
    pclose(pipe);
    return output;
}

