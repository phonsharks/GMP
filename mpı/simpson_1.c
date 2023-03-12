/*Copyright 1991, 1996, 1999, 2000, 2007 Free Software Foundation, Inc.

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

//simpson integration derivative(1/3)


int absol(mpq_ptr dst,mpq_srcptr src){
    //source and destiny transform
    mp_size_t num_abs_size=ABSIZ(NUM(src));
    //mp_size_t range_size=ABSIZ(NUM(n))
    if(dst!=src){
        mp_size_t density_size=SIZ(DEN(src));
        mp_ptr dp;
        
        dp=MPZ_NEWALLOC(NUM(dst),num_abs_size);
        MPN_COPY(dp,PTR(NUM(src),num_abs_size));
        
        dp=MPZ_NEWALLOC(NUM(dst),density_size);
        SIZ(DEN(dst))=density_size;
        MPN_COPY(dp,PTR(DEN(src)),density_size);
        
        //dp=MPZ_NEWALLOC(NUM(dst),range_size);
        
    }
    SIZ(NUM(dst))=num_abs_size;
    return SIZ(NUM(dst));
}


void mpı_s(mpz_t *a,mpz_t *b,mpz_t n){
   
    mpz_t integral;
    mpz_t sum;
    mpz_t x;
    mpz_t h;
    mpz_t f;
    mpz_t X;
    mpq_t Y;
    mpz_init(a);
    mpz_init(b);
    mpz_init(n);
    mpz_init(h);
    mpq_init(f);
    mpz_init(integral);
    mpz_init(x);
    mpz_init(sum);
    mpz_init(X);
    mpq_init(Y);
    mpz_set(0,sum);
    mpz_set(0,a);
    mpz_set(0,b);
    mpz_set(0,n);
    mpz_set(0,integral);
    mpz_set(0,x);
    mpq_set(0,f);
    mpz_set(0,X);
    mpq_set(0,Y);
    h=absol(b,a);
    mpz_div(h,h,n);
    for(int i=0;i<n;i++){
        mpz_sum(x,i,h);
        mpz_add(x,a,x);
       // x=a+i*h;
        if(i%2==0){
           // sum=sum+2*f(x);
            mpz_sum(sum,2,f);
            mpz_add(sum,0,sum);
        }
        else{
            //sum=sum+4*f(x);
            mpz_sum(sum,4,f);
            mpz_add(sum,0,sum);
        }
    }
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(n);
    //mpq_div()
    //mpq_add()
    //mpq_sum()
    //X,Y,Z 
    mpz_div(h,h,3);
    Y=mpz_add(sum,f(a),f(b));
    mpz_sum(integral,X,Y);
   // integral=(mpz_div(h,h,3)*(mpz_add(sum,f,f)));
    mpz_clear(integral);
    //return integral;
}
