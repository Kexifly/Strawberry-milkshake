#include "sound.h"
#include <windows.h>
#include <iostream>

// Function that loads in a sound.wav and continues to play regardless of what keys are pressed. 
void PlaySoundTrack()
{
	BOOL played = PlaySound(L"Pong.wav", NULL, SND_ASYNC | SND_FILENAME | SND_NODEFAULT);
}