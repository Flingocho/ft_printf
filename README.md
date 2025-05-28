# 🖨️ ft_printf

<div align="center">
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language">
  <img src="https://img.shields.io/badge/Status-Completed-success" alt="Status">
  <img src="https://img.shields.io/badge/42-School-brightgreen" alt="42">
  <br><br>
</div>

<details open>
<summary><b>🚀 Overview</b></summary>

The **ft_printf** project involves creating a custom implementation of the C standard library function `printf()`. It parses a format string and displays the formatted output to standard output, handling various format specifiers for different data types. This project introduces concepts like variadic functions, string parsing, and type conversion.

DISCLAIMER: Unlike the standard library's printf which ensures atomic operations (where multiple threads writing simultaneously won't interleave their output), this implementation calls write() multiple times for complex format strings. This means that in a multithreaded environment, output from different ft_printf calls could become interleaved. The standard library implementation buffers the entire formatted output before writing it in a single system call, ensuring atomicity.
</details>

<details>
<summary><b>✨ Features</b></summary>

- 🔠 Handles the most common format specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`
- ⚡ Supports variadic arguments
- 🔄 Returns the number of characters printed, just like the original
- 🧩 Minimal external dependencies (only uses basic C library functions)
- 📚 Compiled as a static library for easy integration
- 🧪 Thoroughly tested for accuracy and reliability
</details>

<details>
<summary><b>📊 Feature Comparison</b></summary>

| Feature                | Original printf | ft_printf | Notes                          |
|------------------------|:--------------:|:---------:|--------------------------------|
| Character (`%c`)       |       ✅       |     ✅     | Fully implemented              |
| String (`%s`)          |       ✅       |     ✅     | Fully implemented              |
| Pointer (`%p`)         |       ✅       |     ✅     | Displays as hexadecimal        |
| Decimal (`%d`, `%i`)   |       ✅       |     ✅     | Supports negative numbers      |
| Unsigned (`%u`)        |       ✅       |     ✅     | Fully implemented              |
| Hex (`%x`, `%X`)       |       ✅       |     ✅     | Both lowercase and uppercase   |
| Percent (`%%`)         |       ✅       |     ✅     | Escapes percent sign           |
| Zero padding           |       ✅       |     ❌     | Not implemented                |
| Width field            |       ✅       |     ❌     | Not implemented                |
| Precision              |       ✅       |     ❌     | Not implemented                |
| Flags                  |       ✅       |     ❌     | Not implemented                |
| Return value           |       ✅       |     ✅     | Returns chars printed          |
</details>

<details>
<summary><b>🛠️ Function Overview</b></summary>

<details>
<summary><b>🔑 Main Function</b></summary>

| Function | Description |
|----------|-------------|
| `ft_printf` | Formats and prints data according to format specification |

</details>

<details>
<summary><b>⚙️ Helper Functions</b></summary>

| Function | Description |
|----------|-------------|
| `ft_putchar` | Outputs a single character to stdout |
| `ft_putstr` | Outputs a string to stdout |
| `ft_putnbr` | Outputs a number to stdout |
| `ft_putnbr_base` | Outputs a number in a specified base |
| `ft_putptr` | Outputs a pointer address in hexadecimal |
| `format_selector` | Selects the appropriate handler based on format specifier |

</details>
</details>

<details>
<summary><b>🛠️ Installation</b></summary>

```bash
# Clone the repository
git clone https://github.com/Flingocho/ft_printf.git

# Navigate to the directory
cd ft_printf

# Build the library
make
```

### Project Structure

The project follows a modern directory structure:

```
ft_printf/
├── include/              # Header files directory
│   └── ft_printf.h       # Main header file with function prototypes
├── src/                  # Source files directory
│   ├── ft_printf.c       # Main function implementation
│   └── ft_printf_utils.c # Helper functions implementation
├── obj/                  # Object files (created during compilation)
└── Makefile              # Build automation
```
</details>

<details>
<summary><b>📋 Usage</b></summary>

### Compilation

```bash
# Compile the library
make

# Link with your program
cc -Wall -Wextra -Werror your_program.c -L. -lftprintf -o your_program
```

### Integration Into Your Project

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    char *str = "Hello, world!";
    int num = 42;
    
    // Using ft_printf
    ft_printf("String: %s\n", str);
    ft_printf("Number: %d\n", num);
    
    // Comparing with standard printf
    printf("Standard printf - Number: %d\n", num);
    
    // Getting the return value
    int count = ft_printf("This returns %d characters\n", 25);
    ft_printf("Previous line printed %d characters\n", count);
    
    return (0);
}
```

### Tips and Best Practices

- **Error Checking**: Always check the return value to confirm successful printing
- **Format Security**: Be careful with user-provided format strings to avoid security issues
- **Memory Efficiency**: For very large outputs, consider using separate calls

</details>

<details>
<summary><b>🔍 Supported Format Specifiers</b></summary>

| Specifier | Output                                 | Example                             |
|-----------|----------------------------------------|-------------------------------------|
| `%c`      | 🔤 Single character                    | `ft_printf("%c", 'A')` → `A`        |
| `%s`      | 📝 String                              | `ft_printf("%s", "hello")` → `hello`|
| `%p`      | 📍 Pointer address in hexadecimal      | `ft_printf("%p", ptr)` → `0x123abc` |
| `%d`      | 🔢 Decimal (base 10) integer           | `ft_printf("%d", 42)` → `42`        |
| `%i`      | 🔢 Integer in base 10                  | `ft_printf("%i", 42)` → `42`        |
| `%u`      | 🔢 Unsigned decimal integer            | `ft_printf("%u", 42)` → `42`        |
| `%x`      | 🧮 Hexadecimal (lowercase)             | `ft_printf("%x", 255)` → `ff`       |
| `%X`      | 🧮 Hexadecimal (uppercase)             | `ft_printf("%X", 255)` → `FF`       |
| `%%`      | % Percentage sign                      | `ft_printf("%%")` → `%`             |

</details>

<details>
<summary><b>⚙️ How It Works</b></summary>

1. The function uses variadic arguments to accept a variable number of parameters
2. It processes the format string character by character
3. When it encounters a `%` followed by a format specifier, it calls the appropriate conversion function
4. It keeps track of the number of characters printed and returns that count
5. Each format specifier has its own specialized handler function:
   - `%c` - Outputs a single character
   - `%s` - Outputs a string
   - `%p` - Converts a pointer to hexadecimal and outputs it
   - `%d/%i` - Converts an integer to decimal and outputs it
   - `%u` - Converts an unsigned integer to decimal and outputs it
   - `%x/%X` - Converts an integer to hexadecimal and outputs it
   - `%%` - Outputs a literal percent sign

### Implementation Details

- The main function parses the format string and dispatches to format-specific handlers
- Format handlers convert arguments of various types to string representations
- All output ultimately goes through character or string output functions
- Memory is managed carefully to avoid leaks

</details>

<details>
<summary><b>🧪 Testing</b></summary>

Create a test file:

```c
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ft_count, std_count;
    char *str = "Hello, world!";
    int num = 42;
    
    // Test basic strings and characters
    printf("\n===== TESTING STRINGS AND CHARACTERS =====\n");
    ft_count = ft_printf("String: %s\n", str);
    std_count = printf("String: %s\n", str);
    printf("ft_printf: %d chars | printf: %d chars\n\n", ft_count, std_count);
    
    // Test integers
    printf("===== TESTING INTEGERS =====\n");
    ft_count = ft_printf("Integer: %d\n", num);
    std_count = printf("Integer: %d\n", num);
    printf("ft_printf: %d chars | printf: %d chars\n\n", ft_count, std_count);
    
    // Test hexadecimal
    printf("===== TESTING HEXADECIMAL =====\n");
    ft_count = ft_printf("Hex (lower): %x, Hex (upper): %X\n", num, num);
    std_count = printf("Hex (lower): %x, Hex (upper): %X\n", num, num);
    printf("ft_printf: %d chars | printf: %d chars\n\n", ft_count, std_count);
    
    // Test pointers
    printf("===== TESTING POINTERS =====\n");
    ft_count = ft_printf("Pointer: %p\n", &num);
    std_count = printf("Pointer: %p\n", &num);
    printf("ft_printf: %d chars | printf: %d chars\n\n", ft_count, std_count);
    
    // Test edge cases
    printf("===== TESTING EDGE CASES =====\n");
    ft_count = ft_printf("Null string: %s\n", NULL);
    std_count = printf("Null string: %s\n", NULL);
    printf("ft_printf: %d chars | printf: %d chars\n", ft_count, std_count);
    
    return 0;
}
```

Compile and run:

```bash
cc -Wall -Wextra -Werror test.c -L. -lftprintf -o test_printf
./test_printf
```
</details>

<details>
<summary><b>🌟 Key Learning Outcomes</b></summary>

- Understanding variadic functions with stdarg.h
- String parsing and format specifier handling
- Type conversion techniques between various data types
- Memory management and string manipulation
- Output redirection and character counting
- Modular programming and function organization
</details>

<details>
<summary><b>📜 License</b></summary>

This project is part of the 42 School curriculum and is provided under the [MIT License](LICENSE).
</details>

---

<div align="center">
  Created with ❤️ by <a href="https://github.com/Flingocho">Flingocho</a>
</div>

