#ifndef H_AB
#define H_AB

typedef struct node node;
typedef struct AverageBuffer AverageBuffer;

void* allocAverageBuffer(int size);
void clearAverageBuffer(AverageBuffer* ab);
void freeAverageBuffer(AverageBuffer* ab);
void addSample(AverageBuffer* ab, int randNum);

//when num of sampales is >=4 we need to check every step;
void checkQuarter(AverageBuffer* ab);

double getAverage(AverageBuffer* ab);
double getAverageForever(AverageBuffer* ab);
double getUpperQuarterAverage(AverageBuffer* ab);
double getLowerQuarterAverage(AverageBuffer* ab);

#endif
