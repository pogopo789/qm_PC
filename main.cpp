#include <qpcpp.hpp>
#include "bsp.h"
#include "Sensors.h"

using namespace QP;

void setup(){
    QF::init();  // initialize the framework
    BSP::init(); // initialize the BSP

    static QEvt const *sensors_queueSto[10]; // event queue buffer for Sensors
    Sensors_ptr->start(1U,sensors_queueSto,Q_DIM(sensors_queueSto),(void *)0, 0U);
}

void loop(){
    QF::run();
}

int main()
{
    setup();
    for(;;){
        
        loop();
    }
    return 0;
}