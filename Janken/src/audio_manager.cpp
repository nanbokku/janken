#include "audio_manager.h"
#include "constants/constants.h"

AudioManager::AudioManager()
{
	// ƒAƒZƒbƒg‚Ì“o˜^
	AudioAsset::Register(U"jan", janPath, AssetParameter::LoadImmediately());
	AudioAsset::Register(U"ken", kenPath, AssetParameter::LoadImmediately());
	AudioAsset::Register(U"pon", ponPath, AssetParameter::LoadImmediately());
}

AudioManager::~AudioManager()
{

}

void AudioManager::playSE(const String& name)
{
	if (name == Constants::Audio::JankenponStr) {
		playJankenpon();
		return;
	}

	const auto audio = AudioAsset(name);
	if (!audio.isEmpty()) audio.playOneShot();
}

void AudioManager::playBGM(const String& name)
{

}

void AudioManager::playJankenpon()
{
	const auto jan = AudioAsset(U"jan");
	const auto ken = AudioAsset(U"ken");
	const auto pon = AudioAsset(U"pon");

	if (jan.isPlaying()) jan.stop();
	if (ken.isPlaying()) ken.stop();
	if (pon.isPlaying()) pon.stop();

	const double time = (Constants::Play::MaxWaitMs + 1000) / 4.0;

	//jan.playOneShot(1.0, jan.lengthSec() * 1000 / time);
	jan.playOneShot();

	System::Sleep(time);

	//ken.playOneShot(1.0, ken.lengthSec() * 1000 / time);
	ken.playOneShot();

	System::Sleep(time);

	//pon.playOneShot(1.0, pon.lengthSec() * 1000 / time);
	pon.playOneShot();
}