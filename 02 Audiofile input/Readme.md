# 02. Audiofile input
Library to play wav, aiff and mp3 files through jack. Wav and aiff can be multichannel files.

01. Make it compile :-)
02. Try playing a few files. Figure out how to parse the filename you want to be played.


# Install
To use this code you need certain libraries installed on your computer.

- [Jack](http://jackaudio.org) is used for audio output.
- [mpg123](https://www.mpg123.de) is used for mp3 decoding

### OSX
To install Jack, go to [jackaudio.org/downloads/](http://jackaudio.org/downloads/) and install `jackOSX Version 0.92_b3`.

You need HomeBrew to install the MPG123 library. If you don't have it already, go to [brew.sh/index_nl](https://brew.sh/index_nl).  
Once you have homebrew:
``` BASH
brew install mpg123
```

### Windows
You're on your own

### Linux
Probably know yourself what you have to do. In case you don't:
``` BASH
sudo apt install jackd
sudo apt install libmpg123 libmpg123-dev
```
