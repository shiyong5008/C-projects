//shi.yong

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* next;
	int wins;
	int years;
}node_t;

node_t* create_list()
{
	node_t* year2018 = malloc(sizeof(node_t));
	node_t* year2017 = malloc(sizeof(node_t));
	node_t* year2016 = malloc(sizeof(node_t));
	node_t* year2015 = malloc(sizeof(node_t));
	node_t* year2014 = malloc(sizeof(node_t));

	//setup data
	year2018->years = 2018;
	year2017->years = 2017;
	year2016->years = 2016;
	year2015->years = 2015;
	year2014->years = 2014;

	year2018->wins = 108;
	year2017->wins = 93;
	year2016->wins = 93;
	year2015->wins = 78;
	year2014->wins = 71;


	//link data
	year2018->next = year2017;
	year2017->next = year2016;
	year2016->next = year2015;
	year2015->next = year2014;
	year2014->next = NULL;

	return year2018;
}

int main()
{
	node_t* redrox = NULL;
	redrox = create_list();

	node_t* iterator = redrox;
	while (iterator != NULL)
	{
		printf("wins in %d are %d\n", iterator->years, iterator->wins);
		iterator = iterator->next;
	}

	free(redrox);
	return 0;
}
