#include <stdio.h>
#include <stdlib.h>

#define ISSUSE 5
#define RATINGS 10

void recordResponse(int issuse, int rating);
void highestRating();
void lowestRating();
float averageRating(int issuse);
void displayResults();

int responses[ISSUSE][RATINGS];
const char *topics[ISSUSE] = {"Global Warming","The Economy","War","Health Care","Education"};

int main(void)
{
	int response, i;
	do
	{
		printf("Please rate the following topic on a scale from 1 - 10"
		"\n 1 = least important, 10  = most important\n");

		for (i = 0; i < ISSUSE; i++)
		{
			do {
				printf("%s? ",topics[i]);
				scanf_s("%d",&response);
			} while (response < 1 || response >10);

			recordResponse(i,response);
		}

		printf("Enter 1 to stop. Enter 0 to rate the issuse again.");
		scanf_s("%d",&response);
	} while (response != 1);
	displayResults();
	system("pause");
	return 0;
}

void recordResponse(int issuse, int rating)
{
	responses[issuse][rating - 1]++;
}

void highestRating()
{
	int highRating = 0;
	int highTopic = 0;
	int i, j;

	for (i = 0; i < ISSUSE; i++)
	{
		int topicRating = 0;
		for (j = 0; j < RATINGS; j++)
		{
			topicRating += responses[i][j] * (j + 1);
		}
		if (highRating < topicRating)
		{
			highRating = topicRating;
			highTopic = i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s",topics[highTopic]);
	printf("with a total rating of %d\n", highRating);
}

void lowestRating()
{
	int lowRating = 0;
	int lowTopic = 0;
	int i, j;

	for (i = 0; i < ISSUSE; i++)
	{
		int topicRating = 0;

		for (j = 0; j < RATINGS; j++)
		{
			topicRating += responses[i][j] * (j + 1);
		}
		if (i==0)
		{
			lowRating = topicRating;
		}
		if (lowRating > topicRating)
		{
			lowRating = topicRating;
			lowTopic = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topics[lowTopic]);
	printf("with a total rating of %d\n", lowRating);
}

float averageRating(int issuse)
{
	float total = 0;
	int counter = 0;
	int i;

	for (i = 0; i < RATINGS; i++)
	{
		if (responses[issuse][i] != 0)
		{
			total += responses[issuse][i] * (i + 1);
			counter += responses[issuse][i];
		}
	}
	return total / counter;
}

void displayResults()
{
	int i, j;
	printf("%20s","Topic");

	for (i = 1; i <= RATINGS; i++)
	{
		printf("%4d",i);
	}

	printf("%20s","Average Rating");
	printf("\n");
	for (i = 0; i < ISSUSE; i++)
	{
		printf("%20s",topics[i]);

		for (j = 0; j < RATINGS; j++)
		{
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f\n",averageRating(i));
	}
	highestRating();
	lowestRating();
}