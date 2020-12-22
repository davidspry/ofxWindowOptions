# ofxWindowOptions

An add-on for [openFrameworks](https://github.com/openframeworks/openFrameworks) providing options for styling a macOS application window.

To use this add-on with openFrameworks:
  - Download the repository;
  - Move the contents of the repository to `{OF_ROOT}/addons/ofxWindowOptions/`;
  - Add ofxWindowOptions as an add-on to your project using the openFrameworks project generator.
  - Rename your project's `main.cpp` file to `main.mm` (or otherwise ensure that your IDE interprets it as an Objective-C++ file).

The `ofxWindowOptions` namespace is only defined in Objective-C for macOS targets.

## Usage

The provided methods should be called in `main` prior to running your application.

Each of the available functions is listed below.

```cpp
#include "ofxWindowOptions.h"

int main()
{
    ofSetupOpenGL(W, H, OF_WINDOW);
    
    ofxWindowOptions::setMovableByWindowBackground(true);
    ofxWindowOptions::setTitleBarVisibility(false);
    ofxWindowOptions::setResizable(true);
    
    ofRunApp(new ofApp());
}
```
