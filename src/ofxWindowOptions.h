//  ofxStyledWindow
//  Created by David Spry on 19/12/20.

#ifdef  __OBJC__
#ifdef  TARGET_OSX
#ifndef OFXWINDOWOPTIONS_H
#define OFXWINDOWOPTIONS_H

#include "ofMain.h"
#include <Cocoa/Cocoa.h>

/// @brief A set of window options to be used with openFrameworks on macOS.

namespace ofxWindowOptions
{

/// @brief Get a pointer to the current `NSWindow` window.

static inline NSWindow* getNSWindow()
{
    return static_cast<NSWindow*>(ofGetCocoaWindow());
}

/// @brief Set whether the window should be resizable by the user or not.
/// @param isResizable Whether the window should be resizable by the user or not.

static void setResizable(const bool isResizable)
{
    NSWindow* window = getNSWindow();

    if (isResizable)
         window.styleMask = window.styleMask |  NSWindowStyleMaskResizable;
    else window.styleMask = window.styleMask & ~NSWindowStyleMaskResizable;
}

/// @brief Set whether the window can be moved by dragging on the window's background.
/// @param isMovable Whether the window should be moved when the user drags on the window's background.

static inline void setMovableByWindowBackground(const bool isMovable)
{
    NSWindow* window = getNSWindow();
    
    [window setOpaque:!isMovable];
    [window setMovableByWindowBackground:isMovable];
    [window setBackgroundColor:NSColor.whiteColor];
}

/// @brief Show or hide the window's title bar (including the buttons).
/// @param isVisible Whether the window's title bar should be visible or not.

static void setTitleBarVisibility(const bool isVisible)
{
    NSWindow* window = getNSWindow();

    window.styleMask |= NSWindowStyleMaskTitled;
    window.styleMask |= NSFullSizeContentViewWindowMask;
    
    if (isVisible)
    {
        window.styleMask |= NSWindowStyleMaskClosable;
        window.styleMask |= NSWindowStyleMaskMiniaturizable;
    }

    else
    {
        window.styleMask &= ~NSWindowStyleMaskClosable;
        window.styleMask &= ~NSWindowStyleMaskMiniaturizable;
    }

    [window setShowsToolbarButton:isVisible];
    [window setTitlebarAppearsTransparent:!isVisible];
    [window setTitleVisibility:NSWindowTitleVisible];
    [window standardWindowButton:NSWindowFullScreenButton].hidden  = !isVisible;
    [window standardWindowButton:NSWindowMiniaturizeButton].hidden = !isVisible;
    [window standardWindowButton:NSWindowCloseButton].hidden = !isVisible;
    [window standardWindowButton:NSWindowZoomButton].hidden  = !isVisible;
    [window makeKeyWindow];
}

}

#endif
#endif
#endif
