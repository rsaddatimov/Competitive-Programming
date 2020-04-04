/* Rafail Saddatimov
   Используем метод разделяй и властвуй
   Сложность по времени - O(n * log(n))
   Дополнительной памяти - O(n)
*/
#include <algorithm>
#include <vector>
#include <stdio.h>

inline long long square(int x) {
    return 1LL * x * x;
}

class Point {
public:
    int x, y;

    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    static bool comparatorX(const Point &f, const Point &s) {
        if (f.x != s.x) return f.x < s.x;
        return f.y < s.y;
    }
    static bool comparatorY(const Point &f, const Point &s) {
        return f.y < s.y;
    }
};

void update(const Point &f, const Point &s, long long &answer) {
    long long dist = square(f.x - s.x) + square(f.y - s.y);
    if (dist < answer) {
        answer = dist;
    }
}

void closest(std::vector<Point> &pt, std::vector<Point> &tmp, int left, int right, long long &answer) {
    if (right - left <= 4) {
        for (int i = left; i <= right; ++i) {
            for (int j = i + 1; j <= right; ++j) {
                update(pt[i], pt[j], answer);
            }
        }
        std::sort(pt.begin() + left, pt.begin() + right + 1, Point::comparatorY);
        return;
    }
    int middle = (left + right) / 2;
    int middleX = pt[middle].x;
    int id = 0;
    closest(pt, tmp, left, middle, answer);
    closest(pt, tmp, middle + 1, right, answer);
    std::merge(pt.begin() + left,
               pt.begin() + middle + 1,
               pt.begin() + middle + 1,
               pt.begin() + right + 1,
               tmp.begin(), Point::comparatorY);
    std::copy(tmp.begin(), tmp.begin() + right - left + 1, pt.begin() + left);
    for (int i = left; i <= right; ++i) {
        if (square(pt[i].x - middleX) >= answer) {
            continue;
        }
        for (int j = id - 1; j >= 0; --j) {
            if (square(pt[i].y - tmp[j].y) >= answer) {
                break;
            }
            update(pt[i], tmp[j], answer);
        }
        tmp[id++] = pt[i];
    }
}
int main() {
    int n;
    scanf("%d", &n);
    std::vector<Point> pt, tmp(n);
    pt.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        pt.emplace_back(x, y);
    }
    std::sort(pt.begin(), pt.end(), Point::comparatorX);
    long long answer = 1e17;
    closest(pt, tmp, 0, n - 1, answer);
    printf("%lld\n", answer);
}
