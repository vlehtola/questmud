inherit "obj/weapon";

start() {
  set_class(8);
  set_sub_type("two-edged axe");
  set_long("This indeed is a fine axe. It has some strange black coating\n"
          + "on its blades. It seems to be humming quietly.\n");
  set_stats("str" + 5);
}

hit() {
  if(random(5) != 0) return;
  tell_room(environment(wielded_by), "The spikes on twin-blade sinks DEEP into "+wielded_by->query_attack()->query_name()+"'s  flesh!\n");


  wielded_by->query_attack()->hit_with_spell(random(70)+10,2);
  return 1;
}

