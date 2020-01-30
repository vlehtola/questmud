short() { return "A cute little kitten"; }
id(str) { return str == "kitten"; }

init() {
    add_action("pat", "pat");
    add_action("kill", "kill");
    add_action("caress", "caress");
}

long(str) {
write("A cute little kidnapped kitten.\n");
    return;
}

kill(str) {
if (str == "kitten") {
write("You pound at the small, innocent kitten with your fist, making blood\n");
write("and intestines rip through its skin promptly ending its life.\n");
say(this_player()->query_name()+ " smashes the kitten's head in with a violent movement of the swordarm.\n");
destruct(this_object());
return 1;
  }
}


pat(str) {
if (str == "kitten") {
write("You gently pat the kitten, which starts purring gently.\n");
say(this_player()->query_name()+ " gently pats the kitten, which starts purring gently.\n");  
return 1;
  }
}

caress(str) {
if (str == "kitten") {
write("You gently caress the kitten, which starts purring gently.\n");
say(this_player()->query_name()+ " gently caresses the kitten, which starts purring gently.\n");
return 1;
  }
}

get() {
    return 1;
}
