//
//  ScreenManager.h
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/17/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#ifndef __SpriteDragger__ScreenManager__
#define __SpriteDragger__ScreenManager__

#include <iostream>
#include "pugixml.hpp"

#endif /* defined(__SpriteDragger__ScreenManager__) */

#include "cocos2d.h"
//#include "Line.h"
class ScreenManager {
private:
    int screenWidth,screenHeight;
    cocos2d::CCPoint *points[1][1];
    //cocos2d::CCDictionary *points;
    static ScreenManager *m_sharedInstance;
    
public:
    
    ScreenManager();
    ~ScreenManager();
    void load(int width,int height);
    //std::list<Line*> getLineList(int screenNumber,int xBuffer,int yBuffer);
    static ScreenManager&  getInstance() {
        static ScreenManager instance;
        return instance;
    };
};
