//
//  Screen.h
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/17/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//
#include "cocos2d.h"
#include "Line.h"
#ifndef __SpriteDragger__Screen__
#define __SpriteDragger__Screen__

#include <iostream>




class LinePoints {
public:
    cocos2d::CCPoint m_startPoint;
    cocos2d::CCPoint m_endPoint;
<<<<<<< HEAD
    bool m_isFloor;
=======
>>>>>>> 20e450736b25c204f2aad87a1670937712016dc4
};

class Screen {
private:
    int m_pointCount;
    int pointCounter;
    LinePoints points[7];
public:
    Screen();
    ~Screen();
    Screen(int pointCount);
<<<<<<< HEAD
    void addPoints(float x1,float y1,float x2,float y2,bool floor);
=======
    void addPoints(float x1,float y1,float x2,float y2);
>>>>>>> 20e450736b25c204f2aad87a1670937712016dc4
    std::list<Line*> makeLines(int width,int height,int xBuffer,int yBuffer,int screenCount);
};

#endif /* defined(__SpriteDragger__Screen__) */

