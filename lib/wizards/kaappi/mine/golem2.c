inherit "room/room";
object monster;
reset(arg) {

if(arg) return;
  if (!monster) {
      monster = clone_object("/wizards/kaappi/mine/mosat/golem.c");
      move_object(monster, this_object());
}
 add_exit("south", "golem1.c");

  short_desc = "The golem's cave";
 long_desc = "The end of this tunnel. This room is much bigger than any other.\n"+
            "There are large cracks on the walls and small pieces of rocks\n"+
            "fill the ground. Looks like something big has been raging here.\n";
set_light(1);
}
