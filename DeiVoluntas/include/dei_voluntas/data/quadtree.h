#ifndef QUADTREE_H
#define QUADTREE_H
#include <vector>
#include <memory>

namespace DeiVoluntas::Data {
    template <typename T>
    struct QuadtreeNode {
        float x, y;
        T value;
    };

    template <typename T>
    class Quadtree {
    public:
        float x, y, width, height;
        int capacity;
        bool divided = false;
        std::vector<QuadtreeNode<T>> points;
        std::unique_ptr<Quadtree<T>> northeast, northwest, southeast, southwest;

        Quadtree(float x, float y, float width, float height, int capacity)
            : x(x), y(y), width(width), height(height), capacity(capacity) {}

        bool Insert(QuadtreeNode<T> point) {
            if (!Contains(point.x, point.y)) {
                return false;
            }

            if (points.size() < capacity) {
                points.push_back(point);
                return true;
            }

            if (!divided) {
                Subdivide();
            }

            return (northeast->Insert(point) || northwest->Insert(point) ||
                    southeast->Insert(point) || southwest->Insert(point));
        }

        void Query(float qx, float qy, float radius, std::vector<QuadtreeNode<T>>& found) {
            if (!Intersects(qx, qy, radius)) {
                return;
            }

            for (const auto& point : points) {
                float dx = qx - point.x;
                float dy = qy - point.y;
                if (dx * dx + dy * dy <= radius * radius) {
                    found.push_back(point);
                }
            }

            if (divided) {
                northeast->Query(qx, qy, radius, found);
                northwest->Query(qx, qy, radius, found);
                southeast->Query(qx, qy, radius, found);
                southwest->Query(qx, qy, radius, found);
            }
        }

        void Reset() {
            points.clear();
            if (divided) {
                northeast = nullptr;
                northwest = nullptr;
                southeast = nullptr;
                southwest = nullptr;
            }
        }

    private:
        void Subdivide() {
            float hw = width / 2.0f;
            float hh = height / 2.0f;
            northeast = std::make_unique<Quadtree<T>>(x + hw, y + hh, hw, hh, capacity);
            northwest = std::make_unique<Quadtree<T>>(x - hw, y + hh, hw, hh, capacity);
            southeast = std::make_unique<Quadtree<T>>(x + hw, y - hh, hw, hh, capacity);
            southwest = std::make_unique<Quadtree<T>>(x - hw, y - hh, hw, hh, capacity);
            divided = true;
        }

        bool Contains(float px, float py) {
            return (px >= x - width && px < x + width && py >= y - height && py < y + height);
        }

        bool Intersects(float qx, float qy, float radius) {
            float dx = std::max(std::abs(qx - x) - width, 0.0f);
            float dy = std::max(std::abs(qy - y) - height, 0.0f);
            return (dx * dx + dy * dy <= radius * radius);
        }
    };
}
#endif