inherit "obj/monster";

reset(arg) {
 object weapon;
 ::reset(arg);
 if(arg) return;
 set_level(40);
 set_name("demon");
 set_alias("guard");
 set_short("Ragadas, the guard of the fire chamber");
 set_long("The demon has long thick horns and its whole presence is magnificent.\n"+
  "The demon is chained to the ground with six huge steel chains.\n");
 set_race("demon");
 weapon = clone_object("/wizards/rimber/hell/obj/fweapon.c");
 move_object(weapon, this_object());
 init_command("wield sword");
 set_block_dir("down");
 set_resists("fire",100);
}
