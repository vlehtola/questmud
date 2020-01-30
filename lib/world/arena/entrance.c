inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("north","/world/city/ice5");
  short_desc = "The entrance to the arena";
  long_desc = "This is the entrance room to the arena.\n"+
              "You can 'enter' it if you want.\n";
}

init() {
        ::init();
        add_action("enter_arena", "enter");
}

enter_arena() {
        object shadow;
        tell_object(this_player(), "You open the door inside the arena and step in.\n");
        say(this_player()->query_name()+" opens the door to arena and steps in.\n");
        this_player()->move_player("arena#/world/arena/arena");
//      move_object(this_player(), "/world/arena/arena");
        shadow = clone_object("/world/arena/death_shadow");
        shadow->start(this_player());
        if(this_player()->query_wiz()) write("death shadow started.\n");
        return 1;
}
