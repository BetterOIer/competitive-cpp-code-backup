#include <bits/stdc++.h>

int board[4][4];

std::pair<int, int> Draw() {
  // draw in the middle of the board
  return std::make_pair(2, 2);
}

signed main() {
  int T;
  std::cin>>T;
  while(T--) {
    while (1) {
      std::pair<int, int> d = Draw();
      board[d.first][d.second] = 1;
      std::cout << d.first << ' ' << d.second << std::endl;
      int t;
      std::cin >> t;
      if (t) break;
      int x, y;
      std::cin >> x >> y >> t;
      board[x][y] = 2;
      if (t) break;
    }
    std::string s;
    std::cin>>s;
    if(s!="seija_win") break;
  }
  return 0;
}