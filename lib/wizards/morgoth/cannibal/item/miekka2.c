inherit "obj/weapon";
 
reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_short("The bloodred sword called 'Flesh Eater'");
    set_long("This sword belongs to the cannibal king.\n"+
             "It is VERY sharp and it seems to be magical.\n");
    set_value(50000);
    set_wc(70);
    set_weight(2);
    set_weapon_type("blade");
    set_hit_func(1);
}
 
hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(5) != 0) return;
  tell_room(environment(wielded_by), "The sword starts to live and BITES "+
        "VERY HARD "+wielded_by->query_attack()->query_name()+"!\n");
  wielded_by->query_attack()->hit_with_spell(random(100)+50,5);
  return 1;
}
