inherit "room/room";
inherit "room/door";
object ghost;
int i;
reset(arg) {
        i = random(2);
if(arg) return;
if(i==0) {
        ghost = clone_object("/wizards/neophyte/city/monst/nghost");
    move_object(ghost, this_object());
}
set_not_out(1);
set_light(3);

short_desc = "A lamp room";
long_desc =  "You have finally reached the top of lighthouse. In the\n"+
             "middle of room is a big gas-lamp rotating slowly. Windows\n"+
             "are dirty, seems like the caretaker hasn't been washing them\n"+
             "for ages. A couple oily rags are left on the floor.\n";

  property = allocate(1);
  property[0] = "no_summon";
  door_reset();
  set_door_label("iron door", 1);
  set_door_dir("down", "/wizards/neophyte/city/lighthouse/corridor16", 1);
  set_door_link("/wizards/neophyte/city/lighthouse/corridor16", 1);
  set_door_code("123", 1);
  set_locked(1, 1);
}

init() {
  ::init();
  door_init();
}

