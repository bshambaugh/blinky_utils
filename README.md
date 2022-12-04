This is meant to test and build an ardunio library for the Blinky Project, but it needs to be refactored (possibly by changing extensions) so that the created .zip file works in the Ardunio IDE and also as an import to a Platform.io Project. Target Platform.io Project:
https://github.com/bshambaugh/BlinkyProject/blob/remoteSigner/edgeDevices/ESP32-testing/src/main.cpp

To create the zip archive file for use as a library, it should be:
sh build.sh

but fix the bug 1st

Thanks to https://www.youtube.com/watch?v=_xRv-3FWyLE&list=PLZBMwMmvlpnkWeNEl3LyE4qnK83wpjL-y for helping me make this happen.
