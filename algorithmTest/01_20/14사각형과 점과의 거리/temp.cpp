#include <iostream>

#include <stdio.h>



int main(int argc, char argv[]) {

FILE *infile;

int numcases;

int i;

int sx1, sy1, sx2, sy2;

int x, y;

int d1, d2;



infile = fopen("input.txt", "r");



fscanf(infile, "%d", &numcases);



for (i = 0;i < numcases;i++) {

fscanf(infile, "%d %d %d %d", &sx1, &sy1, &sx2, &sy2);

fscanf(infile, "%d %d", &x, &y);



if (sx1 <= x&&x <= sx2) {

if (sy1 <= y&&y <= sy2) {

d1 = 0;

d2 = 0;

}

else if (y < sy1) {

d1 = (sy1 - y)*(sy1-y);

d2 = sy1 - y;

}

else {

d1 = (y - sy2)*(y-sy2);

d2 = y - sy2;

}

}

else {

if (sy1 <= y&&y <= sy2) {

d1 = ((x>sx1) ? x - sx2 : sx1 - x)*((x>sx1) ? x - sx2 : sx1 - x);

d2 = (x>sx1) ? x - sx2 : sx1 - x;

}

else if (y < sy1) {

if (x < sx1) {

d1 = (x - sx1)*(x - sx1) + (y - sy1)*(y - sy1);

d2 = (sx1 - x) + (sy1 - y);

}

else {

d1 = (x - sx2)*(x - sx2) + (y - sy1)*(y - sy1);

d2 = (x - sx2) + (sy1 - y);

}

}

else {

if (x < sx1) {

d1 = (x - sx1)*(x - sx1) + (y - sy2)*(y - sy2);

d2 = (sx1 - x) + (y - sy2);

}

else {

d1 = (x - sx2)*(x - sx2) + (y - sy2)*(y - sy2);

d2 = (x - sx2) + (y - sy2);

}

}

}

std::cout << d1 << " " << d2 << std::endl;

}

}
