# RFID-Based Attendance System Using RTC Module

An Arduino-based RFID attendance management system that automatically records attendance using RFID card authentication and timestamps each attendance entry using a DS1307 Real-Time Clock (RTC) module.

---

## 📖 Overview

This project is designed to automate the attendance recording process in educational institutions and workplaces. The system identifies users through RFID cards and records attendance along with the current date and time obtained from the RTC module.

The project is developed using Arduino Uno and simulated using Proteus ISIS Professional.

---

## ✨ Features

- RFID-based user authentication
- Automatic attendance recording
- Real-time date and time stamping
- LCD status display
- Audio indication using buzzer
- Visual indication using LEDs
- Low-cost embedded solution
- Proteus simulation support

---

## 🛠 Hardware Components

| Component | Quantity |
|------------|-----------|
| Arduino Uno | 1 |
| EM-18 RFID Reader | 1 |
| RFID Tags/Cards | 2+ |
| DS1307 RTC Module | 1 |
| 16×2 LCD Display | 1 |
| Green LED | 1 |
| Red LED | 1 |
| Buzzer | 1 |
| Potentiometer | 1 |
| Crystal Oscillator | 1 |
| Battery | 1 |

---

## 💻 Software Requirements

- Arduino IDE
- Proteus ISIS Professional
- RTClib Library
- LiquidCrystal Library
- Wire Library
- SoftwareSerial Library

---

## 🔌 Circuit Connections

### RTC Module

| DS1307 | Arduino |
|---------|----------|
| SDA | A4 |
| SCL | A5 |
| VCC | 5V |
| GND | GND |

### LCD Display

| LCD | Arduino |
|------|----------|
| RS | D7 |
| EN | D6 |
| D4 | D5 |
| D5 | D4 |
| D6 | D9 |
| D7 | D8 |

### Indicators

| Device | Arduino |
|----------|----------|
| Green LED | A0 |
| Red LED | A1 |
| Buzzer | A2 |

### RFID Reader

| EM-18 | Arduino |
|---------|----------|
| TX | D2 |
| VCC | 5V |
| GND | GND |

---

## ⚙️ Working Principle

1. User scans RFID card.
2. RFID reader reads the UID.
3. Arduino receives the UID through serial communication.
4. UID is compared with stored authorized IDs.
5. DS1307 RTC provides current date and time.
6. Attendance is marked for valid users.
7. LCD displays attendance confirmation.
8. Green LED and buzzer indicate successful attendance.
9. Invalid cards trigger the red LED and an access denied message.

---

## 🖥 Proteus Simulation

Since Proteus does not provide a standard EM-18 RFID module, RFID card data is simulated using a Virtual Terminal.

### Simulation Flow

RFID UID → Virtual Terminal → Arduino Uno → RTC → LCD → Attendance Record

---

## 📊 Output

### Valid Card

```text
WELCOME RAJA
ATTENDANCE MARKED

24/06/2026
10:30:45 AM
```

### Invalid Card

```text
INVALID CARD
ACCESS DENIED
```

---

## 📂 Project Structure

```text
RFID-Attendance-System/
│
├── Arduino_Code/
│   └── RFID_Attendance.ino
│
├── Proteus_Files/
│   ├── RFID_Attendance.pdsprj
│   ├── RFID_Attendance.hex
│
├── Report/
│   └── RFID_Attendance_Report.pdf
│
├── Images/
│   ├── Proteus_Schematic.png
│   ├── Output.png
│
└── README.md
```

---

## ✅ Advantages

- Fast attendance processing
- Eliminates manual errors
- Accurate timestamp recording
- Secure identification
- Easy implementation
- Cost-effective solution

---

## 🚀 Future Scope

- Cloud database integration
- IoT-based attendance monitoring
- Mobile application support
- Face recognition integration
- Biometric authentication
- Web dashboard for administrators

---

## 🎯 Applications

- Schools and Colleges
- Corporate Offices
- Government Institutions
- Research Laboratories
- Employee Attendance Systems
- Access Control Systems

---

## 🏁 Conclusion

The RFID-Based Attendance System Using RTC Module provides an efficient, reliable, and automated method for attendance management. By integrating RFID technology with a real-time clock module, the system ensures accurate attendance tracking while reducing manual effort and improving operational efficiency.

---

## 👨‍💻 Author

**Vaikunda Raja S**  
Electronics and Communication Engineering (ECE)  
Mini Project – 2026
