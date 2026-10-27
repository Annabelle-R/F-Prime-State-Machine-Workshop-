module State_machine_workshop {
    @ led manager
    queued component LED_Manager {
        state machine instance Led_State_Machine: LED_States

        event stateTransition($state: LED_TYPE) \
            severity activity high \
            format "Changed LED state to {}"

        telemetry ledState: Fw.On

        sync input port schedIn: Svc.Sched

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Enables command handling
        import Fw.Command

        @ Enables event handling
        import Fw.Event

        @ Enables telemetry channels handling
        import Fw.Channel

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }

    state machine LED_States {
        signal redButton 
        signal yellowButton
        signal greenButton
        signal tick

        action ledOn
        action ledOff
        action ledBlink

        initial enter OFF

        state ON {
            on redButton do { ledOff } enter OFF
            on yellowButton do { ledBlink } enter Blinking

        }

        state OFF {
            on yellowButton do { ledBlink } enter Blinking
            on greenButton do {ledOn} enter ON

        }

        state Blinking {
            on redButton do { ledOff } enter OFF
            on greenButton do {ledOn} enter ON

        }
    }

}