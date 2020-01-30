inherit "room/room";

reset(arg) {
if(arg) return;
add_exit("southwest","/wizards/veron/areat/cotd/cs.c");
add_exit("east","/wizards/veron/areat/cotd/ceme2.c");


  short_desc = "Cemetery";

  long_desc = "The graveyard of Remick is a gloomy place. Some of the graves\n"+
              "have been digged open and some unburied corpses rot on the ground.\n"+	   
	      "Almost all the gravestones have been turned upside down. A single\n"+
              "leafless and blackened tree stands in the middle of the graveyard.\n";
              
  items = allocate(8);
  items[0] = "graves";
  items[1] = "Some graves have been digged open";          
  items[2] = "corpses";
  items[3] = "Unburied corpses of three men";
  items[4] = "gravestones";
  items[5] = "Almost all of the gravestones have been turned upside down";
  items[6] = "tree";
  items[7] = "A blackened and leafless tree stands alone in the middle of the graveyard\n"+
             "it has a brass sign attached to it reading\n"+
             "'Here lies my beloved wife Deborah. Rest in peace'";

}
init() {
  ::init();
  add_action("hep", "bury");
  
 }
hep(str) {
    
    if(str == "heart under tree") {
    if(present("heart", this_player()) && !present("heart", this_player())->query_no_save()) {

    write("You carefully dig open the ground under the tree and place Justin's heart in the\n"+
          "hole. May he rest in peace.\n");
    say(this_player()->query_name() + " carefully digs open the ground under the tree and places Justin's\n"+
			"heart in the hole.\n");
 this_player()->set_quest("Bury Justin's heart in his wife's grave");
  
   

    destruct(present("heart", this_player()));
  
return 1;
}



 else { 
 write("Bury what and where?");
return ;
}}
else {
	return;
}}