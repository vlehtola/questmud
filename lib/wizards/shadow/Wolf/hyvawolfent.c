inherit "room/room";
int venee;


reset(arg) {
  add_exit("down","/wizards/shadow/Wolf/wolf1");
  short_desc = "The entrance to the Valley of the frozen wolf.";
  long_desc =
"You are standing  before the valley of the frozen wolf.\n"+
"The valley itself extends down from here. From up here you \n"+
"can see all around the valley. A long way north, you spot an\n"+
"building that resembles a temple. On the roof of that building you \n"+
"spot a huge, white statue that resemble a wolf. As you look down \n"+
"you notice that there is a sort of giant staircase leading down to the \n"+
"snow covered valley. You see some movement down below. It must\n"+
"be the 'Ice people' that worship the wolf as a god. The temple\n"+
"must be made for that. There is a rowing-boat on the harbor.\n";
}

init() {
    ::init();
   add_action("enter", "enter");
   venee = 1;
}

enter(str) {
  if ((str) == "boat") {
  if (venee == 0) {
  write("The boat is not here at the moment.\n");
  return 1;
  }
  venee = 0;  
  say(this_player()->query_name()+" enters the boat and takes off.\n");
  write("You walk to the rowing-boat and promptly jump on board.\n");
  move_object(this_player(),"/wizards/shadow/Wolf/boat2.c");
  say(this_player()->query_name()+" enters the boat.\n");
  write("You push the boat off the harbor.\n");
  say(this_player()->query_name()+" pushes the boat off the harbor.\n");
  call_out("current1", 10);
  return 1; 
  }
 }
current1() {
  write("The currents carry the boat along.\n");
  call_out("current2", 10);
  return 1;
 }
current2() {
  write("The boat starts moving amazingly rapidly.\n");
  call_out("current3", 10);
  return 1;
 }
current3() {
  write("As you spot dry land, the boat slows down.\n");
  call_out("land", 10);
  return 1; 
 }
land() {
  venee = 1;
  write("The boat reaches a rockt beach, and you quickly jump off.\n");
  move_object(this_player(),"/wizards/shadow/Wolf/beach.c");
  say(this_player()->query_name()+" arrives on a small rowing-boat.\n");    
  tell_room("wizards/shadow/Wolf/wolfent","The boat returns, as if enchanted.\n");
  return 1; 
}
