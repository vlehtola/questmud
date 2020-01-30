inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("staff");
    set_short("Staff of Arcane Rulership");
    set_long("This magnificently carved staff feels warm to the touch.\n");
    set_value(21000);
    set_weight(1);
    set_type(2);
    set_hit_func(1);
    set_wc(69);
    set_stats(4,5);
    set_stats(5,5);
    set_weapon_type("bludgeon");

}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(8) != 1) return;
  tell_room(environment(wielded_by), "The staff sends "+
        "multicolored bright rays at "+wielded_by->query_attack()->query_name()+", causing him to scream in horror.\n");
  wielded_by->query_attack()->hit_with_spell(random(300)+50,4);
  return 1;
}
