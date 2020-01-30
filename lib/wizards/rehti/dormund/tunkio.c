inherit "room/room";
object monster;

reset(arg) {
  add_exit("up","/wizards/rehti/dormund/hall");
  short_desc = "Dungeon";
  long_desc = "This is part of castle dungeon, or what is left of it. Stone walls\n"+
              "look very rough and it looks like no one has been here in a long time.\n"+
              "Slime is dripping from the walls and it makes this room very awful.\n"+
              "You have really bad feeling about this.\n";

items = allocate(4);
  items[0] = "slime";
  items[1] = "This slime covers whole room. You hear some sounds coming below the floor and slime. It must be the other part of these tunnels. Maybe you could open the way somehow.";
  
  move_object(clone_object("/wizards/rehti/dormund/monsut/beast"), this_object());
  if(arg) { return; }
}
init() {
  add_action("open", "open");
  ::init();
}

open(str) {
    write("You open the hatch and discover a tunnel.\n");
    add_exit("down","wizards/rehti/dormund/lair");
    return 1;
}



