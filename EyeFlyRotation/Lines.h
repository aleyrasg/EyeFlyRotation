#ifndef LINES_H
#define LINES_H

#include <SFML/Graphics.hpp>

class Lines {
public:
    Lines(float radius, int points, const sf::Vector2f& center);
    void setCenter(const sf::Vector2f& newCenter);
    void setRotation(float angleOffset);
    const sf::VertexArray& getVertices() const;

private:
    float radius;
    int points;
    sf::Vector2f center;
    float rotationAngle;
    sf::VertexArray vertices;

    void updateVertices();
};

#endif // LINES_H


