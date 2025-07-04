#include <NDL.h>
#include <SDL.h>

#define keyname(k) #k,

static const char *keyname[] = {
	"NONE",
	_KEYS(keyname)};

int SDL_PushEvent(SDL_Event *ev)
{
	return 0;
}

int SDL_PollEvent(SDL_Event *ev)
{
	return 0;
}

int SDL_WaitEvent(SDL_Event *event)
{
	char buf[64] = {0};

	NDL_PollEvent(buf, sizeof(buf) - 1);
	if (buf[1] == 'd')
	{
		event->type = SDL_KEYDOWN;
		// 只封装 j/down k/up g
	}
	else
		event->type = SDL_KEYUP;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask)
{
	return 0;
}

uint8_t *SDL_GetKeyState(int *numkeys)
{
	return NULL;
}
