
inherit "obj/monster"; 
 
reset(arg) {
object armour;                        
::reset(arg);
  if(arg) return;
  set_level(25);
  set_exp(query_exp()*4/3);
  set_name("zombie");
  set_short("A Zombie, risen from the grave");
  set_al(0);
  set_aggressive(1);
  set_undead(1);
  set_mage(1);

    armour = clone_object("/wizards/walla/area/armour/leggings");
    move_object(armour, this_object());
    init_command("wear leggings");
}

