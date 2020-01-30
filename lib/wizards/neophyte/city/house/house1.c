inherit "room/room";
inherit "room/door";

reset(arg) {
if(arg) return;

set_not_out(1);
set_light(3);

short_desc = "Entrance hall";
long_desc =  "Entrance hall of the Lowie family. The floor looks like it has\n"+
             "been cleaned just a moment ago. On the floor is a small mat saying\n"+
             "welcome. There are windows both sides of the door and nicely knit curtains\n"+
             "are hanging on the window. The walls are painted in yellow and a couple\n"+
             "of paintings are placed on the walls.\n";
  add_exit("west", "closet");
  add_exit("north", "house2");
  items = allocate(6);
  items[0] = "floor";
  items[1] = "The floor is made from shiny boards and looks clean like it was just moment ago cleaned";
  items[2] = "mat";
  items[3] = "A nicely knitted mat is laying on the floor and on the mat is text saying welcome";
  items[4] = "paintings";
  items[5] = "The paintings are representing an history of lowie family";

  door_reset();
  set_door_label("bronze door",1);
  set_door_dir("south", "/wizards/neophyte/city/anchor1",1);
  set_door_link("/wizards/neophyte/city/anchor1",1);
  set_door_code("112", 1);
  set_locked(1, 1);
}


init() {
  ::init();
  door_init();
}

