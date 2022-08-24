#pragma once
#include <Arduino.h>
#include "Ecran.h"
class Program
{
public:
    Program();
    void loop();

private:
    Ecran *m_ecran;
    WifiFonction *m_wifiFonction;  

};