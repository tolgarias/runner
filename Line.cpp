//
//  Line.cpp
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/12/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#include "Line.h"


Line::Line() {
    
}
Line::Line(cocos2d::CCPoint p1,cocos2d::CCPoint p2) {
    m_firstPoint = p1;
    m_secondPoint = p2;
    if(p2.y>p1.y) direction = 1;
    else direction = 2;
    calculateLine();
    
}
Line::~Line() {
    
}

void Line::calculateLine(){
    a = this->m_secondPoint.y-this->m_firstPoint.y;
    divider = this->m_secondPoint.x - this->m_firstPoint.x;
    //c = a*this->m_secondPoint.x+divider*m_secondPoint.y;
    float div1 = abs(m_secondPoint.y-m_firstPoint.y);
    float div2 = m_secondPoint.x-m_firstPoint.x;
    float tangant = div1/div2;
    incline = atan(tangant);
    incline = CC_RADIANS_TO_DEGREES(incline);
    if(direction==1){
        incline *=-1;
    }
 
}
float Line::findY(float x) {
    float div1 = a*x - a*m_secondPoint.x;
    return (div1+divider*m_secondPoint.y)/divider;
}

float Line::getIncline() {
    return incline;
}

cocos2d::CCPoint Line::getFirstPoint() {
    return m_firstPoint;
}

cocos2d::CCPoint Line::getSecondPoint() {
    return m_secondPoint;
}

float Line::getMaxY() {
    if(direction==1){
        return m_secondPoint.y;
    }
    else {
        return m_firstPoint.y;
    }
}

float Line::getMinY() {
    if(direction==2){
        return m_secondPoint.y;
    }
    else {
        return m_firstPoint.y;
    }
}

bool Line::checkCollission(int x, float y,int width,int height,float speed){
    bool result = false;
    
    if (x+width>=m_firstPoint.x && x+width<=m_secondPoint.x) {
        float lineY = findY(x+width);
        if (y-height<=lineY && ((y-height)+5)>=lineY) {
                    result = true;
        }
    }
    return result;
}
int Line::getDirection() {
    return direction;
}
