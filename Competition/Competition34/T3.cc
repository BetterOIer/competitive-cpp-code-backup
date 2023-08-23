#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int Maxn = 1e5, Mod = 1e9 + 7;
inline void ModMulTo(int &a, int b) {
  a = (long long)a * b % Mod;
}
void Exgcd(int a, int b, long long &x, long long &y, int &d) {
  if (b == 0) {
    x = 1;
    y = 0;
    d = a;
  } else {
    Exgcd(b, a % b, y, x, d);
    y -= a / b * x;
  }
}
int ModInv(int a) {
  long long x, y;
  int d;
  Exgcd(a, Mod, x, y, d);
  return (x % Mod + Mod) % Mod;
}

inline void ModDivTo(int &a, int b) {
  a = (long long)a * ModInv(b) % Mod;
}

int n, m, m1, origin[Maxn];
int set[Maxn];
vector<long long> add[Maxn];
int mul[Maxn + 1], cnt_mul;

struct cmp {
  bool operator () (int i, int j) const {
    return (__int128)add[i][add[i].size() - 2] * add[j].back()
      < (__int128)add[i].back() * add[j][add[j].size() - 2];
  }
};

priority_queue<int, vector<int>, cmp> addq;

int ans1, ans2;

void AnsMul(long long x) {
  while (x % Mod == 0) {
    x /= Mod;
    ++ans2;
  }
  ModMulTo(ans1, x % Mod);
}

void AnsDiv(long long x) {
  while (x % Mod == 0) {
    x /= Mod;
    --ans2;
  }
  ModDivTo(ans1, x % Mod);
}

int main(void) {
  scanf("%d%d%d", &n, &m, &m1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", origin + i);
  }
  for (int _ = m; _--; ) {
    int t, i, b;
    scanf("%d%d%d", &t, &i, &b);
    --i;
    if (t == 1) {
      set[i] = max(set[i], b);
    } else if (t == 2) {
      if (b > 0) {
        add[i].push_back(b);
      }
    } else {
      if (b > 1) {
        mul[cnt_mul++] = b;
      }
    }
  }
  sort(mul, mul + cnt_mul);
  
  ans1 = 1;
  ans2 = 0;
  for (int i = 0; i < n; ++i) {
    if (set[i] > origin[i]) {
      add[i].push_back(set[i] - origin[i]);
    }
    sort(add[i].begin(), add[i].end());
    if (origin[i] == 0) {
      if (add[i].empty() || !m1) {
        puts("0");
        return 0;
      }
      origin[i] = add[i].back();
      add[i].pop_back();
      --m1;
    }
    add[i].push_back(origin[i]);
    for (int j = add[i].size() - 2; j >= 0; --j) {
      add[i][j] += add[i][j + 1];
    }
    AnsMul(origin[i]);
    if (add[i].size() >= 2) {
      addq.push(i);
    }
  }

  while (m1--) {
    long long mul_1_up = -1, mul_1_down = -1;
    if (!addq.empty()) {
      int i = addq.top();
      mul_1_up = add[i][add[i].size() - 2];
      mul_1_down = add[i].back();
    }
    long long mul_2 = -1;
    if (cnt_mul) {
      mul_2 = mul[cnt_mul - 1];
    }
    if (mul_1_up == -1 || (mul_2 != -1 && (__int128)mul_2 * mul_1_down > mul_1_up)) {
      if (mul_2 == -1) {
        break;
      }
      // Apply 2
      AnsMul(mul_2);
      --cnt_mul;
    } else {
      // Apply 1
      int i = addq.top();
      addq.pop();
      add[i].pop_back();
      if (add[i].size() >= 2) {
        addq.push(i);
      }
      AnsMul(mul_1_up);
      AnsDiv(mul_1_down);
    }
  }
  if (ans2) {
    puts("0");
  } else {
    printf("%d\n", ans1);
  }
  return 0;
}
  