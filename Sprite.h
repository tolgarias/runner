//
//  Sprite.h
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/12/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//
#include "Line.h"

#ifndef __SpriteDragger__Sprite__
#define __SpriteDragger__Sprite__

#include <iostream>
enum spriteStatus {
    RUNNING,
    JUMPING,
    FALLING
};
class Sprite {
private:
    int x,y,size,width,height,status,maxJump,jumpSpeed,speed,jumpLength;
    bool collided;
    float rotation;
    
public:
    Sprite();
    ~Sprite();
    Sprite(int x,int y,int width,int height);
    void setX(int value);
    int getX();
    void setY(int value);
    int getY();
    void setWidth(int value);
    int getWidth();
    void setHeight(int value);
    int getHeight();
    
    void setStatus(int value);
    int getStatus();

    void setCollided(bool value);
    bool getCollided();
    
    void setRotation(float value);
    float getRotation();
    
    int getJumpSpeed();
    
    void setJumpLength(int value);
    int  getJumpLength();
    
    int getMaxJump();
    spriteStatus status1;
    Line* m_line;
    //bool checkCollission
};
#endif /* defined(__SpriteDragger__Sprite__) */

