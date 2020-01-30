inherit "obj/monster";

reset(arg) {
 object weapon;
 ::reset(arg);
 if(arg) return;
 set_level(35);
 set_name("guard");
 set_alias("guard");
 set_race("angel");
 set_gender(1);
 set_al(30);
 set_short("A tall muscular guard");
 set_long("Heavy clothing and armour.\n");
 set_block_dir("south");
 weapon = clone_object("/wizards/rimber/cloudc/obj/ssword.c");
 move_object(weapon, this_object());
 init_command("wield scimitar");
}
