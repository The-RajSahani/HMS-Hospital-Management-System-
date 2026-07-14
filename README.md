# 🏥 Hospital Management System (C Language)

A simple yet efficient **Hospital Management System** developed in **C Programming Language**. This project demonstrates the use of **Structures**, **Functions**, **File Handling**, and **CRUD Operations** for managing hospital patient records.

---

## 📌 Features

✅ Add New Patient

✅ View All Patients

✅ Search Patient by ID

✅ Update Patient Details

✅ Delete Patient Record

✅ Generate Patient Bill

✅ Binary File Storage (`patients.dat`)

---

## 🛠️ Technologies Used

- C Programming
- GCC Compiler
- File Handling
- Structures
- Functions
- Standard C Libraries

---

## 📂 Project Structure

```
Hospital-Management-System/
│
├── main.c              # Main source code
├── patients.dat        # Patient database (auto-generated)
├── hospital            # Compiled executable (Linux)
└── README.md
```

---

## 💻 How to Compile

### Linux

```bash
gcc main.c -o hospital
```

Run the program:

```bash
./hospital
```

### Windows (MinGW)

```bash
gcc main.c -o hospital.exe
```

Run

```bash
hospital.exe
```

---

## 📖 Menu

```
1. Add Patient
2. View Patients
3. Search Patient
4. Update Patient
5. Delete Patient
6. Generate Bill
7. Exit
```

---

## 📋 Patient Information Stored

- Patient ID
- Name
- Age
- Gender
- Disease
- Doctor Name
- Mobile Number

---

## 💰 Bill Generation

The billing module calculates the total amount based on:

- Doctor Fee
- Medicine Charge
- Room Charge
- Test Charge

The total bill is automatically displayed.

---

## 📁 Data Storage

Patient records are stored permanently inside:

```
patients.dat
```

using **Binary File Handling**, ensuring data remains available even after closing the program.

---

## 🎯 Concepts Used

- Structures
- Functions
- Arrays
- Loops
- Conditional Statements
- File Handling
- CRUD Operations
- Binary Files

---

## 🚀 Future Improvements

- User Login & Authentication
- Admin Dashboard
- Appointment Scheduling
- Doctor Management
- Pharmacy Management
- Laboratory Reports
- Database Integration (MySQL/Firebase)
- GUI Version
- Online Hospital Portal

---

## 📷 Preview

```
====================================
      HOSPITAL MANAGEMENT SYSTEM
====================================

1. Add Patient
2. View Patients
3. Search Patient
4. Update Patient
5. Delete Patient
6. Generate Bill
7. Exit
```

---

## 👨‍💻 Author

**Raj Sahani**



GitHub: https://github.com/The-RajSahani

---

## ⭐ Support

If you found this project helpful, consider giving it a ⭐ on GitHub.

---

## 📜 License

This project is open-source and available under the MIT License.