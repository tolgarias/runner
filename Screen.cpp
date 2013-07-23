//
//  Screen.cpp
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/17/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#include "Screen.h"


Screen::Screen(){
    pointCounter = 0;
}
Screen::~Screen(){
    
}

Screen::Screen(int pointCount){
    pointCounter=0;
}

void Screen::addPoints(float x1, float y1, float x2, float y2,bool floor){
    LinePoints p;
    p.m_startPoint = ccp(x1, y1);
    p.m_endPoint = ccp(x2,y2);
    p.m_isFloor = floor;
    points[pointCounter] = p;
    pointCounter++;
}
std::list<Line*> Screen::makeLines(int width,int height,int xBuffer, int yBuffer,int screenCount){
    std::list<Line*> lines;
    for (int i=0; i<pointCounter; i++) {
        LinePoints p = points[i];
        int addYBuffer = yBuffer;
        if(p.m_isFloor){
            addYBuffer = 0;
        }
        float realX1 = screenCount*width + (width*p.m_startPoint.x)/8;
        float realY1 = addYBuffer + (height*p.m_startPoint.y)/6;
        float realX2 = screenCount*width + (width*p.m_endPoint.x)/8;
        float realY2 = addYBuffer + (height*p.m_endPoint.y)/6;

        Line *l = new Line(ccp(realX1, realY1),ccp(realX2, realY2));
        lines.push_front(l);
        
        //std::cout << "screen count:"<< screenCount<< " start x:"<<realX1<<"\n\n";
    }
    return lines;
}