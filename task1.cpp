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

void mostafa1();
void mostafa2();
void mostafa3();
void mostafa4();

vector<string> split(string sentence, string deli);
static void binaryPrint(int n);
void walid3();
void walid4();

int main()
{
    fast();
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
    if(n==0){
        cout << 0 << endl;
        return;
    }
    else{
        if(n/2!=0){
            binaryPrint(n / 2);
        }
        cout << n % 2;
    }
// =========================== Mostafa ==========================================
}
