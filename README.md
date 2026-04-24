# secure-water-quality-secure-monitoring-
Secure IoT water quality monitoring system with encryption, timestamp, and message authentication
# Secure Water Quality Monitoring System (IoT + Embedded Security)

 Overview

This project implements a water quality monitoring system using embedded hardware and IoT concepts. It measures key parameters such as Total Dissolved Solids (TDS) and temperature, processes the data, and transmits it wirelessly.

In addition to the original implementation, this repository presents enhanced security features**, including encryption, timestamping, and message authentication (MAC) to improve data integrity and protection against attacks.


Features

* Real-time water quality monitoring
* TDS and temperature measurement
* Wireless data transmission (Bluetooth / Wi-Fi)
* Lightweight encryption for secure communication
* Timestamp-based replay attack prevention
* Message Authentication Code (MAC) for data integrity
* Scalable embedded system design


System Architecture

 1. Sensing Layer

* TDS sensor → measures dissolved solids
* Temperature sensor → ensures accurate readings

2. Processing Layer

* Microcontroller (Arduino / ESP32)
* Data acquisition and processing

 3. Security Layer (Enhanced)

* Data encryption
* Timestamp generation
* MAC-based authentication

 


Components Used

* Arduino UNO / ESP32
* TDS Sensor
* Temperature Sensor (DS18B20 / LM35)
* HC-05 Bluetooth Module / Wi-Fi
* Power Supply



Working Principle

1. Sensors collect water quality data
2. Microcontroller reads analog signals
3. Data is processed and formatted
4. Security mechanisms are applied:

   * Encryption
   * Timestamp
   * MAC generation
5. Data is transmitted wirelessly
6. Receiver validates and displays data



Security Enhancements (Key Contribution)

 1. Encryption

Lightweight encryption is applied before transmission to protect data confidentiality.



 2. Timestamp (Replay Attack Protection)

Each data packet includes a timestamp to ensure freshness and prevent replay attacks.



 3. Message Authentication Code (MAC)

A MAC is generated using a shared secret key to ensure:

* Data integrity
* Source authenticity
* Tamper detection



 Data Packet Format

[TDS, Temperature, Timestamp, MAC]



Security Concepts Used

* Lightweight symmetric encryption
* Hash-based authentication (MAC concept)
* Replay attack prevention using timestamp

> The original work also includes analysis of cryptographic algorithms such as AES, RSA, SHA, and secure communication protocols for IoT systems.


Project Report

A detailed report of the original implementation is available here:

👉 [View Project Report](docs/project_report.pdf)

> Note: The GitHub version includes additional security enhancements (timestamp + MAC) beyond the original report.





Applications

* Smart water monitoring systems
* Environmental monitoring
* Aquaculture
* Drinking water safety
* Industrial IoT



Limitations

* Lightweight encryption (not production-grade)
* Sensor calibration required for accuracy
* Limited hardware resources



Future Improvements

* AES / ECC-based secure encryption
* Cloud integration (AWS / Firebase)
* Mobile application dashboard
* Real-time alert system
* Secure key management
* Hardware-based security (ESP32 secure boot, flash encryption)



 Conclusion

This project demonstrates how embedded systems and IoT can be combined with security mechanisms to create a reliable monitoring system.

By incorporating timestamp and MAC-based authentication, the system becomes more resilient against **data tampering and replay attacks**, making it more suitable for real-world applications.




