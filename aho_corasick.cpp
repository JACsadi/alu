#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for(int i = 0; i < (n); i++)
#define sd(i) scanf("%d", &i)
#define tcase int t; sd(t); for(int casee = 1; casee <= t; casee++)
#define en printf("\n")
#define mod 1000000007
using namespace std;

const int siz = 26;

typedef struct node {
    int link[26];  // Next nodes for each character
    int go[26];    // Transitions
    int pch;       // Character leading to this node
    int fail = -1; // Failure link
    int flag = 0;  // Marking if this node is the end of some pattern
    int vis = 1;
    int p;         // Parent node

    // Initialize with -1 for links and transitions
    node() {
        fill(begin(link), end(link), -1);
        fill(begin(go), end(go), -1);
    }
} node;

// Function to add a string to the trie
void add(vector<node>& trie, string& str, int ind) {
    int v = 0;
    f(i, str.length()) {
        int nex = str[i] - 'a';
        if (trie[v].link[nex] == -1) {
            trie[v].link[nex] = trie.size();
            trie.emplace_back();
            trie.back().p = v;
            trie.back().pch = nex;
        }
        v = trie[v].link[nex];
    }
    trie[v].flag = ind; // Mark the end of the pattern
}

// Function to build failure links
void buildfailure(vector<node>& trie) {
    queue<int> bfs;
    bfs.push(0);
    trie[0].fail = 0;

    while (!bfs.empty()) {
        int v = bfs.front();
        bfs.pop();

        for (int i = 0; i < 26; i++) {
            if (trie[v].link[i] != -1) {
                int u = trie[v].link[i];
                int f = trie[v].fail;

                // Adjust failure link
                while (f != 0 && trie[f].link[i] == -1) {
                    f = trie[f].fail;
                }

                if (trie[f].link[i] != -1 && trie[f].link[i] != u) {
                    trie[u].fail = trie[f].link[i];
                } else {
                    trie[u].fail = 0;
                }

                bfs.push(u);
            }
        }
    }
}

// Function to set up transitions using the failure links
void setupGo(vector<node>& trie) {
    for (int v = 0; v < trie.size(); v++) {
        for (int ch = 0; ch < 26; ch++) {
            if (trie[v].link[ch] != -1) {
                trie[v].go[ch] = trie[v].link[ch];
            } else if (v == 0) {
                trie[v].go[ch] = 0;
            } else {
                trie[v].go[ch] = trie[trie[v].fail].go[ch];
            }
        }
    }
}

// Function to traverse the trie and mark visited nodes
void visited(string& str, vector<node>& trie, vector<int>& arr) {
    int v = 0;
    for (int i = 0; i < str.size(); i++) {
        int ch = str[i] - 'a';
        int tempv = v;
        while (tempv != 0 && trie[tempv].vis) {
             if(trie[tempv].flag) arr[trie[tempv].flag]++;
             trie[tempv].vis = 0;
             tempv = trie[tempv].fail;
        }
        while (v != 0 && trie[v].go[ch] == -1) {
            v = trie[v].fail;
        }

        // Transition to next state
        v = trie[v].go[ch];
        if (v == -1) v = 0;
        if( i == str.size()-1 && trie[v].flag) arr[trie[v].flag]++;
    }
}

int main() {
    string str;
    cin >> str;

    int q; 
    sd(q);
    
    vector<string> patterns(q);
    vector<node> trie(1);  // Start with root node

    // Add patterns to the trie
    map<string,int> mymap;
    vector<int> track(q+1);
    f(i, q) {
        cin >> patterns[i];
        if(mymap[patterns[i]] != 0) {
            track[i+1] = mymap[patterns[i]];
        } else {
          add(trie, patterns[i], i + 1);
          track[i+1] = i+1;
          mymap[patterns[i]] = i+1;
        }
    }

    // Build failure links and set up go transitions
    buildfailure(trie);
    setupGo(trie);

    // Array to keep track of visited patterns
    vector<int> found(q + 1, 0);

    // Traverse the input string and mark which patterns are found
    visited(str, trie, found);

    // Output results
    f(i, q) {
        cout << (found[track[i+1]]) << endl;
    }

    return 0;
}
