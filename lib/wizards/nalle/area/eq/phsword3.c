inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_short("The Sword of Swift Slaying");
    set_long("A light, slender black sword made of steel.\n");
    set_value(21000);
    set_weight(180);
    set_type("blade");
    set_wc(75);
    set_hit_func(1);
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(4) != 0) return;
  tell_room(environment(wielded_by), "The sword suddenly directs a"+
        " crackling bolt of electricity at"+wielded_by->query_attack()->query_name()+"!\n");
  wielded_by->query_attack()->hit_with_spell(random(333)+50,5);
  return 1;
}
