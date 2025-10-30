-- Name: Pawar Vaibhav  
-- Roll No: 24112023  

-- Problem Statement
  You have n lists stored sequentially in a memory block. Each list contains a variable number of 32-bit unsigned int. Implement two subroutines:
  -list_min() – Finds the minimum number in the currently pointed list and stores it in the reserved output area.
  -list_max() – Finds the maximum number in the currently pointed list and stores it in the reserved output area.

  After processing all lists the program:
    -Finds the maximum among those minimums.
    -Finds the minimum among those maximums.

-- what i learn 
  - array abstraction
  - arithmatic logic behind the asccess element from the array by using base address 


-- Memory Layout
  -Total Memory : unsigned char mem[2048];  
  -Addressing:  
    -Bytes : 0 - 2047  
    -Bits Per Byte: 8 bits numbered 0 (LSB) to 7 (MSB)  

--Macros and its use :
      -len 2048  size of memory in byte
      
      -----subroutine-----
      -l_ptr    len-2	  pointer to each list which use in subroutine
      -ret_val  len-6	  return value for subroutine 
      -err      len-7	  error byte
      -cnt_sl   len-15	counter for iterate list

      -----output---------
      -o_ptr    len-9	  point the start of list which contain max or min from each list

      -------main---------
      -l_no         0       number of list in input
      -f_l_ptr      len-11	point to each list
      -count_l_no   len-13	counter for list

      -----memory access-------- 
      -Read_32(index) (*(unsigned int *)&mem[index])        read 32 bits from index
      -Read_16(index) (*(unsigned short int *)&mem[index])  read 16 bits from index

-- List indexing scheme
		-- 0th byte of input should contain no list in input(no_l)
		-- after that enter the list one after one 
		-- format of input
		
		  0     1    2  3--------  7    8 9   10-------------------------------------n-1
		+------------------------------------------------------------------------------+
		|no_l|lofl| e1|e2|-------|losl|a1|a2|--------                                  |
		+------------------------------------------------------------------------------+

		-- 1st byte contain list of that list(lofl)
		-- elements : each list should have numbers in n*4 bytes after the fisrt byte of the list ;
		-- In the program the memory should be denoted by single array , with it's identifier being mem;
		-- User should write no of lists in 0th byte ;
	        -- Numbers should be written in following manner 
		--- if no starts at m'th byte then m+3th byte in MSB and mth byte is LSB

	        -- both function store output in follwing bytes 
			len-6(LSB) to len(MSB)

		-- max and min element of each list store after input over

--Subroutine Details

    -void list_min()
      -Before calling : l_ptr points to the first byte of the list length.
      -working :
          -Read element count: cnt = Read_16(l_ptr).
          -If cnt == 0, set err = 1.
          -Else, initialize ret_val to first element.
          -Loop i from 1 to cnt-1 : compare and update ret_val if smaller.
          -Store result in Read_32(ret_val).

      -void list_max()
          --Similar work flow to list_min(), but initializes ret_val = 0 and updates if a larger element is found.

      -void Dis_list()
          --Displays the list pointed by `l_ptr`.
          -- Iterates cnt elements, printing each via printf("%d	", Read_32(address)).

--Sample input
          mem = {
            3,           // no_l = 3 lists
            2,           // len1 = 2
            10,0,0,0,    // 10
            5,0,0,0,     // 5
            3,           // len2 = 3
            3,0,0,0,     // 3
            12,0,0,0,    // 12
            4,0,0,0,     // 4
            1,           // len3 = 1
            2,0,0,0      // 2
            // … reserved for output …
          };


--Compilation & Execution

    $> gcc list_min_max.c -o list_min_max
    $> ./list_min_max

--Error Handling
    -If any list length = 0, reports:
        Error: [List No X] : There is no element in the list..!!