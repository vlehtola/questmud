object ob1;
object ob2;
object ob3;
object ob4;
init() {
write("Type 'start' to begin the event.\n");
add_action("start", "start");
}

start() {
write("Ok, moving objects to their locations.\n");
ob1 = clone_object("/wizards/bulut/event/sign");
ob2 = clone_object("/wizards/bulut/event/pkmaster");
ob3 = clone_object("/wizards/bulut/event/pkobj");
ob4 = clone_object("/wizards/bulut/event/pkevent");

shout("Gerdy shouts: Greetings, brave adventurers!\n" +
      "Those who feel strong and fearless, come and test\n"+
      "your strength with the mightiest warriors in Deleria!\n"); 

write_file("/log/pkevent_log", "Loader: " + this_player()->query_name() + "\n");

move_object(ob1, "/world/city/cs");
move_object(ob2, "/world/city/cs");
move_object(ob4, "/wizards/bulut/event/entrance");
destruct(this_object());
return 1;
}                                                       
