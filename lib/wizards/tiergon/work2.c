inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
        monster = clone_object("/wizards/tiergon/miespalvelija");
        move_object(monster, this_object()); }
   if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("dungeon","/wizards/tiergon/dungeon/toptunnel");
  add_exit("west","/wizards/tiergon/workroom");  
  short_desc = "Tiergon's workroom";
  long_desc = "This is Tiergon's workroom.\n"+
                "The whole room is covered with a thick layer of dust.\n"+
                "There is a cavern on the north side of the room.\n";

  set_not_out(3);
  items = allocate(2);
  items[0] = "cavern";
  items[1] = "This cavern leads probably to the manservant's even more"+
        " luxurious quarters\n";

  property = allocate(1);
  property[0] = "no_summon";
}


