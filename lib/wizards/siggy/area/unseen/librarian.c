
inherit"obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_name("librarian");
  set_level(43);
  set_ep(5000);
  set_al(10); 
  set_al_aggr(200);
  set_alias("orangutan");
  set_race("orangutan");
  set_short("Orangutan librarian");
  set_long("It's a mean looking big orangutan. It's reading a book for your amazement.\n"
         + "It's the librarian of this huge place and as your eyes tell you it surely\n"
         + "isn't just any library, it's the library of Unseen University the home of magic\n"
         + "and spells and it's way more larger that any library you have ever seen,\n"
         + "and this 'ape', who is often seen here can be more than proud to own it.\n");
  set_aggressive(0);
  set_spell_chance(90, "exs brr blt");
  set_dead_ob(0);
  set_skill("cast essence", 90);
  set_skill("cast ice", 90);
  set_skill("cast bolt", 90);
  set_skill("attack", 100);
  set_skill("critical", 60);

}
