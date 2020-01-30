inherit "room/room";
q
Q
init() {
  ::init();
  add_action("insert", "insert");
}

insert(str) {
  if(str != "brick") return;
  if(!present("tiili0400190120",this_player()))
    return 0;
    destruct(present("tiili0400190120",this_player())); 
    write("You insert the brick into the wall, but nothing happens.\n");
    say(""+this_player()->query_name()+" fumbles with a brick.\n");
    call_out("seina_aukeaa_1",5);
    return 1;
}

int seina_aukeaa_1() {
tell_room(environment(this_object()),
        "You hear a deep rumbling sound coming from the wall\n");
call_out("seina_aukeaa_2",5);
return 1;
}

int seina_aukeaa_2() {
tell_room(environment(this_object()),
        "The wall starts to creak apart from the middle.\n");
call_out("seina_aukeaa_3",5);
return 1;
}

int seina_aukeaa_3() {
add_exit("west","/wizards/walla/northern/rooms/lvl3/drawbridge_1");
tell_room(environment(this_object()),
        "The wall opens gradually, revealing a drawbridge.\n");
tell_object(find_player(lower_case(str)),"A huge gust of wind hits you in the face.");
shout("The fortifications of castle North Face trembles as "+str+" shakes it's foundations.\n");
return 1;
}

 
reset(arg) {
  if(arg) return;
  add_exit("north","rampart_8");
  add_exit("south","rampart_6");
  short_desc = "On the ramparts";
  long_desc =
"You are standing on top of the ramparts of castle North Face. You can see the courtyard\n" +
"down below. To all directions you can see the mountains stretch for many miles. Looking\n" +
"over the ramparts, you can see the ground, some hundred feet below. A strong breeze\n" +
"blows here, high up in the Khalkhist mountains. You can a huge wall, on the west side\n" +
"with no apparent purpose.\n";
 
  items = allocate(4);                
  items[0] = "wall";
  items[1] = "A massive facade of the western side, at least 10 feet thick, is";
  items[2] = "blocking the view to the west and anything that lies beneath.";
  items[3] = "A brick seems to be missing from the wall.";



}
