# Bulger-Alarm

This project involves building a security alarm system using hardware components and an Arduino board. The system utilizes sensors and output devices to monitor the environment, detect motion, and provide visual and audible alerts. The code provided interacts with sensors like the DHT11 Temperature and Humidity Sensor and the Passive Infrared (PIR) Sensor, as well as control components like LEDs, a buzzer, and an LCD. The system is designed to detect motion and potentially critical temperature levels, offering real-time alerts and display on an LCD screen.

## Components Used

- Arduino board
- DHT11 Temperature and Humidity Sensor
- PIR (Passive Infrared) Sensor
- LCD (Liquid Crystal Display)
- LEDs (Green and Red)
- Buzzer

## How to Use

1. Assemble the hardware components based on the pin configurations mentioned in the code comments.
2. Upload the provided code to the Arduino board using the Arduino IDE.
3. The system will commence monitoring temperature, humidity, and motion.

## Features

- Monitors ambient temperature and humidity using the DHT11 sensor.
- Detects human motion within its vicinity using the PIR sensor.
- Displays real-time temperature and motion status on the LCD.
- Triggers the green LED and buzzer when motion is detected.
- Activates the red LED and buzzer when the temperature exceeds a predetermined threshold (set at 30°C in this code).

## Notes

- Make sure to have the necessary libraries installed in the Arduino IDE for the DHT11 sensor and LCD control.
- Adjust the pin configurations in the code to match your specific hardware connections.
- This code serves for educational purposes and can be further expanded with additional features.

## Author

Mubeen Akhter
