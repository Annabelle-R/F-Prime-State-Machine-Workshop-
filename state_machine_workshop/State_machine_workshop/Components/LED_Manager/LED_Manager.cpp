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
// Handler implementations for commands
// ----------------------------------------------------------------------

void LED_Manager ::TODO_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace State_machine_workshop
