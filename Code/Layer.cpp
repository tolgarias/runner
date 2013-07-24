
#include "SpriteDragger.h"
#include "CCDrawingPrimitives.h"
//#include "GLES/gl.h"
#include "cocos2d.h"
#include "ScreenManager.h"
#include "stdlib.h"

const int TOP_PADDING=120;
const int LEFT_PADDING = 60;
Layer::Layer()
{
	// enable touches so we can drag
	// note that if you call CCLayer's init() it will unset touch enabled!
	this->setTouchEnabled(true);

	// create white background
	this->colorLayer = new CCLayer;
	this->addChild(this->colorLayer, 1);
    lineList = new std::list<Line*>();
    //lineListToRemove = new std::list<Line*>();
    
    
    //box->status1 = spriteStatus::FALLING;
    // create sprite
	CCSize iSize = CCDirector::sharedDirector()->getWinSize();
    width = iSize.height;
    height = iSize.width;
    xBuffer = 0;
    yBuffer = 0;
    speed = 4;
    
    
    box=new Sprite(LEFT_PADDING, iSize.height/2, 32, 32);
    box->setSpeed(speed);
    
    this->sprite = new CCSprite;
	this->sprite->initWithFile("wall.png");
	this->sprite->setAnchorPoint(ccp(0.5f, 0.5f)); // nudge the anchor point upward because of the shadow
    this->sprite->setPosition(CCDirector::sharedDirector()->convertToGL(ccp(box->getY()-(box->getHeight()/2),box->getX()+box->getWidth()/2)));
    //this->sprite->setPosition(ccp(box->getX(),box->getY()));
	
	this->addChild(this->sprite, 2);
    
    
    

    maxYForSprite = iSize.width - TOP_PADDING;
    
    
    ScreenManager::getInstance().load(iSize.height,iSize.width);
    addScreen(0);
    int rnd = rand() % 4;
    addScreen(rnd);
    rnd = rand() % 4;
    addScreen(rnd);
    
    this->schedule(schedule_selector(Layer::tick), 1.0f/60.0f);

}
void Layer::addScreen(int screenIndex) {
    std::list<Line*> newLines = ScreenManager::getInstance().addScreen(screenIndex, xBuffer,yBuffer);
    for(std::list<Line*>::iterator list_iter = newLines.begin();
        list_iter != newLines.end(); list_iter++){
        Line* l = dynamic_cast<Line*>(*list_iter);
        lineList->push_front(l);
    }
}
CCPoint Layer::ccpForScreen(float x, float y){
    return CCDirector::sharedDirector()->convertToGL(ccp(x,y));
}
void Layer::tick(float dt){
    move();
    controlCollission();
    if(!box->getCollided() && box->getStatus()!=spriteStatus::JUMPING){
        box->setStatus(spriteStatus::FALLING);
        box->m_line = NULL;
    }
    setPositions();
    std::list<Line*>::iterator i = lineList->begin();
    while (i != lineList->end())
    {
        Line* line = dynamic_cast<Line*>(*i);
        if(xBuffer>line->getSecondPoint().x){
            lineList->erase(i++);  // alternatively, i = items.erase(i);
        }
        else
        {
            ++i;
        }
    }
}
void Layer::controlCollission() {
    if(box->getStatus()==spriteStatus::FALLING || box->checkCollission()){
        //std::cout << "size:"<<lineList->size();
        for (std::list<Line*>::iterator it = lineList->begin(); it != lineList->end(); it++){
            Line* line = dynamic_cast<Line*>(*it);
            if(line->checkCollission(box->getX(),box->getY()+yBuffer,box->getWidth(),box->getHeight(),box->getJumpSpeed())){
                box->setCollided(true);
                box->setRotation(line->getIncline());
                box->setStatus(spriteStatus::RUNNING);
                box->m_line = line;
                return;
            }
           
        }
        box->setCollided(false);
    }
}
Layer::~Layer()
{
	// unset this so we unregister with the touch dispatcher
	this->setTouchEnabled(false);
	
	// release our sprite and layer so that it gets dealloced
	CC_SAFE_RELEASE_NULL(this->sprite);
	CC_SAFE_RELEASE_NULL(this->colorLayer);
}

CCPoint Layer::touchToPoint(CCTouch* touch)
{
	// convert the touch object to a position in our cocos2d space
	return CCDirector::sharedDirector()->convertToGL(touch->locationInView());
}

bool Layer::isTouchingSprite(CCTouch* touch)
{
	// here's one way, but includes the rectangular white space around our sprite
	//return CGRectContainsPoint(this->sprite->boundingBox(), this->touchToPoint(touch));
	
	// this way is more intuitive for the user because it ignores the white space.
	// it works by calculating the distance between the sprite's center and the touch point,
	// and seeing if that distance is less than the sprite's radius
	return (ccpDistance(this->sprite->getPosition(), this->touchToPoint(touch)) < 100.0f);
}
void Layer::draw() {
    
    cocos2d::ccDrawColor4F(1.0, 1.0, 1.0, 1);
    
    drawLines();
}

void Layer::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
	// reset touch offset
	this->touchOffset = CCPointZero;
	
	for( auto it = touches->begin(); it != touches->end(); it++) 
	{
		CCTouch* touch = dynamic_cast<CCTouch*>(*it);

		// if this touch is within our sprite's boundary
		if( touch && this->isTouchingSprite(touch) )
		{
			// calculate offset from sprite to touch point
			this->touchOffset = ccpSub(this->sprite->getPosition(), this->touchToPoint(touch));
		}
        CCPoint touchPoint = touch->locationInView();
        box->setStatus(spriteStatus::JUMPING);
        box->m_line = NULL;
	}
   
}

void Layer::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	for( auto it = touches->begin(); it != touches->end(); it++) 
	{
		CCTouch* touch = dynamic_cast<CCTouch*>(*it);

		// set the new sprite position
		//if( touch && touchOffset.x && touchOffset.y )
		//	this->sprite->setPosition(ccpAdd(this->touchToPoint(touch), this->touchOffset));
        //CCPoint *newPoint = new CCPoint;
        //newPoint->setPoint(touch->locationInView().y, touch->locationInView().x);
        //this->sprite->cocos2d::CCNode::setPosition(touch->locationInView().y, touch->locationInView().x);
	}
}

void Layer::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	for( auto it = touches->begin(); it != touches->end(); it++) 
	{
		CCTouch* touch = dynamic_cast<CCTouch*>(*it);
		/*if( touch && touchOffset.x && touchOffset.y  )
		{
			// set the new sprite position
			this->sprite->setPosition(ccpAdd(this->touchToPoint(touch), this->touchOffset));

			// animate letting go of the sprite
			this->sprite->runAction(CCSequence::create(
				CCScaleBy::create(0.125f, 1.111f),
				CCScaleBy::create(0.125f, 0.9f),
				nullptr
				));
		}*/
        //this->sprite->cocos2d::CCNode::setPosition(CCDirector::sharedDirector()->convertToGL(ccp(touch->locationInView().x, touch->locationInView().y)));
        box->setStatus(spriteStatus::FALLING);
        box->setJumpLength(0);
        //box->m_line = NULL;
        
	}
}
void Layer::drawLine(CCPoint p1, CCPoint p2){
    ccDrawLine(CCDirector::sharedDirector()->convertToGL(p1),CCDirector::sharedDirector()->convertToGL(p2));
}

void Layer::drawLines() {
    for (std::list<Line*>::iterator it = lineList->begin(); it != lineList->end(); it++){
        Line* ll = dynamic_cast<Line*>(*it);
        CCPoint p1 = ccp(ll->getFirstPoint().y-yBuffer,ll->getFirstPoint().x-xBuffer);
        CCPoint p2 = ccp(ll->getSecondPoint().y-yBuffer,ll->getSecondPoint().x-xBuffer);
        drawLine(p1, p2);
    }
}

void Layer::move() {
    xBuffer+=speed;
    box->setX(box->getX()+speed);
    float ySpeed = box->getJumpSpeed();
    if (box->m_line!=NULL && box->getStatus() == spriteStatus::RUNNING) {

        float incline = box->m_line->getIncline();
        if(incline<0) {
            incline*=-1;
        }
        incline = CC_DEGREES_TO_RADIANS(incline);
        float hipotenus = speed/cosf(incline);
        ySpeed = hipotenus*sinf(incline);
        if(box->m_line->getDirection()==2){
            ySpeed=-1*ySpeed;
        }
    }
    else if(box->getStatus() == spriteStatus::FALLING){
        ySpeed = -1*box->getJumpSpeed();
    }
    else if (box->getStatus()==spriteStatus::JUMPING) {
        box->setJumpLength(box->getJumpLength()+box->getJumpSpeed());
        ySpeed = box->getJumpSpeed();
        if(box->getJumpLength()>box->getMaxJump()){
            box->setStatus(FALLING);
            box->setJumpLength(0);
            ySpeed=0;
        }
    }
    
    float yPosition = box->getY();
    //if sprite going up
    if(ySpeed>0) {
        yPosition += ySpeed;
        //float diff = 0;
        if(yPosition>maxYForSprite){
           // diff = yPosition-maxYForSprite;
            yPosition -= ySpeed;
            yBuffer+=ySpeed;
        }
    }
    //if sprite going down
    else if(ySpeed<0) {
        if(yBuffer>0){
            yBuffer+=ySpeed;
            if(yBuffer<0)yBuffer=0;
        }
        else {
            yPosition+=ySpeed;
        }

    }
    box->setY(yPosition);
    
    screenController+=speed;
    if(screenController>=width){
        addScreen(rand()%ScreenManager::getInstance().getScreenCount());
        screenController=0;
    }
    
}

void Layer::setPositions() {
    this->sprite->setPosition(ccpForScreen(box->getY()-box->getHeight()/2,LEFT_PADDING+box->getWidth()/2));
    if(box->getCollided()){
        this->sprite->setRotation(box->getRotation());
    }
    else {
        this->sprite->setRotation(180);
    }
}
