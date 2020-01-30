inherit "obj/monster";

reset(arg) {
 object armour, weapon;
 ::reset(arg);
 if(arg) return;
 set_level(50);
 set_log(1);
 set_name("rufus");
 set_alt_name("captain");
 set_alias("rufus");
 set_short("An angel captain Rufus");
 set_long("A tall human looking creature with long white hair. Rufus has large white\n"+
  "wings. He is wearing light brown sandals.\n");
 set_race("angel");
 set_gender(1);
 weapon = clone_object("/wizards/rimber/cloudc/obj/rsword.c");
 move_object(weapon, this_object());
 init_command("wield sword");
 armour = clone_object("/wizards/rimber/cloudc/obj/rsandals.c");
 move_object(armour, this_object());
 init_command("wear sandals");
 set_al(40);
}
