# Smart-Environmental-Monitor-for-Nuclear-Payload
Arduino-based project designed to detect changes in Temperature, infrared radation, acceleration, gyroscopic motion, and tampering. Made for the Canadian Nuclear Laboratories Hackathon.
## Features
The Monitor has two toggle able modes, storage and transport.
### Storage mode
- Detects changes in sound and lets off auditory and visual signals
- Has more sensitive motion detection
- Increased IR detection threshold

### Transport mode
- Detects a wider range of acceptable acceleration values
- Has crash detection that triggers when there is a large spike in acceleration
- Has fall detection and roll detection
- Has a larger acceptable IR value due to transportation noise
- Sends auditory and visual signals when any component detects unsafe conditions

## Components 
- Arduino UNO
- Photoresistor
- Accelerometer/gyroscope(DFRobot BMX160 9-Axis IMU)
- Buzzer(Grove)
- 3x LEDs
- Sound Sensor(Grove)
- Button

  ## Prototype of Minitor
![Prototype of monitor](https://github.com/Harry-670/Smart-Environmental-Monitor-for-Nuclear-Payload/blob/2bd5d6260d09492e46ec2a910e50e01c34c7e215/CNL_Hackathon.jpg)
