inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("deer");
set_alias("deer");
switch(a) {
case 0 : set_level(15+random(7));
set_short("Old deer eating grass");
set_gender(0);
set_alt_name("deer");

break;
case 1 : set_level(21+random(1));
set_short("A large deer eating grass");
set_gender(0);
set_alt_name("deer");

break;
case 2 : set_level(17+random(5));
set_short("A large deer");
set_gender(0);
set_alt_name("deer");
break;
}
 set_long(  "This stocky deer with sturdy legs is 4 to 6-1/2 feet\n" +
            "in length and 3 to 3-1/2 feet high at the shoulder.\n" +
            "During the summer, the coat on its upper body is\n" +
            "yellow- or reddish-brown, while in winter more gray.\n" +
            "The throat patch, rump patch, inside ears and inside\n" +
            "legs are white with lower portions running cream to tan.\n" +
            "A dark V-shaped mark, extending from a point between the\n" +
            "eyes upward and laterally is characteristic of all Mule\n" +
            "Deer.\n");


 }