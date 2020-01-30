inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_alias("sword");
    set_short("Sharp sword");
    set_long("This sword belongs to the guard of cannibal king.\n",
             "This is very sharp sword.\n");
    set_material(5);
    set_class(40);
    set_weapon_type("blade");
    set_value(500);
    set_weight(2);

  hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(5) != 0) return;
  tell_room(environment(wielded_by), "The BONE and FLESH flies from BODY
OF
"+wielded_by->query_attack()->query_name()+"!\n");
  wielded_by->query_attack()->hit_with_spell(random(1)+50,5);
return 1;
}
