//$file${./include::bsp.cpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: model.qm
// File:  ${./include::bsp.cpp}
//
// This code has been generated by QM 5.2.1 <www.state-machine.com/qm>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// This generated code is open source software: you can redistribute it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation.
//
// This code is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// NOTE:
// Alternatively, this generated code may be distributed under the terms
// of Quantum Leaps commercial licenses, which expressly supersede the GNU
// General Public License and are specifically designed for licensees
// interested in retaining the proprietary status of their code.
//
// Contact information:
// <www.state-machine.com/licensing>
// <info@state-machine.com>
//
//$endhead${./include::bsp.cpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include "qpcpp.hpp"  // QP/C++ framework API
#include "bsp.h"    // Board Support Package interface
#include "Sensors.h"
#include "Monitor.h"
#include <iostream>   // for cout/cerr
#include <cstdlib>    // for exit()
#include <chrono>

using namespace std;
using namespace QP;

void BSP::init(void)   {
    cout << "Simple Blinky example\nQP/C++ version: "
         << QP_VERSION_STR
         << "\nPress Ctrl-C to quit..."
         << endl; // print QP version
}

// callback functions needed by the framework --------------------------------
void QF::onStartup(void) {}
void QF::onCleanup(void) {}
void QF::onClockTick(void) {
    QTimeEvt::TICK_X(0U, nullptr);  // perform the QF clock tick processing
}
void Q_onAssert(char const * const module, int loc) {
    cerr << "Assertion failed in " <<  module << ":" << loc << endl;
    exit(-1);
}

//$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// Check for the minimum required QP version
#if (QP_VERSION < 690U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpcpp version 6.9.0 or higher required
#endif
//$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${Evts} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${Evts::AO_Monitor} ........................................................
QP::QActive * const AO_Monitor = &Monitor::instance;

//${Evts::AO_Sensors} ........................................................
QP::QActive * const AO_Sensors = &Sensors::instance;
//$enddef${Evts} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
