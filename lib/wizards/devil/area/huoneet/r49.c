inherit "room/room";
object monster,monster2;

reset(arg) {
  if(!present("vampire")) {
    move_object(clone_object("/wizards/devil/area/mobit/vampire.c"), this_object());
    move_object(clone_object("/wizards/devil/area/mobit/vampire.c"), this_object());
}
 
  if(arg) return;
 
  add_exit("east","/wizards/devil/area/huoneet/r48.c");

  short_desc = "In the middle of the graveyard";
  long_desc = "You have arrived in the middle of this huge graveyard. You can see lots of\n"+
                "gravestones all around you. Huge temple rises to the sky from here.\n"+
                "There is a special gravestone under the big tree beside you.\n";  
 
items = allocate(4);
  items[0] = "gravestone";
  items[1] = "This gravestone belongs to someone important person, like king or emperor. It is made from gold and there is an old writing on it."; 
  items[2] = "writing";
  items[3] = "King Mordok our ruler and beloved king: Rest In Peace "; }
  
init() {
  ::init(); 
  add_action("push", "push");
}

push(str) {
  if(str == "gravestone") {
    write("You gather your powers and push the gravestone aside.\n"); 
    say(""+this_player()->query_name()+" vanishes under the gravestone.\n");    
    move_object(this_player(),"/wizards/devil/area/huoneet/r50.c");
    return 1; 
}
    write("You cannot push that.\n");
    return 1;
}
