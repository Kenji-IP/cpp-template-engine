# C++ TEMPLATE FOR ENGINES

> A subjective C++ engine template that includes basic tools and project structure to help you get started quickly.

## Requirements

- Git (**Required**)
- Ninja (**Required**)
- CMake (**Minimum version: 4.3.2**)
- clangd (*Optional*)
- At least one compiler:
  - Clang
  - GCC
  - MSVC (*Windows only*)

---

## Using This Template for Your Project

1. Create a folder for your project.
2. Open a terminal inside the root directory of your project.
3. Clone this repository into your project folder:

   ```bash
   git clone https://github.com/Kenji-IP/cpp-template-engine .
   ```

4. *(Optional but recommended)* Remove the existing Git history:

   **Windows:**
   ```bash
   rmdir /s /q .git
   ```

   Or simply delete the `.git` folder manually.

5. If you removed `.git`, initialize a new Git repository:

   ```bash
   git init
   ```

6. Stage all files:

   ```bash
   git add .
   ```

   > **Important:** Make sure you are inside your project root directory.

7. Create your first commit:

   ```bash
   git commit -m "First Commit"
   ```

8. Done! Your project is now ready.

---

## Build and Run the Project

### Using VSCode + CMake Tools Extension

1. Open your project in VSCode.

2. When opening the project for the first time, VSCode should display a popup asking you to select a CMake preset.

   If it does not appear:

   - Open the **CMake Tools** sidebar.
   - Find the **Configure** section.
   - Click the pencil icon.
   - Select the preset you want to use.

3. Build the project by clicking **Build** in the bottom-left corner.

4. Run or debug the project:

   - Click the **Run** button to launch.
   - Click the **Debug** button (bug icon) to debug.

5. If everything works correctly, you should see:

   ```text
   Hello World!
   ```

   This output is triggered by `ENGINE_ASSERT`, indicating the project was built and executed successfully.

---

### Using Terminal (Manual)

1. List available presets:

   ```bash
   cmake --list-presets
   ```

2. Configure the project using your chosen preset:

   ```bash
   cmake --preset "PRESET_NAME"
   ```

3. Build the project:

   ```bash
   cmake --build --preset "PRESET_NAME"
   ```

4. After a successful build, the executable can usually be found at:

   ```text
   build/PRESET_NAME/bin/yourproject.exe
   ```

5. Run the executable.

6. Done!

---

## Project Architecture

```text
Engine (Shared / Static Library*)
├── Core
│   └── Entrypoint.h   # main() entry point
├── Debug
├── Utils
└── Platform           # Platform abstraction layer

Game (Executable / Client)
```

---

## TODOs

- [ ] Add a CMake toggle for building the engine as either a Shared or Static library
- [ ] Add Script to dynamically change project name and namespace name from user input/metadata