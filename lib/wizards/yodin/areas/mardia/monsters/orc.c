inherit "obj/monster";
reset(arg) {
object pants,sword,shirt;
int a;
a = random(7);
::reset(arg);
if (arg) return;
set_race("orc");
set_name("orc");
set_alias("orc");
switch(a) {

case 0 : set_level(36+random(5));
set_short("A dirty orc");
set_gender(1);
set_alt_name("orc");

break;
case 1 : set_level(37+random(3));
set_short("A large orc");
set_gender(1);
set_alt_name("orc");

break;
case 2 : set_level(36+random(4));
set_short("Orc digging the wall");
set_gender(0);
set_alt_name("orc");
break;

break;
case 3 : set_level(34+random(6));
set_short("Orc picking his nose here"); 
set_gender(0);
set_alt_name("orc");
break;

break;
case 4 : set_level(36+random(4));
set_short("Ugly orc standing in guard");
set_gender(0);
set_alt_name("orc");
break;

break;
case 5 : set_level(38+random(2));
set_short("A hostile looking orc");
set_gender(0);
set_alt_name("orc");
break;

break;
case 6 : set_level(35+random(5));
set_short("Bad smelling orc");
set_gender(0);
set_alt_name("orc");
break;

}
 set_long("This Ugly orc stands here with rusty sword in its hand.\n" +
          "Orc has some muddy clothes on and it smells very bad.\n" +
          "This orc is quite large sized for orc and it looks very \n" +
          "muscular. It has long muddy hair and large glimmering eyes.\n"+
          "these orcs seems to thing that everything is food.\n");


shirt = clone_object("/wizards/yodin/areas/mardia/obj/shirt.c");
    move_object(shirt, this_object());
    init_command("wear shirt");      
   
pants = clone_object("/wizards/yodin/areas/mardia/obj/pants.c");
    move_object(pants, this_object());
    init_command("wear pants");      

sword = clone_object("/wizards/yodin/areas/mardia/obj/sword.c");
    move_object(sword, this_object());
    init_command("wield sword");   




}
