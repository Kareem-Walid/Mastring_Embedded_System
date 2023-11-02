#include "Linked_List.h"
extern gpFirstStudent;
int main()
{
	uint8 option[40];
	uint32  Length;
	while(1){

		DPRINTF("\n==============================");
		DPRINTF("\nChose one of the Following Options:");
		DPRINTF("\n1. Add Student:");
		DPRINTF("\n2. Delete Student:");
		DPRINTF("\n3. View Student:");
		DPRINTF("\n4. Delete All:");
		DPRINTF("\n5. Get Nth Index:");
		DPRINTF("\n6. Get Nth Index from End:");
		DPRINTF("\n7. Length of the List:");
		DPRINTF("\n8. Get The Middle:");
		DPRINTF("\n9. Detect Loop:");
		DPRINTF("\n10. Reverse Linked List:")
		DPRINTF("\n==============================");
		DPRINTF("\nEnter Your Option:");
		gets(option);
		switch(atoi(option))
		{
		case 1:
			Add_Student();
			break;
		case 2:
			Delete_Student();
			break;
		case 3:
			View_All();
			break;
		case 4:
			Delete_All();
			break;
		case 5:
			Get_Nth_Index();
			break;
		case 6:
			Get_Nth_Index_end();
			break;
		case 7:
			Length = Get_Length_2(gpFirstStudent);
			DPRINTF("Length of the List:%d",Length);
			break;
		case 8:
			Get_Middle();
			break;

		case 9:
			Detect_Loop();
			break;
		case 10:
			Reverse_List();
			break;

		default:
			DPRINTF("\nWrong Option...");

		}

	}

	return 1;
}
