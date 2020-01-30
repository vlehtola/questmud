inherit "obj/weapon";

start() {
    set_class(7);
    set_sub_type("battle axe");
    set_short("The legendary axe named 'Elvenslayer'");
    set_alias("axe");
    set_name("elvenslayer");
    set_long("A black scythe, which has a bloody, silver, razor-sharp blade\n"+
             "and a wooden handle, painted to black. A shape of crow's head\n"+
             "can be seen engraved on the blade, among the blood.\n");
    set_stats("damage",4);
    set_stats("hit",2);
}
hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(15) != 0) return;
  tell_room(environment(wielded_by), "The elvenslayer axe starts glowing"+
" with an eerie light as it slices through "+wielded_by->query_attack()->query_name()+" leaving "+
"SCORCHED burnmarks on "+wielded_by->query_attack()->query_name()+"'s BODY!.\n");
  wielded_by->query_attack()->hit_with_spell(random(500)+50, "fire");
  return 1;
}

