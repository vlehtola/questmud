inherit "room/room";
inherit "room/door";
int rats;
object rotta,rotta2,rotta3,rotta4;

reset(arg) {
if(arg) return;
 

if(!rotta) {
  rotta = clone_object("/wizards/kaappi/dcity/mobs/rat1.c");
  move_object(rotta, this_object()); }

if(!rotta2) {
  rotta2 = clone_object("/wizards/kaappi/dcity/mobs/rat1.c");
  move_object(rotta2, this_object()); }

if(!rotta3) {
  rotta3 = clone_object("/wizards/kaappi/dcity/mobs/rat1.c");
  move_object(rotta3, this_object()); }

if(!rotta4) {
  rotta4 = clone_object("/wizards/kaappi/dcity/mobs/rat1.c");
  move_object(rotta4, this_object()); }

short_desc = "The warehouse";
long_desc = "You have arrived to the warehouse of the city of\n"+
            "Amaranthgard. Some boxes are piled in the northwest\n"+
            "corner with remarkable accuracy, when some flour sacks\n"+
            "lie in the northeast corner. Several bear carcasses are\n"+
            "hanging from the ceiling, attached to meathooks. The\n"+
            "aroma of wine fills your nose. Many giant rats are \n"+
            "running on the floor, some of those are gnawing \n"+
            "the flour sacks.\n"; 
  set_light(3);
rats = 4;
  
door_reset();
set_door_label("wooden door",1);
set_door_dir("south", "katu48.c", 1);
set_door_link("/wizards/kaappi/dcity/rooms/katu48.c",1);
set_door_code("999", 1);
set_locked(1, 1);

set_not_out();
}
init() {
  ::init();
  door_init();
}
reduce_number() {
  rats -= 1;
if(rats == 0) {
  call_out("rats_killed", 1);
}
}
rats_killed() {
  object isorotta;
  if(rats == 0) {
  write("A furious looking giant rat attacks from behind the boxes.\n");
  isorotta = clone_object("/wizards/kaappi/dcity/mobs/rat.c");
  move_object(isorotta, this_object());
 }
}
