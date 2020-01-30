inherit "room/room";
 status i = 1;

reset(arg) {
  if(arg) { return; }
  add_exit("northeast", "/wizards/torspo/areat/ogre/room5.c");
  add_exit("east", "/wizards/torspo/areat/ogre/room8.c");

  short_desc = "Dark forest";
  long_desc = "A flock of birds rises from the bushes as you walk past them. This\n"+
              "part of the forest is full of life. Different small animals run all around\n"+
              "the ground, playing and teasing each other. There is also a couple meters\n"+
              "high anthill beside an ancient pine.\n";

  items = allocate(4);
  items[0] = "anthill";
  items[1] = "A couple meters high anthill. Little ants sure have had a lot of work building\n"+
             "it. The destruction of the anthill might be displeasure for the ants, who\n"+
             "have built it for ever\n";
  items[2] = "animals";
  items[3] = "Lots of different small animals, such as rabbits and rats, run all around the place";
}

 init() {
  ::init();
  add_action("anthill", "stamp");
 }

  anthill(str) {
   if(str == "anthill") {
    if(i) {
    write("You stamp the anthill but it doesn't seem to affect it. One ant manages to\n"+
          "crawl up your leg and you slap it into it's death.\n");
    say(this_player()->query_name()+ " desperately tries to stamp huge anthill down but fails miserably.\n");
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/eq/ant.c"), this_player());
    i--;
    return 1;
   }

    write("You stamp the anthill but it doesn't seem to affect it.\n");
    say(this_player()->query_name()+ " desperately tries to stamp huge anthill down but fails miserably\n");
    return 1;
   }
 }
