#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *	2. DEFINIEREN SIE EINE STRUKTUR row_t ...
 */
typedef struct
{
	int id;
	char *name;
	char *ip_addr;
	char *tech_name;
} row_t;

static int compare(const void *a, const void *b)
{
	const row_t *rowA = (const row_t *)a;
	const row_t *rowB = (const row_t *)b;

	int result;
	/* TODO: result<0 if a<b, result>0 if a>b, result=0 if a==b */


	return result;
}

void init_row(row_t *row) {
	row->name	= (char *) malloc(31);
	row->ip_addr	= (char *) malloc(15);
	row->tech_name	= (char *) malloc(31);
}

int main(int argc, char **argv)
{
	// Check arguments
	if(argc < 2)
	{
		printf("Please provide test case file name\n");
		return 0;
	}

	// Read file
	FILE *fp = fopen(argv[1], "r");

	/*
	 *	3. LESEN SIE MITHILFE VON FSCANF DIE ANZAHL ...
	 *	(2 + 32 + 16 + 32 for each row (not forgetting '\n'))
	 */
	int row_count;
	fscanf(fp, "%d", &row_count);
	row_t *rows = (row_t *) calloc(row_count, 5 + 82*row_count);
	printf("row_count: %d\n", row_count);

	/*
	 *	4. LESEN SIE NUN DIE EINZELNEN ZEILEN MIT fscanf IN rows EIN
	 */
	int i = 0;
	init_row(&rows[i]);

	while (i < row_count) {
		fscanf(fp, "%d %s %s %s\n", &rows[i].id, rows[i].name, rows[i].ip_addr, rows[i].tech_name);
		printf("%d %s %s %s\n", rows[i].id, rows[i].name, rows[i].ip_addr, rows[i].tech_name);
		i++;
		init_row(&rows[i]);
	}

	fclose(fp);

	/*
	 *	5. SORTIERALGORITHMUS ANWENDEN
	 */
	// qsort(/* TODO: ?, ?, ? */, compare);

	/*
	 *	7. GEBEN SIE DAS SORTIERTE ARRAY IM KORREKTEN FORMAT AUS
	 */
	printf("legga array :3\n");

	/*
	 *	8. GEBEN SIE DAS FORMALS ALLOZIIERTE ARRAY WIEDER FREI
	 */
	free(rows);

	return 0;
}
