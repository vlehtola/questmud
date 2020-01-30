inherit "room/room";
reset(arg) {
call_other("/wizards/gynter/darke/city/tunnels/virtual_tunnel_map", "XX", 0);
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/darke/city/Scity6");
  add_exit("south","/wizards/gynter/darke/city/tunnels/virtual_tunnel_map: 30 6"); //Virtual map
  /* setting desc */
  short_desc = "The entrances to the dark tunnels";
  long_desc = "As you stand at the entrance of the tunnels\n"+
              "you can smeel evil oozing out of the opening.\n"+
              "Maybe this place is where the darkelfs perform\n"+
              "their arts.\n";
}
