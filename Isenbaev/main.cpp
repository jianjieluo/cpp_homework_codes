#include <iostream>
#include <map>
#include <string>
#include <queue>
std::map<std::string, int>::iterator iter;

int main(void) {
    int n;
    std::cin >> n;
    int a[100][3];
    int id = 0;
    std::map<std::string, int> id_map;
    std::map<int, int> dist;
    std::map<int, bool> visit;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::string temp;
            std::cin >> temp;
            if (id_map.find(temp) == id_map.end()) {
                id_map[temp] = id++;
            }
            a[i][j] = id_map[temp];
        }
    }  // id now is the current people number
    for (int i = 0; i < id; ++i) {
        dist[i] = 0;
    }
    bool flag = true;
    if (id_map.find("Isenbaev") == id_map.end()) flag = false;
    if (!flag) {
        for (iter = id_map.begin(); iter != id_map.end(); ++iter) {
            std::cout << iter->first << " undefined" << std::endl;
        }
        return 0;
    }
    int boss_id = id_map["Isenbaev"];
    std::queue<int> q;
    for (int i = 0; i < id; ++i) {
        visit[i] = true;
    }
    q.push(boss_id);
    visit[boss_id] = false;
    while (!q.empty()) {
        int person = q.front();
        q.pop();
        for (int i = 0; i < n; ++i) { // 这个是循环了小组情况一轮
            if (a[i][0] == person || a[i][1] == person || a[i][2] == person) {
                for (int j = 0; j < 3; ++j) {
                    if (visit[a[i][j]]) {
                        dist[a[i][j]] = dist[person] + 1;
                        visit[a[i][j]] = false;
                        q.push(a[i][j]);
                    }
                }
            }
        }
    }
    for (iter = id_map.begin(); iter != id_map.end(); ++iter) {
        if (iter->second == boss_id) {
            std::cout << iter->first << " 0" << std::endl;
            continue;
        }
        if (dist[iter->second] == 0) {
            std::cout << iter->first << " undefined" << std::endl;
        } else {
            std::cout << iter->first << " " << dist[iter->second] << std::endl;
        }
    }  // output result
    return 0;
}
