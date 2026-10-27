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
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command TODO
    //!
    //! TODO
    void TODO_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                         U32 cmdSeq            //!< The command sequence number
                         ) override;
};

}  // namespace State_machine_workshop

#endif
