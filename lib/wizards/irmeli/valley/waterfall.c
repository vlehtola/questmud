inherit "room/outroom";

start() {
  mapfile = "/wizards/irmeli/valley/virtual_map";
  short_desc = "Waterfall";
  long_desc = "A huge waterfall gushes water down to the ground, from\n"+
              "the top of the eastern fold mountain. The water flows\n"+
              "rapidly towards west, leaving behind a small, swallow\n"+
              "river. The water is cold and translucid in the river.\n";
 }

init() {
  ::init(); 
  add_action("enter", "enter"); 
}

enter(str) {
  if(str == "waterfall") {
    write("You step through the waterfall and a narrow tunnel reveals behind the waterfall.\n"); 
    say(this_player()->query_name()+" vanishes behind the waterfall.\n");
    move_object(this_player(),"/wizards/irmeli/valley/tunnel.c");
    this_player()->look();

     return 1;
 }

    
    write("Enter what?\n");

    return 1;

}