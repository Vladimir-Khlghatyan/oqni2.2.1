#include "sound.hpp"

Sound::Sound(QObject *parent, double volume)
    : QObject(parent)
{
    _soundSelect            = new QSoundEffect();
    _soundVolume            = new QSoundEffect();
    _soundCheck             = new QSoundEffect();
    _soundAbout             = new QSoundEffect();
    _soundDefaultButton     = new QSoundEffect();
    _soundTools             = new QSoundEffect();
    _soundCheckBox          = new QSoundEffect();
    _soundTestMode          = new QSoundEffect();
    _soundInvalidDuration   = new QSoundEffect();

    _soundSelect->setSource(QUrl::fromLocalFile(":/Sounds/select.wav"));
    _soundVolume->setSource(QUrl::fromLocalFile(":/Sounds/volume.wav"));
    _soundCheck->setSource(QUrl::fromLocalFile(":/Sounds/check.wav"));
    _soundAbout->setSource(QUrl::fromLocalFile(":/Sounds/about.wav"));
    _soundDefaultButton->setSource(QUrl::fromLocalFile(":/Sounds/defaultButton.wav"));
    _soundTools->setSource(QUrl::fromLocalFile(":/Sounds/tools.wav"));
    _soundCheckBox->setSource(QUrl::fromLocalFile(":/Sounds/checkBox.wav"));
    _soundTestMode->setSource(QUrl::fromLocalFile(":/Sounds/testMode.wav"));
    _soundInvalidDuration->setSource(QUrl::fromLocalFile(":/Sounds/invalidDuration.wav"));

    setVolume(volume);
}

Sound::~Sound()
{
    delete _soundSelect;
    delete _soundVolume;
    delete _soundCheck;
    delete _soundAbout;
    delete _soundDefaultButton;
    delete _soundTools;
    delete _soundCheckBox;
    delete _soundTestMode;
    delete _soundInvalidDuration;
}

void Sound::setVolume(double volume)
{
    _soundSelect->setVolume(volume);
    _soundVolume->setVolume(volume);
    _soundCheck->setVolume(volume);
    _soundAbout->setVolume(volume);
    _soundDefaultButton->setVolume(volume);
    _soundTools->setVolume(volume);
    _soundCheckBox->setVolume(volume);
    _soundTestMode->setVolume(volume);
    _soundInvalidDuration->setVolume(volume);
}
