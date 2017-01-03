#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

struct InputState
{
	bool rightArrowPressed = false;
	bool leftArrowPressed = false;
	bool upArrowPressed = false;
	bool downArrowPressed = false;
	bool animate = true;
};

#endif // #ifndef INPUT_H_INCLUDED