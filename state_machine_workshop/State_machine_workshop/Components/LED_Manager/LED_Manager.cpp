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
    
    Fw::Logic red_state;
    this->gpioRead_out(0, red_state);

    Fw::Logic yellow_state;
    this->gpioRead_out(1, yellow_state);

    Fw::Logic green_state;
    this->gpioRead_out(2, green_state);

    auto currentState = this->Led_State_Machine_getState();

    if (red_state == Fw::Logic::HIGH){
        this->Led_State_Machine_sendSignal_redButton();
    }
    else if (yellow_state == Fw::Logic::HIGH){
        this->Led_State_Machine_sendSignal_yellowButton();
    }
    else if (green_state == Fw::Logic::HIGH){
        this->Led_State_Machine_sendSignal_greenButton();
    }

    switch (currentState){
        case LED_StatesStateMachineBase::State::ON:
            this->gpioWrite_out(0, Fw::Logic::HIGH);
            m_ledOn = 1;
            break;
        case LED_StatesStateMachineBase::State::OFF:
            this->gpioWrite_out(0, Fw::Logic::LOW);
            m_ledOn = 0;
            break;
        case LED_StatesStateMachineBase::State::Blinking:
            m_count++;
            if (m_count > 4){
                m_count = 0;
                m_ledOn = (m_ledOn == 0) ? 1 : 0;
                
                if (m_ledOn == 0)
                    this->gpioWrite_out(0, Fw::Logic::LOW);
                else
                    this->gpioWrite_out(0, Fw::Logic::HIGH);
            }
            break;
    }
}

// ----------------------------------------------------------------------
// Implementations for internal state machine actions
// ----------------------------------------------------------------------

void LED_Manager ::State_machine_workshop_LED_States_action_ledOn(SmId smId,
                                                                  State_machine_workshop_LED_States::Signal signal) {
    this->log_ACTIVITY_HI_stateTransition(LED_TYPE::LED_ON);
}

void LED_Manager ::State_machine_workshop_LED_States_action_ledOff(SmId smId,
                                                                   State_machine_workshop_LED_States::Signal signal) {
    this->log_ACTIVITY_HI_stateTransition(LED_TYPE::LED_OFF);
}

void LED_Manager ::State_machine_workshop_LED_States_action_ledBlink(SmId smId,
                                                                     State_machine_workshop_LED_States::Signal signal) {
    this->log_ACTIVITY_HI_stateTransition(LED_TYPE::LED_BLINK);
    m_count = 0;
}

}  // namespace State_machine_workshop
