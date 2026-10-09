#include "ball.h"
#include <cmath>

Ball::Ball()
{

}

void Ball::moveTheBall()
{
    x++;
    z++;
}

float Ball::volumeOfBall()
{
    return (3/4)*(3.14)*(pow(radius_cm,3));
}

Football::Football()
{
    radius_cm = 45;
}

void Football::moveTheBall()
{
    x++;
    z++;
    y++;
}
