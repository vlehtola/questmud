





inherit "room/room";
object dwarf;

reset(arg){
if(!dwarf) {
 dwarf = clone_object("/wizards/yodin/areas/island/tunnel/monsters/dwarf");
 move_object(dwarf, this_object());
 }

  if(arg) return;
   set_not_out(1);
   short_desc = "Tunnels";
   long_desc = "You are walking in the small dwarwen tunnel that seems to be endless.\n";
add_exit("northeast", "3.c");

add_exit("west", "/wizards/yodin/areas/island/tunnel/0.c");
}
