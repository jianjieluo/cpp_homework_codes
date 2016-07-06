#include <iostream>
#include <map>
#include <queue>
#include <utility>

#define Rock '#'
#define Start 'S'
#define End 'E'
#define Road '.'
#define Fire '!'
using namespace std;
std::map<std::pair<int, int>, char>::iterator it;

int main(void) {
  int n, m;
  std::cin >> n >> m;  // n rows, m cloumn
  std::map<std::pair<int, int>, char> maze;
  std::map<std::pair<int, int>, int> dis;
  std::map<std::pair<int, int>, bool> visit;
  std::map<std::pair<int, int>, char>::iterator itBegin;
  std::map<std::pair<int, int>, char>::iterator itEnd;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char temp;
      std::cin >> temp;
      maze[make_pair(i, j)] = temp;
      if (temp == Fire || temp == Rock) {
        visit[make_pair(i, j)] = false;
      } else {
        visit[make_pair(i, j)] = true;
        dis[make_pair(i, j)] = 0;
      }
    }
  }
  for (std::map<std::pair<int, int>, char>::iterator i = maze.begin();
       i != maze.end(); ++i) {
    if (i->second == Start) itBegin = i;
    if (i->second == End) itEnd = i;
  }
  std::queue<std::pair<int, int> > que;
  que.push(itBegin->first);
  visit[itBegin->first] = false;
  bool judge = false;
  int step = -1;
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
      if (maze[right] == End) {
        judge = true;
        break;
      }
      que.push(right);
      visit[right] = false;
    }
    if (visit[down]) {
      dis[down] = dis[vs] + 1;
      if (maze[down] == End) {
        judge = true;
        break;
      }
      que.push(down);
      visit[down] = false;
    }
    if (visit[left]) {
      dis[left] = dis[vs] + 1;
      if (maze[left] == End) {
        judge = true;
        break;
      }
      que.push(left);
      visit[left] = false;
    }
    if (visit[up]) {
      dis[up] = dis[vs] + 1;
      if (maze[up] == End) {
        judge = true;
        break;
      }
      que.push(up);
      visit[up] = false;
    }
  }
  if (judge) step = dis[itEnd->first];
  std::cout << step << std::endl;
  return 0;
}
