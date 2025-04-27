# School-Work
# Corner Grocer – Project Three

## Project Summary
The Corner Grocer application is a C++ console program that reads a chronological list of grocery items from `CS210_Project_Three_Input_File.txt`, counts how many times each item was purchased, and exposes four menu-driven features:  
- **Search** for a specific item’s frequency  
- **Display** all item frequencies  
- **Show** a histogram (asterisks per occurrence)  
- **Exit** the program safely

An internal `GroceryTracker` class encapsulates the `std::map<std::string,int>` data structure for tracking frequencies, and the program writes a backup file `frequency.dat` on startup.

## Reflection

1. What did I do particularly well?  
   - Designed a clear object-oriented interface (`GroceryTracker`) that cleanly separates file I/O, data storage, and display logic.  
   - Implemented robust input validation on the menu, using `std::cin.clear()` and `ignore()` to handle non-integer entries without crashing.  
   - Followed professional coding standards: descriptive variable/method names (`itemFrequencyMap`, `PrintHistogram`), consistent indentation, and inline comments for each method

2. Where could I enhance my code?
   - Performance & scalability: Switch to `std::unordered_map` for lookup if processing very large datasets.  
   - Error handling: Use exceptions or check `ifstream::fail()` to catch file-open errors and report them to the user.  
   - Configurability: Read filenames from a configuration file or command-line arguments instead of hard-coding.  
   - Testing: Add unit tests (e.g., with Google Test) to validate methods like `GetItemFrequency` and `PrintHistogram` automatically.

3. Most challenging pieces & how I overcame them  
   - Menu loop input validation: Ensuring invalid input didn’t cause infinite loops or leave stray characters in the input buffer. I studied C++ reference docs and experimented with `std::cin.ignore()` and `clear()`.  
   - Formatting the histogram: Aligning item names nicely required `std::setw` and iomanip; I consulted online examples on using manipulators in loops.

4. Transferable skills  
   - File I/O in C++: reading from and writing to text files reliably.  
   - STL containers: choosing and using the right map type for frequency counting.  
   - Error-resilient user interfaces: input validation patterns that apply to any console or GUI program.  
   - Modular design: encapsulating functionality in classes to keep code maintainable and testable.

5. Maintaining readability & adaptability  
   - Descriptive naming: every variable and method name clearly states its purpose.  
   - Separation of concerns: file loading, data management, and user interaction live in separate methods and could easily be refactored into header/source files.  
   - Inline documentation: comments above each method explain “what” and “why,” not just “how,” so future contributors can onboard quickly.  
   - Consistent style: uniform indentation, braces on their own lines, and logical grouping of related code blocks make it easy to scan and extend.
