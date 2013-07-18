//
//  Screen.h
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/17/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#ifndef __SpriteDragger__Screen__
#define __SpriteDragger__Screen__

#include <iostream>

#endif /* defined(__SpriteDragger__Screen__) */
#include "cocos2d.h"

class Screen {
private:
    int m_pointCount;
    int pointCounter;
    cocos2d::CCPoint *points[][];
public:
    Screen();
    ~Screen();
    Screen(int pointCount);
    void addPoints(float x1,float y1,float x2,float y2);
};