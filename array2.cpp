#include <bits/stdc++.h>
using namespace std;
int max_sum_subarr(vector<int> arr) // previous sum ending with arr[i]
{
    int n = arr.size();
    int prevmax[n];
    int ans = arr[0];
    prevmax[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prevmax[i] = max(prevmax[i - 1] + arr[i], arr[i]);

        ans = max(prevmax[i], ans);
    }
    //  for(int i: prevmax)
    //  {
    //      cout<<i<<" ";
    //  }
    return ans;
}

int max_sum_arr(vector<int> arr) // kadane algo
{
    int curr = arr[0];
    int maxsum = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        curr += arr[i];
        if (curr < 0)
            curr = 0;

        maxsum = (maxsum, curr);
    }
    return maxsum;
}

int alt_odd_even_subarray(vector<int> arr)
{
    int maxlength = 1;
    int currlength = 1;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if ((((arr[i] % 2) == 0) and (arr[i + 1] % 2) == 1) or ((arr[i] % 2 == 1) and (arr[i + 1] % 2 == 0)))
        {
            currlength++;
            maxlength = max(maxlength, currlength);
        }
        else
        {
            currlength = 0;
        }

        return maxlength;
    }
}
int majority(vector<int> arr) // Moore Voting Algorithm
{
    int n = arr.size();
    int res = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
        {
            count++;
        }
        else if (count == 0)
        {
            res = i;
        }
        else
        {
            count--;
        }
    }
    return arr[res]; // assuming majority always exists (apeearing more than n/2)
}
void twomajority(vector<int> arr) // Extended Moore Vote Algorithm
{
    int n = arr.size();
    int res1 = 0;
    int res2 = 0;
    int count1 = 1;
    int count2 = 1;

    for (int i = 1; i < n; i++)
    {
        if ((arr[res1] == arr[i]))
        {
            count1++;
        }
        else if ((arr[res2] == arr[i]))
        {
            count2++;
        }

        else if ((count1 == 0) or (count2 == 0))
        {
            if (count1 == 0)
                res1 = i;

            else
                res2 = i;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    cout << arr[res1] << "  " << arr[res2] << endl;
}
void majority_map(vector<int> arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto x : mp)
    {
        if (x.second > n / 3)
        {
            cout << x.first << " ";
        }
    }
}
void min_flips(vector<int> arr) 
{
    int n=arr.size();
    for(int i = 1; i < n; i++)
    {
        if(arr[i]!=arr[i-1])   // We will always start with the second
                               // group and start flippng it
        {
            if(arr[i]!=arr[0])
            {
                cout<<"From "<<i<<" to ";
            }

            else{
                cout<<i-1<<endl;
            }
        }
    
    }
    if(arr[n-1]!=arr[0]) cout<<n-1;
    
}
int main()
{
    int a;
    vector<int> arr;
    for (int i = 0; i < 8; i++)
    {
        cin >> a;
        arr.push_back(a);
    }

    // cout<<max_sum_subarr(arr)<<" ";
    // cout<<max_sum_arr(arr)<<" ";

    // cout<<alt_odd_even_subarray(arr)<<" ";
    // cout<<majority(arr)<<" ";
    // twomajority(arr);
   // majority_map(arr);
   //min_flips(arr);   bool arrays: { 0 0 1 1 1 0 }
   
}
