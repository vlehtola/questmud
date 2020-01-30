inherit "obj/weapon";

start() {
    set_class(9);
    set_sub_type("broad sword");
    set_short("Sword of the planes");
    set_name("sword");
    set_alias("hc_walla_sword");
    set_long("This sword was made by the barbarians of the plains. It's\n"+
             "hilt is so long that you could, if needed put your other\n"+
             "there, to aid the blow.\n");
    set_stats("damage",4);
    set_stats("hit",2);
}
hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(15) != 0) return;
  tell_room(environment(wielded_by), "The elvenslayer axe starts glowing"+
" with an eerie light as it slices through "+wielded_by->query_attack()->query_name()+" leaving "+
"SCORCHED burnmarks on "+wielded_by->query_attack()->query_name()+"'s BODY!.\n");
  wielded_by->query_attack()->hit_with_spell(random(500)+50, "cold");
  return 1;
}
