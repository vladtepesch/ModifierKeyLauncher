ModifierKeyLauncher
===================
This small Tool can be used to enhance the possibilities of the application keys of some keyboards.
It can be installed to start different applications depending on the modifier keys.

Revision History
----------------

- 2019-04-06 V 1.2
  - bugfix to prevent calling itself over and over again if called without parameters
- 2019-04-05 V 1.1
  - release on github
- 2015-06-23 V 1.0
  - initial Release


Explanation
-----------

The application that is mapped to this application keys can be controlled via the subkeys of the following registry key:  
`HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\AppKey`  
and the therein lying `ShellExecute` string value.

e.g. the calculator key is the following:
    
    HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\AppKey\18

    
    
following Mappings i took from here: http://ashish.vashisht.net/2008/01/configuring-keyboard-multimedia-keys.html

    AppKey#  Name                                          Description
    ======================================================================================================
     1       APPCOMMAND_BROWSER_BACKWARD                   Navigate backward.
     2       APPCOMMAND_BROWSER_FORWARD                    Navigate forward.
     3       APPCOMMAND_BROWSER_REFRESH                    Refresh page.
     4       APPCOMMAND_BROWSER_STOP                       Stop download.
     5       APPCOMMAND_BROWSER_SEARCH                     Open search.
     6       APPCOMMAND_BROWSER_FAVORITES                  Open favorites.
     7       APPCOMMAND_BROWSER_HOME                       Navigate home.
     8       APPCOMMAND_VOLUME_MUTE                        Mute the volume.
     9       APPCOMMAND_VOLUME_DOWN                        Lower the volume.
    10       APPCOMMAND_VOLUME_UP                          Raise the volume.
    11       APPCOMMAND_MEDIA_NEXTTRACK                    Go to next track.
    12       APPCOMMAND_MEDIA_PREVIOUSTRACK                Go to previous track.
    13       APPCOMMAND_MEDIA_STOP                         Stop playback.
    14       APPCOMMAND_MEDIA_PLAY_PAUSE                   Play or pause playback.
    15       APPCOMMAND_LAUNCH_MAIL                        Open mail.
    16       APPCOMMAND_LAUNCH_MEDIA_SELECT                Go to Media Select mode. (launch media player)
    17       APPCOMMAND_LAUNCH_APP1                        Start App1. (open Explorer at "My Computer")
    18       APPCOMMAND_LAUNCH_APP2                        Start App2. (open calulator)
    19       APPCOMMAND_BASS_DOWN                          Decrease the bass.
    20       APPCOMMAND_BASS_BOOST                         Toggle the bass boost on and off.
    21       APPCOMMAND_BASS_UP                            Increase the bass.
    22       APPCOMMAND_TREBLE_DOWN                        Decrease the treble.
    23       APPCOMMAND_TREBLE_UP                          Increase the treble.
    24       APPCOMMAND_MICROPHONE_VOLUME_MUTE             Mute the microphone.
    25       APPCOMMAND_MICROPHONE_VOLUME_DOWN             Increase microphone volume.
    26       APPCOMMAND_MICROPHONE_VOLUME_UP               Decrease microphone volume.
    27       APPCOMMAND_HELP                               Open the Help dialog.
    28       APPCOMMAND_FIND                               Open the Find dialog.
    29       APPCOMMAND_NEW                                Create a new window.
    30       APPCOMMAND_OPEN                               Open a window.
    31       APPCOMMAND_CLOSE                              Close the window (not the application).
    32       APPCOMMAND_SAVE                               Save current document.
    33       APPCOMMAND_PRINT                              Print current document.
    34       APPCOMMAND_UNDO                               Undo last action.
    35       APPCOMMAND_COPY                               Copy the selection.
    35       APPCOMMAND_REDO                               Redo last action.
    37       APPCOMMAND_CUT                                Cut the selection.
    38       APPCOMMAND_PASTE                              Paste
    39       APPCOMMAND_REPLY_TO_MAIL                      Reply to a mail message.
    40       APPCOMMAND_FORWARD_MAIL                       Forward a mail message.
    41       APPCOMMAND_SEND_MAIL                          Send a mail message.
    42       APPCOMMAND_SPELL_CHECK                        Initiate a spell check.
    43       APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE  Toggles between two modes of speech input: dictation and command/control (giving commands to an application or accessing menus).
    44       APPCOMMAND_MIC_ON_OFF_TOGGLE                  Toggle the microphone.
    45       APPCOMMAND_CORRECTION_LIST                    Brings up the correction list when a word is incorrectly identified during speech input.


The `ShellExecute` string value specifies the application that will be called when this key is pressed.

This is the step there this little program kicks in. 
It is a small dispatcher that decides which program to call depending of the state of the modifier keys on the keyboard.

command line syntax is the following:

    PathToTool\ModifierKeyLauncher.exe "normal\Program\path" "shift\Program\path" "cntrl\Program\path" "alt\Program\path"

The program reads the key states and starts the program (or opens the document/file)


### Example: 
choose between different calculators:

- open regedit
- create (if not exist) a key  
  `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\AppKey\18`
- create a string value `ShellExecut` 
- set the value to:  
 `c:\PathToTool\ModifierKeyLauncher.exe  "C:\somePath\Microsoft Calculator Plus\CalcPlus.exe" "calc.exe" "C:\somePath\SpeedCrunch.exe" `


