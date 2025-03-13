#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

// 2D ��ṹ
struct Point {
    float x, y;
    Point(float x = 0, float y = 0) : x(x), y(y) {}
};

// 2D �����ṹ
struct Vector2 {
    float x, y;
    Vector2(float x = 0, float y = 0) : x(x), y(y) {}
};

// �������������ĵ��
float Dot(const Vector2& a, const Vector2& b) {
    return a.x * b.x + a.y * b.y;
}

// ���������ķ���������ֱ��ԭ������������
Vector2 Normal(const Vector2& v) {
    return Vector2(-v.y, v.x);
}

// ����������ĳ�����ϵ�ͶӰ��Χ
void ProjectPolygon(const Vector2& axis, const std::vector<Point>& polygon, float& min, float& max) {
    min = std::numeric_limits<float>::max();
    max = std::numeric_limits<float>::lowest();

    for (const auto& point : polygon) {
        float projection = Dot(Vector2(point.x, point.y), axis);
        if (projection < min) min = projection;
        if (projection > max) max = projection;
    }
}

// ���������Χ�Ƿ��ص�
bool Overlap(float min1, float max1, float min2, float max2) {
    return max1 >= min2 && max2 >= min1;
}

// �����ᶨ��������͹������Ƿ��ཻ
bool SAT(const std::vector<Point>& polygon1, const std::vector<Point>& polygon2) {
    // ��ȡ�����1�����б�
    std::vector<Vector2> axes;
    for (size_t i = 0; i < polygon1.size(); i++) {
        Point p1 = polygon1[i];
        Point p2 = polygon1[(i + 1) % polygon1.size()];
        Vector2 edge = Vector2(p2.x - p1.x, p2.y - p1.y);
        axes.push_back(Normal(edge));
    }

    // ��ȡ�����2�����б�
    for (size_t i = 0; i < polygon2.size(); i++) {
        Point p1 = polygon2[i];
        Point p2 = polygon2[(i + 1) % polygon2.size()];
        Vector2 edge = Vector2(p2.x - p1.x, p2.y - p1.y);
        axes.push_back(Normal(edge));
    }

    // ��ÿ�������ͶӰ���
    for (const auto& axis : axes) {
        float min1, max1, min2, max2;
        ProjectPolygon(axis, polygon1, min1, max1);
        ProjectPolygon(axis, polygon2, min2, max2);

        if (!Overlap(min1, max1, min2, max2)) {
            return false; // ���ڷ����ᣬ���ཻ
        }
    }

    return true; // �����ᶼ�ص����ཻ
}

int main() {
    // ��������͹�����
    std::vector<Point> polygon1 = {
        Point(0, 0),
        Point(4, 0),
        Point(4, 4),
        Point(0, 4)
    };

    std::vector<Point> polygon2 = {
        Point(2, 2),
        Point(6, 2),
        Point(6, 6),
        Point(2, 6)
    };

    // ����Ƿ��ཻ
    if (SAT(polygon1, polygon2)) {
        std::cout << "Polygons intersect!" << std::endl;
    } else {
        std::cout << "Polygons do not intersect!" << std::endl;
    }

    return 0;
}