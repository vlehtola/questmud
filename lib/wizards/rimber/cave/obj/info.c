
id(str) { return str == "paper"; }

short() { return "An old piece of paper"; }

long() {
 write("The paper is yellow and looks very fragile. Someone has written rough black\nletters in it. Maybe you could read it.\n");
 }

init() {
 add_action("read", "read");
}

read(string str) {
 if(str != "paper") { write("Read what?");
  return 1;
 }
 write("Long time ago dark dweller kings had mystical warhammer. Rumors tell that this\nwarhammer sucked all the light around it and released it in a lightning form.\nBut one day powerful wizards got this warhammer and he broke it in three\npieces. He separeted a stone from the warhammer's head and untied the leather\nstrap. After this he gave the warhammer back to dark dweller king.\nOnly Brutus the blacksmith can rebuild this warhammer again. But he has\ndisappeared in the dark dweller maze.\n");
 return 1;
}

get() { return 1; }

