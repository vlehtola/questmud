inherit "obj/armour";
  start() {

   set_short("Necklace of Glory (Blessed)");
   set_long("Oddly glowing necklace which seems to emit\n"+
            "light. There are diamonds embedded on the\n"+
            "center of the necklace and there are some\n"+
            "runes written on the back of it. Some people\n"+
            "say that this necklace is blessed by the God\n"+
            "himself. After all, its a very good piece of\n"+
            "art");

   set_stats("con", 6);
   set_stats("str", 10);
   set_resists("fire", 20);
   set_resists("cold", 20);
   set_resists("electric", 20);

   set_slot("neck");
   set_name("necklace");

}
