inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  short_desc = "snowfield";
  long_desc=("Cold wind blows as endless field of snow opens here.\n"+
             "No other objects can be spotted. Just snow, this is\n"+
             "great place to start snow-war.\n");   
             add_exit("west","/wizards/luminarc/spec/snow1");
                add_exit("north","/wizards/luminarc/spec/snow3");
                add_exit("east","/wizards/luminarc/spec/snow5");
   set_light(3);

}

init() {
  ::init();
  add_action("make", "make");
}

make(str) {
  if(str == "snowball") {
        call_out("snowball", 10); 
        write("You start making small snowball.\n");
        return 1; /* stop the execution */
   }

}

snowball() {
    if (present("snowball", this_player()))
    {
    write("But you already have one snowball.\n");
    return 1;
    }
    write("snowball ready!\n");
    ob = clone_object("/wizards/luminarc/spec/snowball");
    move_object(ob, this_player());
}




