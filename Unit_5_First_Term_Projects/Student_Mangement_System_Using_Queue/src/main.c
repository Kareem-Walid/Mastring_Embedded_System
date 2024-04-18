

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Student_System_Queue.h"


int main(void)
{

	int Loc_Exit_Flag = 1;
	int Loc_User_Choice;

	DPRINTF("===============@===============\n");
	DPRINTF("Welcome to the Student Management System");
	DPRINTF("\n===============@===============\n");



	while(Loc_Exit_Flag)
	{
		DPRINTF("----------------------------------------\n");
        DPRINTF("Choose the Task you want to perform\n");
		DPRINTF("1. Add Student Information Manually.\n");
		DPRINTF("2. Add Student Information From Text File.\n");
		DPRINTF("3. Find The Student Details by Roll Number.\n");
		DPRINTF("4. Find The Student Details by First Name.\n");
		DPRINTF("5. Find The Student Details by Course Id.\n");
		DPRINTF("6. Find The Total Number of Students.\n");
		DPRINTF("7. Delete The Student Details by Roll Number.\n");
		DPRINTF("8. Update The Student Details by Roll Number.\n");
		DPRINTF("9. Show All Information.\n");
		DPRINTF("10. Exit.\n");
		DPRINTF("----------------------------------------\n");
		DPRINTF("# Choice: ");
		scanf("%u",&Loc_User_Choice);


		switch(Loc_User_Choice)
		{
		case 1:
			Add_Student_Manually();
			break;

		case 2:
			Add_Student_File();
			break;

		case 3:
			Find_Student_From_Roll();
			break;

		case 4:
			Find_Student_From_Name();
			break;

		case 5:
			Find_Student_From_Course_ID();
			break;

		case 6:
			Find_Total_Students();
			break;
		case 7:
			Delete_Student_by_Roll_Number();
			break;

		case 8:
			Update_Student_by_Roll_Number();
			break;

		case 9:
			Display_All_Information();
			break;

		case 10:
			DPRINTF("Thanks for Using Our Student Management System...\n");
			Loc_Exit_Flag = 0;
			break;


		default:
			DPRINTF("[ERROR] Wrong User Choice ......Please Try Again...\n");
		}


	}




}
