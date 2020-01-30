inherit "obj/monster";
object weapon;
object armour;
reset(arg) {
   ::reset(arg);
if(arg) return;
set_name("priest");
set_level(26);
set_race("human");
set_gender(1);
set_alias("Priest");
set_short("A Wolf Priest");
set_long("A tall man clad in a magnificient robe of furs.\n"+
         "He is seems serous and strong.\n");
set_aggressive(0);

weapon = clone_object("/wizards/nalle/area/eq/knstaff");
move_object(weapon, this_object());
init_command("wield staff");

armour = clone_object("/wizards/shadow/Wolf/armour/wprrobe");
move_object(armour, this_object());
init_command("wear robe");
}
