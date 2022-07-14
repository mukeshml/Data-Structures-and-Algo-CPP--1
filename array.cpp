#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> arr)
{
    int res = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[res])
        {
            res = i;
        }
    }
    return arr[res];
}
int secondlargest(vector<int> arr)
{
    int res = -1;
    int largest = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[largest] < arr[i])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if ((res == -1) or (arr[i] > arr[res]))
            {
                res = i;
            }
        }
    }

    return arr[res];
}
void swap_arr(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;

        low++;
        high--;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
void reverse_arr(vector<int> &arr, int low, int high)
{
    while (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;

        low++;
        high--;
    }
}
vector<int> acw_by_d_algo(vector<int> &arr, int n, int d)
{
    reverse_arr(arr, 0, d - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    reverse_arr(arr, d, n - 1);

    reverse_arr(arr, 0, n - 1);

    return arr;
}
int no_duplicate(int arr[], int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[res - 1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}
vector<int> move0s(vector<int> arr)
{
    // Naive

    // for(int i=0;i<arr.size();i++)
    // {
    //     if(arr[i]==0)
    //     {
    //         for (int j = i+1; j < arr.size(); j++)
    //         {
    //             if(arr[j]!=0)
    //            { swap(arr[i],arr[j]);}
    //         }

    //     }
    // }
    // return arr;

    // Efficient
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
    return arr;
}
void acw_rot(vector<int> arr)
{
    int temp = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    // return arr;
}
vector<int> acw_rot_by_d(vector<int> arr, int d)
{

    for (int i = 0; i < d; i++)
    {
        acw_rot(arr);
    }

    return arr;
}
bool sorted_arr(vector<int> arr) // non-decreasing
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}
vector<int> acw_by_d(vector<int> arr, int d)
{
    int temp[d];
    int n = arr.size();
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    for (int i = 0; i < d; i++)
    {
        arr[n - d + i] = temp[i];
    }
    return arr;
}
int max_diff(vector<int> arr)
{
    int res = INT16_MIN;
    int minval = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        res = max(res, arr[i] - minval);
        minval = min(arr[i], minval);
    }
    return res;
}
void freq_arr(vector<int> &arr) //sorted
{
    int count = 1, i = 1;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            count++;
        }
        else
        {
            cout << arr[i - 1] << " " << count << endl;
            count = 1;
        }
    }
    if ((n == 1) or (arr[n - 1] != arr[n - 2]))
    {
        cout << arr[n - 1] << " "
             << "1" << endl;
    }
}
int stockbuysell(vector<int> prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}
void trappingwater(vector<int> &A)
{
    int res = 0;
    int n = A.size();
    int lmax[n], rmax[n];
    lmax[0] = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        lmax[i] = max(lmax[i - 1], A[i]);
    }
    cout << " lmax : ";
    for (int i = 0; i < n; i++)
    {
        cout << lmax[i] << " ";
    }
    cout << endl;
    rmax[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], A[i]);
    }

    cout << "rmax : ";
    for (int i = 0; i < n; i++)
    {
        cout << rmax[i] << " ";
    }
    for (int i = 1; i < n - 1; i++)
    {
        res = res + (min(lmax[i], rmax[i]) - A[i]);
    }
    cout << endl;
    cout << "Ans  : " << res;
}
int maxrepeating1s(vector<int> arr)
{
    int n = arr.size();
    int count = 0;
    int maxcount = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 0)
        {
            count = 0;
        }
        else
        {
            count++;
            maxcount = max(count, maxcount);
        }
    }
    return maxcount;
}

int main()
{
    // int d,n;
    // cin>>n>>d;
    vector<int> A;
    int a;
    for (int i = 0; i < 5; i++)
    {
        cin >> a;
        A.push_back(a);
    }

    // cout<<largest(A)<<endl;
    // cout<<secondlargest(A)<<endl;

    // swap_arr(A);
    //   int n;
    //   cin>>n;
    //   int A[n];
    //   for (int i = 0; i < n; i++)
    //   {
    //       cin>>A[i];
    //   }

    // cout<<no_duplicate(A,n);
    //   vector<int> ans;
    //   int d;
    //   cin>>d;
    // ans=move0s(A);
    // ans=acw_rot(A);
    //   ans=acw_rot_by_d(A,d);

    //   for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    // cout<<sorted_arr(A);
    // vector<int> ans;
    // ans=acw_by_d(A,d);
    // for(int i=0;i<ans.size();i++)
    // {
    // cout<<ans[i]<<" ";
    // }
    // vector<int> ans;
    // ans=acw_by_d_algo(A,n,d);

    // for(int i=0;i<n;i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    // cout << max_diff(A);
    // freq_arr(A);
    // cout<<stockbuysell(A)<<" ";
    // cout<<trappingwater(A)<<" ";
    // trappingwater(A);
    cout << maxrepeating1s(A) << " ";
}