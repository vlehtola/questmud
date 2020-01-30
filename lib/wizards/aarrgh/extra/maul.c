inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("mace");
set_short("The Mithril mace of Lesser Demons");
    set_long("This mace has been made of the finest mithril.\n ");
    set_value(80000);
set_weight(1500);
    set_class(10);
    set_material(10);
    set_weapon_type("bludgeon");
    set_type(1);
set_wc(65);
    set_hit_func(1);
}

hit() {
if(!wielded_by || !wielded_by->query_attack()) return;
if(random(5)) return;
tell_room(environment(wielded_by), "Mace SWINGS itself and "
        "MUTILATES "+wielded_by->query_attack()->query_name()+"!\n");
wielded_by->query_attack()->hit_with_spell(random(50)+50,0);
  return 1;
}

