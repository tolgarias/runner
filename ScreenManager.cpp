//
//  ScreenManager.cpp
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/17/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#include "ScreenManager.h"

const int SCREEN_COUNT=5;
ScreenManager::ScreenManager(){
    
    //points = new cocos2d::CCDictionary();
    //points->setObject(nullptr, "1");
    
}

ScreenManager::~ScreenManager(){
    
    //points = new cocos2d::CCDictionary();
    //points->setObject(nullptr, "1");
    
}

void ScreenManager::load(int width, int height){
    screenWidth = width;
    screenHeight = height;
    
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("screens.xml");
    std::cout << "Load result:" << result.description() << "\n\n";
    
}
