#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef struct Node {
  int x, y, d;
  Node(int _x = 0, int _y = 0, int _d = 0) : x(_x), y(_y), d(_d) {}
  bool operator==(const Node &oth) { return (x == oth.x && y == oth.y); }
} Node;

bool map[8][8];

void findWay(Node &vs, const Node &vd, int &l) {
  queue<Node> q;
  Node v1, v2;

  int dir[8][2] = {{1, 2},  {-1, 2},  {2, 1},  {-2, 1},
                   {1, -2}, {-1, -2}, {2, -1}, {-2, -1}};
  vs.d = 0;
  q.push(vs);
  map[vs.x][vs.y] = true;

  auto isValid = [](const Node &a) {
    return (map[a.x][a.y] == false && a.x >= 0 && a.y >= 0 && a.x < 8 &&
            a.y < 8);
  };

  while (!q.empty()) {
    v1 = q.front();
    for (int i = 0; i < 8; ++i) {
      v2 = Node(v1.x + dir[i][0], v1.y + dir[i][1], v1.d + 1);
      if (v2 == vd) {
        l = v2.d;
        return;
      }

      if (isValid(v2)) {
        q.push(v2);
        map[v2.x][v2.y] = true;
      }
    }
    q.pop();
  }
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        map[i][j] = false;
      }
    }
    string begin, end;
    cin >> begin >> end;
    Node vs(begin[1] - '1', begin[0] - 'a', 0);
    Node vd(end[1] - '1', end[0] - 'a', 0);
    int l = 0;

    if (vs == vd) {
      cout << l << endl;
      continue;
    }

    findWay(vs, vd, l);
    cout << l << endl;
  }
  return 0;
}

