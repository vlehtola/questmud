object ob;
int time;
int exp_award;

short() { return "A sign";}

init() {
add_action("join", "join");
}


id(str) {
return str == "event_sign","sign";
}


long(str) {
write("This competition is not for the weak!\n");
write("The fight will take place in a 3*3 square hall, located in unknown area.\n");
write("(Note: You will NOT lose experience from your death!!)\n");
}

join() {
write("Ok, You join the competition.\n");
write("Gerdy makes funny gestures and your surroundings change!\n");
move_object(this_player(), "/wizards/bulut/event/entrance");
shout("Gerdy shouts: " + capitalize(this_player()->query_name()) + " just signed up!\n");
return 1;}

self_destruct() {
destruct(present("event_sign",find_object("/world/city/cs")));
      
}                                        
