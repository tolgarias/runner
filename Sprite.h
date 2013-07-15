//
//  Sprite.h
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/12/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#ifndef __SpriteDragger__Sprite__
#define __SpriteDragger__Sprite__

#include <iostream>

#endif /* defined(__SpriteDragger__Sprite__) */

class Sprite {
private:
    int x,y,size,width,height;
    
public:
    Sprite();
    ~Sprite();
    Sprite(int x,int y,int width,int height);
    void setX(int value);
    int getX();
    void setY(int value);
    int getY();
    void setWidth(int value);
    int getWidth();
    void setHeight(int value);
    int getHeight();
    
};
