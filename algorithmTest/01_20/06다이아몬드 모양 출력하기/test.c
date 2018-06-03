space = (maxstar - 1) / 2;

line = ( (maxstar-1) / 2 ) + 1;

for ( ; line > 0 ; line-- ) // 아래로 내려 갈 수록 별이 늘어나는 for문

{

for( i = space ; i>=0 ; i-- ) {

printf(" ");

}

for ( i = star ; i>0  ; i-- ) {

printf("*");

}

space--;

star = star + 2;

printf("\n");

}

// 많이 변해버린 변수들을 초기화

space = space + 2;

line = (maxstar-1) / 2 ;

star = star - 4;

for ( ; line > 0 ; line-- ) // 내려 갈 수록 별이 줄어드는 for문

{

for( i = space ; i>=0 ; i-- ) {

printf(" ");

}

for ( i = star ; i>0  ; i-- ) {

printf("*");

}

space++;

star = star - 2 ;

printf("\n");

}

}
