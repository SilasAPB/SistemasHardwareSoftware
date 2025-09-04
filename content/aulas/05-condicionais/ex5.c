//long ex5(long a, long b){
  //  if ((a==0)==(b==0)) goto f1;
 //   return b-2;
 //   f1:
 //   return a+5;
//}

long ex5(long a, long b){
    if ((a>0) && (b<=0)){
        return a+5;
    }
    return b-2;
}


