#ifndef BALL_H
#define BALL_H

class Ball
{
public:
    Ball();
protected:
    unsigned int radius_cm = 10;
    int x = 0, y = 0, z = 0;
public:
    virtual void moveTheBall();
    virtual float volumeOfBall();
};

class Football: public Ball
{
public:
    Football();
public:
    void moveTheBall() override;
};
#endif // BALL_H
