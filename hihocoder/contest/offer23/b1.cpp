//#define DEBUG
//#define PROBLEM
//#define MY
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int M = 1e6 + 10;
struct Node {
    string name;
    map<string, int> son;
    Node() {}
    Node(const string &s) {
        name = s;
        son.clear();
    }
};
vector<Node> tree;
int n;
char a[M];
vector<string> b;
void Solve() {
    tree.clear();
    tree.push_back(Node("/"));
    for (int i = 0; i < n; i++) {
        const string &s = b[i];
        int root = 0;
        for (int j = 1; j < s.size(); j++) {
            int last = j;
            for (int k = j + 1; k < s.size(); k++) {
                if (s[k] == '/') break;
                last = k;
            }
            string name = s.substr(j, last - j + 1);
            if (tree[root].son.count(name)) {
                root = tree[root].son[name];
            } else {
                tree.push_back(Node(name));
                tree[root].son[name] = tree.size() - 1;
                root = tree.size() - 1;
            }
            j = last + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        string &s = b[i];
        int root = 0;
        for (int j = 1; j < s.size(); j++) {
            int last = j;
            for (int k = j + 1; k < s.size(); k++) {
                if (s[k] == '/') break;
                last = k;
            }
            string name = s.substr(j, last - j + 1);
            if (j != 1 && last != s.size() - 1 && tree[root].son.size() == 1) {
                s[j - 1] = '-';
            }
            root = tree[root].son[name];
            j = last + 1;
        }
    }
}
int main() {
    #ifdef PROBLEM
    freopen("problem_in.txt", "r", stdin);
    freopen("brute_out.txt", "w", stdout);
    #endif // PROBLEM

    #ifdef MY
    freopen("my_in.txt", "r", stdin);
    freopen("brute_out.txt", "w", stdout);
    #endif // MY

    scanf("%d", &n);
    b.clear();
    for (int i = 0; i < n; i++) {
        scanf("%s", a);
        b.push_back((string)a);
    }
    Solve();
    for (int i = 0; i < n; i++) {
        puts(b[i].c_str());
    }
    return 0;
}

