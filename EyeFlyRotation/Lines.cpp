#include "Lines.h"
#include <cmath>

Lines::Lines(float radius, int points, const sf::Vector2f& center)
    : radius(radius), points(points), center(center), rotationAngle(0.0f) {
    updateVertices();
}

void Lines::setCenter(const sf::Vector2f& newCenter) {
    center = newCenter;
    updateVertices();
}

void Lines::setRotation(float angleOffset) {
    rotationAngle = angleOffset;
    updateVertices();
}

const sf::VertexArray& Lines::getVertices() const {
    return vertices;
}

void Lines::updateVertices() {
    vertices = sf::VertexArray(sf::Lines, 2 * (points / 2));

    for (int i = 1; i <= points / 2; ++i) {
        float angle1 = i * 10 * (3.14159265359f / 180.0f) + rotationAngle;
        float x1 = center.x + radius * std::cos(angle1);
        float y1 = center.y + radius * std::sin(angle1);

        float angle2 = ((i + 13) % 36) * 10 * (3.14159265359f / 180.0f) + rotationAngle;
        float x2 = center.x + radius * std::cos(angle2);
        float y2 = center.y + radius * std::sin(angle2);

        vertices[2 * (i - 1)].position = sf::Vector2f(x1, y1);
        vertices[2 * (i - 1)].color = sf::Color::Cyan;

        vertices[2 * (i - 1) + 1].position = sf::Vector2f(x2, y2);
        vertices[2 * (i - 1) + 1].color = sf::Color::Cyan;
    }
}
