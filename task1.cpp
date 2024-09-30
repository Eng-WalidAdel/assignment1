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
void sentence();
void Sieve();
void dominos();
void Bias();

void inclusive_speech_processor ();
void mostafa2();
void mostafa3();
void mostafa4();

vector<string> split(string sentence, string deli);
void binaryPrint(int n);
static bool bears(int n);
void phisshing_emails();

int main()
{
    phisshing_emails();
    return 0;
}

// ================================ GAMAL =======================================

void sentence()
{
    string ans, s;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != ' ')
        {
            ans += tolower(s[i]);
        }
        else
        {
            ans += s[i];
            while (s[i] == ' ')
            {
                i++;
            }
            ans += tolower(s[i]);
        }
    }
    ans[0] = toupper(ans[0]);
    cout << ans << '\n';
}

void Sieve()
{
    int n;
    cin >> n;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
        {
            cout << i << ' ';
        }
    }
}

struct dominoT
{
    int leftDots;
    int rightDots;
};
void dominos()
{
    int n;
    cin >> n;
    vector<dominoT> d(n);
    vector<int> prem(n);
    for (int i = 0; i < n; ++i)
    {
        prem[i] = i;
        cin >> d[i].leftDots >> d[i].rightDots;
    }

    do
    {
        bool valid_chain = true;
        valid_chain &= d[prem[0]].rightDots == d[prem[1]].leftDots;
        for (int i = 1; i < n - 1; ++i)
        {
            valid_chain &= d[prem[i]].leftDots == d[prem[i - 1]].rightDots;
            valid_chain &= d[prem[i]].rightDots == d[prem[i + 1]].leftDots;
        }
        valid_chain &= d[prem[n - 1]].leftDots == d[prem[n - 2]].rightDots;
        if (valid_chain)
        {
            for (int i = 0; i < n; ++i)
            {
                cout << d[prem[i]].leftDots << '|' << d[prem[i]].rightDots << ((i == n - 1) ? "\n" : " - ");
            }
            return;
        }
    } while (next_permutation(prem.begin(), prem.end()));

    cout << "Impossible" << '\n';
}

void Bias()
{
    unordered_map<string, string> alter;
    ifstream alter_file("alter.txt");
    string exp;
    while (getline(alter_file, exp))
    {
        string key, value;
        bool v = false;
        for (int i = 0; i < exp.size(); ++i)
        {
            if (!isspace(exp[i]))
            {
                ((v) ? key += exp[i] : value += exp[i]);
            }
            else
            {
                v = true;
            }
        }
        alter[key] = value;
    }
    string word;
    int cnt = 0;
    while (cin >> word)
    {
        if (alter.find(word) == alter.end())
        {
            cout << word << ' ';
        }
        else
        {
            cnt++;
            cout << alter[word] << ' ';
        }
    }
    //    cout << cnt << '\n';
}

// ================================== WALEAD ==============================================

vector<string> split(string sentence, string deli)
{
    vector<string> res;
    int start;
    string sub;
    while (sentence.find(deli) != string::npos)
    {
        start = sentence.find(deli);
        sub = sentence.substr(0, start);
        res.push_back(sub);
        sentence.erase(0, start + deli.length());
    }
    res.push_back(sentence);
    return res;
}

void binaryPrint(int n)
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
            binaryPrint(n / 2);
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
    unordered_map<string, int> phishing = {{"secure", 2}, {"transaction", 2}, {"login", 2}, {"credit card", 3}, {"identity", 2}, {"update", 2}, {"security alert", 3}, {"bank", 1}, {"invoice", 2}, {"winner", 3}, {"verify your identity", 3}, {"confirm", 2}, {"refund", 2}, {"limited time", 2}, {"offer", 2}, {"lottery", 3}, {"free", 2}, {"urgent", 3}, {"password", 3}, {"reset", 2}, {"click here", 3}, {"verify", 3}, {"account", 2}, {"suspended", 3}, {"limited", 2}, {"social security", 3}, {"prize", 3}, {"you have won", 3}, {"claim", 3}};
    int totalpoints = 0;
    map<string, int> shared_words;
    string filename;
    cout << "PLease, Enter a file name: ";
    cin >> filename;
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        for (char &ch : line)
        {
            ch = tolower(ch);
        }
        for (auto it = phishing.begin(); it != phishing.end(); it++)
        {
            short pos = line.find(it->first);
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
// =========================== Mostafa ==========================================

//                                *** Problem 2 ***

void inclusive_speech_processor()
{

    string sentence, word, inclusive_speech;
    // 'word' holds each word being processed; 'inclusive_speech' stores the modified sentence.

    getline(cin, sentence); // Read the input sentence from the user.

    // Loop through each character in the input sentence.
    for (char letter : sentence)
    {

        // Check if the current character is a separator (punctuation or space).
        if (letter == ' ' || letter == '?' || letter == ',' || letter == '.' ||
            letter == ';' || letter == ':' || letter == '!' || letter == '-' ||
            letter == '"' || letter == '/' || letter == '(' || letter == ')')
        {

            // Check if the current word is a gender-specific pronoun and replace it.
            if (word == "he" || word == "she")
            {
                inclusive_speech += "he or she"; // Replace "he" or "she" with "he or she".
            }

            else if (word == "He" || word == "She")
            {
                inclusive_speech += "He or She"; // Replace "He" or "She" with "He or She".
            }

            else if (word == "him" || word == "her")
            {
                inclusive_speech += "him or her"; // Replace "him" or "her" with "him or her".
            }

            else if (word == "Him" || word == "Her")
            {
                inclusive_speech += "Him or Her"; // Replace "Him" or "Her" with "Him or Her".
            }

            else if (word == "his" || word == "hers")
            {
                inclusive_speech += "his or hers"; // Replace "his" or "hers" with "his or hers".
            }

            else if (word == "His" || word == "Hers")
            {
                inclusive_speech += "His or Hers"; // Replace "His" or "Hers" with "His or Hers".
            }

            else if (word == "himself" || word == "herself")
            {
                // Replace "himself" or "herself" with "himself or herself".
                // Note: It's assumed "himself" or "herself" won't start a sentence.
                inclusive_speech += "himself or herself";
            }

            else
            {
                // If the word is not a gender-specific pronoun, add it to the result unchanged.
                inclusive_speech += word;
            }

            // Add the punctuation or space (the current letter) to the result.
            inclusive_speech += letter;
            word.clear(); // Clear the current word to start building the next word.
        }

        else
        {
            // If the current character is not punctuation or a space, it's part of a word.
            word += letter; // Add the character to the current word.
        }
    }

    cout << inclusive_speech << endl; // Output the modified sentence.
}

 //                                        *** Problem 5 ***

void Top_Ten_Players(){

    vector < pair <string,int> > Players_List (10) ;

    while (true) {

        cout << "Please, choose an operation!\n   (A) Add a new player and score.\n   (B) Print the top 10 names and scores.\n   (C) Know player score.\n   (D) Exit." << endl;
        cout << "Enter wanted operation's character:";
        string choice;
        cin >> choice;

        if (choice == "A" || choice == "a") {
            string player_name;
            int player_score;

            cout << "Please, enter player's name:";
            cin >> player_name;

            while (true) {
                cout << "Please, enter player's score:";

                try {
                    cin >> player_score;
                    cout << endl;
                    // Check if more than one character was entered
                    if (cin.fail() || cin.peek() != '\n') {
                        throw invalid_argument("Input is not a valid integer!");
                    }
                    break;

                }
                catch (const invalid_argument &e) {
                    // Clear the input buffer and reset cin state
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << e.what() << " Please try again.\n";
                }
                cout << endl;
            }

            Add_Player( Players_List, player_name , player_score);

        }

        else if (choice == "B" || choice == "b") {

            Print_Top_10( Players_List);

        }

        else if (choice == "C" || choice == "c") {

            string player_name;
            cout << "Please, enter player's name:";
            cin >> player_name;
            Find_Player_Name(Players_List , player_name);

        }

        else if (choice == "D" || choice == "d") {
            cout << "I hope you have a great day." << endl;
            break;
        }

        else {
            cout << "Please, Enter a valid choice!" << endl;
        }

    }

}


void Add_Player ( vector < pair <string,int> >& Players_List , string player_name, int player_score){

    if ( Players_List.back().first == "" && Players_List.back().second == 0){

        Players_List.push_back( make_pair(player_name , player_score) );
        sort(Players_List.rbegin() , Players_List.rend());

    }

    else {

        if (player_score > Players_List.back().second){

            Players_List.back().first = player_name;
            Players_List.back().second = player_score;
            sort(Players_List.rbegin() , Players_List.rend());

        }
        // No need to sort if the score is not added to the top 10.
    }

}

void Print_Top_10 (const vector < pair <string,int> >& Players_List){

    cout << "=========================\n";
    cout << setw(10) << left << "Player" << " | " << setw(10) << right << "Score" << endl;
    cout << "=========================\n";
    // Loop through the vector and print each player's name and score with a vertical line

    for (int i = 0; i < 10 ; ++i) {

        cout << setw(10) << left << Players_List[i].first << " | "
             << setw(10) << right << Players_List[i].second << endl;

    }
}

void Find_Player_Name (const vector < pair <string,int> >& Players_List , string player_name){

    for (int i = 0; i < 10; ++i) {

        if (player_name == Players_List[i].first ){

            cout << player_name << "'s score is: " << Players_List[i].second << endl << endl;
            break;
        }

        if (i == 9){

            cout << "Sorry, this player's name isn't on the top 10!" << endl;
        }
    }
}
