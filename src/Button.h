/*** image.h  Javi Agenjo (javi.agenjo@gmail.com) 2013
This file defines the class Image that allows to manipulate images.
It defines all the need operators for Color and Image.
It has a TGA loader and saver.
***/

#ifndef BUTTON_H
#define BUTTON_H

#include <stdio.h>
#include <iostream>
#include "framework.h"


//Class Image: to store a matrix of pixels
class Button
{
	unsigned int width = 60;
	unsigned int height = 60;
	Color color = Color::BLACK;

public:
	
	// CONSTRUCTORS 
	Button();
	
	// Getters
	unsigned int getWidth(void);
	unsigned int getHeight(void);
	Color getColor(void);
	
	// Setters
	void setWidth(unsigned int width);
	void setHeight(unsigned int height);
	void setColor(Color c);

};

#endif