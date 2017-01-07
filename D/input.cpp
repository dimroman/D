#include "input.h"
#include <Windows.h>

void input::on_key_down(UINT8 const key)
{
	switch (key)
	{
	case VK_LEFT:
		leftArrowPressed = true;
		break;
	case VK_RIGHT:
		rightArrowPressed = true;
		break;
	case VK_UP:
		forward_arrow_pressed = true;
		break;
	case VK_DOWN:
		backward_arrow_pressed = true;
		break;
	case VK_SPACE:
		animate = !animate;
		break;
	}

}

void input::on_key_up(UINT8 const key)
{
	switch (key)
	{
	case VK_LEFT:
		leftArrowPressed = false;
		break;
	case VK_RIGHT:
		rightArrowPressed = false;
		break;
	case VK_UP:
		forward_arrow_pressed = false;
		break;
	case VK_DOWN:
		backward_arrow_pressed = false;
		break;
	}
}

void input::on_mouse_move(WPARAM const button_state, int const x, int const y)
{
	if ((button_state & MK_LBUTTON) != 0)
	{
		last_dx = math::to_radians(0.25f*static_cast<float>(x - last_mouse_x));
		last_dy = math::to_radians(0.25f*static_cast<float>(y - last_mouse_y));
	}

	last_mouse_x = x;
	last_mouse_y = y;
}

void input::reset()
{
	last_dx = 0.0f;
	last_dy = 0.0f;
}