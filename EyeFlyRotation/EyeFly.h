#ifndef EYEFLY_H
#define EYEFLY_H

#include "Circle.h"
#include "Lines.h"
#include <SFML/Graphics.hpp>

class EyeFly {
public:
    EyeFly(float radius, int points, const sf::Vector2f& center);
    void move(const sf::Vector2f& offset);
    void rotate(float angleOffset);
    void draw(sf::RenderWindow& window);

private:
    sf::Vector2f center;
    float rotationAngle;
    Circle circle;
    Lines lines;
};

#endif // EYEFLY_H

