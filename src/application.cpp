#include "application.h"
#include "utils.h"
#include "image.h"

Application::Application(const char* caption, int width, int height)
{
	this->window = createWindow(caption, width, height);

	// initialize attributes
	// Warning: DO NOT CREATE STUFF HERE, USE THE INIT 
	// things create here cannot access opengl
	int w,h;
	SDL_GetWindowSize(window,&w,&h);

	this->window_width = w;
	this->window_height = h;
	this->keystate = SDL_GetKeyboardState(NULL);
}

//Here we have already GL working, so we can create meshes and textures
void Application::init(void)
{
	std::cout << "initiating app..." << std::endl;

	//here add your init stuff

	// Set Matrix to false
	for (unsigned int x = 0; x < 680; x++)
		for (unsigned int y = 0; y < 760; y++)
			Matrix[x][y] = false;
	
	// Init buttons and associate colours
	for (unsigned int i = 0; i < numBut; i++)
		arrayBut[i] = Button();

	arrayBut[0].setColor(Color::RED);		// CIRCLE

	arrayBut[1].setColor(Color::GREEN);		// SQUARE

	arrayBut[2].setColor(Color::BLUE);		// TRIANGLE

	arrayBut[3].setColor(Color::GRAY);		// ERASE
}

//render one frame
void Application::render(void)
{
	// Clear the window and the depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//render grid
	Image img( 800, 800 );

	
	/********************  CODE  ********************/
	unsigned int x, y, i;


	// Left menu
	for (x = 0; x < 80; x++)
		for(y = 20; y < img.height - 20; y++)
			img.setPixel(x, y, Color::WHITE);

	// Buttons
	for (i = 0; i < numBut; i++)
	{
		for (x = 0; x < 80; x++)
			img.setPixel(x, (img.height - (20 + i * arrayBut[i].getHeight())), Color::RED);

		unsigned int centerX = arrayBut[i].getWidth()/2+10;
		unsigned int centerY = img.height - 20 - i* arrayBut[i].getHeight() - arrayBut[i].getHeight()/2;
		unsigned int radi = 15;
		Color butColor = arrayBut[i].getColor();

		switch (i)
		{
			// CIRCLE
			case 0:	
				for (x = 25; x < 55; x++)
					for (y = img.height - 20 - (i+1)* arrayBut[i].getHeight(); y < img.height - 20; y++)
						if (sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY)) < radi)
							img.setPixel(x, y, butColor);
				break;
			
			// SQUARE
			case 1:
				for (x = 25; x < 55; x++)
					for (y = img.height - 5 - (i + 1) * arrayBut[i].getHeight(); y < img.height - 35 - i * arrayBut[i].getHeight(); y++)
						img.setPixel(x, y, butColor);
				break;

			// TRIANGLE
			case 2:
				for (x = 10; x < 70; x++)
					for (y = img.height - 5 - (i + 1)* arrayBut[i].getHeight(); y < img.height - 35 - i * arrayBut[i].getHeight(); y++)
						if (x < 40 && x - 10 > y - (img.height - 5 - (i + 1)* arrayBut[i].getHeight()))
							img.setPixel(x, y, butColor);
						else if (x - 40 < (img.height - 35 - i * arrayBut[i].getHeight()) - y)
							img.setPixel(x, y, butColor);
				/*
				for (y = 20; y < 35; y++){
					if (x < 40 && x - 25 > y - 20)
						img.setPixel(x, y, butColor);
					else if (x-39 < 35-y)
						img.setPixel(x, y, butColor);
				}
				*/
				break;

			// ERASE
			case 3:
				for (x = 15; x < 65; x++)
					for (y = img.height - 5 - (i + 1)* arrayBut[i].getHeight(); y < img.height - 35 - i * arrayBut[i].getHeight(); y++)
						img.setPixel(x, y, butColor);
					break;
		}
	}

	
	// Matrix
	for (x = 0; x < 680; x++)
		for (y = 0; y < 760; y++)
			if ( Matrix[x][y] )
				img.setPixel(x + 100, y + 20, Color::BLACK);
			else
				img.setPixel(x + 100, y + 20, Color::WHITE);


	/************************************************/


	img.scale( this->window_width, this->window_height );

	renderImage( &img );

	//swap between front buffer and back buffer
	SDL_GL_SwapWindow(this->window);
}

//called after render
void Application::update(double seconds_elapsed)
{
	if (keystate[SDL_SCANCODE_SPACE])
	{
		//...
	}
}

//keyboard press event 
void Application::onKeyPressed( SDL_KeyboardEvent event )
{
	switch(event.keysym.sym)
	{
		case SDLK_ESCAPE: exit(0); break; //ESC key, kill the app
	}
}

//mouse button event
void Application::onMouseButtonDown( SDL_MouseButtonEvent event )
{
	if (event.button == SDL_BUTTON_LEFT) //left mouse pressed
	{
		if (event.x < 80)	// Menu
		{
			if (event.y < 780 && event.y > 720)
				pattern = 0;	// case 0 => circle

			else if (event.y < 720 && event.y > 660)
				pattern = 1;	// case 1 => square

			else if (event.y < 660 && event.y > 580)
				pattern = 2;	// case 2 => triangle

			else if (event.y < 580 && event.y > 500)
				pattern = 3;	// case 3 => erase

			// else if (...)
			// Si ens dones temps de fer lo dels tamanys ho posariem a continuació restant 80 pixels
		}

		else if (event.x > 100 && event.x < 790 && event.y > 20 && event.y < 790)	// Document
			setPointtoMatrix(pattern, size);			
	}

}

void Application::onMouseButtonUp( SDL_MouseButtonEvent event )
{
	if (event.button == SDL_BUTTON_LEFT) //left mouse unpressed
	{

	}
}

//when the app starts
void Application::start()
{
	std::cout << "launching loop..." << std::endl;
	launchLoop(this);
}

void Application::setPointtoMatrix(unsigned int pattern, unsigned int size)
{
	// Aqui hauras d'utilitzar el que hem fet a casa meva


}