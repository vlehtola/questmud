inherit "room/room";
  
reset(arg) {
if(arg) return;

  add_exit("north","/wizards/siki/lizard/dock1");


  short_desc = "At the end of the dock";
  long_desc = "The dock is very old and the wood that it is made of is slowly\n"+
              "rotting. The small lake is calm, but you sense something\n"+
              "strange in it.\n";
  items = allocate(4);
  items[0] = "lake";
  items[1] = "A small calm lake. The water is muddy and there is something\n"+
             "strange in it. You feel uncomfortable";
 items[2] = "water";
 items[3] = "A small calm lake. The water is muddy and there is something\n"+
            "strange in it. You feel uncomfortable";
}
  init() {
  add_action("dive", "dive");
  ::init();
}


dive(str) {
    write("You dive into the cold water.\n");
    say(this_player()->query_name()+" dives into the water.\n");
    this_player()->set_quest("Dive into the cold water");
    move_object(this_player(), "/wizards/siki/lizard/water2");
    say(this_player()->query_name()+" enters the water.\n");

    return 1;

  }



