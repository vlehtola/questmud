inherit "obj/monster";

reset(arg) {
 object weapon;
 ::reset(arg);
 if(arg) return;
 set_level(32);
 set_name("guard");
 set_alias("guard");
 set_race("angel");
 set_gender(1);
 set_al(30);
 set_short("A patrolling guard");
 set_long("Heavy clothing and armour.\n");
 weapon = clone_object("/wizards/rimber/cloudc/obj/ssword.c");
 move_object(weapon, this_object());
 init_command("wield scimitar");
 call_out("move", 2);
}

int move() {
 switch(random(4)) {
  case 0 : init_command("north");
   break;
  case 1 : init_command("south");
   break;
  case 2 : init_command("east");
   break;
  case 3 : init_command("west");
   break;
 }
}
