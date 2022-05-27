#include "sound.h"
#include <windows.h>
#include <iostream>

// Function that loads in a sound.wav and continues to play regardless of what keys are pressed. 
void PlaySoundTrack()
{
	// Added SND_LOOP so that when the track ends it starts again from the beggining. 
	BOOL played = PlaySound(L"Pong.wav", NULL, SND_LOOP | SND_ASYNC | SND_FILENAME | SND_NODEFAULT);
	
}