#pragma once
#include "WifiFonction.h"

class Ecran
{
private:
WifiFonction *m_wifiFonction;
public:
//ctor
Ecran();
void loop(void);
void setup();
};