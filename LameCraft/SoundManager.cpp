#include "SoundManager.h"

SoundManager SoundManager::m_SoundManager;

SoundManager* SoundManager::Instance()
{
	return &m_SoundManager;
}

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{

}

void SoundManager::Init()
{
	//first of all init audio engine
	VirtualFileInit();
	//oslInitAudioME(OSL_FMT_MP3);
	oslInitAudio();

	//button sound
	buttonSound = oslLoadSoundFile("Assets/Sounds/button1.wav",OSL_FMT_MP3);

	//TNT
	tnt = oslLoadSoundFile("Assets/Sounds/tnt.wav",OSL_FMT_MP3);

	door = oslLoadSoundFile("Assets/Sounds/door.wav",OSL_FMT_MP3);

	//plop sound
	plopSound = oslLoadSoundFile("Assets/Sounds/plop.wav",OSL_FMT_MP3);
    //cave sounds
    caveSounds[0] = oslLoadSoundFile("Assets/Sounds/cave2.wav",OSL_FMT_MP3);
    caveSounds[1] = oslLoadSoundFile("Assets/Sounds/cave3.wav",OSL_FMT_MP3);
    caveSounds[2] = oslLoadSoundFile("Assets/Sounds/cave4.wav",OSL_FMT_MP3);
    caveSounds[3] = oslLoadSoundFile("Assets/Sounds/cave5.wav",OSL_FMT_MP3);
    caveSounds[4] = oslLoadSoundFile("Assets/Sounds/cave6.wav",OSL_FMT_MP3);
    caveSounds[5] = oslLoadSoundFile("Assets/Sounds/cave7.wav",OSL_FMT_MP3);
	//grass sounds
	grassSounds[0] = oslLoadSoundFile("Assets/Sounds/walking/grass1.wav",OSL_FMT_MP3);
	grassSounds[1] = oslLoadSoundFile("Assets/Sounds/walking/grass2.wav",OSL_FMT_MP3);
	grassSounds[2] = oslLoadSoundFile("Assets/Sounds/walking/grass3.wav",OSL_FMT_MP3);
	grassSounds[3] = oslLoadSoundFile("Assets/Sounds/walking/grass4.wav",OSL_FMT_MP3);

	//grawel
	grawelSounds[0] = oslLoadSoundFile("Assets/Sounds/walking/gravel1.wav",OSL_FMT_MP3);
	grawelSounds[1] = oslLoadSoundFile("Assets/Sounds/walking/gravel2.wav",OSL_FMT_MP3);
	grawelSounds[2] = oslLoadSoundFile("Assets/Sounds/walking/gravel3.wav",OSL_FMT_MP3);
	grawelSounds[3] = oslLoadSoundFile("Assets/Sounds/walking/gravel4.wav",OSL_FMT_MP3);

	//stone
	stoneSounds[0] = oslLoadSoundFile("Assets/Sounds/walking/stone1.wav",OSL_FMT_MP3);
	stoneSounds[1] = oslLoadSoundFile("Assets/Sounds/walking/stone2.wav",OSL_FMT_MP3);
	stoneSounds[2] = oslLoadSoundFile("Assets/Sounds/walking/stone3.wav",OSL_FMT_MP3);
	stoneSounds[3] = oslLoadSoundFile("Assets/Sounds/walking/stone4.wav",OSL_FMT_MP3);

	//wood
	woodSounds[0] = oslLoadSoundFile("Assets/Sounds/walking/wood1.wav",OSL_FMT_MP3);
	woodSounds[1] = oslLoadSoundFile("Assets/Sounds/walking/wood2.wav",OSL_FMT_MP3);
	woodSounds[2] = oslLoadSoundFile("Assets/Sounds/walking/wood3.wav",OSL_FMT_MP3);
	woodSounds[3] = oslLoadSoundFile("Assets/Sounds/walking/wood4.wav",OSL_FMT_MP3);
	
	//sand
	sandSounds[0] = oslLoadSoundFile("Assets/Sounds/walking/sand1.wav",OSL_FMT_MP3);
	sandSounds[1] = oslLoadSoundFile("Assets/Sounds/walking/sand2.wav",OSL_FMT_MP3);
	sandSounds[2] = oslLoadSoundFile("Assets/Sounds/walking/sand3.wav",OSL_FMT_MP3);
	sandSounds[3] = oslLoadSoundFile("Assets/Sounds/walking/sand4.wav",OSL_FMT_MP3);


	// Ambient
	ambientSounds[0] = oslLoadSoundFile("Assets/Sounds/ambient/track1.bgm",OSL_FMT_STREAM);
	ambientSounds[1] = oslLoadSoundFile("Assets/Sounds/ambient/track2.bgm",OSL_FMT_STREAM);
	ambientSounds[2] = oslLoadSoundFile("Assets/Sounds/ambient/track3.bgm",OSL_FMT_STREAM);
	ambientSounds[3] = oslLoadSoundFile("Assets/Sounds/ambient/track4.bgm",OSL_FMT_STREAM);
	ambientSounds[4] = oslLoadSoundFile("Assets/Sounds/ambient/track5.bgm",OSL_FMT_STREAM);
	ambientSounds[5] = oslLoadSoundFile("Assets/Sounds/ambient/track6.bgm",OSL_FMT_STREAM);

	srand(time(NULL));

	//set default values
	currentWalkSound = 0;
	lastWalkSound = 0;

	playerSounds = true;
}

void SoundManager::PlayMenuSound()
{
	oslPlaySound(buttonSound, 1);
}

void SoundManager::PlayPlopSound()
{
	if(playerSounds)
		oslPlaySound(plopSound,1);
}

void SoundManager::TNTSound()
{
	if(playerSounds)
		oslPlaySound(tnt,6);
}

void SoundManager::doorSound()
{
	if(playerSounds)
		oslPlaySound(door,1);
}

void SoundManager::PlayCaveSound()
{
	if(playerSounds)
    {
        short randSound = rand() % 5;
        oslPlaySound(caveSounds[randSound],6);
    }
}

void SoundManager::PlayWalkSound(int type)
{
	if(playerSounds)
	{
		switch(type)
		{
			case 0://grass
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(grassSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(grassSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
			case 1://gravel
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(grawelSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(grawelSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
			case 2://stone
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(stoneSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(stoneSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
			case 3://wood
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(woodSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(woodSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
			case 4://sand
			{
				currentWalkSound = rand() % 4;

				//stop last sound
				oslStopSound(sandSounds[lastWalkSound]);

				//play new sound
				oslPlaySound(sandSounds[currentWalkSound],1);

				//set last sound as current
				lastWalkSound = currentWalkSound;
			}
			break;
		}
	}
}

int SoundManager::PlayRandomAmbient()
{
 	currentAmbientSound = rand() % 6;

	//stop last sound
	oslStopSound(ambientSounds[lastAmbientSound]);

	//play new sound
	if(ambientSounds[currentAmbientSound]&&ambientSoundsEnabled)
		oslPlaySound(ambientSounds[currentAmbientSound],2);

	//set last sound as current
	lastAmbientSound = currentAmbientSound;

	switch(currentAmbientSound)
	{
		case 0:
			{
				return 230;
			}
			break;
		case 1:
			{
				return 210;
			}
			break;
		case 2:
			{
				return 220;
			}
			break;
		case 3:
			{
				return 280;
			}
			break;
		case 4:
			{
				return 90;
			}
			break;
		case 5:
			{
				return 90;
			}
			break;
	}
	return 1;
}
