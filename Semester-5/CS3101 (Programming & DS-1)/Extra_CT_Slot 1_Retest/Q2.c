#include <stdio.h>
#include <string.h>

// Defining struct for storing judge scores for various rounds
typedef struct judge
{
	char name[10];
	int round1[6];
	int round2[6];
	int round3[6];
	int semifinal[6];
} JUDGE;


// Function to print an array
void print_array(int *ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", ptr[i]);
	}
	printf("\n");
}


// Function to find minimum of scores array for non-eliminated participants
// Returns index of minimum scoring participant
int check_min(int *arr, int *eliminated, int size)
{
	int min = 1000;
	int index = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min && eliminated[i] != 1)
		{
			min = arr[i];
			index = i;
		}
	}

	return index;	
}

// Function to find maximum of scores array for non-eliminated participants
// Returns index of maximum scoring participant
int check_max(int *arr, int size)
{
	int max = arr[0];
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}

	return index;
}


void main()
{
	printf("\n");
	printf("Welcome to the singing reality show Kontho!\n");
	printf("\n");

	// Input from user for number of judges and participants
	int judge_num;
	int participant_num;

	printf("Enter the number of judges: ");
	scanf("%d", &judge_num);
	printf("Enter the number of participants: ");
	scanf("%d", &participant_num);
	printf("\n");

	while (getchar() != '\n');

	// Initialising an array to store all judge structs
	JUDGE judges[judge_num];
	char jname[10];

	// Asking for name of judges from user
	for (int i = 0; i < judge_num; i++)
	{
		printf("Enter name of judge %d: ", i+1);
		fgets(jname, sizeof(jname), stdin);
		jname[strcspn(jname, "\n")] = 0;

		strcpy(judges[i].name, jname); 
	}
	printf("\n");

	// Initialsing an array for storing participant names
	char participants[participant_num][20];
	char pname[20];
	int eliminated[participant_num];	// 0 if particioant is not eliminated, 1 otherwise

	// Asking for participant names from user
	for (int i = 0; i < participant_num; i++)
	{
		printf("Enter name of participant %d: ", i+1);
		fgets(pname, sizeof(pname), stdin);
		pname[strcspn(pname, "\n")] = 0;

		strcpy(participants[i], pname);
		eliminated[i] = 0;
	}
	printf("\n");

	int score;	  // Store score of each judge for 1 participant
	int pid = 0;  // Index of participants
	int total[participant_num]; // To store total score of all rounds for each participant

	// ROUND 1
	printf("ROUND 1\n");
	printf("\n");

	// Score input from judges for each participant
	for (int i = 0; i < judge_num; i++)
	{
		printf("Hello %s. Please enter your scores for the following participants.\nEnter -1 if you want to undo a score for a participant\n", judges[i].name);

		while (pid < participant_num)
		{
			printf("%s: ", participants[pid]);
			scanf("%d", &score);

			// If score is greater than 10, enter again
			if (score > 10)
			{
				printf("Score cannot be greater than 10. Enter again\n");
				printf("\n");
				continue;
			}

			// Undo last input
			if (score == -1)
			{
				pid--;
				total[pid] -= judges[i].round1[pid];
				continue;
			}

			judges[i].round1[pid] = score;

			if (i == 0)
			{
				total[pid] = score;
			}
			else
			{
				total[pid] += score;
			}

			pid++;
		}

		pid = 0;
		printf("\n");
	}

	// Find out the minimum scoring participants of ROUND 1
	int index = check_min(total, eliminated, participant_num);

	// Printing total and eliminated participant
	printf("Total after round 1: ");
	print_array(total, participant_num);
	printf("Eliminated participant of round 1: %s\n", participants[index]);
	eliminated[index] = 1;		// Updating elimination array
	printf("\n");

	// ROUND 2
	printf("ROUND 2\n");
	printf("\n");

	// Score input from judges for each participant
	for (int i = 0; i < judge_num; i++)
	{
		printf("Hello %s. Please enter your scores for the following participants.\nEnter -1 if you want to undo a score for a participant\n", judges[i].name);

		while (pid < participant_num)
		{
			// No input for eliminated participants
			if (eliminated[pid] == 1)
			{
				judges[i].round2[pid] = 0;
				pid++;
				continue;
			}

			printf("%s: ", participants[pid]);
			scanf("%d", &score);

			// If score is greater than 10, enter again
			if (score > 10)
			{
				printf("Score cannot be greater than 10. Enter again\n");
				printf("\n");
				continue;
			}

			// Undo last input
			else if (score == -1)
			{
				// Go back 2 indices if the previous participant was eliminated
				if (eliminated[pid-1] == 1)
				{
					pid--;
				}

				pid--;
				total[pid] -= judges[i].round2[pid];
				continue;
			}

			judges[i].round2[pid] = score;
			total[pid] += score;

			pid++;
		}

		pid = 0;
		printf("\n");
	}

	// Find out the minimum scoring participant of ROUND 2
	index = check_min(total, eliminated, participant_num);

	printf("Total after round 2: ");
	print_array(total, participant_num);
	printf("Eliminated participant of round 2: %s\n", participants[index]);
	eliminated[index] = 1;
	printf("\n");

	// ROUND 3
	printf("ROUND 3\n");
	printf("\n");

	// Score input from judges for each participant
	for (int i = 0; i < judge_num; i++)
	{
		printf("Hello %s. Please enter your scores for the following participants.\nEnter -1 if you want to undo a score for a participant\n", judges[i].name);

		while (pid < participant_num)
		{
			// No input for eliminated participant
			if (eliminated[pid] == 1)
			{
				judges[i].round3[pid] = 0;
				pid++;
				continue;
			}

			printf("%s: ", participants[pid]);
			scanf("%d", &score);

			// If score is greater than 10, enter again
			if (score > 10)
			{
				printf("Score cannot be greater than 10. Enter again\n");
				printf("\n");
				continue;
			}

			// Undo last input
			else if (score == -1)
			{
				// Go back 2 indices if the previous participant was eliminated
				if (eliminated[pid-1] == 1)
				{
					pid--;
				}

				pid--;
				total[pid] -= judges[i].round3[pid];
				continue;
			}

			judges[i].round3[pid] = score;
			total[pid] += score;

			pid++;
		}

		pid = 0;
		printf("\n");
	}

	// Find out the minimum and maximum scoring participants of ROUND 3
	index = check_min(total, eliminated, participant_num);
	int immunity_index = check_max(total, participant_num);

	printf("Total after round 3: ");
	print_array(total, participant_num);
	printf("Eliminated participant of round 3: %s\n", participants[index]);
	eliminated[index] = 1;
	printf("\n");

	// SEMIFINAL
	printf("SEMI-FINAL\n");
	printf("\n");

	// Score input from judges for each participant
	for (int i = 0; i < judge_num; i++)
	{
		printf("Hello %s. Please enter your scores for the following participants.\nEnter -1 if you want to undo a score for a participant\n", judges[i].name);

		while (pid < participant_num)
		{
			// No input for eliminated participant
			if (eliminated[i] == 1)
			{
				judges[i].semifinal[pid] = 0;
				pid++;
				continue;
			}

			printf("%s: ", participants[pid]);
			scanf("%d", &score);

			// If score is greater than 10, enter again
			if (score > 10)
			{
				printf("Score cannot be greater than 10. Enter again\n");
				printf("\n");
				continue;
			}

			// Undo last input
			else if (score == -1)
			{
				// Go back 2 indices if the previous participant was eliminated
				if (eliminated[pid-1] == 1)
				{
					pid--;
				}

				pid--;
				total[pid] -= judges[i].semifinal[pid];
				continue;
			}

			judges[i].semifinal[pid] = score;
			total[pid] += score;

			pid++;
		}

		pid = 0;
		printf("\n");
	}

	// Find out the minimum scoring participant of SEMI-FINAL
	index = check_min(total, eliminated, participant_num);

	printf("Total after semi-final: ");
	print_array(total, participant_num);

	if (index == immunity_index)
	{
		printf("No participant is eliminated in Semi-Finals\n");
	}
	else
	{
		printf("Eliminated participant of Semi-Finals: %s\n", participants[index]);
		eliminated[index] = 1;
	}
	printf("\n");
}
