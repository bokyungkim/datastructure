#ifndef _MAZE_
#define _MAZE_

#define HEIGHT	4
#define WIDTH	4

typedef struct
{
	int	x;
	int	y;
	char direction;
	struct MapPosition* pLink;
} MapPosition;

#endif