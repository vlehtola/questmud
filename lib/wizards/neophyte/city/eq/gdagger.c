inherit "obj/weapon";
start() {
        set_class(6);
        set_sub_type("dagger");
        set_short("A rune covered black dagger");
        set_long("A black dagger which have a rune on the hilt.\n"+
                 "This weapon doesnt look that dangerous until\n"+
                 "that rune start to emit strong light.\n");
        set_stats("damage", 5);
        set_stats("hit", 5);
        set_stats("hpr", 10);
        set_stats("spr", 10);
        set_slayer("human");
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(10) != 0) return;
  tell_room(environment(wielded_by), "The rune on dagger starts to emit light.\n");
  wielded_by->query_attack()->hit_with_spell(random(10)+30, "physical");
  wielded_by->query_attack()->set_stunned(random(2)+1);
  return 1;
}
