/* ball.c - Library source */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include <assert.h>

#include "include/ball.h"
#include "include/field.h"


struct Ball* ball_create(	int x, int y,
				int max_x, int max_y,
				int next_x, int next_y,
				int x_direction, int y_direction,
				char element[strlen(BALL_STRING)] )
{
	struct Ball *_ball = malloc(sizeof(struct Ball));

	assert(_ball != NULL);

	_ball->x 		= x;
	_ball->y 		= y;
	_ball->max_x		= max_x;
	_ball->max_y		= max_y;
	_ball->next_x 		= next_x;
	_ball->next_y 		= next_y;
	_ball->x_direction 	= x_direction;
	_ball->y_direction 	= y_direction;

	strcpy(_ball->element, element);

	return _ball;
}

void ball_next(struct Ball* _ball)
{
	_ball->next_x = _ball->x + _ball->x_direction;
	_ball->next_y = _ball->y + _ball->y_direction;

	// Calculate for x-axis
	if(_ball->next_x >= _ball->max_x || _ball->next_x < 0) {
		_ball->x_direction *= -1;
	} else {
		_ball->x += _ball->x_direction;
	}

	// Calculate for y-axis
	if(_ball->next_y >= _ball->max_y || _ball->next_y < 0) {
		_ball->y_direction *= -1;
	} else {
		_ball->y += _ball->y_direction;
	}

}

void ball_destroy(struct Ball* _ball)
{
	// Release "malloc" allocated memory
	assert(_ball != NULL);
	free(_ball);
}

