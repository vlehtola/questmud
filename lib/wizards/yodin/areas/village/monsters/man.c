inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_race("human");
set_name("man");
set_alias("human");
switch(a) {
case 0 : set_level(25+random(5));
set_short("A man walking to the shop");
set_gender(1);
set_alt_name("man");

break;
case 1 : set_level(12+random(20));
set_short("A busy looking man");
set_gender(1);
set_alt_name("man");

break;
case 2 : set_level(6+random(24));
set_short("Townsman running on the streets");
set_gender(1);
set_alt_name("townsman");
break;
}
 set_long("This fellow is ordinary looking man with normal clothes on.\n" +
          "He looks very happy maybe because the atmosphere of the village.\n" +
          "Man is here to do his daily tasks and just walking on these \n" +
          "beautiful streets.\n");


 }