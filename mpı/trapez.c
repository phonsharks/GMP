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

/*
mpz_t n;
mpz_init(n);
mpz_set_ui(0,n);
mpz_clear(n);
*/


double general_first(double a,double b,double n,double f(double x))
{
    mpz_t a;
    mpz_t b;
    mpz_t n;
    mpz_init(a);
    mpz_init(b);
    mpz_init(n);
    mpz_set_ui(0,a);
    mpz_set_ui(0,b);
    mpz_set_ui(0,n);
    char inputStr[1024];
    h=abs(a-b)/n;
    for(int i=1;i<n;i++)
    {
        x=a+i*h;
        //sum+=f(x)
        mpz_mul(sum,sum,f(x));
        //burada yeni dizi oluşumu yapmam gerekmekte fazla olan sayı kontrolü için.
    }
    integral=(h/2)*(f(a)+f(b)+2*sum);
    return integral;
}



double general_second(double a,double b,double n,double f(double x))
{
    mpz_t a;
    mpz_t b;
    mpz_t n;
    mpz_init(a);
    mpz_init(b);
    mpz_init(n);
    mpz_set_ui(0,a);
    mpz_set_ui(0,b);
    mpz_set_ui(0,n);
    char inputStr[1024];
    h=abs(a-b)/n;
    for(int i=1;i<n;i++)
    {
        x=a+i*h;
        //sum+=f(x)
        mpz_mul(sum,sum,f(x));
        //burada yeni dizi oluşumu yapmam gerekmekte fazla olan sayı kontrolü için.
    }
    integral=(h/2)*(f(a)+f(b)+2*sum);
    return (integral * -1);
}


double general_all(){
    int s;
    s=general_second()+general_first();
    return s;
}


double trapeziodal(double a,double b,int n){
    
    if(a==0 && b==0){
        return 0;
    }
    
    if(a<0 && b<0){
        //Negatif kapsamda trapeziodal hesaplam yapacağım.
         general_second();
    }
    
    if((a>0 && b<0) || (a<0 && b>0)){
        //iki sınırdan birisinin pozitif yada negatif olma durumuna yönelik kodlamam
       general_all();
    }
    
    if((a!=0 || a>0) &&  (b!=0 || b>0)){
        //Normal trapez yöntemi ile irdeleme durumum.
        general_first();
    }
}











