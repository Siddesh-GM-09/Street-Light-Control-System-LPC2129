# 🌉 Street Light Control System – LPC2129

![Platform](https://img.shields.io/badge/Platform-ARM7%20LPC2129-blue)
![Language](https://img.shields.io/badge/Language-Embedded%20C-green)
![ADC](https://img.shields.io/badge/ADC-MCP3204-orange)
![Interface](https://img.shields.io/badge/Interface-SPI-yellow)
![Sensor](https://img.shields.io/badge/Sensor-LDR-lightgrey)
![Status](https://img.shields.io/badge/Project-Completed-success)

---

## 📌 Project Overview
An **automatic street light control system** using **LPC2129 (ARM7)**, **LDR**, and **MCP3204 ADC**.  
The system continuously monitors ambient light intensity and automatically turns the street light **ON/OFF** to reduce power consumption.  
This project is implemented in **Embedded C** and tested in real-time using sensor input.

---

## 🖼️ Project Screenshot
![Project Simulation](https://i.ibb.co/YFCV3gZn/Screenshot-2026-02-04-100115.png)

---

## 🧰 Hardware Used
- LPC2129 (ARM7 Microcontroller)
- MCP3204 (12-bit SPI ADC)
- LDR (Light Dependent Resistor)
- 16x2 LCD (LM016L)
- LED (Street Light Indicator)
- Power Supply (3.3V)

> 🔹 **Note:**  
> The project is tested with **1 street light**, but the same logic can be extended to **multiple street lights** by adding more output control pins.

---

## 🧩 Software & Tools
- Embedded C
- Keil µVision IDE
- Proteus (Simulation)
- UART Terminal (Debugging)

---

## ⚙️ Working Logic
1. LDR senses the ambient light intensity.
2. Analog value from LDR is converted to digital using **MCP3204 ADC** via **SPI**.
3. LPC2129 reads the sensor value and compares it with a predefined threshold.
4. **Decision Logic:**
   - If **sensor value < 50%** → **Street Light ON**
   - If **sensor value ≥ 50%** → **Street Light OFF**
5. Light status is displayed on the LCD.
6. The LED acts as the street light output.

---

## 🧪 Real-Time Testing
- The system was tested by **varying light on the LDR**.
- Increasing light intensity → Street light turns **OFF**
- Decreasing light intensity → Street light turns **ON**

---

## 📂 Project Structure
```
STREET_LIGHT_CONTROL/
├── main.c
├── header.h
├── spi_driver.c
├── mcp3204_driver.c
├── sensors.c
├── lcd4bit_driver.c
├── uart0_driver.c
├── delay.c
├── Startup.s
├── project.uvproj
├── README.md
```

---

## 🎯 Key Learning Outcomes
- SPI communication with external ADC
- Sensor interfacing (LDR)
- Threshold-based decision making
- ARM7 GPIO control
- Embedded system modular design
- Real-time testing & debugging

---

## 🚀 How to Run
1. Open the project in **Keil µVision**.
2. Build the project and generate the HEX file.
3. Load the HEX file into **Proteus**.
4. Adjust light intensity on the LDR.
5. Observe LED and LCD output.

---

## 👤 Author
**Siddesh G M**  
Embedded Systems Fresher  
ARM7 | Embedded C | SPI | ADC
