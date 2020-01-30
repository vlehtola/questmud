inherit "room/room";
inherit "room/door";
object ob;
reset(arg) {
if(arg) return;
if(!ob) {
	ob = clone_object("/wizards/neophyte/city/monst/gravekeeper");
	move_object(ob, this_object());
}

set_not_out(1);
set_light(0);

short_desc = "Entrance room the graveyard";
long_desc =  "The graveyard of sailors is place where all the sailors are buried after\n"+
             "decent ceremonies. The ground is soft and nice looking grass is growing\n"+
             "beside the pathway, which goes all the way to the ceremonial chapel. The\n"+
             "graveyard is filled with different sized graves and tombs and beside those\n"+
             "are bunch of flowers.\n";
  add_exit("north", "room2");
  items = allocate(6);
  items[0] = "chapel";
  items[1] = "The chapel is located in the north side of graveyard and small pathway is going to it";
  items[2] = "graves";
  items[3] = "They are all different sized and made from different materials";
  door_reset();
  set_door_label("bone door",1);
  set_door_dir("south", "/wizards/neophyte/city/navigator1",1);
  set_door_link("/wizards/neophyte/city/navigator1",1);
  set_door_code("4632", 1);
  set_locked(1, 1);
}


init() {
  ::init();
  door_init();
}

