inherit "obj/monster";
reset(arg) {
object shirt;
::reset(arg);
if(arg) { return; }
set_race("human");
set_level(75);
set_str(query_str() + -150);
set_dex(query_dex() + -30);
set_max_hp(query_hp() + -3000);
set_name("human");
set_alt_name("hunter");
set_aggressive(0);
switch (random(3)) {
case 0:
set_short("A human hunter stalking here.");
break;
case 1:
set_short("A human forest ranger.");
break;
case 2:
set_short("Human is stalking for his pray.");
break;
}
 set_long( "A human hunter is here to hunt some deers and bears. \n" +
           "He has some dirty old clothing on him. He has placed \n" +
           "some traps here and there and hopefully he gets something \n" +
           "to eat. He is a hunting so do not disturb him.\n"
);


set_skill("counter spell", 75);
set_gender(0);
shirt = clone_object("/wizards/yodin/areas/forest/obj/shirt");
    move_object(shirt, this_object());
    init_command("wear shirt");


}
