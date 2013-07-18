//
//  Sprite.cpp
//  SpriteDragger
//
//  Created by Tolga Saglam's mac on 7/12/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#include "Sprite.h"
const int MAX_JUMP = 60;
const int JUMP_SPEED = 2;
Sprite::Sprite() {
    x=0;
    y=0;
    width = 0;
    height = 0;
    status = 0;
    collided = false;
    maxJump = MAX_JUMP;
    jumpSpeed = JUMP_SPEED;
}

Sprite::Sprite(int x,int y,int width,int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    status = 0;
    collided = false;
    maxJump = MAX_JUMP;
    jumpSpeed = JUMP_SPEED;
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
bool Sprite::getCollided() {
    return collided;
}
void Sprite::setCollided(bool value){
    collided = value;
}

int Sprite::getStatus() {
    return  status;
}

void Sprite::setStatus(int value){
    status = value;
}

float Sprite::getRotation() {
    return  rotation;
}
void Sprite::setRotation(float value){
    rotation = value;
}
int Sprite::getJumpSpeed() {
    return  jumpSpeed;
}
void Sprite::setJumpLength(int value){
    jumpLength = value;
}
int Sprite::getJumpLength() {
    return  jumpLength;
}
int Sprite::getMaxJump() {
    return maxJump;
}





