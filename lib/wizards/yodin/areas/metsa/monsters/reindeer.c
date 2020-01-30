inherit "obj/monster";


reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("reindeer");
set_alias("animal");
switch(a) {
case 0 : set_level(22+random(3));
set_short("A large reindeer");
set_gender(1);
set_alt_name("reindeer");

break;
case 1 : set_level(22+random(3));
set_short("A brown reindeer");
set_gender(1);
set_alt_name("reindeer");

break;
case 2 : set_level(22+random(2));
set_short("A small reindeer");
set_gender(2);
set_alt_name("reindeer");
break;
}
set_long( "The reindeer is a hooved animal related to the other\n" +
           "kind of deers lat: cervus that can be found in most\n" +
           "parts of the world, but not as closely as a quick look at\n" +
           "a reindeer might make one think since the reindeer in some\n" +
           "respects is unique. Browsing through scientific literature\n" +
           "might give you a hint that the reindeer is special, since \n" +
           "it sometimes can be found listed together with the\n" +
           "Munitacus and Hydropontes. Most of the special characteristics\n" +
           "have developed as an adaption to the arctic and sub arctic,\n" +
           "such as the broad hooves which enable the reindeer to walk\n" +
           "on and dig in deep snow after food. The hooves are also\n" +
           "flexible and can be spread out to carry the animal on soft\n" +
           "ground or snow. Useful both on the soft snow in the \n" +
           "springtime and on mosses and swamps during the short summer.\n");




 }
