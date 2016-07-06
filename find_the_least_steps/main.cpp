#include <iostream>
#include <map>
#include <queue>
#include <utility>
using std::make_pair;

int main(void) {
  int T;
  std::cin >> T;
  std::map<std::pair<int, int>, int> dis;
  std::map<std::pair<int, int>, bool> visit;
  while (T--) {
    std::string start, end;
    std::cin >> start >> end;
    const int a = start[0] - 96;
    const int b = start[1] - '0';
    const int c = end[0] - 96;
    const int d = end[1] - '0';
    std::pair<int, int> staplace(make_pair<a, b>);
    std::pair<int, int> endplace(make_pair<c, d>);
    for (int i = 1; i < 9; ++i) {
      for (int j = 1; j < 9; ++j) {
        visit[make_pair(i, j)] = true;
        dis[make_pair(i, j)] = 0;
      }
    }
    std::queue<std::pair<int, int> > que;
    visit[staplace] = false;
    while (!que.empty()) {
      std::pair<int, int> vs = que.front();
      que.pop();
      std::pair<int, int> up, down, right, left;
      up = make_pair(vs.first, vs.second - 1);
      down = make_pair(vs.first, vs.second + 1);
      right = make_pair(vs.first + 1, vs.second);
      left = make_pair(vs.first - 1, vs.second);

      if (visit[right]) {
        dis[right] = dis[vs] + 1;
        if (right == endplace) {
          break;
        }
        que.push(right);
        visit[right] = false;
      }
      if (visit[down]) {
        dis[down] = dis[vs] + 1;
        if (down == endplace) {
          break;
        }
        que.push(down);
        visit[down] = false;
      }
      if (visit[left]) {
        dis[left] = dis[vs] + 1;
        if (left == endplace) {
          break;
        }
        que.push(left);
        visit[left] = false;
      }
      if (visit[up]) {
        dis[up] = dis[vs] + 1;
        if (up == endplace) {
          break;
        }
        que.push(up);
        visit[up] = false;
      }
    }
    std::cout << dis[endplace] << std::endl;
  }
  return 0;
}
