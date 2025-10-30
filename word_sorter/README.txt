-- Name : Vaibhav Pawar  
-- Roll No: 24112023

-- Problem Statement
         - Sort a sequence of words stored in memory in alphabetical order.

-- How It Works

   -This program takes a block of memory (4096 bytes) and sorts all the words alphabetically based on ASCII values. 
    
    Words are:
    -Stored sequentially in memory with a single space (`0x20`) as a separator.
    -Terminated with a null character (`'\0'`).
    -Sorted in place by shifting each character to temporary location of 1 byte
    -it required 1 extra byte to store charater duriung shifting

    Example :

         xyz _bc              --temp : a
         axyz _c              --temp : b
         abXyz _              --temp : c
         abcXyz_              --temp : space   
         abc xyz              --sorted              


---

-- Memory Structure

      - Memory Size: 4096 bytes (4 KB)
      - Bytes: Numbered from 0 to 4095
      - Bits per Byte: 8 (numbered right to left: `7 6 5 4 3 2 1 0`)
      - Reserved Bytes (Last 14 Bytes): Used for pointer variables and temporary storage in the program.
         
         -temporary Variable usege and where it store (last 14 Byte)
              
               | Variable | where it store  | Purpose                          |
               |----------|-----------------|----------------------------------|
               |  m       | mem[4094]       | Pointer/index to word char       |
               |  n       | mem[4092]       | Pointer/index to another word    |
               |  p       | mem[4090]       | Pointer for swapping logic       |
               |  fw      | mem[4088]       | First word pointer               |
               |  sw      | mem[4086]       | Second word pointer              |
               |  temp    | mem[4085]       | Temporary character during swap  |
               |  flag    | mem[4084]       | Flag for checking swap condition |

-- How to Run

   -- Compile the Program:
      gcc -o word_sorter word_sorter.c

   -- Run:
      ./word_sorter

   -- Expected Output:
      The unsorted and sorted word sequence will be printed in the console.

-- How flow of program
   -- The program compares each word (`fw`) with all remaining words (`sw`).
   -- If the current word is alphabetically greater than the other, a swap is performed by shifting characters.
   -- Sorting continues until the entire sequence is in order.

-- Sample Input :
   mem = {"apple banana cat dog elephant frog goat hat \0"};
   Note: All words are space-separated and must end with `\0`.

-- Sample Output :
   unsorted : goat hat apple frog cat banana elephant dog
   Sorted :apple banana cat dog elephant frog goat hat

