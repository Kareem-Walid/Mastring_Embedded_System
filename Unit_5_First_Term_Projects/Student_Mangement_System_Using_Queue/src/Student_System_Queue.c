

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Student_System_Queue.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static int Queue_State(void);
static void Checking_Functions(void);
static int Check_Student_GPA(float Student_GPA);
static int Check_Student_Roll(int Roll_Number);
static int Check_Student_CourseID(int Courses_ID[]);
static void Display_Student_Information(void);


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/* The three main parameters for any Queue */
int gFront =0;
int gRear = 0;
int gCounter =0;

int Student_Roll;




/******************************************************************************
 * Function Number  : 1
 * \Syntax          : void Add_Student_Manually(void);
 * \Description     : This function can add student Manually, The user that manage the student system
 *                    can add student information manually.
 *                    The information scanned from user is :
 *                    1. Student Roll Number  2. First Name of the student 3. Last Name of student
 *                    3. GPA 4. Coursed that he/she want to enter
 *
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Add_Student_Manually(void)
{
	int Loc_Counter =0;

	/* 1. Validation Step
	 * Check if the Queue is Full */
	if(Queue_State() != Queue_Full)
	{
		/* 2. Store Data from User */
		DPRINTF("----------------------------------------\n");
		DPRINTF("---> Add The Student Details:\n");
		DPRINTF("----------------------------------------\n");

		DPRINTF("Enter the Student Roll Number: ");
		scanf("%u",&Students[gRear].Roll);
		DPRINTF("Enter the First Name of the Student: ");
		scanf("%s",&Students[gRear].FName);
		DPRINTF("Enter the Last Name of the Student: ");
		scanf("%s",&Students[gRear].LName);
		DPRINTF("Enter the GPA of  the Student: ");
		scanf("%f",&Students[gRear].GPA);
		DPRINTF("Enter the Course ID of every Student:\n");
		for(Loc_Counter=0; Loc_Counter< COURSES_WIDTH; Loc_Counter++)
		{
			DPRINTF("Course %u ID: ",Loc_Counter+1);
			scanf("%u",&Students[gRear].Credit_Id[Loc_Counter]);
			/* Note: If the user entered 0 it mean -> finish number of courses */
			if(Students[gRear].Credit_Id[Loc_Counter] == 0 ) break;
		}

		/*3. Check on the information that the user entered */
		Checking_Functions();

	}else{
		DPRINTF("----------------------------------------\n");
		DPRINTF("[ERROR] Queue is Full .....\n");
		DPRINTF("----------------------------------------\n");
	}

}




/******************************************************************************
 * Function Number  : 2
 * \Syntax          : void Add_Student_File(void);
 * \Description     : By using this function you can add set of students from external file
 *
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Add_Student_File(void)
{
	FILE  *Fptr;
	char String[100];
	int File_Counter=0;
	int Arr_Counter =0;
	int Credit_Counter = 0;
	float FGPA;

	int counter=0;
	int  Multi =1;
	int Rev_Counter =0;
	int Course_ID =0;

	/* Open File */
	Fptr = fopen(STUDENTS_FILE_NAME,"r");

	if(Fptr == NULL)
	{
		DPRINTF("----------------------------------------\n");
		DPRINTF("[ERROR] Can't be open the file...\n");
		DPRINTF("----------------------------------------\n");

	}else if (Queue_State() != Queue_Full)
	{
		while(fgets(String,50,Fptr) != NULL)
		{
			File_Counter =0;
			Arr_Counter =0;
			Credit_Counter = 0;

			/* Store Roll of Student */
			Students[gRear].Roll = atoi(String);

			while(String[File_Counter++] != SPACE);

			while(String[File_Counter] != SPACE)
				Students[gRear].FName[Arr_Counter++] = String[File_Counter++];

			/*Store Last Name of the Student*/
			File_Counter++;
			Arr_Counter = 0;
			while(String[File_Counter] != SPACE)
				Students[gRear].LName[Arr_Counter++] = String[File_Counter++];

			/* Store GPA */
			FGPA = String[++File_Counter] - ASCII_OFFSET;
			FGPA += (float)(String[File_Counter +=2] - ASCII_OFFSET)/10;
			Students[gRear].GPA= FGPA;

			/* Store Credit Courses */
			File_Counter += 2;
			while(String[File_Counter]  != '\0')
			{
				counter = 0;
				Course_ID =0;
				Multi = 1;
				File_Counter ++;
				while(String[File_Counter]  != '\0' && String[File_Counter] != ' ')
				{
					counter++;
					File_Counter ++;
				}

				Rev_Counter = File_Counter -1 ;
				while(String[Rev_Counter]  != ' ')
				{
					String[Rev_Counter] = String[Rev_Counter] -  ASCII_OFFSET;
					Course_ID  += (String[Rev_Counter] * Multi);
					Multi *=10;
					Rev_Counter -- ;
				}
				Students[gRear].Credit_Id[Credit_Counter] = Course_ID;
				Credit_Counter++;
			}

			//	Display_Student_Information(gRear);
			Checking_Functions();
		}

		/* Last Step : Close File */
		fclose(Fptr);

	}else{
		DPRINTF("----------------------------------------\n");
		DPRINTF("[ERROR] Queue is Full...");
		DPRINTF("----------------------------------------\n");

	}
}


/******************************************************************************
 * Function Number  : 3
 * \Syntax          : void Find_Student_From_Roll(void)
 * \Description     : This function can get student information by Student roll number
 *
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Find_Student_From_Roll(void)
{
	int Student_Roll;
	int result;
	DPRINTF("----------------------------------------\n");
	DPRINTF("Enter The Roll Number of the Student:");
	scanf("%u",&Student_Roll);
	result = Check_Student_Roll(Student_Roll);

	if(result == Roll_Exist)
	{
		Display_Student_Information();
	}else{
		DPRINTF("----------------------------------------\n");
		DPRINTF("[ERROR] Roll not Exist\n");
		DPRINTF("----------------------------------------\n");

	}
}



/******************************************************************************
 * Function Number  : 4
 * \Syntax          : void Find_Student_From_Name(void)
 * \Description     : This function can get student information by Student Name
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Find_Student_From_Name(void){

	char Loc_Name[50];
	int Loc_Front = gFront;
	int Loc_result;

	DPRINTF("------------------------------------\n");
	DPRINTF("Enter The First Name of the Student:");
	scanf("%s",&Loc_Name);

	while(Loc_Front < gCounter)
	{
		Loc_result = stricmp(Students[Loc_Front].FName,Loc_Name);
		if(Loc_result == 0)
		{
			Student_Roll = Loc_Front;
			Display_Student_Information();
			Loc_Front = (Loc_Front + 1 ) % NUMBER_OF_STUDENTS ;
			// break;
		}else{
			Loc_Front = (Loc_Front + 1 ) % NUMBER_OF_STUDENTS ;
		}
	}

}




/******************************************************************************
 * Function Number  : 5
 * \Syntax          : void Find_Student_From_Course_ID(void);
 * \Description     : This function can get student information by Course ID
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Find_Student_From_Course_ID(void)
{
	int Course_ID;
	int Local_Front = gFront;
	int Counter =0;
	int Students_Counter =0;

	DPRINTF("----------------------------------------\n");
	DPRINTF("Enter The Course ID: ");
	scanf("%u",&Course_ID);

	/* Loop on all Students */
	while(Local_Front < gCounter)
	{

		for(Counter = 0; Counter < COURSES_WIDTH; Counter++)
		{
			if(Students[Local_Front].Credit_Id[Counter] == Course_ID )
			{
				Student_Roll = Local_Front;
				Display_Student_Information();
				Students_Counter ++;
				continue ;
			}
		}

		Local_Front = (Local_Front + 1 ) % NUMBER_OF_STUDENTS ;

	}

	if(Students_Counter == 0)
	{
		DPRINTF("[ERROR] Course ID %u is Not Fount",Course_ID);
	}else{
		DPRINTF("[INFO] Total Number of Students Enrolled is: %u",Students_Counter);
	}

}


/******************************************************************************
 * Function Number  : 6
 * \Syntax          : void Find_Total_Students(void);
 * \Description     : This function used to get
 *                    1. total number of students and
 *                    2. all student you can add
 *                    3. number of students you can add
 *
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void Find_Total_Students(void)
{
	DPRINTF("----------------------------------------\n");
	DPRINTF("[INFO] The Total Number of Students is: %u\n",gCounter);
	DPRINTF("[INFO] You Can add up to %u Students.\n",NUMBER_OF_STUDENTS);
	DPRINTF("[INFO] You Can add %u More Students.\n",NUMBER_OF_STUDENTS - gCounter);
	DPRINTF("-----------------------------------------\n");

}



/******************************************************************************
 * Function Number  : 7
 * \Syntax          : void Delete_Student_by_Roll_Number(void);
 * \Description     : This function can delete student by Roll number
 *
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Delete_Student_by_Roll_Number(void)
{
	int Loc_Student_Roll;
	int Loc_Front = gFront;
	int i;
	int Loc_counter=0;
	int Loc_student_flag = 0;

	/* 1. Scan information from user */
	DPRINTF("----------------------------------------\n");
	DPRINTF("Enter The Roll Number of the Student: ");
	scanf("%u",&Loc_Student_Roll);


	while(Loc_Front < gCounter)
	{
		if(Loc_Student_Roll == Students[Loc_Front].Roll)
		{
			/* 2. Shifting all students by one */
			Loc_student_flag = 1;
			while(gCounter - Loc_counter++)
			{

				/* a. Shift roll number by 1*/
				Students[Loc_Front].Roll = Students[Loc_Front +1].Roll;

				/* b. Shift First Name */
				for(i=0 ; i<= NAME_WIDTH ; i++)
				{
					Students[Loc_Front].FName[i] = Students[Loc_Front +1].FName[i];
				}

				/* c. Shift Last Name */
				for(i=0 ; i<= NAME_WIDTH ; i++)
				{
					Students[Loc_Front].LName[i] = Students[Loc_Front +1].LName[i];
				}

				/* d. Shift GPA of the student*/
				Students[Loc_Front].GPA = Students[Loc_Front +1 ].GPA;

				/* e. shift Coursed ID */
				for(i=0 ; i<= COURSES_WIDTH ; i++)
				{
					Students[Loc_Front].Credit_Id[i] = Students[Loc_Front +1].Credit_Id[i];
				}
				Loc_Front ++;
			}
		}else{

			// Inc Local_Front
			Loc_Front = (Loc_Front + 1 ) % NUMBER_OF_STUDENTS ;
			Loc_counter ++;
		}

	}

	gRear --;
	gCounter --;

	if(Loc_student_flag == 1)
	{
		DPRINTF("[INFO] The Student is removed successfully...\n");
		Find_Total_Students();
	}
	else {
		DPRINTF("[ERROR] This Roll Number %u Not found",Student_Roll);
	}



}



/******************************************************************************
 * Function Number  : 8
 * \Syntax          : void Update_Student_by_Roll_Number(void);
 * \Description     : This function can update student by Roll number.
 *
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Update_Student_by_Roll_Number(void)
{
	int loc_student_roll;
	int Loc_Student[COURSES_WIDTH];
	float Loc_GPA;
	int Loc_choice;
	int Loc_Counter =0;
	int loc_error_flag =1;
	DPRINTF("----------------------------------------\n");
	DPRINTF("Enter The Roll Number of the Student: ");
	scanf("%u",&loc_student_roll);

	if(Check_Student_Roll(loc_student_roll) == Roll_Exist)
	{

		DPRINTF("----------------------------------------\n");
		DPRINTF("Which operation you want to perform ? \n")
		DPRINTF("1. Roll Number\n");
		DPRINTF("2. First Name\n");
		DPRINTF("3. Last Name\n");
		DPRINTF("4. GPA\n");
		DPRINTF("5. Course ID\n");
		DPRINTF("# Choice: ");
		scanf("%u",&Loc_choice);

		switch(Loc_choice)
		{
		case 1:
			DPRINTF("Enter the New Roll of the Student: ");
			scanf("%u",&loc_student_roll);
			/* Checking Step */
			if(Check_Student_Roll(loc_student_roll) == Roll_Exist)
			{
				DPRINTF("[ERROR] Roll Number %u is Already Existing \n",loc_student_roll);
				loc_error_flag = 0;
			}else{
				Students[Student_Roll].Roll = loc_student_roll;
			}
			break;


		case 2:
			DPRINTF("Enter the New First Name of the Student: ");
			scanf("%s",Students[Student_Roll].FName);
			break;

		case 3:
			DPRINTF("Enter the New Last Name of the Student: ");
			scanf("%s",Students[Student_Roll].LName);
			break;

		case 4:
			DPRINTF("Enter the New GPA of the Student: ");
			scanf("%f",&Loc_GPA);
			if (Check_Student_GPA(Loc_GPA) == GPA_Error)
			{
				DPRINTF("[ERROR] GPA Number %0.2f is Not True. Hint: GPA must be from 0 to 4 \n",Loc_GPA);
				loc_error_flag = 0;
			}else
			{
				Students[Student_Roll].GPA = Loc_GPA;
			}
			break;


		case 5:
			DPRINTF("Enter the New Courses of the Student: \n");
			for(Loc_Counter=0;Loc_Counter< COURSES_WIDTH ;Loc_Counter++)
			{
				DPRINTF(" Course %u ID: ",Loc_Counter+1);
				scanf("%u",&Loc_Student[Loc_Counter]);
			}

			if(Check_Student_CourseID(Loc_Student)== Course_ID_Exist)
			{
				DPRINTF("[ERROR] Two Courses ID with the same ID \n");
				loc_error_flag = 0;
			}else{

				for(Loc_Counter=0;Loc_Counter< COURSES_WIDTH ;Loc_Counter++)
				{
					Students[Student_Roll].Credit_Id[Loc_Counter] = Loc_Student[Loc_Counter];
				}
			}

			break;

		}
		if(loc_error_flag == 1)
		{
			DPRINTF("----------------------------------------\n");
			DPRINTF("[INFO] Information UPDATED SUCCESSFULLY....\n");
			DPRINTF("----------------------------------------\n");
		}

		loc_error_flag = 1 ;
	}else{
		DPRINTF("----------------------------------------\n");
		DPRINTF("[ERROR] This Roll Number %u Not found",Loc_Student[0]);
		DPRINTF("\n----------------------------------------\n");
	}
}





/******************************************************************************
 * Function Number  : 9
 * \Syntax          : void Display_All_Information(void);
 * \Description     : This function used to display all student information
 *
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Display_All_Information(void)
{
	int Loc_Student_ID = gFront;

	if(Queue_State() == Queue_Empty)
	{
		DPRINTF("\n[ERROR] No Students in the System (System Still Empty)\n")
	}else
	{
		while(Loc_Student_ID < gCounter)
		{
			Student_Roll = Loc_Student_ID;
			Display_Student_Information();
			Loc_Student_ID++;
		}

	}

}



/********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *******************************************************************************************************************/
/******************************************************************************
 * Function Number  : 1
 * \Syntax          : static int Queue_State(void);
 * \Description     : This is a local function that can check on the queue state
 *
 * \Parameters (in) : None
 * \Parameters (out): Queue State
 * \Return value:   : Queue_Full, Queue_Empty or  Queue_Not_Full_Or_Empty
 *******************************************************************************/

static int Queue_State(void){
	Queue_Status State;
	if(gCounter == NUMBER_OF_STUDENTS)
	{
		State= Queue_Full;

	}else if(gCounter == 0)
	{
		State = Queue_Empty;
	}else{
		State = Queue_Not_Full_Or_Empty;
	}

	return State;
}


/******************************************************************************
 * Function Number  : 2
 * \Syntax          : static void Checking_Functions(void);
 * \Description     : This function is a combination of three functions that check on the user information that he entered
 *                    1. Roll 2. GPA  3. Coursed ID
 *                    and this function display the result of the checking.
 *
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

static void Checking_Functions(void){

	int loc_Roll_Result;
	int loc_GPA_Result;
	int loc_CoursesID_Result;


	loc_Roll_Result = Check_Student_Roll(Students[gRear].Roll);
	loc_GPA_Result = Check_Student_GPA(Students[gRear].GPA);
	loc_CoursesID_Result = Check_Student_CourseID(Students[gRear].Credit_Id);



	if (loc_Roll_Result == Roll_Not_Found && loc_GPA_Result == GPA_True && loc_CoursesID_Result == Course_ID_True )
	{
		gRear = ((gRear + 1 ) % NUMBER_OF_STUDENTS);
		gCounter ++;
		DPRINTF("----------------------------------------\n");
		DPRINTF("[INFO] Student Details is Added Successfully..\n");
		DPRINTF("----------------------------------------\n");
		Find_Total_Students();
	}else if(loc_Roll_Result == Roll_Exist)
	{
		DPRINTF("[ERROR] Roll Number %u is Already Existing \n",Students[gRear].Roll);

	}else if(loc_GPA_Result == GPA_Error)
	{
		DPRINTF("[ERROR] GPA Number %0.2f is Not True. Hint: GPA must be from 0 to 4 \n",Students[gRear].GPA);
	}else if(loc_CoursesID_Result == Course_ID_Exist)
	{
		DPRINTF("[ERROR] Two Courses ID with the same ID \n");
	}
}




/******************************************************************************
 * Function Number  : 3
 * \Syntax          : static int Check_Student_Roll(int Roll_Number)
 * \Description     : This function checking on the roll number if this roll exist or not
 *
 * \Parameters (in) : None
 * \Parameters (out): State
 * \Return value:   : Roll_Not_Found or Roll_Exist
 *******************************************************************************/
static int Check_Student_Roll(int Roll_Number)
{
	Student_State_t State = Roll_Not_Found;
	int Local_Front = gFront;

	while(Local_Front < gCounter)
	{
		if(Roll_Number == Students[Local_Front].Roll)
		{
			State = Roll_Exist;
			Student_Roll = Local_Front;
			break;
		}else{
			Local_Front = (Local_Front + 1 ) % NUMBER_OF_STUDENTS;
		}
	}

	return State;
}



/******************************************************************************
 * Function Number  : 4
 * \Syntax          : static int Check_Student_GPA(float Student_GPA);
 * \Description     : This function responsible for checking on GPA it must be between 0 ~ 4
 *
 * \Parameters (in) : None
 * \Parameters (out): State
 * \Return value:   : GPA_True or GPA_Error
 *******************************************************************************/
static int Check_Student_GPA(float Student_GPA)
{
	Student_State_t  State = GPA_Error;

	if(Student_GPA <= 4 && Student_GPA >= 0)
	{
		State = GPA_True;
	}else{
		State = GPA_Error;
	}
	return State;
}



/******************************************************************************
 * Function Number  : 5
 * \Syntax          : This function responsible for checking on coursed id
 * \Description     :
 *
 * \Parameters (in) : None
 * \Parameters (out): State
 * \Return value:   : Course_ID_True or Course_ID_Exist
 *******************************************************************************/
static int Check_Student_CourseID(int Courses_ID[])
{
	int loc_Counter = 0;
	int loc_Counter2=0;
	Student_State_t  State = Course_ID_True;
	for(loc_Counter=0; loc_Counter<COURSES_WIDTH && State != Course_ID_Exist; loc_Counter++)
	{
		for(loc_Counter2 = loc_Counter+1;loc_Counter2<COURSES_WIDTH ;loc_Counter2++)
		{
			if(Courses_ID[loc_Counter] == Courses_ID[loc_Counter2] && Courses_ID[loc_Counter] != 0)
			{
				State =  Course_ID_Exist ;
				break;
			}
		}
	}

	return State;
}



/******************************************************************************
 * Function Number  : 6
 * \Syntax          : this function used to display student information
 * \Description     :
 *
 * \Parameters (in) : None
 * \Parameters (out): State
 * \Return value:   : Course_ID_True or Course_ID_Exist
 *******************************************************************************/
static void Display_Student_Information(void)
{
	int Loc_Counter = 0;
	/*Print All Information */
	DPRINTF ("================================================ \n");
	DPRINTF("The Student Details are:\n");
	DPRINTF("The Student Roll:%u \n",Students[Student_Roll].Roll);
	DPRINTF("First Name:%s \n",Students[Student_Roll].FName);
	DPRINTF("Last Name:%s \n",Students[Student_Roll].LName);
	DPRINTF("GPA:%0.1f \n",Students[Student_Roll].GPA);
	DPRINTF("Courses ID: \n");
	for(Loc_Counter =0; Loc_Counter < COURSES_WIDTH ;Loc_Counter++)
	{
		if(Students[Student_Roll].Credit_Id[Loc_Counter] == 0) break;
		DPRINTF("  Course %u ID: %u \n",Loc_Counter+1,Students[Student_Roll].Credit_Id[Loc_Counter]);
	}

	DPRINTF ("================================================ \n");
	DPRINTF("\n");
}


