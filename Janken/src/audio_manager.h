#pragma once

#include <Siv3D.hpp>

// singleton class
class AudioManager
{
public:
	AudioManager(const AudioManager&) = delete;
	AudioManager operator=(const AudioManager&) = delete;
	AudioManager(const AudioManager&&) = delete;
	AudioManager& operator=(const AudioManager&&) = delete;

	void playSE(const String&);
	void playBGM(const String&);

	static AudioManager& Instance()
	{
		static AudioManager singleton;
		return singleton;
	}

private:
	AudioManager();
	~AudioManager();

	void playJankenpon();

	const FilePath janPath = U"../wav/audio_16385.wav";
	const FilePath kenPath = U"../wav/audio_16380.wav";
	const FilePath ponPath = U"../wav/audio_16388.wav";
};