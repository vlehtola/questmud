inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_race("human");
set_name("woman");
set_alias("human");
switch(a) {
case 0 : set_level(15+random(5));
set_short("A beautiful woman smiling at you");
set_gender(2);
set_alt_name("woman");

break;
case 1 : set_level(12+random(5));
set_short("Busy woman running by");
set_gender(2);
set_alt_name("woman");

break;
case 2 : set_level(6+random(24));
set_short("A happy woman walking to shop");
set_gender(2);
set_alt_name("woman");
break;
}
 set_long("A Beautiful looking woman wearing a long red dress\n" +
          "and grey shirt. She looks very happy maybe because the \n" +
          "atmosphere in village. Woman is quite beautiful and \n" +
          "she smiles all the time.\n");


 }