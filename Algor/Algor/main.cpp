//
//  main.cpp
//  Algor
//
//  Created by Lilly Fiorino on 6/4/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include <stdio.h>

int ack(int n, int m);
int main(int argc, const char * argv[])
{
    for(int a=0; a<6; a++){
        for(int b=0; b<6; b++){
            printf("ack(%d,%d) = %d\n", a, b, ack(a,b));
        }
    }
    return 0;
}

int ack(int m, int n)
{
    if (m == 0) return n+1;
    if (n == 0) return ack( m - 1, 1 );
    return ack( m - 1, ack( m, n - 1 ) );
}
