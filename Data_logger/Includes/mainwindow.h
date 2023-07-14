#ifndef MAINWINDOW_H
# define MAINWINDOW_H

# include <QSoundEffect>
# include <QPainter>

# include "../ui_mainwindow.h"
# include "comport.hpp"
# include "windowchart.hpp"

# define MY_DEFINED_DEFAULT_ACTIVE_BUTTON   "QPushButton {border-radius: 5px; background: solid white;  color: black; border: 1px solid #0078D4; font-size: 14pt;} \
                                       QPushButton:hover {border-radius: 5px; background: #e0eef9;      color: black; border: 1px solid #0078D4; font-size: 14pt;}"
# define MY_DEFINED_DEFAULT_PASSIVE_BUTTON               "border-radius: 6px; background: #D3D3D3;      color: gray; border: 1px solid gray;"
# define MY_DEFINED_RELEASED_BUTTON         "QPushButton {border-radius: 5px; background: solid white;  color: black; border: 1px solid #0078D4; font-size: 14pt;} \
                                       QPushButton:hover {border-radius: 5px; background: #e0eef9;      color: black; border: 1px solid #0078D4; font-size: 14pt;}"
# define MY_DEFINED_PRESSED_BUTTON                       "border-radius: 6px; background: white;   color: blue;  border: 1px solid #0078D4;"
# define MY_DEFINED_DEFAULT_ACTIVE_TEXT     "font-size: 14px; padding: 0 5px; background: white;   color: blue;"
# define MY_DEFINED_DEFAULT_ACTIVE_TEXT2    "font-size: 14px; padding: 0 5px; background: white;   color: blue; selection-background-color: transparent;"
# define MY_DEFINED_DEFAULT_PASSIVE_TEXT    "font-size: 14px; padding: 0 5px; background: #D3D3D3; color: blue;"
# define MY_DEFINED_DEFAULT_PASSIVE_TEXT2   "font-size: 14px; padding: 0 5px; background: #D3D3D3; color: gray;"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class WindowNext;
class WindowChart;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        
    public:
        ComPort			*getSelectedComPort() const {return _selectedComPort;}

    private:
        void            putWindowOnScreen(int windowWidth, int windowHeight);
        QPushButton     *createButton(const QString &name, int x, int y, int width, \
                                      int height, std::function<void(void)> action, QWidget *box);
        void            addLoadingAnimation(QPushButton *button, int x, int y, int width, int height);
        void            createGroupBox(int x, int y, int width, int height);
        void            createLiftVertical(int x, int y, int width, int height);
        void            buttonCheckAction(void);
        void            buttonNextAction(void);
        void            buttonChartAction(void);
		void            buttonToolAction(ComPort *comPort);
        void            buttonSoundAction(void);
        void            buttonAboutAction(void);
        QString         getExecutableGrandparentDirPath(void);

    private:
        Ui::MainWindow      *ui;
        
        QPushButton         *_buttonCheck;
        QPushButton         *_buttonNext;
        QPushButton         *_buttonChart;
        QToolButton         *_buttonAbout;
        QToolButton         *_buttonSound;
        
        QLabel              *_gifLabel;
        QMovie              *_gifMovie;
        QLabel              *_connectedPortsText;
        QGroupBox           *_upperLine;
        QGroupBox           *_groupBox;
        QVector<ComPort*>   _comPorts;
        ComPort             *_selectedComPort;
        QScrollBar          *_liftVertical;
        
        QStringList         _baudRateItems;
        QStringList         _dataBitsItems;
        QStringList         _parityItems;
        QStringList         _stopBitsItems;
        QStringList         _flowControlItems;
        
        WindowNext          *_windowNext;
        WindowChart         *_windowChart;
        
        ComPort             *_previewsRadioButton;
        int                 _portCount;
        bool				_isRejected;
        QCheckBox			*_filesList;

        double              _volume;
        QSoundEffect        *_soundSelect;
        QSoundEffect        *_soundVolume;
        QSoundEffect        *_soundCheck;
        QSoundEffect        *_soundAbout;
        QSoundEffect        *_soundDefaultButton;
        QSoundEffect        *_soundTools;
};

#endif
