# Simple Task Manager in C

A beginner-friendly command-line Task Manager written in C. You can create tasks with a name, description, date, and priority, and manage them by marking them as completed or deleting them.

## Features

- Add new tasks with:
  - Name
  - Description
  - Due date (YYYY-MM-DD)
  - Priority (1 to 5)
- View all tasks
- Filter by status: Pending or Completed
- Mark tasks as completed
- Delete tasks
- Simple menu interface using loops and switch-case
- Uses structs and arrays (no dynamic memory)

## Demo
<img width="371" height="296" alt="main menu" src="https://github.com/user-attachments/assets/fc94bf88-c7cf-4003-b0f3-c95fcdbff4c6" />

## Compilation & Usage

To compile and run the program, use:

```bash
gcc taskManager.c -o taskManager
./taskManager
```
Make sure you have GCC installed.

## Possible Improvements (Future Ideas)
- Save/load tasks from a .txt file
- Search tasks by name or date
- Sort tasks by date or priority
- Add time tracking or deadline notifications
- Convert to a web or GUI-based version

## Contributing

Pull requests are welcome. If you have suggestions for improvements or new features, feel free to open an issue first to discuss them.

This is a learning-focused project, so any educational contributions are also appreciated!

## License

[MIT](https://choosealicense.com/licenses/mit/)
