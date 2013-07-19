
#pragma once

#include "SpriteDragger.h"
#include "cocos2d.h"
#include "Sprite.h"
#include "ScreenManager.h"

class Layer : public CCLayer
{
	private:
		/// Our sprite
		CCSprite* sprite;
		
		/// The background color layer
		CCLayer* colorLayer;
		
		/// The offset of a touch
		CCPoint touchOffset;
        Sprite *box;
        //Line *line;
        int xBuffer;
        std::list<Line*> *lineList;
        int speed;
        int yBuffer;
        int maxYForSprite;
        int screenController;
        int width,height;
        //CCPoint p1,p2;
	public:
		Layer();
		~Layer();
		
		/// Returns the Cocos2d position of the touch
		CCPoint touchToPoint(CCTouch* touch);
		
		/// Returns true if the touch is within the boundary of our sprite
		bool isTouchingSprite(CCTouch* touch);

		// we are multi-touch enabled, so we must use the ccTouches functions
		// vs the ccTouch functions
		void ccTouchesBegan(CCSet* touches, CCEvent* event);
		void ccTouchesMoved(CCSet* touches, CCEvent* event);
		void ccTouchesEnded(CCSet* touches, CCEvent* event);
        void draw();
        void drawLine(CCPoint p1,CCPoint p2);
        void tick(float dt);
        void controlCollission();
        CCPoint ccpForScreen(float x,float y);
        void drawLines();
        void move();
        void setPositions();
        void addScreen(int screenIndex);
};
