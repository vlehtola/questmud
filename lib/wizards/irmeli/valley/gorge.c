inherit "room/outroom";

start() {
  mapfile = "/wizards/irmeli/valley/virtual_map";
  short_desc = "Gorge";
  long_desc = "A deep gorge, full of translucid water, separates you from the\n"+
              "mountain. On the other side of the gorge is a small hole in\n"+
              "the mountain, entrance to a tunnel or a cave. A brittle rope\n"+
              "bridge, which has been built across the gorge, offers an easy\n"+
              "way to cross the gorge.\n";
 }

init() {
  ::init(); 
  add_action("cross", "cross"); 
}

cross(str) {
  if(str == "gorge") {
    write("You walk along the rope bridge to the other side.\n"); 
    say(this_player()->query_name()+" walks along the rope bridge to the other side.\n");
    move_object(this_player(),"/wizards/irmeli/valley/tunnel2.c");
    command("look",this_player());
     }
     return 1; 
}

