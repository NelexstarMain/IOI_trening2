#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int a, b, c;

    Student(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}

    bool is_sleeping() {
        return c > a;
    }

    void update(int awake, int sleeping) {
        if (c == a) {
            if (sleeping > awake) {
                c++;
            } else {
                c = 1;
            }
        } else if (c == a + b) {
            c = 1;
        } else {
            c++;
        }
    }
};

void solve() {
    int n, caseNum = 1;
    while (cin >> n && n > 0) {
        vector<Student> students;
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            students.push_back(Student(a, b, c));
        }

        int result = -1;
        for (int t = 1; t <= 1000000; t++) {
            int current_sleeping = 0;
            int current_awake = 0;

            for (int i = 0; i < n; i++) {
                if (students[i].is_sleeping()) current_sleeping++;
                else current_awake++;
            }

            if (current_awake == n) {
                result = t;
                break;
            }

            for (int i = 0; i < n; i++) {
                students[i].update(current_awake, current_sleeping);
            }
        }

        cout << "Case " << caseNum++ << ": " << result << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}