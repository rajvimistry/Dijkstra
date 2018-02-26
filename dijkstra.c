#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc,char *argv[])
{
	FILE *file_ptr;
	int count = 0,i = 0,j = 0;
	char buf[100], *tok;
	file_ptr = fopen(argv[1],"r");
	if (!file_ptr)
        	printf("Unable to open a file");

	while(fscanf(file_ptr,"%[^\n]",buf) != EOF)
	{
		fgets(buf,10,file_ptr);
		count++;
	}

	int temp = 0;
	fclose(file_ptr);

	int matrix[count-1][count-1];

	//open and read from file
	file_ptr = fopen(argv[1],"r");
	if (!file_ptr)
        	printf("Unable to open a file");
	
	while(temp < count-1)
	{
		fscanf(file_ptr,"%[^\n]",buf);
		tok = strtok(buf,",");
			j=0;
			while(tok!=NULL)
			{
				matrix[i][j] = atoi(tok);
				tok = strtok(NULL,",");
				j++;
			}
		fgets(buf,10,file_ptr);
		i++;
		temp++;
	}

	//Creatig a Distance Matrix
	int distance[count-1], copy_distance[count-1], s=0, next_node = 0;
	
	printf("Enter a starting node: \n");
	scanf("%d",&s);
	

	for(i=0;i<count-1;i++)
	{
		distance[i] = matrix[s][i];
		copy_distance[i] = matrix[s][i];
	}

	int next_min_dist = 5000,count2=0;


	//finding next nearest node
l1:	for(i=0;i<count-1;i++)
	{
		if(i != s && distance[i]<next_min_dist && distance[i]>0 && copy_distance[i] != 10000)
		{
			next_min_dist = distance[i];
			next_node = i;
		}
	}

	count2++;
	next_min_dist = 5000;

	copy_distance[next_node] = 10000;

	//dijkstra's algorithm
	for(j=0;j<count-1;j++)
	{
		if(matrix[next_node][j]>0)
		{
			if(distance[j] > distance[next_node]+matrix[next_node][j] || distance[j] < 0)
			{
				distance[j] = distance[next_node]+matrix[next_node][j];
			}
			else
			{
				distance[j] = distance[j];
			}
		}
	}

	if(count2<count-1)
	{goto l1;}

	for(j=0;j<count-1;j++)
	{
		printf("Node %d: %d\n",j,distance[j]);
	}

	fclose(file_ptr);
}
