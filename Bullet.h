#pragma once
#include <SFML/Graphics.hpp>
#include "../../States/PlayState.h"

class Bullet {
public:
    Bullet() {}
    ~Bullet() {}
    
    virtual void update(float deltams) = 0;

	sf::Vector2f pos;
	sf::Vector2f vel;

	float radius;
    bool isAlive;
    void setReference(PlayState *r) { ref = r; }
    PlayState *ref;
};