#include "../../../include/Entities/Ships/RocketShip.h"
#include "../../../include/Globals.h"

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

	isBounced = false;
	bounceAccumulator = 5;
	bounceFactor = 0;

	radius = 40;
	attachShape();

	if (!rocketShipTexture.loadFromFile("resources/SHIP_SPEED.png")) {
		printf("Could not load spaceship");
	}
	//rocketShipTexture.loadFromImage(rocketShipImage);
	//rocketShipTexture.setSmooth(true);
	rocketShipObject.setTexture(rocketShipTexture);
	rocketShipObject.setScale(0.1f, 0.1f);
    rocketShipObject.setOrigin(rocketShipObject.getGlobalBounds().width/2, rocketShipObject.getGlobalBounds().height/2);
    
}

void RocketShip::update(float deltams) {
	
    //shipShape -> m_p.Set(pos.x,pos.y);
    bounceAccumulator += deltams;

    if (bounceAccumulator < 500 ) {
    	isBounced = false;
    }

    if(!isBounced){

    	bounceAccumulator = 0;

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
	}

	pos += vel * deltams;

	rocketShipObject.setPosition(pos);
}


void RocketShip::attachShape(){
    
    shipShape= new b2CircleShape();
    shipShape -> m_p.Set(0.0f, 0.0f);
    shipShape -> m_radius = 50.0f;
      
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

void bounce(sf::Vector2f collision_point, float bounce_factor){

	isBounced = true;

	float x_check = pos.x - collision_point.x;
	float y_check = pos.y - collision_point.y;

	vel.x = bounce_factor / x_check;
	vel.y = bounce_factor / y_check;

	// //if the collision happened to the right
	// if(x_check < 0){

	// 	//if the ship is travelling to the left
	// 	if (vel.x < 0){

	// 	}
	// 	else {

	// 	}
	// }
	// else {

	// }

	// // if the collision happened below the ship
	// if(y_check < 0){

	// 	//if the ship is travelling up
	// 	if (vel.y < 0){

	// 	}
	// 	else {

	// 	}
	// }
	// else {

	// }

}


b2CircleShape* RocketShip::getShape(){
    
    return shipShape;
    
}



