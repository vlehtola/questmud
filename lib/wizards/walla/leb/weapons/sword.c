inherit "obj/weapon"; 
 
reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_alias("blade");
    set_short("Rot'Ub'Irter");
    set_long("This curved blade looks as it has been bade in the east, by maures.\n");
    set_value(1000);
    set_weight(500);
    set_type(3);
    set_hit_func(4);
}
 
hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(3) != 0) return;
  tell_room(environment(wielded_by), "The Rot'Ub'Irter flashes and crackles as an electric bolt leaves the \n" +
        "shimmering blade, only to find "+wielded_by->query_attack()->query_name()+" s heart where it stays,\n" +
        "paralyzing the victim\n");
  wielded_by->query_attack()->hit_with_spell(random(333)+100,5);
  return 1;
}
 

