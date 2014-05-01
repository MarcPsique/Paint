#include "Button.h"


// CONSTRUCTORS 
Button::Button() {}


// Getters
unsigned int Button::getWidth(void)		{ return this->width; }
unsigned int Button::getHeight(void)	{ return this->height; }
Color Button::getColor(void)			{ return this->color; }

// Setters
void Button::setWidth(unsigned int width)		{ this->width = width; }
void Button::setHeight(unsigned int height)		{ this->height = height; }
void Button::setColor(Color c)					{ this->color = c; }