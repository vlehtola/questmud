





inherit "room/room";


reset(arg){

  if(arg) return;
   set_not_out(1);
   short_desc = "Tunnels";
   long_desc = "You are walking in the small dwarwen tunnel that seems to be endless.\n";
add_exit("east", "/wizards/yodin/areas/island/tunnel/5.c");
add_exit("southwest", "/wizards/yodin/areas/island/tunnel/7.c");
}