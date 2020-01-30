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
    set_stats("damage",10);
    set_stats("hit",7);
}
hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(50) != 0) return;
  tell_room(environment(wielded_by), "The Sword of the Planes crackles"+
" with a flash of lightning as it penetrates "+wielded_by->query_attack()->query_name()+"'s defences "+
"with the speed of light. "+wielded_by->query_attack()->query_name()+"'s body starts convulsing "+
"and trembling from the force of the attack!.\n");
  wielded_by->query_attack()->hit_with_spell(random(1500)+50, "electric");
  return 1;
}
