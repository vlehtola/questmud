inherit "room/room";
object monster,monster2;

reset(arg) {
   if(arg) return;
   
       if (!monster) {
                monster = clone_object("/wizards/jenny/linnake/mosut/poika_august.c");
                move_object(monster, this_object());
        }
       if (!monster2) {
                monster2 = clone_object("/wizards/jenny/linnake/mosut/queen.c");
                move_object(monster2, this_object());
        }


        add_exit("west","/wizards/jenny/linnake/huoneet/throne6.c");
        add_exit("east","/wizards/jenny/linnake/huoneet/throne4.c");
        add_exit("southeast","/wizards/jenny/linnake/huoneet/throne3.c");
        add_exit("south","/wizards/jenny/linnake/huoneet/throne2.c");
        add_exit("southwest","/wizards/jenny/linnake/huoneet/throne1.c");

  short_desc = "The throne room";
  long_desc = "When you look around you see 2 large thrones, the other one\n"+
              "belongs to queen and other belong to king. There is red carpet\n"+
              "on the floor and a huge curtain is on the wall. There are some\n"+
              "people coming and going all the time and you hear music coming\n"+
              "from somewhere.\n";

 
        items = allocate(2);
        items[0] = "curtain";
        items[1] = "Huge curtain is on the wall, maybe there is something behind it";
}
 

init() {
  ::init(); 
  add_action("penetrate", "penetrate"); 
}

penetrate(str) {
  if(str == "curtain") {
    write("You penetrate yourself through the curtain!\n"); 
    say(this_player()->query_name()+" vanishes behing the curtain!\n");
    move_object(this_player(),"/wizards/jenny/linnake/huoneet/treasure1.c");
    command("look",this_player());
     }
     return 1;
 }
