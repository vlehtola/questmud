inherit "obj/monster";

reset(arg) {
 object weapon;
 ::reset(arg);
 if(arg) return;
 switch(random(2)) {
 case 0 :
 set_level(30);
 set_name("soldier");
 set_alias("soldier");
 set_short("A tall cloud soldier");
 break;
 case 1 :
 set_level(35);
 set_name("soldier");
 set_alias("soldier");
 set_short("A tall muscular soldier");
 break;
}
 set_long("A tall soldier with long white hair.\n");
 set_race("angel");
 set_gender(1);
 set_al(30);
 weapon = clone_object("/wizards/rimber/cloudc/obj/ssword.c");
 move_object(weapon, this_object());
 init_command("wield scimitar");
}
