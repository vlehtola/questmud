inherit "obj/monster";
object weapon;
object armour;
reset(arg) {
   ::reset(arg);
if(arg) return;
set_name("guard");
set_level(38);
set_gender(1);
set_race("human");
set_alias("wolf guard");
set_short("A guard stands here guarding something");
set_long("A tall man clad in wolf furs stands here seemingly guarding something.\n"+
         "He is a strongly built man with lots of muscle.\n");
set_aggressive(0);
set_block_dir("enter");
set_block_message("The guard says: 'You can't go in the chamber of the king!'");
weapon = clone_object("/wizards/shadow/Wolf/weapons/icesword");
move_object(weapon, this_object());
init_command("wield sword");

armour = clone_object("/wizards/shadow/Wolf/armour/icebplate");
move_object(armour, this_object());
init_command("wear chainmail");
}
