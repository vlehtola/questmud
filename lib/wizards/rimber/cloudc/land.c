inherit "room/room";
object oracle;

reset(arg) {
 if(!oracle) {
 oracle = clone_object("/wizards/rimber/cloudc/mobs/oracle.c");
 move_object(oracle, this_object());
 }
 if(arg) return;
 set_light(3);
 short_desc = "Stone circle";
 long_desc = "Long grass grows all over the place as far as you can see.\n"+
"Here the grass has been stamped down in to a form of a circle.\n"+
"In the middle of the stamped grass is a small circle. Next\n"+
"to the circle is a hut.\n";
 add_exit("leave", "/wizards/rimber/workroom.c");
}

init() {
 ::init();
 add_action("enter", "enter");
}

enter(str) {
 if(str == "circle") {
  if(present("oracle", environment(this_player()))) {
   write("You step inside the circle and oracle starts chanting. Pillar of light comes from the clouds and blinds you.\n");
   move_object(this_player(), "/wizards/rimber/cloudc/entrance.c");
  }
  else { write("You step inside the circle but suddenly the ground beneath you disappears.\n");
   move_object(this_player(), "/wizards/rimber/hell/entrance.c");
  }
 }
 return 1;
}
