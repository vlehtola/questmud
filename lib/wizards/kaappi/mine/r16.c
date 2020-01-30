inherit "room/room";
inherit "room/door";
object child,child2,child3,child4,vahti;

reset(arg) {

if(!child) {
  child = clone_object("/wizards/kaappi/mine/mosat/ydwarf.c");
  move_object(child, this_object()); }

if(!child2) {
  child2 = clone_object("/wizards/kaappi/mine/mosat/ydwarf.c");
  move_object(child2, this_object()); }

if(!child3) {
  child3 = clone_object("/wizards/kaappi/mine/mosat/ydwarf.c");
  move_object(child3, this_object()); }

if(!child4) {
  child4 = clone_object("/wizards/kaappi/mine/mosat/ydwarf.c");
  move_object(child4, this_object()); }

if(arg) return;

if(!vahti) {
   vahti = clone_object("/wizards/kaappi/mine/mosat/lvahti.c");
   move_object(vahti, this_object()); }

  short_desc = "Playroom for children";
  long_desc =
  ("As you open the door and step in to the room, you see many little\n"+
   "children running and playing there. This must be some kind\n"+
   "of playroom for the children while their parents are working.\n");

door_reset();
set_door_label("wooden door",1);
set_door_dir("east", "r15.c",1);
set_door_link("/wizards/kaappi/mine/r15.c",1);
set_locked(0, 1);

set_not_out();
}
init() {
  ::init();
  door_init();
}
