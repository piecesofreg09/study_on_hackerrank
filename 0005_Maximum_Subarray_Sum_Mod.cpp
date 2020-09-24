/*
sum[i, j] % mod = (prefix[j] - prefix[i]) % mod = flag
if prefix[j] % mod > prefix[i] % mod, then flag = prefix[j] % mod - prefix[i] % mod
if prefix[j] % mod < prefix[i] % mod, then flag = prefix[j] % mod - prefix[i] % mod + mod

mod = 7
for example for the array  3 3 9  9  5
index                      0 1 2  3  4
the prefix sum is          3 6 15 24 29
the mod prefix sum is      3 6 1  3  1

for example for prefix[3] % 7 = 3 and prefix[2] % 7 = 1, because 3 > 1, sum[2,3] % mod = 9 % 7 = (24 - 15) % 7 = 24 % 7 - 15 % 7 = 3 - 1 = 2

for example for prefix[3] % 7 = 3 and prefix[1] % 7 = 6, because 3 < 6, sum[1,3] % mod = 18 % 7 = (24 - 6) % 7 = 24 % 7 - 6 % 7 + 7= 3 - 6 + 7 = 4

calculate the prefix sum
calculate the prefix sum % mod
get the maximum value of this array
then iterate through the array, for example a1, a2, a3, a4, ...
for a4, find the smallest element in [a1, a2, a3] that is bigger than a4

this process can be done by using a sorted structure
this sorted structure should be able to be looked and inserted in log(n) time.

*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumSum function below.
long maximumSum(vector<long> a, long m) {
    
    long res = LONG_MIN;
    long sum = 0;
    long temp = LONG_MAX;
    // c++ set is ordered
    set<long> sett;
    long n = a.size();
    // the presum vector needs to declared with long
    vector<long> vect(n, 0);

    for (int i = 0; i < n; i++) {
        sum = (sum + a[i]) % m;
        vect[i] = sum;
        res = std::max(res, sum);
        //cout << vect[i] << " current " << res << endl;
    }

    // find the smallest element that is larger than the current presum
    for (auto x: vect) {
        auto p = sett.insert(x);
        //cout << *p.first << endl;
        // ++p.first modified the p.first value
        if (++p.first != sett.end()) {
            //cout << *p.first << endl;
            temp = min(*p.first - x, temp);
        }
        //cout << endl;
    }

    return std::max(res, m - temp);
    /*
    long sum = 0, max = LONG_MIN, result = LONG_MAX;
    set<long> s;

    for (int i = 0; i < a.size(); i++) {
        sum = (sum + a[i]) % m;
        a[i] = sum;
        max = std::max(max, sum);
    }

    for (auto x: a) {
        auto p = s.insert(x);
        if (++p.first != s.end()) {
            result = min(*p.first - x, result);
        }
    }

    return std::max(max, m - result);
    */
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        long m = stol(nm[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<long> a(n);

        for (int i = 0; i < n; i++) {
            long a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        long result = maximumSum(a, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
