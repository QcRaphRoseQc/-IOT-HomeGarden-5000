#include "Program.h"

Program::Program()
{
    Serial.begin(115200);
    this->m_ecran = new Ecran();
    this->m_ecran->setup();
}

void Program::loop()
{
    this->m_ecran->loop();
}
