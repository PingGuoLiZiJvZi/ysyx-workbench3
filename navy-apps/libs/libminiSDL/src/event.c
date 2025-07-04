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
		switch (buf[3])
		{
		case '0':
			event->key.keysym.sym = SDLK_0;
			break;
		case '1':
			event->key.keysym.sym = SDLK_1;
			break;
		case '2':
			event->key.keysym.sym = SDLK_2;
			break;
		case '3':
			event->key.keysym.sym = SDLK_3;
			break;
		case '4':
			event->key.keysym.sym = SDLK_4;
			break;
		case '5':
			event->key.keysym.sym = SDLK_5;
			break;
		case '6':
			event->key.keysym.sym = SDLK_6;
			break;
		case '7':
			event->key.keysym.sym = SDLK_7;
			break;
		case '8':
			event->key.keysym.sym = SDLK_8;
			break;
		case '9':
			event->key.keysym.sym = SDLK_9;
			break;
		case 'G':
			event->key.keysym.sym = SDLK_G;
			break;
		case 'J':
			event->key.keysym.sym = SDLK_J;
			break;
		case 'K':
			event->key.keysym.sym = SDLK_K;
			break;
		default:
			event->key.keysym.sym = SDLK_NONE;
			break;
		}
	}
	else
		event->type = SDL_KEYUP;
	return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask)
{
	return 0;
}

uint8_t *SDL_GetKeyState(int *numkeys)
{
	return NULL;
}
