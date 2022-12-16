#include <iostream>


using namespace std;

int main() {
  long long n, x, m = 0, s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    m = max(m, x);
    s += x;
  }
  cout << (m > (s - m) ? 2 * m : s) << endl;
}
