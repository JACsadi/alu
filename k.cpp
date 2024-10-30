    #include <iostream>
    #include <queue>
    using namespace std;
    int main() {
        int n,k,target; //n = size of array
        cin >> n >> k >> target;
        int arr[n];
        for(int i = 0; i<n;i++) cin>>arr[i];
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0; i<n;i++) pq.push({abs(arr[i]-target), arr[i]});
        priority_queue<int, vector<int>,greater<int>> ans;
        for(int i = 0;i< k; i++) {
            pair<int,int> top = pq.top();
            pq.pop();
            ans.push(top.second);
        }
        for(int i = 0;i< k; i++) {
            int top = ans.top();
            ans.pop();
            cout << top << " ";
        }
        cout << endl;
        return 0;
    }