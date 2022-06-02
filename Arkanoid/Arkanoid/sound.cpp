#include "sound.h"
#include <iostream>
#include <windows.h>

// Function that loads in a sound.wav and continues to play regardless of what keys are pressed.
void PlaySoundTrack()
{
	// Added SND_LOOP so that when the track ends it starts again from the beggining. 
	BOOL played = PlaySound(L"", NULL, SND_LOOP | SND_ASYNC | SND_FILENAME | SND_NODEFAULT);
}