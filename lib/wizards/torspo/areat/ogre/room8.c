inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("cave", "/wizards/torspo/areat/ogre/cave.c");
  add_exit("west", "/wizards/torspo/areat/ogre/room6.c"); 
  short_desc = "Dark forest";
  long_desc = "A waterfall gushes water down from the projecting rock. The couple meters\n"+
              "high projecting rock gushes clear water to a small, clear lake. As you gaze\n"+
              "at the lake, you see an image of yourself and lots of small fishes swimming\n"+
              "in the water. A small stream originates in from the lake, flowing rapidly\n"+
              "southwards.\n";

  items = allocate(4);
  items[0] = "waterfall";
  items[1] = "A couple meters wide, beautiful waterfall. A dark cave can be seen behind the\n"+
             "waterfall";  
  items[2] = "lake";
  items[3] = "A small lake with clear water. You can see the bottom of the lake and lots\n"+
             "of salmons swimming down there";
}

 init() {
  ::init();
  add_action("ant", "dip");
 }

  ant(str) {
   int i;
   if(str == "ant") {
    if(present("ant", this_player())) {
     object ob;
     ob = present("ant" ,this_player());
     destruct(ob);
     i = random(2);
      if(i != 0) {
       write("You drop ant into water and it sinks to the bottom.\n");
    say(this_player()->query_name()+ " drops ant in the lake and watches how it sinks to the bottom.\n");
      return 1;
      }
     write("You dip the ant into water and it instantly some fishes swim upwards and\n"+
           "eat it. You manage to catch one of the fishes and put it into your pocket\n");
    say(this_player()->query_name()+ " drops ant into the lake and catches one salmon when the fishes\n"+
                                     "come to take the offered food\n");
     move_object(clone_object("/wizards/torspo/areat/ogre/monsters/eq/salmon.c"), this_player());
      return 1;
      }
     write("You dont have one.\n");
     return 1;
   }
 }
