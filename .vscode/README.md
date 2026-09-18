# C++ Practice Programs

This repository contains two C++ console programs:

- `astronot.cpp`: simulates astronaut elimination using a changing `K` value.
- `sandi_alien.cpp`: encodes and decodes text using an alien cipher.

## Requirements

Install a C++ compiler and debugger, then make sure these commands work in the VS Code terminal:

```powershell
g++ --version
gdb --version
```

On Windows, MSYS2 UCRT64 is recommended. Add its `bin` folder to PATH, for example:

```text
C:\msys64\ucrt64\bin
```

## Run in VS Code

1. Open this folder in VS Code.
2. Open either `.cpp` file.
3. Press `F5` or choose **Run > Start Debugging**.
4. Enter the program input in the integrated terminal.

VS Code automatically builds the active C++ file before running it. The shared settings are in `.vscode/tasks.json` and `.vscode/launch.json`.

## Run from a terminal

```powershell
g++ .\astronot.cpp -o .\astronot.exe
.\astronot.exe
```

Or:

```powershell
g++ .\sandi_alien.cpp -o .\sandi_alien.exe
.\sandi_alien.exe
```

Generated `.exe` files are ignored by Git because they depend on the operating system and compiler. They are recreated automatically when the project is built.
