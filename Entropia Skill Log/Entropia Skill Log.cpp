#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::fstream;
using std::string;
using std::size_t;
using std::ios;

int main()
{
    fstream chatlog;
    chatlog.open("chat.log", ios::in); // TODO: Check if this file is already in use

    cout << "Entropia Skill Log is running.." << "\n\n";

    if (!chatlog.is_open()) {
        //cout << system("dir");
        cout << "Unable to open main chat log!";
        return -1;
    }

    string line; size_t found;
    while (getline(chatlog, line)) {
        found = line.find("You have gained");
        if (found != string::npos)
            cout << getPrettyStr(line) << "\n";
    }

    chatlog.close();
}

string getPrettyStr(string str) {
    str.erase(29, 3); // Erase the extra [] from the skill gain lines
    return str;
}
