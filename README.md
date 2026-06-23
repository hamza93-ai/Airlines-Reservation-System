# ✈️ Airlines Reservation System

A console-based **Airline Reservation System** built in **C++** using **Object-Oriented Programming (OOP)** concepts. The system allows users to register as customers, browse available flights departing from Karachi, Pakistan, book a flight, and generate a formatted boarding pass / e-ticket — all through a step-by-step guided menu.

---

## 🚀 Features

- ✅ **Step-by-step workflow** — enforces correct order: Customer → Flight → Ticket
- ✅ **Customer registration** with full validation (ID, name, age, address, gender)
- ✅ **12 international flights** from Karachi, Pakistan with flight codes, duration & prices
- ✅ **Boarding Pass style e-ticket** generated on screen and saved to `ticket.txt`
- ✅ **Customer search** by name with formatted display
- ✅ **Input validation** — handles invalid types, out-of-range values, and wrong sequences
- ✅ **Multiple customers** supported in a single session
- ✅ **No crashes** — all edge cases handled

---

## 🛠️ Tech Stack

| Component | Details |
|-----------|---------|
| Language | C++ (C++11 or later) |
| Paradigm | Object-Oriented Programming (OOP) |
| Concepts Used | Classes, Objects, Encapsulation, File I/O, Vectors, Dynamic Memory |
| Compiler | g++ / any standard C++ compiler |
| Platform | Cross-platform (Windows, Linux, macOS) |

---

## 📁 Project Structure

```
xyz-airlines-reservation/
│
├── main.cpp          # Main source code
├── ticket.txt        # Auto-generated e-ticket (created at runtime)
└── README.md         # Project documentation
```

---

## 🖥️ How to Run

### Option 1 — Online (Recommended for quick test)
1. Go to [OnlineGDB](https://www.onlinegdb.com/online_c_compiler)
2. Set language to **C++**
3. Paste the code from `main.cpp`
4. Click **Run**

### Option 2 — Local (g++ compiler)
```bash
g++ -o airline main.cpp
./airline        # Linux/macOS
airline.exe      # Windows
```

---

## 📋 System Workflow

```
[1] Enter Customer Details
        ↓
[2] Book a Flight  (12 destinations from Karachi, Pakistan)
        ↓
[3] Generate & View Ticket  (Boarding Pass printed + saved to ticket.txt)
        ↓
[4] Show Customer Details  (Search by name)
        ↓
[5] Exit
```

> ⚠️ **Sequence is enforced** — you cannot book a flight without entering customer details first, and cannot generate a ticket without booking a flight.

---

## ✈️ Available Flights

| # | Flight | From | To | Duration | Price (PKR) |
|---|--------|------|----|----------|-------------|
| 1 | XY-101 | Karachi, Pakistan | Dubai | 3h 00m | 85,000 |
| 2 | XY-202 | Karachi, Pakistan | Saudi Arabia | 3h 30m | 95,000 |
| 3 | XY-303 | Karachi, Pakistan | Turkey | 6h 00m | 1,20,000 |
| 4 | XY-404 | Karachi, Pakistan | UK | 9h 30m | 1,75,000 |
| 5 | XY-505 | Karachi, Pakistan | USA | 14h 00m | 2,10,000 |
| 6 | XY-606 | Karachi, Pakistan | Canada | 14h 30m | 2,05,000 |
| 7 | XY-707 | Karachi, Pakistan | Australia | 12h 00m | 1,95,000 |
| 8 | XY-808 | Karachi, Pakistan | Europe | 8h 00m | 1,55,000 |
| 9 | XY-909 | Karachi, Pakistan | Malaysia | 4h 30m | 1,10,000 |
| 10 | XY-110 | Karachi, Pakistan | China | 5h 00m | 1,15,000 |
| 11 | XY-111 | Karachi, Pakistan | Japan | 7h 30m | 1,60,000 |
| 12 | XY-112 | Karachi, Pakistan | Singapore | 5h 30m | 1,25,000 |

---

## 🎫 Sample Output — Boarding Pass

```
****************************************************
*                                                  *
*             XYZ AIRLINES                         *
*          BOARDING PASS / E-TICKET                *
*                                                  *
****************************************************
*                                                  *
*  PASSENGER  : Hamza Asif                         *
*  CUST ID    : 101                                *
*  AGE        : 20                                 *
*  GENDER     : Male                               *
*                                                  *
*--------------------------------------------------*
*                                                  *
*  FLIGHT NO  : XY-111                             *
*  DEST       : Japan                              *
*  DURATION   : 7h 30m                             *
*                                                  *
*--------------------------------------------------*
*                                                  *
*  TOTAL FARE : PKR 160000                         *
*  STATUS     : CONFIRMED                          *
*                                                  *
*  HAVE A SAFE AND PLEASANT JOURNEY!               *
*                   XYZ Airlines Team              *
*                                                  *
****************************************************
```

---

## 🧠 OOP Concepts Used

| Concept | Where Used |
|---------|-----------|
| **Class & Object** | `Customer`, `Flight`, `Ticket` classes |
| **Encapsulation** | All data members are `private`, accessed via public methods |
| **Constructor** | `Flight` and `Ticket` use parameterized constructors |
| **Object Composition** | `Ticket` object is built using `Customer` and `Flight` objects |
| **Vectors** | `vector<Customer>` and `vector<Flight>` for dynamic storage |
| **File I/O** | `ofstream` / `ifstream` to write and read `ticket.txt` |
| **Dynamic Memory** | `new` / `delete` for `Ticket` pointer management |

---

## 👨‍💻 Author

**Hamza Asif**

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Hamza%20Asif-blue?style=flat-square&logo=linkedin)](https://linkedin.com/in/hamza-asif-b84523325)
[![GitHub](https://img.shields.io/badge/GitHub-hamza93--ai-black?style=flat-square&logo=github)](https://github.com/hamza93-ai)

---
