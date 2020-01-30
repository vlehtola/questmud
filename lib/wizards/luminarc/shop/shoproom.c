inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc = "Kauppa";
  long_desc = "Kauppamesta.\n"; 
  property = allocate(1);
  set_light(3);
}
init() {
        ::init();
        add_action("buy_room", "buy_room");
}
buy_room(str) {
        if (str == "small") {
        write("You bought small room");
}
        if (str == "medium") {
        write("You bought medium room.\n");
}
        if (str == "large") {
        write("You bought large room.\n");
}

return 1;

}
