//Roll no : 24112023
//Name : Pawar Vaibhav

/*Problem Statement : Given n lists in memory with each list having variable number of elements write 2 subroutines
			1. min() : finds minimum number present in the list
			2. max() : finds maximum number present in the list
- User Interface :
	-- input shall be in the memory
	-- Memory Size : 2048 bytes , 1 byte is 8 bits long;
	-- Numbers Size : 4 bytes 
	-- Memory indexing scheme :
		--- Bytes : Numbered from left to right 
			    Starting from 0 and ending on (n - 1)
			+---------------------------------------------+
			| | | | | | | | | | | | | | | | | | | | | | | |
			+---------------------------------------------+
			 0 1 2 ...                                   n-1 = 2047

		--- Bits : Numbered from rigth to left starting from 0 and ending on 7
			+---------------+
			| | | | | | | | |
			+---------------+
			 7 6 5 4 3 2 1 0

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

*/

#include<stdio.h>
#define len 2048    //size of memory in byte

//-----subroutine-----
#define l_ptr len-2	//pointer to each list which use in subroutine
#define ret_val len-6	//return value for subroutine 
#define err len-7	//error byte
#define cnt_sl len-15	//counter for iterate list

//-----output---------
#define o_ptr len-9	//point the start of list which contain max or min from each list

//-------main---------
#define l_no 0          //number of list in input
#define f_l_ptr len-11		//point to each list
#define count_l_no len-13	//counter for list

//-----memory access-------- 
#define Read_32(index) (*(unsigned int *)&mem[index])
#define Read_16(index) (*(unsigned short int *)&mem[index])

unsigned char mem[len] = {4,0,
			  2,0,10,0,0,0,5,0,0,0,
			  3,0,3,0,0,0,12,0,0,0,4,0,0,0,
			  0,0,
			  1,0,2,0,0,0
			  };

void list_min()
{
	mem[err] = 0;			        //error byte set to zero
	Read_16(cnt_sl) = 0;			//sublist counter set 0

	if(Read_16(Read_16(l_ptr)) == 0)        //check list is empty or not 
	{	
		mem[err] = 1;			//if it is empty then err byte set to 1
	}
	else if(Read_16(Read_16(l_ptr)) != 0)	//if it is not empty
	{
		Read_32(ret_val) = Read_32(Read_16(l_ptr) + (Read_16(cnt_sl) * 4) + 2);   //initalize with 1st element 
		Read_16(cnt_sl) = Read_16(cnt_sl) + 1;		

		while(Read_16(cnt_sl) != Read_16(Read_16(l_ptr)))			//itrate while viwed all element
		{
			if(Read_32(ret_val) > Read_32(Read_16(l_ptr) + (Read_16(cnt_sl) * 4) + 2))     //check result is samll than current element
			{
				Read_32(ret_val) = Read_32(Read_16(l_ptr) + (Read_16(cnt_sl) * 4) + 2);	        //if small than update result
			}

			Read_16(cnt_sl) = Read_16(cnt_sl) + 1;
		}
	}
}

void list_max()
{
	mem[err] = 0;			      //error byte set to zero
	Read_16(cnt_sl) = 0;		      //sublist counter set 0
	Read_32(ret_val) = 0;		      //result initalize with 0
	if(Read_16(Read_16(l_ptr)) == 0)			//check list is empty or not
	{	
		mem[err] = 1;			//if it is empty then err byte set to 1
	}
	else if(Read_16(Read_16(l_ptr)) != 0)		//if it not empty
	{
		while(Read_16(cnt_sl) != Read_16(Read_16(l_ptr)))   	//itrate while viwed all element
		{
			if(Read_32(ret_val) < Read_32(Read_16(l_ptr) + (Read_16(cnt_sl) * 4) + 2))              //check result small than current number
			{
				Read_32(ret_val) = Read_32(Read_16(l_ptr) + (Read_16(cnt_sl) * 4) + 2);		//if it is small than update it
			}

			Read_16(cnt_sl) = Read_16(cnt_sl) + 1;				//increment the counter
		}
	}
}

void Dis_list()
{	
	mem[err] = 0;			      //error byte set to zero
	Read_16(cnt_sl) = 0;			//sublist counter set 0

	if(Read_16(Read_16(l_ptr)) == 0)        //check list is empty or not
	{
		mem[err] = 1;			//if it is empty then err byte set 1
	}
	else if(Read_16(Read_16(l_ptr)) != 0)    //if list is not empty
	{
		printf("List : ");
		while(Read_16(cnt_sl) != Read_16(Read_16(l_ptr)))     //itrate while viwed all elements
		{
			printf("%d\t",Read_32(Read_16(l_ptr) + (Read_16(cnt_sl) * 4) + 2));			//Display element
			Read_16(cnt_sl) = Read_16(cnt_sl) + 1;			//increase counter
		}

		printf("\n");
	}
}

int main( )
{
	Read_16(count_l_no) = 0;		//list counter initalize with 0
	Read_16(f_l_ptr) = 2;			//point to first list

	while(Read_16(count_l_no) != Read_16(l_no))		//viwed all list
	{	
		Read_16(l_ptr) = Read_16(f_l_ptr);		

		Read_16(f_l_ptr) = Read_16(f_l_ptr) + (Read_16(Read_16(f_l_ptr)) * 4)+2;		//find the byte after the input for store max or min element of each list

		Read_16(count_l_no) = Read_16(count_l_no) + 1;
	}

	Read_16(o_ptr) = Read_16(f_l_ptr);
	Read_16(f_l_ptr) = 2;
	Read_16(count_l_no) = 0;
	
	while(Read_16(count_l_no) != Read_16(l_no))
	{
		Read_16(l_ptr) = Read_16(f_l_ptr);            //point to the next list

		list_min();					//call list_min subroutine
		
		if(mem[err] == 1)			//error byte set to 1
		{
			printf("Error : [List No %d] : There is no element in the list..!!\n",Read_16(count_l_no)+1);
		}
		else if(mem[err] == 0)
		{
			Read_32(Read_16(o_ptr) + (Read_16(Read_16(o_ptr)) * 4)+2) = Read_32(ret_val);       //copy the output in output list
			Read_16(Read_16(o_ptr)) = Read_16(Read_16(o_ptr)) + 1;
		}

		Read_16(f_l_ptr) = Read_16(f_l_ptr) + (Read_16(Read_16(f_l_ptr)) * 4)+2;   //increment the pointer to point next list
		Read_16(count_l_no) = Read_16(count_l_no) + 1;
	}

	Read_16(l_ptr) = Read_16(o_ptr);             //set pointer to the output list
	
	printf("List of minimum number from each list : \n");
	Dis_list();						//display the output list

	if(mem[err] == 1)
	{
		printf("There is no element in the list\n");		
	}

	Read_16(l_ptr) = Read_16(o_ptr);
	list_max();					//find max from output list

	if(mem[err] == 1)
	{
		printf("There is  no element in the list\n");
	}

	printf("Maximum number from minimum list : %d\n\n\n",Read_32(ret_val));
	
	
	Read_16(Read_16(o_ptr)) = 0;
	Read_16(f_l_ptr) = 2;
	Read_16(count_l_no) = 0;

	while(Read_16(count_l_no) != Read_16(l_no))
	{
		Read_16(l_ptr) = Read_16(f_l_ptr);            //point to the next list

		list_max();					//call list_max for subroutine
		
		if(mem[err] == 1)			//error byte set to 1
		{
			printf("Error : [List No %d] : There is no element in the list..!!\n",Read_16(count_l_no)+1);
		}
		else if(mem[err] == 0)
		{
			Read_32(Read_16(o_ptr) + (Read_16(Read_16(o_ptr)) * 4)+2) = Read_32(ret_val);
			Read_16(Read_16(o_ptr)) = Read_16(Read_16(o_ptr)) + 1;
		}

		Read_16(f_l_ptr) = Read_16(f_l_ptr) + (Read_16(Read_16(f_l_ptr)) * 4)+2;
		Read_16(count_l_no) = Read_16(count_l_no) + 1;
	}

	Read_16(l_ptr) = Read_16(o_ptr);
	
	printf("List of maximum number from each list : \n");
	Dis_list();

	if(mem[err] == 1)
	{
		printf("There is no element in the list\n");
	}

	Read_16(l_ptr) = Read_16(o_ptr);
	list_min();

	if(mem[err] == 1)
	{
		printf("There is  no element in the list\n");
	}

	printf("Minimum number from maximum list : %d\n",Read_32(ret_val));

	return 0;
	}
