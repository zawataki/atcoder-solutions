#include <iostream>

using namespace std;

#define BIGINT_SIZE (1000)

class BigInt {
private:
    unsigned int _num[BIGINT_SIZE]{};

    void carry_up() {
        for (int i = 0; i < BIGINT_SIZE - 1; ++i) {
            if (_num[i] >= 10) {
                _num[i + 1] += _num[i] / 10;
                _num[i] %= 10;
            }
        }
    }

public:
    BigInt() {
        for (unsigned int &i : _num) {
            i = 0;
        }
    }

    void add(int num) {
        _num[0] += num;
        carry_up();
    }

    string to_string() {

        int i = BIGINT_SIZE - 1;
        for (; i >= 0; --i) {
            if (_num[i] != 0) break;
        }
        if (i < 0) {
            return "0";
        }

        string ret;
        while (i >= 0) {
            ret += ::to_string(_num[i]);
            i--;
        }

        return ret;
    }
};

int main() {
    string s, t;
    cin >> s >> t;

    BigInt count;
    int prev_pos = -1;
    for (char c : t) {
        if (++prev_pos >= s.length()) {
            prev_pos = 0;
            count.add(s.length());
        }

        int pos_from_prev_pos = s.find(c, prev_pos);

        if (pos_from_prev_pos != string::npos) {
            prev_pos = pos_from_prev_pos;
            continue;
        }

        count.add(s.length());
        int pos_from_top = s.find(c);
        if (pos_from_top == string::npos) {
            cout << "-1" << endl;
            return 0;
        }

        prev_pos = pos_from_top;
    }

    count.add(prev_pos + 1);

    string answer = count.to_string();
    cout << answer << endl;
}
