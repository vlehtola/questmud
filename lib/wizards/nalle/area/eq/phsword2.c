inherit "obj/weapon";
inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_short("The Sword of Swift Slaying");
    set_long("A slender sword made of black steel pulsing with an evil aura.\n");
    set_value(21000);
    set_weight(100);
    set_hit_func(1);
    set_weapon_type("blade");
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(10) != 0) return;
  tell_room(environment(wielded_by), "The sword suddenly directs "+
        "a crackling bolt of electricity at
"+wielded_by->query_attack()->query_name()+", making it grimace in pain.\n");
  wielded_by->query_attack()->hit_with_spell(random(333)+50,5);
  return 1;
}

reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_short("The Sword of Swift Slaying");
    set_long("A slender sword made of black steel pulsing with an evil aura.\n");
    set_value(21000);
    set_weight(1);
    set_type(2);
    set_hit_func(1);
    set_wc(60);
    set_weapon_type("blade");
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(10) != 0) return;
  tell_room(environment(wielded_by), "The sword suddenly directs "+
        "a crackling bolt of electricity at "+wielded_by->query_attack()->query_name()+", making it grimace in pain.\n");
  wielded_by->query_attack()->hit_with_spell(random(333)+50,5);
  return 1;
}
