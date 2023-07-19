#ifndef SOUND_HPP
#define SOUND_HPP

# include <QObject>
# include <QSoundEffect>

class Sound : public QObject
{
        Q_OBJECT
    public:
        Sound(QObject *parent, double volume);
        ~Sound();

        void setVolume(double volume);

    public:
        QSoundEffect    *_soundSelect;
        QSoundEffect    *_soundVolume;
        QSoundEffect    *_soundCheck;
        QSoundEffect    *_soundAbout;
        QSoundEffect    *_soundDefaultButton;
        QSoundEffect    *_soundTools;
        QSoundEffect    *_soundCheckBox;
        QSoundEffect    *_soundTestMode;
        QSoundEffect    *_soundInvalidDuration;
};

#endif
