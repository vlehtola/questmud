inherit "obj/weapon";

start() {
    set_class(10);
    set_sub_type("great axe");
    set_short("The legendary axe named 'Elvenslayer'");
    set_alias("axe");
    set_name("elvenslayer");
    set_long("You see a huge battleaxe that has been crafted by the best of\n"+
             "the dwarven metalsmiths. During the long elvish wars, the hatred\n"+
             "of the dwarves grew stronger. The hilt has carved in it, a mark\n"+
             "for every elf killed. There are more lines than you could ever\n"+
             "even count on this hilt.\n");
    set_stats("damage",8);
    set_stats("hit",10);
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
