inherit "obj/armour";
start() {
  set_slot("belt");
  set_name("belt");
  set_short("A greenish skin belt full of fractures");
  set_long("An image of throwaway belt lying in the bottom of a pond appears in your\n" +
           "head as you see this ugly item. The belt is full of fractures caused by\n" +
           "high dampness in the place where it has been formerly stored. In the gaping\n" +
           "fractures can be seen growing some organisms like tiny algae. Seems that\n" +
           "the algae are sucking their nutrients from the belt, because they blossom\n" +
           "even now. The attachment-mechanism of the belt is not damaged and it can\n" +
           "be worn as any other belts");
  
  set_value(1000);
  set_weight(150);
  set_stats("int", 5);
  set_stats("wis", 10);
  set_stats("spr", 16);
}
