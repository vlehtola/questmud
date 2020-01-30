inherit "obj/weapon";

start() {
    set_class(8);
    set_alias("hammer");
    set_sub_type("warhammer");
    set_short("The ancient Hammer of Stone");
    set_long("The ancient hammer of stone. It was forged by the McArthur family centuries\n"+
             "ago. It has been in the McArthur family from the first day to this day. The\n"+
             "handle of the hammer is made of oak. Altought it's old it looks like just\n"+
             "made. Its striking head is a bit warm.\n");
    set_stats("damage",3);
    set_stats("hit",5);
    set_stats("str",5);
}
hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(15) != 0) return;
  tell_room(environment(wielded_by), "The hammer glows in RED"+
" as it HITS to "+wielded_by->query_attack()->query_name()+"'s body sending BLOOD everywhere.\n");
  wielded_by->query_attack()->hit_with_spell(random(50)+5, "fire");
  return 1;
}
