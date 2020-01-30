inherit "room/room";

reset(arg) {
  add_exit("south","/wizards/walla/peepseye/kitty/chapel");
  short_desc = "Behind the chapel of OilOhnRock";
  long_desc =
 "Here, behind the real chapel, you feel at ease. Your powers run through you\n" +
 "as you remember what you have been doing this sad day. You kneel before a\n" +
 "crucifix, which is nailed on the wall.\n" ;


  items = allocate(4);
  items[0] = "crucifix";
  items[1] = "The crucifix of the son of our God, Jesus Christ.";

  property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";

}
