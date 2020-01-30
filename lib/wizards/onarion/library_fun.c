string short,long;

reset() {
   short = allocate(100);
   long = allocate(100);
}

get_short(num) {
   if (num == 1) { return "Basics of Magics"; }
}

get_long(num) {
   if (num == 1) {
      return "Magic is based on the words of power. If you don't know\n"+
	     "them, it is impossible to cast the spell.\n";
   }
}
