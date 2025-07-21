//Copyright 2025-Present riplin

#include <stdio.h>
#include <has/system/keyboard.h>

int main()
{
     using namespace Has::System;

     KB::InstallKeyboardHandler();

     volatile bool escapeReleased = false;

     KB::SetScanCodeHandler([&](KB::ScanCode_t scanCode)
     {
          if (scanCode == (KB::ScanCodeSet1::Escape | KB::ScanCodeSet1::Released))
               escapeReleased = true;
     });

     while (!escapeReleased)
     {

     }

     KB::RemoveKeyboardHandler();

     return 0;
}