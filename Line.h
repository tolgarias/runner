//
//  Line.h
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/12/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#ifndef __SpriteDragger__Line__
#define __SpriteDragger__Line__

#include <iostream>
#include "cocos2d.h"




//#include "Sprite.h"

class Line {
    private:
    float x,y,a,c,divider,incline;
    cocos2d::CCPoint m_firstPoint,m_secondPoint;
    int direction;
    public:
    Line();
    Line(cocos2d::CCPoint p1,cocos2d::CCPoint p2);
    ~Line();
    
    void setX(float value);
    float getX();
    void setY(float value);
    float getY();
    void setA(float value);
    float getA();
    void setC(float value);
    float getC();
    void setDividier(float value);
    float getDivider();
    float getIncline();
    void calculateLine();
    float findY(float x);
    cocos2d::CCPoint getFirstPoint();
    cocos2d::CCPoint getSecondPoint();
    float getMinY();
    float getMaxY();
    bool checkCollission(int x,float y,int width,int height,float speed);
    int getDirection();
};

#endif /* defined(__SpriteDragger__Line__) */