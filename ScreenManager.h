//
//  ScreenManager.h
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/17/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#include <iostream>
#include "pugixml.hpp"
#include "Screen.h"

#ifndef __SpriteDragger__ScreenManager__
#define __SpriteDragger__ScreenManager__
#include "cocos2d.h"
#include "Line.h"
class ScreenManager {
private:
    int screenWidth,screenHeight,screenCounter;
    //cocos2d::CCPoint *points[1][1];
    //cocos2d::CCDictionary *points;
    static ScreenManager *m_sharedInstance;
    Screen *m_screens[10];
    int addedScreenCount;
public:
    
    ScreenManager();
    ~ScreenManager();
    void load(int width,int height);
    //std::list<Line*> getLineList(int screenNumber,int xBuffer,int yBuffer);
    static ScreenManager&  getInstance() {
        static ScreenManager instance;
        return instance;
    };
    std::list<Line*> addScreen(int screenNumber,int xBuffer,int yBuffer);
    int getScreenCount();
};


#endif /* defined(__SpriteDragger__ScreenManager__) */