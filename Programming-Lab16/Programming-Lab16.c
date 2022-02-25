#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define ANGLE_MIN_VALUE    0.0
#define ANGLE_MAX_VALUE    180.0
#define TRIANGLE_ANGLE_SUM 180.0
#define MAX_COS_SUM        1.5
#define EPSILON            1e-15

#define EQUAL(a,b) abs(a-b)<EPSILON

#define LESS_THAN_OR_EQUAL(a,b) a-b<EPSILON

#define ENTER_ANGLE(a) {\
	do\
	{\
		printf("Enter angle "#a" between 0 and 180 degrees: ");\
		scanf_s("%lf",&a);\
	}while(LESS_THAN_OR_EQUAL(a,ANGLE_MIN_VALUE)||LESS_THAN_OR_EQUAL(ANGLE_MAX_VALUE,a));\
}

#define NEW_LINE() putchar('\n');

#define COS(x) cos(x)

#define TO_RADIANS(a) a/ANGLE_MAX_VALUE*M_PI

#define CHECK(A,B,C) {\
	double cos_sum = COS(TO_RADIANS(A))+COS(TO_RADIANS(B))+COS(TO_RADIANS(C));\
	printf("cos(%lf) + cos(%lf) + cos(%lf) = %lf\n",A,B,C,cos_sum);\
	puts(LESS_THAN_OR_EQUAL(cos_sum,MAX_COS_SUM)?"True":"False");\
}

#define OUTPUT_MESSAGE(m) puts(m)

int main()
{
	double A, B, C;

	OUTPUT_MESSAGE("Enter triangle angles A, B and C (in degrees):");

	ENTER_ANGLE(A);
	ENTER_ANGLE(B);
	ENTER_ANGLE(C);

	NEW_LINE();

	if (EQUAL(A + B + C, TRIANGLE_ANGLE_SUM))
	{
		CHECK(A, B, C);
	}
	else
	{
		OUTPUT_MESSAGE("Wrong input");
	}
}