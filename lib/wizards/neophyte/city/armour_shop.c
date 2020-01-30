inherit "room/room";
object armourer;
string killer;
reset(arg) {
  if(arg) return;
                  if(!armourer) {
                          armourer = clone_object("/wizards/neophyte/city/monst/armourer");
                          move_object(armourer, this_object());
                  }
  short_desc = "The pirates armour shop";
  long_desc = "This is the true pirate armour shop, various things are sold in here.\n"+
              "Sharp hooks, wooden legs and a pirate flag are all hanging on the walls\n"+
              "of the shop. There are also lots of different armours piled on the corner\n"+
              "of the room. On the ground is a huge fireplace and next to that is an\n"+
              "anvil. It's quite hot in here, the fireplace makes you sweat.\n";
  set_not_out(1);
  set_light(3);

   items = allocate(8);
   items[0] = "flag";
   items[1] = "A big and black pirate flag. There's a white skull on the flag";
   items[2] = "anvil";
   items[3] = "The anvil is quite rusty, but still in use";
   items[4] = "hook";
   items[5] = "A shining hook is copy from Captain Hook's hook";
   items[6] = "fireplace";
   items[7] = "The fireplace burns with small fire";

  add_exit("south", "amber3");
}

set_killer(string str) {
	killer = str;
}
query_killer() { return killer; }
