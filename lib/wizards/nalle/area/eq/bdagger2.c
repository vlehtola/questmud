inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("dagger");
    set_short("A sharp dagger named The Presence of Death");
    set_long("This beautiful black dagger would surely sink into anyone's back with ease.\n");
    set_value(2100);
    set_weight(1);
    set_type(2);
    set_hit_func(1);
    set_wc(60);
    set_weapon_type("blade");
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(7) != 0) return;
  tell_room(environment(wielded_by), "The dagger leaves traces of some unknown liquid"+
        " onto "+wielded_by->query_attack()->query_name()+", making disgusting wounds.\n");
  wielded_by->query_attack()->hit_with_spell(random(200)+150,2);
  return 1;
}

