inherit "room/room";

static status cross_pressed;

reset(arg) {
  if(!present("statue")) { 
    move_object(clone_object("/wizards/irmeli/valley/object/statue"),
    this_object());
 }

 if (arg) { return; }

 set_not_out(1);

 short_desc = "An old chamber";
 long_desc = "An old chamber has been driven inside a huge mountain. The ceiling, ground\n"+
             "and walls are rough, covered with cobwebs and dust. The rock is disintegrating\n"+
             "gradually from the walls and ceiling. Rock paintings, on the walls of the\n"+
             "chamber, are ancient and dusty. A huge cleft, in the ground, is at the far\n"+
             "end of the chamber.\n";

    add_exit("north", "/wizards/irmeli/valley/tunnel2.c");

  items = allocate(4);
  items[0] = "cleft";
  items[1] = "A huge cleft, in the ground, is full of translucid water"; 
  items[2] = "paintings";
  items[3] = "Ancient and dusty rock paintings are written in Latin, impossible to interpret";
}
int cross_pushed;
init() {
  ::init(); 
  add_action("push", "push"); 
}

push(str) {
  if(cross_pressed) {
    write("It doesn't budge anymore.\n");
    return 1;
  }
  if(str == "cross") {
    write("After doubting a little while, you decide to push the cross, which\n"); 
    write("is in front of knight's chest.\n");
    write("Suddenly a knight jumps from the cleft, among the water.\n");
    say(this_player()->query_name()+" operates the cross in front of knight's chest.\n");
    move_object(clone_object("/wizards/irmeli/valley/monsters/knight.c"), this_object());

   cross_pressed = 1;
     }
     return 1;
 }
