# Heat Extinguisher Bot

This project is a heat extinguisher bot that detects fire and gas leaks and activates a water pump and alert system when a fire or hazardous gas level is detected. The bot is equipped with multiple flame sensors, a gas sensor, a servo motor to direct water flow, and a GSM module to send SMS alerts.

## Features

- Detects fire using three flame sensors.
- Monitors gas levels using an MQ2 gas sensor.
- Activates a water pump to extinguish fire upon detection.
- Sends an SMS alert when a fire or gas leak is detected using a GSM module.
- Controls a robot movement system with a motor driver.

## Components

- **Arduino Uno** or any compatible microcontroller
- **GSM Module** (e.g., SIM800L)
- **Flame Sensors** (x3)
- **MQ2 Gas Sensor**
- **Servo Motor**
- **Water Pump and Relay Module**
- **Motor Driver** (e.g., L298N) for controlling movement
- **Jumper Wires** for connections

## Pin Configuration

| Component         | Arduino Pin |
|-------------------|-------------|
| Flame Sensor 1    | 2           |
| Flame Sensor 2    | 3           |
| Flame Sensor 3    | 4           |
| Gas Sensor (MQ2)  | A0          |
| Water Pump Relay  | 5           |
| Motor Driver Pin1 | 6           |
| Motor Driver Pin2 | 7           |
| Motor Driver Pin3 | 8           |
| Motor Driver Pin4 | 9           |
| Servo Motor       | 10          |
| GSM Module RX     | 11          |
| GSM Module TX     | 12          |

## Code Overview

1. **Sensor Initialization**: Initializes flame sensors and gas sensor to detect fire or gas leaks.
2. **Servo and Water Pump Control**: Activates the water pump and directs the water nozzle using the servo motor when fire is detected.
3. **SMS Alert**: Uses the GSM module to send an SMS alert if fire or gas leaks are detected.
4. **Robot Movement**: Controls the movement of the robot using motor driver pins.

## Usage

1. **Install Arduino IDE**:
   - Download and install the Arduino IDE from [Arduino's website](https://www.arduino.cc/en/software).

2. **Add Code to Arduino IDE**:
   - Copy the code from the project file and paste it into a new Arduino sketch.

3. **Select the Board and Port**:
   - Go to **Tools > Board** and select your Arduino model.
   - Go to **Tools > Port** and select the correct port for your Arduino.

4. **Upload the Code**:
   - Click on the **Upload** button to compile and upload the code to the Arduino board.

5. **Test the Bot**:
   - Monitor the Serial Monitor to see if fire or gas leaks are detected.
   - When fire is detected, the water pump should activate, and an SMS should be sent using the GSM module.

## Dependencies

- **SoftwareSerial** library: Included with Arduino IDE for GSM communication.
- **Servo** library: Included with Arduino IDE for controlling the servo motor.

## Example Output

On detecting fire:
```
Fire Detected!
Water pump activated.
SMS Alert Sent: "Fire detected! Water pump activated."
```

On detecting gas leak:
```
Gas Leak Detected!
SMS Alert Sent: "Gas leak detected! Take necessary action."
```

## License

This project is open-source and available under the MIT License. Feel free to modify and use it for personal and educational purposes.
