// ======================================================================
// \title  LED_Manager.hpp
// \author banana
// \brief  hpp file for LED_Manager component implementation class
// ======================================================================

#ifndef State_machine_workshop_LED_Manager_HPP
#define State_machine_workshop_LED_Manager_HPP

#include "State_machine_workshop/Components/LED_Manager/LED_ManagerComponentAc.hpp"

namespace State_machine_workshop {

class LED_Manager final : public LED_ManagerComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct LED_Manager object
    LED_Manager(const char* const compName  //!< The component name
    );

    //! Destroy LED_Manager object
    ~LED_Manager();

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for typed input ports
    // ----------------------------------------------------------------------

    U32 m_count = 0;
    U32 m_ledOn = 0;

    //! Handler implementation for schedIn
    void schedIn_handler(FwIndexType portNum,  //!< The port number
                         U32 context           //!< The call order
                         ) override;

    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command RED
    void RED_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                        U32 cmdSeq            //!< The command sequence number
                        ) override;

    //! Handler implementation for command GREEN
    void GREEN_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                          U32 cmdSeq            //!< The command sequence number
                          ) override;

    //! Handler implementation for command YELLOW
    void YELLOW_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                           U32 cmdSeq            //!< The command sequence number
                           ) override;

  private:
    // ----------------------------------------------------------------------
    // Implementations for internal state machine actions
    // ----------------------------------------------------------------------

    //! Implementation for action ledOn of state machine State_machine_workshop_LED_States
    void State_machine_workshop_LED_States_action_ledOn(
        SmId smId,                                        //!< The state machine id
        State_machine_workshop_LED_States::Signal signal  //!< The signal
        ) override;

    //! Implementation for action ledOff of state machine State_machine_workshop_LED_States
    void State_machine_workshop_LED_States_action_ledOff(
        SmId smId,                                        //!< The state machine id
        State_machine_workshop_LED_States::Signal signal  //!< The signal
        ) override;

    //! Implementation for action ledBlink of state machine State_machine_workshop_LED_States
    void State_machine_workshop_LED_States_action_ledBlink(
        SmId smId,                                        //!< The state machine id
        State_machine_workshop_LED_States::Signal signal  //!< The signal
        ) override;
};

}  // namespace State_machine_workshop

#endif
