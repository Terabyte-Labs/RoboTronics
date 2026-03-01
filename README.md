# 🚀 Arduino Labs – Embedded Experiments

## 🧠 Overview

Repositorio dedicado a proyectos de electrónica y sistemas embebidos usando **Arduino**.
Aquí documento experimentos, pruebas de hardware, control de sensores y desarrollo modular en C++.

Este repositorio no es solo “sketches”, sino una base para:

* Arquitectura limpia en microcontroladores
* Separación de lógica y hardware
* Uso profesional de C++
* Buenas prácticas embedded

---

## 🔧 Stack Tecnológico

* Arduino (C++11)
* PlatformIO / Arduino IDE
* Microcontroladores AVR (UNO, Nano)
* Sensores digitales y analógicos
* Displays 7 segmentos
* UART / I2C / SPI
* PWM
* PROGMEM para optimización de memoria

---

## 📂 Estructura del Proyecto

```
arduino-labs/
│
├── src/
│   ├── main.ino
│   ├── config.h
│   ├── display.cpp
│   ├── display.h
│   ├── sensor.cpp
│   ├── sensor.h
│
├── docs/
│   ├── diagrams/
│   └── schematics/
│
└── README.md
```

---

## 🏗 Arquitectura

Principios aplicados:

* Separación de hardware y lógica
* Uso de `constexpr` y `const`
* Encapsulamiento con clases
* Modularidad por componente
* Código testeable (cuando aplica)

Ejemplo de clase:

```cpp
class Led {
    byte pin;

public:
    Led(byte p) : pin(p) {}

    void begin() {
        pinMode(pin, OUTPUT);
    }

    void on() {
        digitalWrite(pin, HIGH);
    }

    void off() {
        digitalWrite(pin, LOW);
    }
};
```

---

## 🔌 Proyectos Incluidos

### 1️⃣ Display 7 Segmentos

* Identificación ánodo común / cátodo común
* Multiplexado
* Control por funciones modulares

### 2️⃣ Sensor + Actuador

* Lectura digital / analógica
* Control basado en umbral
* Máquina de estados simple

### 3️⃣ Control PWM

* Regulación de intensidad LED
* Control básico de motor DC

---

## ⚡ Buenas Prácticas Aplicadas

* Nunca conectar LEDs sin resistencia
* Documentar pinout antes de cablear
* Uso de `INPUT_PULLUP` cuando aplica
* Optimización de RAM con `PROGMEM`
* Comentarios técnicos claros

---

## 📊 Recursos

* Datasheets oficiales
* Diagramas eléctricos en `/docs`
* Esquemáticos actualizados por proyecto

---

## 🧪 Roadmap

* [ ] Comunicación I2C avanzada
* [ ] Manejo de interrupciones
* [ ] Driver propio para display
* [ ] Librería reutilizable
* [ ] Proyecto completo tipo “sistema embebido”

---

## 🛠 Filosofía

> No es solo hacer que prenda un LED.
> Es entender cómo funciona el hardware por debajo.

---

## 👨‍💻 Autor

Luis G.
Embedded & Software Engineer
Construyendo desde Java hasta electrónica ⚡