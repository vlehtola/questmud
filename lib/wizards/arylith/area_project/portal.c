inherit "room/room";
reset(status arg) {
if(arg) return;
add_exit("southwest", "/wizards/arylith/workroom");
add_exit("portal", "/wizards/arylith/area_project/desert/entrance");

short_desc = "A portal room.\n";
long_desc = "Burning torches in iron sconces line the walls of this room, lighting it brilliantly.\n"+
"At the room's center lies a squat stone altar, its top covered in recently spilled blood.\n"+
"A channel in the altar funnels the blood down its side to the floor where\n"+
"it fills grooves in the floor that trace some kind of pattern or symbol around the altar.\n"+
"Unfortunately, you can't tell what it is from your vantage point.\n"+
"You can see a some sort of a portal up ahead.\n";
}
