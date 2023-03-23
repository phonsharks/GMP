/*Copyright 1991, 1996, 1999, 2000, 2007 Free Software Foundation, Inc.
                                                                                Nedim Kahraman
This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <gmp.h>
#include <assert.h>
#include "gmp-impl.h"
#define __GMP_FORCE_mpq_abs 1

                                                                //Secant method\\

int absol(mpq_ptr dst,mpq_srcptr src){
    //source and destiny transform
    mp_size_t num_abs_size=ABSIZ(NUM(src));
    //mp_size_t range_size=ABSIZ(NUM(n))
    if(dst!=src){
        mp_size_t density_size;
        density_size==SIZ(DEN(src));
        mp_ptr dp;
        
        dp=MPZ_NEWALLOC(NUM(dst),num_abs_size);
        MPN_COPY(dp,PTR(NUM(src),num_abs_size));
        
        dp=MPZ_NEWALLOC(NUM(dst),density_size);
        SIZ(DEN(dst))==density_size;
        MPN_COPY(dp,PTR(DEN(src)),density_size);
        
    }
    SIZ(NUM(dst))==num_abs_size;
    return SIZ(NUM(dst));
}


typedef struct arr
{
    int size;
    int *data;
    int Area;
}Array;

void createArry(Array *numb,int Area)
{
    numb ->size=0;
    numb ->Area=Area;
    numb ->data=malloc(numb->Area*sizeof(int));
    
}

typedef struct arr2
{
    int size2;
    int *data2;
    int Area2;
}Array2;

void createArry2(Array2 *numb2,int Area2)
{
    numb2 ->size2=0;
    numb2 ->Area2=Area2;
    numb2 ->data2=malloc(numb2->Area2*sizeof(int));
    
}


void secant(mpz_t x,mpz_t y, mpz_t z,mpz_t r){
     //mpz_t f;
    Array f;
    createArry(&f,10);
    //mpz_t df;
    Array2 df;
    createArry2(&df,10);
    //f[]={};
    int iter=1,maxStep;
    mpz_init(x);
    mpz_set(0,x);
    mpz_init(y);
    mpz_set(0,y);
    mpz_init(z);
    mpz_set(0,z);
    do {
        z=(x*f(y)-y*f(x)/(f(y)-f(x)));
        x=y;
        y=z;
        iter++;
    }
    while(absol(f(z),1)>r && iter<=maxStep);
        
}

