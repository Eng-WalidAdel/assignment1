#include <iostream>
#include <vector>
#define endl '\n'
#define loop(i, n) for (int i = 0; i < n; i++)
#define loop2(i, n) for (int i = 1; i <= n; i++)
#define testcases \
    int t;        \
    cin >> t;     \
    while (t--)
#define loop_cout(d) for (auto it = d.begin(); it != d.end(); it++)
#define ll long long
#define endl '\n'
using namespace std;
void fast()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}
void gamal1();
void gamal2();
void gamal3();
void gamal4();

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

    return 0;
}

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

}
