# State_machine_workshop::LED_Manager
Manager to handle led state machine to control whether led is on, off, or blinking.

## Introduction

This is a queued component that handles a state machine for managing a led on, off, and blinking state.

## Requirements

| Name | Description | Rationale | Validation |
|---|---|---|---|
|   |   |   |   |

## Design

### Commands


### Events

- Event stateTransition will report whenever the state of the led is changed.

### Telemetry

- Telemetry ledState will report whether the led is currently on or off.

### Port

- Port tick will be connected to the rate group for 10Hz to check button presses.

## Configuration

<!-- If the component requires configuration at initialization, document here -->
