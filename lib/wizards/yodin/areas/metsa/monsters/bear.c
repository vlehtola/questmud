inherit "obj/monster";
reset(arg) {
string chat_str;
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("bear");
set_alias("animal");
switch(a) {

case 0 : set_level(30+random(6));
set_short("A gigantic brown bear");
set_gender(1);
set_alt_name("bear");


break;
case 1 : set_level(30+random(6));
set_short("A large bear");
set_gender(1);
set_alt_name("bear");

break;
case 2 : set_level(30+random(6));
set_short("A huge brown bear growling here");
set_gender(2);
set_alt_name("bear");
break;
}
 set_long( "Brown bears are up to 7 feet (2.1 m) long and weigh\n" +
           "up to 1,500 pounds (680 kg). Females are about 1/2 to 2/3\n" +
           "the size of males. Their thick fur ranges in color from\n" +
           "black to brown to reddish brown to blond. They have dense\n" +
           "fur close to the skin and long, coarse guard hairs.\n" +
           "They have a big head, a long muzzle, and a large hump on\n" +
           "their shoulder ( the hump is a mass of muscles that give\n" +
           "the front legs extra strength). Like all bears, they are\n" +
           "plantigrade (flat-footed). The front claws are up to 4.75\n" +
           "inches (12 cm), almost twice as long as the rear claws\n");
  

  set_skill("kick", 100);
   
   if (!chat_str) {
                                chat_str = allocate(2);
                                chat_str[0] = "Bear looks at you hungrily.\n";
                                chat_str[1] = "Bear stares at you.\n";
                                }
                         load_chat(2, chat_str);




}
