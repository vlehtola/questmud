string short,long;

reset() {
   short = allocate(100);
   long = allocate(100);
}

get_short(num) {
   if (num == 1) { return "Book labelled 'Basics of Magic'"; }
   if (num == 2) { return "Book labelled 'Offensive Magics'"; }
   if (num == 3) { return "Book labelled 'Essence casting'"; }
}

get_long(num) {
   if (num == 1) {
      return "Magic is based on the words of power. If you don't know\n"+
	     "them, it is impossible to cast the spell.\n";
   }
   if (num == 2) {
      return "Essence offensive magic damage is based on the casters\n"+
 	"casting skills of the used words, his intelligence and\n"+
	"his mastery skills. There are three affecting mastery skills; one\n"+
	"for each damage type, mastery of the castegory of the damage type;\n"+
	"mastery of elements or mastery of nature, and finally offensive\n"+
	"mastery.\n";
   }
   if (num == 3) {
      return "The word for essence casting, cast essence, is 'exs'.\n";
   }
}
