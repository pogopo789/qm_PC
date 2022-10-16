#include <qpcpp.hpp>
#include "bsp.h"
#include "Sensors.h"
#include "Monitor.h"
#include <iostream>

using namespace QP;

void setup(){
    
    QF::init();  // initialize the framework
    BSP::init(); // initialize the BSP

    static QF_MPOOL_EL(SensorsEvt) smlPoolSto[10];
    static QP::QSubscrList subscrSto[MAX_PUB_SIG];
    QP::QActive::psInit(subscrSto, Q_DIM(subscrSto));
    QP::QF::poolInit(smlPoolSto, sizeof(smlPoolSto), sizeof(smlPoolSto[0]));

    static QEvt const *monitor_queueSto[10]; // event queue buffer for Monitor
    Monitor::instance.start(2U,monitor_queueSto,Q_DIM(monitor_queueSto),(void *)0, 0U);

    static QEvt const *sensors_queueSto[10]; // event queue buffer for Sensors
    Sensors::instance.start(1U,sensors_queueSto,Q_DIM(sensors_queueSto),(void *)0, 0U);

}

// void loop(){
// }

int main()
{
    setup();
    return QF::run();
}