typedef struct {
	int *arr;
	int capacity;
	int index;
}dast;

dast* createDast(int capacity);

int insert(dast* da, int num); /*return 1 if succ and 0 if not*/

void printDast(dast* da);

void destoryDast(dast* da);