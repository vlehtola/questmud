test(int chance) {
  int i,max,x;
/*  i |= 1 << random(max); */
  for(x=0;x<10;++x) {
    i |= 1 << x;
    write("i: "+i+"\n");
  }
}
test2() {
  int i;
  i = 32;
  if(i & 2*2*2*2*2) { write("jee\n"); }
  if(i & 2*2*2*2) { write("jee\n"); }
  i |= 2;
  return i;
}
/*
        if (scar & j) {        jos scarin bit slotissa j on jotain
            old_value &= ~j;   old valuen j slotti pois
*/
