//
//  Sprite.cpp
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/12/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#include "Sprite.h"

Sprite::Sprite() {
    x=0;
    y=0;
    width = 0;
    height = 0;
}

Sprite::Sprite(int x,int y,int width,int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}


int Sprite::getX(){
    return x;
}
int Sprite::getY(){
    return y;
}

int Sprite::getWidth(){
    return width;
}
int Sprite::getHeight(){
    return height;
}
void Sprite::setX(int value){
    x = value;
}
void Sprite::setY(int value){
    y = value;
}




