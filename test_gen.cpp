#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

string longToStr(long long n) {
    return to_string(n); 
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <int|strlexi|strlenlexi> <1|2|3|4|5>\n";
        return 1;
    }

    string type = argv[1];
    int test_num = atoi(argv[2]);

    if (test_num < 1 || test_num > 5) {
        cerr << "Error: Test number must be between 1 and 5.\n";
        return 1;
    }

    srand(time(NULL));
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    if (type == "int") {
        int n_int = 100000;
        cout << n_int << "\n";
        for (int i = 0; i < n_int; i++) {
            if (test_num == 1) {
                long long r = ((long long)rand() << 16) | rand();
                cout << r % 2147483648LL * (rand() % 2 ? -1 : 1) << "\n";
            } else if (test_num == 2) {
                cout << (n_int - i) << "\n";
            } else if (test_num == 3) {
                cout << ((i % 2 == 0) ? "-2147483648" : "2147483647") << "\n";
            } else if (test_num == 4) {
                cout << "123456\n";
            } else if (test_num == 5) {
                cout << ((long long)(i + 1) * 65536 % 2147483647LL) << "\n";
            }
        }
    } 
    else if (type == "strlexi") {
        int n_str = 100000;
        cout << n_str << "\n";
        
        if (test_num == 3 || test_num == 4) {
            vector<string> t(n_str);
            for(int i = 0; i < n_str; i++) {
                string num = longToStr(i);
                t[i] = string(100 - num.length(), 'b') + num;
            }
            if (test_num == 3) {
                sort(t.begin(), t.end());
            } else {
                sort(t.begin(), t.end());
                reverse(t.begin(), t.end());
            }
            for(int i = 0; i < n_str; i++) {
                cout << t[i] << "\n";
            }
        } 
        else {
            string prefix99(99, 'a');
            for(int i = 0; i < n_str; i++) {
                if (test_num == 1) {
                    int len = rand() % 91 + 10;
                    string s = ""; 
                    for(int j = 0; j < len; j++) s += alpha[rand() % 26];
                    cout << s << "\n";
                } else if (test_num == 2) {
                    cout << prefix99 + (char)('a' + (i % 26)) << "\n";
                } else if (test_num == 5) {
                    cout << string(100, 'm') << "\n";
                }
            }
        }
    } 
    else if (type == "strlenlexi") {
        int n_len = 10000;
        cout << n_len << "\n";
        for (int i = 0; i < n_len; i++) {
            if (test_num == 1) {
                cout << string((i % 91) + 10, alpha[rand() % 26]) << "\n";
            } else if (test_num == 2) {
                cout << string(95, 's') + longToStr(1000 + (i % 9000)) << "\n";
            } else if (test_num == 3) {
                cout << string(10, (char)('z' - (i % 26))) << "\n";
            } else if (test_num == 4) {
                cout << ((i % 2 == 0) ? string(15, '9') : string(16, '1')) << "\n";
            } else if (test_num == 5) {
                int L = rand() % 91 + 10;
                string s = ""; 
                for(int j = 0; j < L; j++) s += alpha[rand() % 26];
                cout << s << "\n";
            }
        }
    } 
    else {
        cerr << "Error: Invalid test type. Expected int, strlexi, or strlenlexi.\n";
        return 1;
    }

    return 0;
}