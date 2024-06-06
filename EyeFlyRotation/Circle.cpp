#include "Circle.h"
#include <cmath>

Circle::Circle(float radius, int points, const sf::Vector2f& center)
    : radius(radius), points(points), center(center), rotationAngle(0.0f) {
    updateVertices();
}

void Circle::setCenter(const sf::Vector2f& newCenter) {
    center = newCenter;
    updateVertices();
}

void Circle::setRotation(float angleOffset) {
    rotationAngle = angleOffset;
    updateVertices();
}

const sf::VertexArray& Circle::getVertices() const {
    return vertices;
}

void Circle::updateVertices() {
    vertices = sf::VertexArray(sf::TriangleFan, points + 2);
    vertices[0].position = center;

    for (int i = 0; i <= points; ++i) {
        float angle = i * 10 * (3.14159265359f / 180.0f) + rotationAngle;
        float x = center.x + radius * std::cos(angle);
        float y = center.y + radius * std::sin(angle);

        vertices[i + 1].position = sf::Vector2f(x, y);
        vertices[i + 1].color = sf::Color::Magenta;
    }
}
