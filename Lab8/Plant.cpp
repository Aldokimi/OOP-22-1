#include "Plant.h"

Potatoe* Potatoe::m_instance = nullptr;

Potatoe* Potatoe::instance(){
    if(m_instance == nullptr) m_instance = new Potatoe();
    return m_instance;
}


Pea* Pea::m_instance = nullptr;
Pea* Pea::instance()
{
    if(nullptr==m_instance)m_instance = new Pea();
    return m_instance;
}

Onion* Onion::m_instance = nullptr;
Onion* Onion::instance()
{
    if(nullptr==m_instance) m_instance = new Onion();
    return m_instance;
}

Rose* Rose::m_instance = nullptr;
Rose* Rose::instance()
{
    if(nullptr==m_instance) m_instance = new Rose();
    return m_instance;
}

Carnation* Carnation::m_instance = nullptr;
Carnation* Carnation::instance()
{
    if(nullptr==m_instance) m_instance = new Carnation();
    return m_instance;
}

Tulip* Tulip::m_instance = nullptr;
Tulip* Tulip::instance()
{
    if(nullptr==m_instance) m_instance = new Tulip();
    return m_instance;
}
