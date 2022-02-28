<!-- Text Tables: Enable - enable extension.
Text Tables: Create table - create new table in cursor position.
Text Tables: Format under cursor - reformat the table under cursor.
Text Tables: Enter table mode - enter table mode.
Text Tables: Exit table mode - exit table mode.
Text Tables: Go to next cell - switch to next cell in current table.
Text Tables: Go to previous cell - switch to previous cell in current table.
Text Tables: Clear cell - clear cell under cursor. -->

# 8-bit Timer/Counter Register Description
# Timer/Counter Control Register
# TCCR0

| Bit            | 7  | 6  | 5  | 4  | 3  | 2    | 1    | 0    |
| Register TCCR0 | NA | NA | NA | NA | NA | CS02 | CS01 | CS00 |
| Read/Write     | R  | R  | R  | R  | R  | R/W  | R/W  | R/W  |
| Initial Value  | 0  | 0  | 0  | 0  | 0  | 0    | 0    | 0    |

Clock Select Bit Description:
If external pin modes are used for the Timer/Counter0, transitions on the T0 pin will clock the
counter even if the pin is configured as an output. This feature allows software control of the
counting.

| CS02 | CS01 | CS00 | Description                                            |
| 0    | 0    | 0    | No clock source (Timer/Counter stopped)                |
| 0    | 0    | 1    | clkI/O/(No prescaling)                                 |
| 0    | 1    | 0    | clkI/O/8 (From prescaler)                              |
| 0    | 1    | 1    | clkI/O/64 (From prescaler)                             |
| 1    | 0    | 0    | clkI/O/256 (From prescaler)                            |
| 1    | 0    | 1    | clkI/O/1024 (From prescaler)                           |
| 1    | 1    | 0    | External clock source on T0 pin. Clock on falling edge |
| 1    | 1    | 1    | External clock source on T0 pin. Clock on rising edge  |


# Timer/Counter Register
# The Timer/Counter Register gives direct access, both for read and write operations, to the
# Timer/Counter unit 8-bit counter.
# TCNT0

| Bit           | 7   | 6   | 5   | 4   | 3   | 2   | 1   | 0   |
| Read/Write    | R/W | R/W | R/W | R/W | R/W | R/W | R/W | R/W |
| Initial Value | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |


# Timer/Counter Interrupt Mask Register
# TIMSK

| Bit           | 7     | 6     | 5      | 4      | 3      | 2     | 1   | 0     |
| TIMSK         | OCIE2 | TOIE2 | TICIE1 | OCIE1A | OCIE1B | TOIE1 | –   | TOIE0 |
| Read/Write    | R/W   | R/W   | R/W    | R/W    | R/W    | R/W   | R/W | R/W   |
| Initial Value | 0     | 0     | 0      | 0      | 0      | 0     | 0   | 0     |


# Timer/Counter Interrupt Flag
# TIFR

| Bit           | 7     | 6     | 5      | 4      | 3      | 2     | 1   | 0     |
| TIFR          | OCF2  | TOV2  | ICF1   | OCF1A  | OCF1B  | TOV1  | –   | TOV0  |
| Read/Write    | R/W   | R/W   | R/W    | R/W    | R/W    | R/W   | R/W | R/W   |
| Initial Value | 0     | 0     | 0      | 0      | 0      | 0     | 0   | 0     |

# Special Function IO Register
# SFIOR

| Bit        | 7 | 6 | 5 | 4 | 3    | 2   | 1    | 0     |     |
| SFIOR      | – | – | – | – | ACME | PUD | PSR2 | PSR10 |     |
| Read/Write | R | R | R | R | R/W  | R/W | R/W  | R/W   | R/W |


######################################################################################################
######################################################################################################


# 16-bit Timer/Counter1
# Timer/Counter 1 Control Register A
# TCCR1A

| Bit        | 7      | 6      | 5      | 4      | 3     | 2     | 1     | 0     |
| TCCR1A     | COM1A1 | COM1A0 | COM1B1 | COM1B0 | FOC1A | FOC1B | WGM11 | WGM10 |
| Read/Write | R/W    | R/W    | R/W    | R/W    | W     | W     | R/W   | R/W   |
| Initial    | 0      | 0      | 0      | 0      | 0     | 0     | 0     | 0     |

# Compare Output Mode, Non-PWM

| COM1A1/COM1B1 | COM1A0/COM1B0 | Description                                                |
| 0             | 0             | Normal port operation, OC1A/OC1B disconnected.             |
| 0             | 1             | Toggle OC1A/OC1B on Compare Match                          |
| 1             | 0             | Clear OC1A/OC1B on Compare Match (Set output to low level) |
| 1             | 1             | Set OC1A/OC1B on Compare Match (Set output to high level)  |

# Compare Output Mode, Fast PWM

| COM1A1/COM1B1 | COM1A0/COM1B0 | Description                                                                     |
| 0             | 0             | Normal port operation, OC1A/OC1B disconnected.                                  |
| 0             | 1             | WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B                                |
|               |               | disconnected (normal port operation). For all other WGM1                        |
|               |               | settings, normal port operation, OC1A/OC1B disconnected.                        |
| 1             | 0             | Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM, (non-inverting mode) |
| 1             | 1             | Set OC1A/OC1B on Compare Match, clear OC1A/OC1B at BOTTOM, (inverting mode)     |


# Compare Output Mode, Phase and Frequency Correct PWM

| COM1A1/COM1B1 | COM1A0/COM1B0 | Description                                              |
| 0             | 0             | Normal port operation, OC1A/OC1B disconnected.           |
| 0             | 1             | WGM13:0 = 9 or 14: Toggle OC1A on Compare Match, OC1B    |
|               |               | disconnected (normal port operation). For all other WGM1 |
|               |               | settings, normal port operation, OC1A/OC1B disconnected. |
| 1             | 0             | Clear OC1A/OC1B on Compare Match when up-counting. Set   |
|               |               | OC1A/OC1B on Compare Match when downcounting.            |
| 1             | 1             | Set OC1A/OC1B on Compare Match when up-counting. Clear   |
|               |               | OC1A/OC1B on Compare Match when downcounting.            |


# Waveform Generation Mode Bit Description

| Mode | WGM13 | WGM12 (CTC1) | WGM11 (PWM11) | WGM10 (PWM10) | Timer/Counter Mode ofOperation(1) | TOP    | Update of OCR1x | TOV1 Flag Set on |
| 0    | 0     | 0            | 0             | 0             | Normal                            | 0xFFFF | Immediate       | MAX              |
| 1    | 0     | 0            | 0             | 1             | PWM, Phase Correct, 8-bit         | 0x00FF | TOP             | BOTTOM           |
| 2    | 0     | 0            | 1             | 0             | PWM, Phase Correct, 9-bit         | 0x01FF | TOP             | BOTTOM           |
| 3    | 0     | 0            | 1             | 1             | PWM, Phase Correct, 10-bit        | 0x03FF | TOP             | BOTTOM           |
| 4    | 0     | 1            | 0             | 0             | CTC                               | OCR1A  | Immediate       | MAX              |
| 5    | 0     | 1            | 0             | 1             | Fast PWM, 8-bit                   | 0x00FF | BOTTOM          | TOP              |
| 6    | 0     | 1            | 1             | 0             | Fast PWM, 9-bit                   | 0x01FF | BOTTOM          | TOP              |