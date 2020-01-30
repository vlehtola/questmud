inherit "room/room";

reset(arg) {
    short_desc = "gate";
    long_desc = "You come to small tunnel. In the end of the tunnel is\n"+
"huge gate. There are two guardingposts on both sides\n"+
"of the gate. There's only one guard who operates the gate.\n"+
"In one post is big wooden lever.\n";
        items = allocate(4);
items[0] = "gate";
items[1] = "The gate is made of iron.\n";
items[2] = "lever";
items[3] = "This lever operates the gate.\n";
set_light(5);
add_exit("east","wizards/moonstar/areas/wasteland/fortress/yard10.c");
}

init() {
    ::init();
   add_action("pull", "pull");
}

pull(str) {
   if(str == "lever") {
  say(this_player()->query_name()+"pulls the lever and the gate opens.\n");
  write("You pull the lever and the gate opens.\n");
  add_exit("west", "wizards/moonstar/areas/wasteland/fortress/plain1.c");
  return 1;
   }
  return 0;

}
