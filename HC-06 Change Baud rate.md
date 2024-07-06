# Changing Baud Rate of HC-06 Bluetooth Module on macOS

This guide explains how to change the baud rate of an HC-06 Bluetooth module using a USB-to-serial adapter on macOS.

## Requirements
1. HC-06 Bluetooth module
2. USB-to-serial adapter
3. macOS computer
4. Terminal program (using built-in `screen` command)

## Step-by-Step Instructions

### 1. Connect the HC-06 Module to Your USB-to-Serial Adapter
- **VCC**: Connect to 3.3V or 5V power supply (depending on your module specifications)
- **GND**: Connect to ground
- **TX**: Connect to RX pin of your USB-to-serial adapter
- **RX**: Connect to TX pin of your USB-to-serial adapter

### 2. Identify the Serial Port
Open Terminal and list the available serial ports:
```sh
ls /dev/tty.*
```
Identify your USB-to-serial adapter device. It will be something like `/dev/tty.usbserial-XXXXXX`.

### 3. Open a Serial Connection Using `screen`
Open the serial connection with the default baud rate of the HC-06 (commonly 9600):
```sh
screen /dev/tty.usbserial-XXXXXX 9600
```
Replace `/dev/tty.usbserial-XXXXXX` with the actual device name of your USB-to-serial adapter.

### 4. Enter AT Command Mode
Type `AT` and press Enter. You should receive an `OK` response indicating the module is in AT command mode.

### 5. Change the Baud Rate
To change the baud rate, use the following command:
```sh
AT+BAUD8
```
This sets the baud rate to 115200. You should receive an `OK115200` response.

### 6. Verify the Change
Exit the `screen` session by pressing `Ctrl+A` followed by `K` and then `Y` to confirm.

### 7. Reconnect at the New Baud Rate
Open a new `screen` session with the new baud rate:
```sh
screen /dev/tty.usbserial-XXXXXX 115200
```
Verify that you can communicate with the HC-06 at the new baud rate by typing `AT` and pressing Enter. You should see `OK`.
