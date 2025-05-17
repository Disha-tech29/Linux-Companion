# Linux Companion 🧠🖥️

A smart console-based assistant that detects user inactivity and gently reminds them to take self-care breaks. Built in C for Windows using the WinAPI.

---

## ✨ Features

- Detects user inactivity (idle time)
- Logs each suggestion and its timestamp
- Displays a friendly message every  5 minutes of inactivity
- Automatically cycles through different messages
- Simple logging to `companion.log`

---

## 🔧 How It Works

- Checks for keyboard/mouse inactivity using WinAPI
- If idle time exceeds 5 minutes, a motivational message appears
- Logs the activity with timestamp to a file

---

## 🛠️ Requirements

- Windows OS
- C compiler (MinGW recommended)
- Run via terminal or add to startup via Task Scheduler

---

## 🚀 How to Run

### 1. Compile the Code

Use this in Command Prompt:
gcc companion.c -o companion.exe
2. Run It
./companion.exe
You’ll see:
Hello, I am your Linux Companion!

After 5 minutes of no keyboard/mouse input, messages like:
Rest your eyes! (Idle 5 min)
Do a quick stretch! (Idle 5 min)

📂 Log Output
Saved to a file named companion.log:
[2025-05-18 14:33:10] STATUS: IDLE. MESSAGE: Take a quick walk!

⚙️ Optional Setup: Auto Start on Boot
Use Windows Task Scheduler:
Open Task Scheduler → Create Task
Trigger: At logon
Action: Start a Program → companion.exe path
Check "Run whether user is logged on or not"

💡 Future Ideas
Add speech reminders with espeak
Add active mode self-care messages (after 30–60 mins)
Add GUI or system tray icon

📌 Author
Created by Disha
---
