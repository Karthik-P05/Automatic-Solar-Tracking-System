## 🌞 Automatic Solar Tracking System using Arduino
An efficient solar tracking system using Arduino UNO, LDRs, and servo motors, designed to rotate solar panels automatically to follow the sun throughout the day, maximizing energy capture.

##🚀 Features

- Dual LDR (Light Dependent Resistors) to detect sunlight intensity.

- Dual servo motors to rotate the panel based on light direction.

- Arduino UNO microcontroller as the system’s brain.

- Increases solar efficiency compared to static panels.

- Simple to build and deploy in real-world conditions.

## ⚙️ Components Used
- Arduino UNO
- 2× Servo Motors (SG90 or similar)
- 2× LDRs
- Resistors (10kΩ recommended)
- Breadboard & jumper wires
- Solar Panel (for final implementation)

## 🧠 How It Works

- LDR sensors placed on both sides of the panel detect light intensity.

- The Arduino compares the readings.

- If there's a significant difference, it moves the panel towards the brighter side using servo motors.

- This constant adjustment throughout the day ensures the panel receives maximum sunlight.

- At night or during uniform light, the system remains idle.

## 🔧 Arduino Code

### The main logic is handled in a simple Arduino sketch:

- Compares ldr1 and ldr2 analog readings.

- Adjusts servo motor angles based on which side receives more light.

- Includes tolerance to avoid unnecessary motor movements.

- Includes angle limit checks (0° to 180°).

## ✅ Benefits

- Improves solar efficiency without manual repositioning.

- Can be deployed in home, educational, or small-scale solar projects.

- Cost-effective and beginner-friendly.
  
