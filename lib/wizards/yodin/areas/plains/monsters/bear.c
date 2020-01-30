inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("bear");
set_alias("bear");
switch(a) {
case 0 : set_level(25+random(5));
set_short("An enormous sized grizzly bear");
set_gender(0);
set_alt_name("bear");

break;
case 1 : set_level(30+random(1));
set_short("A large grizzly bear");
set_gender(0);
set_alt_name("bear");

break;
case 2 : set_level(28+random(2));
set_short("A huge grizzly bear");
set_gender(0);
set_alt_name("bear");
break;
}
 set_long(  "This large animal reaches weights of 300-1500\n" +
            "pounds. The coat color ranges from shades of \n" +
            "blond, brown, black or a combination of these;\n" +
            "the long outer guard hairs are often tipped with\n" +
            "white or silver giving it a grizzled appearance\n" +
            "hence the name. The grizzly has a large hump over\n" +
            "the shoulders which is a muscle mass used to power\n" +
            "the forelimbs in digging. The head is large and\n" +
            "round with a concave facial profile.\n");


 }