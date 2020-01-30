inherit "room/room";
object monster;

reset(arg) {
  if(!present("vampire")) {
    move_object(clone_object("/wizards/irmeli/area3/vampire.c"),
    this_object());
}
 
  if(arg) return;
 
  add_exit("east","/wizards/irmeli/area3/ruum48.c");

  short_desc = "In the middle of the graveyard";
  long_desc = "You have arrived in the middle of this huge graveyard. You can see lots of\n"+
                "gravestones all around you. Huge temple rises to the sky from here.\n"+
                "There is a special gravestone under the big tree beside you.\n";  
 
items = allocate(4);
  items[0] = "gravestone";
  items[1] = "This gravestone belongs to someone important person, like king or emperor. It is made from gold and there is an old writing on it. You might to try push it"; 
  items[2] = "writing";
  items[3] = "King mordor our ruler and beloved king: Rest In Peace "; }
  
init() {
  ::init(); 
  add_action("push", "push");
}

push(str) {
  if(str == "gravestone") {
    write("You gather your powers and push the gravestone aside.\n"); 
    this_player()->move_player("vanishes under the gravestone","/wizards/irmeli/area3/ruum50.c");
    return 1; 
}
    write("Ewwwk.\n");
    return 1;
}

