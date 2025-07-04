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
	char type[4] = {0};
	char key_name[16] = {0};
	NDL_PollEvent(buf, sizeof(buf) - 1);
	sscanf(buf, "%s %s", type, key_name);
	if (strcmp(type, "kd") == 0)
	{
		event->type = SDL_KEYDOWN;
	}
	else if (strcmp(type, "ku") == 0)
	{
		event->type = SDL_KEYUP;
	}
	else
	{
		return 0; // Not a key event
	}
	for (int i = 0; i < sizeof(keyname) / sizeof(keyname[0]); i++)
	{
		if (strcmp(keyname[i], key_name) == 0)
		{
			event->key.keysym.sym = i;
			break;
		}
	}
	if (event->key.keysym.sym == SDLK_NONE)
	{
		return 0; // Unknown key}
	}
	return 1; // Event successfully read
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask)
{
	return 0;
}

uint8_t *SDL_GetKeyState(int *numkeys)
{
	return NULL;
}
