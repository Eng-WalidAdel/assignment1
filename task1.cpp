#include <bits/stdc++.h>
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
void walid4();

int main()
{

    return 0;
}

// ================================ GAMAL =======================================

void sentence() {
    string ans , s;
    getline(cin , s);
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] != ' ')
        {
            ans += tolower(s[i]);
        }
        else
        {
            ans += s[i];
            while (s[i] == ' '){
                i++;
            }
            ans += tolower(s[i]);
        }
    }
    ans[0] = toupper(ans[0]);
    cout << ans << '\n';
}

void Sieve() {
    int n;
    cin >> n;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << ' ';
        }
    }
}

struct dominoT {
    int leftDots;
    int rightDots;
};
void dominos()
{
    int n;
    cin >> n;
    vector<dominoT>d(n);
    vector<int>prem(n);
    for (int i = 0; i < n; ++i) {
        prem[i] = i;
        cin >> d[i].leftDots >> d[i].rightDots;
    }

    do {
        bool valid_chain = true;
        valid_chain &= d[prem[0]].rightDots == d[prem[1]].leftDots;
        for (int i = 1; i < n - 1; ++i) {
            valid_chain &= d[prem[i]].leftDots == d[prem[i - 1]].rightDots;
            valid_chain &= d[prem[i]].rightDots == d[prem[i + 1]].leftDots;
        }
        valid_chain &= d[prem[n - 1]].leftDots == d[prem[n - 2]].rightDots;
        if(valid_chain)
        {
            for (int i = 0; i < n; ++i) {
                cout << d[prem[i]].leftDots << '|' << d[prem[i]].rightDots << ((i == n - 1)? "\n" : " - ");
            }
            return;
        }
    } while (next_permutation(prem.begin() , prem.end()));

    cout << "Impossible" << '\n';
}

void Bias()
{
    unordered_map<string , string>alter;
    ifstream alter_file("alter.txt");
    string exp;
    while (getline(alter_file , exp))
    {
        string key , value;
        bool v = false;
        for (int i = 0; i < exp.size(); ++i) {
            if(!isspace(exp[i]))
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
        if(alter.find(word) == alter.end())
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
            if (((n % 10) * (n % 100)) >0 && bears(n - ((n % 10) * ((n % 100)/10))))
                return true;
        }
    }
    return false;
}
// =========================== Mostafa ==========================================

void inclusive_speech_processor (){

    string sentence , word , inclusive_speech;
    // 'word' holds each word being processed; 'inclusive_speech' stores the modified sentence.

    getline(cin, sentence); // Read the input sentence from the user.


    // Loop through each character in the input sentence.
    for (char letter : sentence){

        // Check if the current character is a separator (punctuation or space).
        if ( letter == ' ' || letter == '?' || letter == ',' || letter == '.' ||
             letter == ';' || letter == ':' || letter == '!' || letter == '-' ||
             letter == '"' || letter == '/' || letter == '(' || letter == ')' ){

            // Check if the current word is a gender-specific pronoun and replace it.
            if ( word == "he" || word == "she" ){
                inclusive_speech += "he or she"; // Replace "he" or "she" with "he or she".
            }

            else if ( word == "He" || word == "She" ){
                inclusive_speech += "He or She"; // Replace "He" or "She" with "He or She".
            }

            else if ( word == "him" || word == "her" ){
                inclusive_speech += "him or her"; // Replace "him" or "her" with "him or her".
            }

            else if ( word == "Him" || word == "Her" ){
                inclusive_speech += "Him or Her"; // Replace "Him" or "Her" with "Him or Her".
            }

            else if ( word == "his" || word == "hers" ){
                inclusive_speech += "his or hers"; // Replace "his" or "hers" with "his or hers".
            }

            else if ( word == "His" || word == "Hers" ){
                inclusive_speech += "His or Hers"; // Replace "His" or "Hers" with "His or Hers".
            }

            else if ( word == "himself" || word == "herself" ){
                // Replace "himself" or "herself" with "himself or herself".
                // Note: It's assumed "himself" or "herself" won't start a sentence.
                inclusive_speech += "himself or herself";
            }

            else {
                // If the word is not a gender-specific pronoun, add it to the result unchanged.
                inclusive_speech += word;
            }

            // Add the punctuation or space (the current letter) to the result.
            inclusive_speech += letter;
            word.clear(); // Clear the current word to start building the next word.
        }

        else {
            // If the current character is not punctuation or a space, it's part of a word.
            word += letter; // Add the character to the current word.
        }
    }

    cout << inclusive_speech << endl; // Output the modified sentence.
}