inherit "room/room";
int i;
object tiili;
 
reset(arg) {
 
  add_exit("north","rampart_8");
  add_exit("south","rampart_6");
  short_desc = "On the ramparts";
  long_desc =
"You are standing on top of the ramparts of castle North Face. You can see the courtyard\n" +
"down below. To all directions you can see the mountains stretch for many miles. Looking\n" +
"over the ramparts, you can see the ground, some hundred feet below. A strong breeze\n" +
"blows here, high up in the Khalkhist mountains. You can see a huge wall, on the west side\n" +
"with no apparent purpose.\n";
 
  items = allocate(4);                
  items[0] = "wall";
  items[1] = "A massive facade of the western side, at least 10 feet thick, is\n"+
             "blocking the view to the west and anything that lies beneath.\n"+
             "A brick seems to be missing from the wall.";

}
init()
{
 
::init();
add_action("west","west");
add_action("place","place");
}
place(string str) {
if(!str) { write("Place what?\n"); return; }
tiili=present("tiili0407432002",this_player());

if(!tiili) {
write("You don't have the right stuff to put in the wall.\n");
return;
}

write("You insert the brick into the wall, but nothing happens.\n");
    say(""+this_player()->query_name()+" fumbles with a brick.\n");
    destruct(tiili);
    call_out("seina_aukeaa_1",5);
    i = 1;
    return 1;
}

int seina_aukeaa_1() {
tell_room(this_object(),
        "You hear a deep rumbling sound coming from the wall.\n");
call_out("seina_aukeaa_2",5);
return 1;
}

int seina_aukeaa_2() {
tell_room(this_object(),
        "The wall starts to creak apart from the middle.\n");
call_out("seina_aukeaa_3",5);
return 1;
}

int seina_aukeaa_3() {
add_exit("west","/wizards/walla/northern/rooms/lvl3/drawbridge_1");
tell_room(this_object(),
        "The wall opens gradually, revealing a drawbridge.\n");
shout("The fortifications of castle North Face tremble as forgotten secrets are revealed.\n");
return 1;
}



west() {
if(!i) {
write("There is a huge wall in front of you, which you cannot pass.\n");
return 1;
}
call_other("/wizards/walla/northern/rooms/lvl3/drawbridge_1","joku_tuli",this_player()->query_name());
}
