// ======================================================================
// \title  LED_Manager.cpp
// \author banana
// \brief  cpp file for LED_Manager component implementation class
// ======================================================================

#include "State_machine_workshop/Components/LED_Manager/LED_Manager.hpp"

namespace State_machine_workshop {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

LED_Manager ::LED_Manager(const char* const compName) : LED_ManagerComponentBase(compName) {}

LED_Manager ::~LED_Manager() {}

// ----------------------------------------------------------------------
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void LED_Manager ::schedIn_handler(FwIndexType portNum, U32 context) {
    // TODO
}

// ----------------------------------------------------------------------
// Implementations for internal state machine actions
// ----------------------------------------------------------------------

void LED_Manager ::State_machine_workshop_LED_States_action_ledOn(SmId smId,
                                                                  State_machine_workshop_LED_States::Signal signal) {
    // TODO
}

void LED_Manager ::State_machine_workshop_LED_States_action_ledOff(SmId smId,
                                                                   State_machine_workshop_LED_States::Signal signal) {
    // TODO
}

void LED_Manager ::State_machine_workshop_LED_States_action_ledBlink(SmId smId,
                                                                     State_machine_workshop_LED_States::Signal signal) {
    // TODO
}

}  // namespace State_machine_workshop
