





inherit "room/room";


reset(arg){

  if(arg) return;
   set_not_out(1);
   short_desc = "Tunnels";
   long_desc = "You are walking in the small dwarwen tunnel that seems to be endless.\n";
add_exit("northeast", "/wizards/yodin/areas/island/tunnel/64.c");
add_exit("south", "/wizards/yodin/areas/island/tunnel/71.c");
}
