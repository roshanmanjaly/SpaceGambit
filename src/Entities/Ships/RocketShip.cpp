#include "./Entities/Ships/RocketShip.h"
#include "./Globals.h"

RocketShip::RocketShip(sf::Vector2f p) {
	vel = sf::Vector2f(0, 0);
    pos = p;

	ACCEL = 50;
	DECEL = .92;
	maxSpeed = MAXSPEED;

	moveUp = false;
	moveDown = false;
	moveLeft = false;
	moveRight = false;

	radius = 40;
	attachShape();

	if (!rocketShipTexture.loadFromFile("resources/SHIP_SPEED.png")) {
		printf("Could not load spaceship");
	}
	//rocketShipTexture.loadFromImage(rocketShipImage);
	//rocketShipTexture.setSmooth(true);
	rocketShipObject.setTexture(rocketShipTexture,true);
	rocketShipObject.setScale(0.1f, 0.1f);
    rocketShipObject.setOrigin(rocketShipObject.getGlobalBounds().width/2, rocketShipObject.getGlobalBounds().height/2);
}

void RocketShip::update(float deltams) {
	if (moveUp || moveDown) {
		if (moveUp)
			vel.y -= ACCEL;
		if (moveDown)
			vel.y += ACCEL;
	}
	else
		vel.y *= DECEL;

	if (moveLeft || moveRight) {
		if (moveLeft)
			vel.x -= ACCEL;
		if (moveRight)
			vel.x += ACCEL;
	}
	else
		vel.x *= DECEL;

	if (vel.x <= -maxSpeed)	vel.x = -maxSpeed;
	if (vel.x >= maxSpeed)	vel.x = maxSpeed;
	if (vel.y <= -maxSpeed)	vel.y = -maxSpeed;
	if (vel.y >= maxSpeed)	vel.y = maxSpeed;

	pos += vel * deltams;

	rocketShipObject.setPosition(pos);
}

void RocketShip::attachShape(){
    
    shipShape= new b2CircleShape();
    shipShape -> m_p.Set(0.0f, 0.0f);
    shipShape -> m_radius = 200.0f;
      
    // create new triangle Body
    b2Vec2 vertices1[3];//PolygonA
    vertices1[0].Set(300,250);
    vertices1[1].Set(350,350);
    vertices1[2].Set(250,350);
    int count1= 3;
    //shipShape= new b2PolygonShape();
    //shipShape -> Set(vertices1, count1);
    //shipShape -> m_radius = 50;
    //shipShape->Set(vertices1,count1);
    //shipShape->m_radius = 2; 
    //shipFixture.shape = shipShape;
    
    
    
    
}


b2CircleShape* RocketShip::getShape(){
    
    return shipShape;
    
}


