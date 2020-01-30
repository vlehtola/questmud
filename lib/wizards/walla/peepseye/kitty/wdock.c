inherit "room/room";
object monster;

reset(arg) {
  if(!present("gull")) {
    move_object(clone_object("/wizards/walla/peepseye/monsters/gull"),
    this_object());
  }

  if(arg) return;

  add_exit("south","/wizards/walla/peepseye/kitty/dock2");
  set_not_out(1);

  short_desc = "At the end of the dock of OilOhnRock";
  long_desc = "This is as far as you can go in OilOhnRock. Before you, you can only see the sea.\n"+
                "There is a rusty bell, that is believed having served to summon a ferry of some sort.\n"+
                "All of this is purely speculations, since the evidence of the bell being so old and\n"+
                "appearing not to been used in many years.\n";

  items = allocate(2);
  items[0] = "bell";
  items[1] = "A normal type of bell, hanging on a pole. It says: to summon ye ferry, ring heir";

  call_other("wizards/walla/peepseye/ferry/ferry", "start_ferry", 1);
}
