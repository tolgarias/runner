//
//  ScreenManager.cpp
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/17/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#include "ScreenManager.h"
#include "CCFileUtils.h"

const int SCREEN_COUNT=5;
ScreenManager::ScreenManager(){
    
    //points = new cocos2d::CCDictionary();
    //points->setObject(nullptr, "1");
    screenCounter=0;
    addedScreenCount = 0;
}

ScreenManager::~ScreenManager(){
    
    //points = new cocos2d::CCDictionary();
    //points->setObject(nullptr, "1");
    
}

void ScreenManager::load(int width, int height){
    screenWidth = width;
    screenHeight = height;
    pugi::xml_document doc;
    
    
    std::string fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("screens.xml");
    unsigned char* pBuffer = NULL;
    unsigned long bufferSize = 0;
    pBuffer = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "r", &bufferSize);
    pugi::xml_parse_result result = doc.load_buffer(pBuffer,bufferSize);
    std::cout << "Load result:" << result.description()<<"\n\n";
    
    
    pugi::xml_node screens = doc.child("Screens");
    //for (pugi::xml_node screen = screens.child("Screen"); screen; screen = screens.next_sibling("Screen"))
    for (pugi::xml_node screen: screens.children())
    {
        pugi::xml_node points = screen.child("points");
        Screen *s = new Screen();
        for (pugi::xml_node point: points.children())
        {
<<<<<<< HEAD
            bool isFloor = point.attribute("floor")==nullptr?false:true;
=======
>>>>>>> 20e450736b25c204f2aad87a1670937712016dc4
            float x1 = atof(point.child("startx").child_value());
            float y1 = atof(point.child("starty").child_value());
            float x2 = atof(point.child("endx").child_value());
            float y2 = atof(point.child("endy").child_value());
<<<<<<< HEAD
            s->addPoints(x1, y1, x2, y2,isFloor);
=======
            s->addPoints(x1, y1, x2, y2);
>>>>>>> 20e450736b25c204f2aad87a1670937712016dc4
        }
        m_screens[screenCounter] = s;
        screenCounter++;
    }
    
}

std::list<Line*> ScreenManager::addScreen(int screenNumber, int xBuffer, int yBuffer) {
    Screen* s = m_screens[screenNumber];
    std::list<Line*>lines =  s->makeLines(screenWidth, screenHeight, xBuffer, yBuffer,addedScreenCount);
    addedScreenCount++;
    return lines;
}
int ScreenManager::getScreenCount(){
    return  screenCounter;
}




