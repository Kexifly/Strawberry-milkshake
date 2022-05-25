#include "sound.h"
#include <windows.h>
#include <iostream>

void PlaySoundTrack()
{
	BOOL played = PlaySound(L"Pong.wav", NULL, SND_ASYNC | SND_FILENAME | SND_NODEFAULT);

	std::cout << "It worked " << std::boolalpha << (played == TRUE) << std::endl;
}