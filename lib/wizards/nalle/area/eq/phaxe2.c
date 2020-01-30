inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("axe");
    set_short("The Blasphemer, a blood dripping axe");
    set_long("A tyrannous axe made of some black metal. It's covered by numerous stains of blood.\n");
    set_wc(80);
    set_weapon_type("axe");
    set_value(21000);
    set_weight(1100);
    set_stats(1,6);
    set_hit_func(1);
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(7) != 0) return;
  tell_room(environment(wielded_by), "The axe's blade draws a bloody"+
  " across "+wielded_by->query_attack()->query_name()+"'s face.\n");
  wielded_by->query_attack()->hit_with_spell(random(90)+50,1);
  return 1;
}
