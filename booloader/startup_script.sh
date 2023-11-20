#!/bin/bash

# Enable Universal Asynchronous Receiver-Transmitter (UART)
BOOT_UART=1

# Power off the Raspberry Pi when halted (shutdown)
POWER_OFF_ON_HALT=1

# Raspberry Pi will attempt to boot in the specified order
BOOT_ORDER=0xf416

# Open Google Classroom in Chrome
chromium-browser https://classroom.google.com &

# You can add more lines for other applications or configurations

# End of script
