inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("mace");
    set_short("The Mithril Mace of Lesser Demons'");
    set_long("This mace has been made of the finest mithril...\n ");
    set_value(80000);
    set_weight(30);
    set_class(10);
    set_material(10);
    set_weapon_type("bludgeon");
    set_type(1);
    set_hit_func(1);
}

hit() {
if(!wielded_by->query_attack()) return;
if(random(1) != 0) return;
tell_room(environment(wielded_by), "You SWING your Mace and "
        "MUTILATE "+wielded_by->query_attack()->query_name()+"!\n");
  wielded_by->query_attack()->hit_with_spell(random(100)+200,1);
  return 1;
}
