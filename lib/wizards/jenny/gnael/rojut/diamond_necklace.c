inherit "obj/armour";
  start() {

   set_short("A marvelous looking diamond necklace");
   set_long("This marvelous looking diamond necklace\n"+
            "looks centuries old. There are over fifty\n"+
            "diamonds embedded on it and it sparkles in\n"+
            "a lovely way. When you touch the diamonds you feel\n"+
            "cold and shiver because this necklace was\n"+
            "once owned by one of Mondasa's minions");

   set_value(20000);
   set_stats("int", 8);
   set_stats("wis", 2);
   set_stats("spr", 12);
   set_slot("neck");
   set_name("necklace");

}
