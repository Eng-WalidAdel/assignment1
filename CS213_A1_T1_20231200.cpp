/*

    Assignemnt (1) Task (1)

    Solved Problems: 3 , 6 , 9 , 12 problem

    Name: Walid Adel Mordy Rohyem

    ID: 20231200

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#define endl '\n'
using namespace std;
void fast()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}
// Problem no. (3)
void split();
//================
// Problem no. (6)
void binary_print(int n);
//================
// Problem no. (9)
static bool bears(int n);
//================
// Problem no. (12)
void phisshing_emails();
//================

// Menu for My problems
void menu()
{
    while (true)
    { // A Welcome message
        cout << endl
             << "Welcome Ya user Ya Habibi!" << endl;
        cout << endl;
        cout << "In this mini program we just solve some problems to enjoy our time." << endl;
        cout << "You have some options from ( 1 : 5 )\n1) Split problem.\n2) Binary Print problem.\n3) Bears Problem.\n4) Phisshing e mails problem.\n5) Exit.\n\nPlease, Enter your choice: ";
        // get user`s Choice
        int choice;

        while (!(cin >> choice))
        {
            // Clear the error state of cin
            cin.clear();

            // Ignore the invalid input
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Invalid input. Please enter an integer: ";
        }
        // check validity of the input
        while (choice > 5 || choice < 1)
        {
            cout << "Invalid input! Please, Follow the instructions." << endl
                 << endl;
            cout << "You have some option from ( 1 : 5 )\n1) Split problem.\n2) Binary Print problem.\n3) Bears Problem.\n4) Phisshing e mails problem.\n5) Exit.\n\nPlease, Enter your choice: ";
            // get user`s Choice again
            while (!(cin >> choice))
            {
                // Clear the error state of cin
                cin.clear();

                // Ignore the invalid input
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Invalid input. Please enter an integer: ";
            }
        }

        if (choice == 1)
        {
            split();
        }
        else if (choice == 2)
        {
            int n;
            cout << "Welcome in BINARY PRINT problem ya User ya Habibi" << endl;
            cout << "Enter the number you wanna convert it ot binary system format: ";
            while (!(cin >> n))
            {
                // Clear the error state of cin
                cin.clear();

                // Ignore the invalid input
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Invalid input. Please enter an integer: ";
            }
            while (n < 0)
            {
                cout << "Invalid input! Please, Follow the instructions." << endl
                     << endl;
                cout << "Enter the number you wanna convert it ot binary system format: ";
                while (!(cin >> n))
                {
                    // Clear the error state of cin
                    cin.clear();

                    // Ignore the invalid input
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    cout << "Invalid input. Please enter an integer: ";
                }
            }
            binary_print(n);
        }
        else if (choice == 3)
        {
            int n;
            cout << "Welcome in BEARS problem ya User ya Habibi" << endl;
            cout << "Enter the number of bears: ";
            while (!(cin >> n))
            {
                // Clear the error state of cin
                cin.clear();

                // Ignore the invalid input
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Invalid input. Please enter an integer: ";
            }
            while (n < 0)
            {
                cout << "Invalid input! Please, Follow the instructions." << endl
                     << endl;
                cout << "Enter the number you wanna convert it ot binary system format: ";
                while (!(cin >> n))
                {
                    // Clear the error state of cin
                    cin.clear();

                    // Ignore the invalid input
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    cout << "Invalid input. Please enter an integer: ";
                }
            }
            cout << (bears(n) ? "True" : "False") << endl;
        }
        else if (choice == 4)
        {
            phisshing_emails();
        }
        else
        {
            return;
        }
    }
}

int main()
{
    menu();
    return 0;
}

// ================================== WALEED ==============================================

void split()
{
    string sentence, deli;
    cout << "Enter your sentence you wanna split it: ";
    cin.ignore();
    getline(cin, sentence, '\n');
    cout << "Now Enter your delimiter: ";
    getline(cin, deli);
    vector<string> res;
    int start;
    string sub;
    while (sentence.find(deli) != string::npos)
    {
        start = sentence.find(deli);
        sub = sentence.substr(0, start);
        res.push_back(sub);
        sentence.erase(0, start + deli.length()); //"do re mi fa so la ti do"
    }
    res.push_back(sentence);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl
         << endl;
}

void binary_print(int n)
{
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        if (n / 2 != 0)
        {
            binary_print(n / 2);
        }
        cout << n % 2;
    }
}

static bool bears(int n)
{
    if (n < 42)
    {
        return false;
    }
    else if (n == 42)
    {
        return true;
    }
    else
    {
        if (n % 5 == 0)
        {
            if (bears(n - 42))
                return true;
        }
        if (n % 2 == 0)
        {
            if (bears(n / 2))
                return true;
        }
        if ((n % 3 == 0) || (n % 4 == 0))
        {
            if (((n % 10) * (n % 100)) > 0 && bears(n - ((n % 10) * ((n % 100) / 10))))
                return true;
        }
    }
    return false;
}
void phisshing_emails()
{
    map<string, int> phishing = {{"click here", 3}, {"offers", 3}, {"see", 3}, {"watch", 2}, {"send", 1}, {"secure", 2}, {"transaction", 2}, {"login", 2}, {"credit card", 3}, {"identity", 2}, {"update", 2}, {"security alert", 3}, {"bank", 1}, {"invoice", 2}, {"winner", 3}, {"verify your identity", 3}, {"confirm", 2}, {"refund", 2}, {"limited time", 2}, {"offer", 2}, {"lottery", 3}, {"free", 2}, {"urgent", 3}, {"password", 3}, {"reset", 2}, {"click here", 3}, {"verify", 3}, {"account", 2}, {"suspended", 3}, {"limited", 2}, {"social security", 3}, {"prize", 3}, {"you have won", 3}, {"claim", 3}};
    int totalpoints = 0;
    map<string, int> shared_words;
    string filename;
    cout << "PLease, Enter a file name and if you don`t have a file Enter(ph.txt)file to see the output : ";
    cin >> filename;

    ifstream file(filename);
    while (!file)
    {
        cout << "The file name isn't detected!" << endl;
        cout << "Please, enter file's name again: ";
        cin >> filename;
        cout << endl;
        file.open(filename, ios::in);
    }
    string line;
    while (getline(file, line))
    {
        for (char &ch : line)
        {
            ch = tolower(ch);
        }
        for (auto it = phishing.begin(); it != phishing.end(); it++)
        {
            short pos = line.find(it->first); // ewewyg click here jhsef click here efwef
            while (pos != string::npos)
            {
                shared_words[it->first]++;
                totalpoints += it->second;
                pos = line.find(it->first, pos + it->first.length());
            }
        }
    }
    file.close();
    cout << "The results of the scanner: ";
    for (auto it = shared_words.begin(); it != shared_words.end(); it++)
    {
        cout << "phisshing word: [ " << it->first << " ] appeared ( " << it->second << " ) times in that email." << endl;
    }
    cout << endl
         << "Total points of phishing words in this email: " << totalpoints << endl;
}