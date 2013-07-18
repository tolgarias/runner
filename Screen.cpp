//
//  Screen.cpp
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/17/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#include "Screen.h"


Screen::Screen(){
    
}
Screen::~Screen(){
    
}

Screen::Screen(int pointCount){
    this->m_pointCount = pointCount;
   // cocos2d::CCPoint *resizePoints[][] = new cocos2d::CCPoint*[pointCount][2];
    //points = resizePoints;
    //delete [] resizePoints;
    pointCounter=0;
}