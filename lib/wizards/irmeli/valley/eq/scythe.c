inherit "obj/weapon";

start() {
    set_class(7);
    set_sub_type("broad sword");
    set_short("Black scythe with silver razor-sharp blade <Dripping blood>");
    set_alias("scythe");
    set_long("A black scythe, which has a bloody, silver, razor-sharp blade\n"+
             "and a wooden handle, painted to black. A shape of crow's head\n"+
             "can be seen engraved on the blade, among the blood.\n");
    set_stats("damage",4);
    set_stats("hit",2);
}
hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(15) != 0) return;
  tell_room(environment(wielded_by), "The BLOOD spills around"+
" the place as the scythe RIPS "+wielded_by->query_attack()->query_name()+" with MASSIVE force.\n");
  wielded_by->query_attack()->hit_with_spell(random(60)+10, "physical");
  return 1;
}

