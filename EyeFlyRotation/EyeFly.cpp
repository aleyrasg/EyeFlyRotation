#include "EyeFly.h"
EyeFly::EyeFly(float radius, int points, const sf::Vector2f& center)
    : circle(radius, points, center), lines(radius, points, center), center(center), rotationAngle(0.0f) {}

void EyeFly::move(const sf::Vector2f& offset) {
    center += offset;
    circle.setCenter(center);
    lines.setCenter(center);
}

void EyeFly::rotate(float angleOffset) {
    rotationAngle += angleOffset;
    circle.setRotation(rotationAngle);
    lines.setRotation(rotationAngle);
}

void EyeFly::draw(sf::RenderWindow& window) {
    window.draw(circle.getVertices());
    window.draw(lines.getVertices());
}
