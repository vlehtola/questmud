inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("fox");
set_alias("fox");
switch(a) {
case 0 : set_level(8+random(6));
set_short("A skinny fox hunting rabbits");
set_gender(0);
set_alt_name("fox");

break;
case 1 : set_level(8+random(3));
set_short("A small fox hiding behind bush");
set_gender(0);
set_alt_name("fox");

break;
case 2 : set_level(10+random(4));
set_short("A small fox");
set_gender(0);
set_alt_name("fox");
break;
}
 set_long( "A small, dog like animal. The fur of this\n" +
 		   "fox is short, very thick undercoat covered\n" +
 		   "with long guard hairs. It is light \n" +
 		   "orange to brownish red in colour, with black\n" +
 		   "legs and ears, and a white under belly, chin,\n" +
 		   "and tail tip.\n");


 }