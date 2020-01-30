inherit "obj/weapon"; 
 
reset(arg) {
    ::reset(arg);
    set_name("dagger");
    set_short("The Ba'al Veerzi dagger");
    set_long("This dagger is curved and embedded with rubys and diamonds.\n");
    set_value(50000);
    set_weight(1);
    set_type(1);
    set_hit_func(1);
}
 
hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(5) != 0) return;
  tell_room(environment(wielded_by), "The Ba'al Veerzi dagger does it's job and finds the heart, to where it quickly plunges causing "+
        "the heart to rupture inside "+wielded_by->query_attack()->query_name()+"!\n");
  wielded_by->query_attack()->hit_with_spell(random(690)+100,5);
  return 1;
}
