#include "player.h"
#include <iostream>

Player::Player(int posx, int posy, int speed_) :
    speed(speed_),
    charW(40),
    charH(40)
{
    this->posx = posx;
    this->posy = posy;
    this->facingDirection = Direction::RIGHT;

    lives = 3;
    moving = false;

    forward.load("://Images/Characters/gator_forward.png");
    reverse.load("://Images/Characters/gator_reverse.png");
    up.load("://Images/Characters/gator_forward_up.png");
    down.load("://Images/Characters/gator_forward_down.png");

}

QRectF Player::boundingRect() const
{
    return QRect(0,0,charW,charH);
    std::cout << "0" ;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(facingDirection)
    {
    case LEFT:
        painter->drawPixmap(posx,posy,charW,charW,reverse);
        break;
    case RIGHT:
        painter->drawPixmap(posx,posy,charW,charW,forward);
        break;
    case UP:
        painter->drawPixmap(posx,posy,charW,charW,up);
        break;
    case DOWN:
        painter->drawPixmap(posx,posy,charW,charW,down);
        break;
    case NONE:
        painter->drawPixmap(posx,posy,charW,charW,forward);
        break;
    }
}

int Player::getSpeed() const
{
    return speed;
}

int Player::getPosx() const
{
    return posx;
}

void Player::setPosx(int x)
{
    if (x >= 0 && x <= 520)
    {
        posx = x;
    }
}

int Player::getPosy() const
{
    return posy;
}

void Player::setPosy(int y)
{
    if (y >= 10 && y <= 570)
    {
        posy = y;
    }
}

bool Player::isMoving() const
{
    return moving;
}

void Player::setMoving(bool value)
{
    moving = value;
}

int Player::getLives() const
{
    return lives;
}

void Player::setLives(int lives)
{
    if (lives >= 0 || lives <= 3)
    {
        this->lives = lives;
    }
}

void Player::resetOrientation()
{
    facingDirection = Direction::RIGHT;
    direction = Direction::RIGHT;
    nextDirection = Direction::NONE;
}

void Player::setDirection(Direction dir)
{
    facingDirection = dir;
}

void Player::setNextDirection(Direction dir)
{
    nextDirection = dir;
}
