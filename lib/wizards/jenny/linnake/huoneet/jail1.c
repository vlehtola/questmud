inherit "room/room";
inherit "room/door";
object prisoner;

reset(arg) {
   
    if(!present("prisoner")) {
      move_object(clone_object("/wizards/jenny/linnake/mosut/prisoner.c"), this_object());
        }

        short_desc = "Cell number 1";
        long_desc = "Dirty looking prison cell, there are many forms of life\n"+
                    "wandering on the floor...maggots, rats, ants...There are\n"+
                    "some torches burning on the wall and you hear moaning\n"+
                    "coming from somewhere.\n";
 
        door_reset();
        set_door_label("Shiny prison cell door",1);
        set_door_dir("east", "/wizards/jenny/linnake/huoneet/prison6.c",1);
        set_door_link("/wizards/jenny/linnake/huoneet/prison6.c",1);
        set_door_code("571",1);
        set_locked(1,1);

        set_not_out();
}

init() {
  ::init();
  door_init();
}
