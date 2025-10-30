
--Name : Vaibhav Pawar
--Roll No : 24112023

--Title 
    -Min/Max Value Extraction from 18-bit Data

    This C program extracts 18-bit values from a memory buffer, compares them, and calculates the minimum and maximum values from the data set. The values are stored in a specific memory structure, and the program reads and processes them using bit-shift operations.

-- what i learn :
    -Bit Manipulation : Extracts 18-bit values using a bit-shift operation.
    -Memory Handling : Reads and processes data from a fixed-size memory buffer.

--Data Memory Layout
    -The program operates on a memory of size 1024 bytes.

--Mecro and usage :    
    -count  : Tracks the number of values processed.
    -re_min : Stores the current minimum value found.
    -re_max : Stores the current maximum value found.
    -idx    : Points to the current index in the buffer being processed.
    -shift  : Stores the current bit shift value for extracting data.

    -R16(x) : Reads a 16-bit value from memory at index `x`.
    -R32(x) : Reads a 32-bit value from memory at index `x`.
    -R18(x, shift) : Extracts an 18-bit value from a 32-bit value by applying a bit shift.


-- compile and execution 
    -gcc min_max_18Bit.c -o min_max_18Bit
    -./min_max_18Bit




