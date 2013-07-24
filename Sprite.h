//
//  Sprite.h
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/12/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#ifndef __SpriteDragger__Sprite__
#define __SpriteDragger__Sprite__

#include <iostream>
#include "Line.h"

enum spriteStatus {
    RUNNING,
    FALLING,
    JUMPING
};

class Sprite {
private:
    int x,size,width,height,maxJump,jumpSpeed,speed,jumpLength;
    spriteStatus status;
    bool collided;
    float rotation;
    float y;
    
public:
    Sprite();
    ~Sprite();
    Sprite(int x,float y,int width,int height);
    void setX(int value);
    int getX();
    void setY(float value);
    float getY();
    void setWidth(int value);
    int getWidth();
    void setHeight(int value);
    int getHeight();
    
    //void setStatus(int value);
    //int getStatus();
    
    void setStatus(spriteStatus value);
    spriteStatus getStatus();

    void setCollided(bool value);
    bool getCollided();
    
    void setRotation(float value);
    float getRotation();
    
    int getJumpSpeed();
    
    void setJumpLength(int value);
    int  getJumpLength();
    
    int getMaxJump();
    
    Line* m_line;
    bool checkCollission();
    void setSpeed(int value);
};



#endif /* defined(__SpriteDragger__Sprite__) */

