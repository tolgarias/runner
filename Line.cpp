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
    float div1 = m_secondPoint.y-m_firstPoint.y;
    float div2 = m_secondPoint.x-m_firstPoint.x;
    float tangant = div1/div2;
    incline = atan(tangant);
    incline = CC_RADIANS_TO_DEGREES(incline);
    if(direction==1){
        incline *=-1;
    }
    //std::cout << "\n";
    //std::cout << incline;
    //std::cout << "\n";
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
