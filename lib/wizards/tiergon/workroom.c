inherit "room/room";
object monster;

reset(arg) {
  add_exit("inn","/world/city/inn");
  add_exit("dungeon","/wizards/tiergon/dungeon/toptunnel");
  add_exit("ban","/room/banroom");  
  short_desc = "Tiergon's workroom";
  long_desc = "This is Tiergon's workroom.\n"+
                "The whole room is covered with a thick layer of dust.\n"+
                "There is a cavern on the north side of the room.\n";

  set_not_out(3);
  property = allocate(1);
  property[0] = "no_summon";
}


